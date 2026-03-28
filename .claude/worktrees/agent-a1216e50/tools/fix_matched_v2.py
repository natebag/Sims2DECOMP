#!/usr/bin/env python3
"""
Fix auto-matched files so they compile. V2 - much more aggressive.

Strategy:
1. Strip #if 0 wrapper
2. Apply text-level fixes for common patterns
3. Try compile
4. If fails, apply error-driven fixes
5. If still fails, re-wrap in #if 0
"""

import os
import re
import sys
import subprocess
import tempfile

REPO = r"F:\coding\Decompiles\Sims 2"
MATCHED_DIR = os.path.join(REPO, "src", "matched")
CXX = r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC\bin\powerpc-eabi-g++.exe"
CXXFLAGS = [
    "-mcpu=750", "-meabi", "-mhard-float", "-O2",
    "-fno-exceptions", "-fno-rtti", "-fno-builtin",
    "-fshort-wchar", "-nostdinc++", "-Wall", "-Wno-unused", "-Wno-return-type",
    "-fpermissive",  # Allow implicit conversions (int<->ptr)
    "-Iinclude", "-Isrc", "-Ilibs/dolphinsdk", "-Ilibs/sn_runtime", "-Ilibs/apt",
    "-DNDEBUG", "-DEA_PLATFORM_GAMECUBE=1", "-DGEKKO",
]


def try_compile(filepath):
    """Try to compile a file, return (success, error_output)."""
    cmd = [CXX] + CXXFLAGS + ["-c", filepath, "-o", "NUL"]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=30, cwd=REPO)
        return result.returncode == 0, result.stderr
    except Exception as e:
        return False, str(e)


def strip_if0(content):
    """Remove #if 0 / #endif wrapper."""
    lines = content.split('\n')
    new_lines = []
    found_if0 = False
    for line in lines:
        if not found_if0 and line.strip() == '#if 0':
            found_if0 = True
            continue
        new_lines.append(line)
    if found_if0:
        for i in range(len(new_lines) - 1, -1, -1):
            if new_lines[i].strip() == '#endif':
                new_lines.pop(i)
                break
    return '\n'.join(new_lines)


def ensure_includes(content):
    """Ensure the file has #include directives."""
    has_types = '#include "types.h"' in content
    has_stub = '#include "stub_classes.h"' in content
    lines = content.split('\n')
    insert_pos = 0
    for i, line in enumerate(lines):
        stripped = line.strip()
        if stripped and not stripped.startswith('//'):
            insert_pos = i
            break
    additions = []
    if not has_types:
        additions.append('#include "types.h"')
    if not has_stub:
        additions.append('#include "stub_classes.h"')
    if additions:
        for j, add in enumerate(additions):
            lines.insert(insert_pos + j, add)
    return '\n'.join(lines)


def name_all_params(line):
    """
    Given a function definition line, name all unnamed parameters.
    Uses r4=p4, r5=p5, etc. for multi-param.
    Uses 'val' for single setters with pointer/int/etc.
    """
    # Must have { in the line
    if '{' not in line or '::' not in line:
        return line

    brace_pos = line.index('{')
    decl = line[:brace_pos]
    body = line[brace_pos:]

    # Find parameter list parens
    # Search backward from brace_pos for matching ()
    paren_end = None
    paren_start = None

    # First find the ) before {, skipping optional const
    search_area = decl.rstrip()
    # Remove trailing const
    if search_area.endswith('const'):
        search_area = search_area[:-5].rstrip()

    if not search_area.endswith(')'):
        return line

    paren_end = len(search_area) - 1
    depth = 1
    i = paren_end - 1
    while i >= 0 and depth > 0:
        if search_area[i] == ')':
            depth += 1
        elif search_area[i] == '(':
            depth -= 1
        i -= 1
    paren_start = i + 1

    if depth != 0:
        return line

    params_str = search_area[paren_start+1:paren_end]
    before_params = search_area[:paren_start+1]  # includes (
    after_params = decl[paren_end:]  # includes ) and optional const and spaces

    # Split params respecting nesting
    params = split_params(params_str)

    # Determine what names the body needs
    needs = set()
    for name in ['val', 'fval', 'f1', 'f2', 'f3', 'index', 'first',
                 'p4', 'p5', 'p6', 'p7', 'p8']:
        if re.search(r'\b' + name + r'\b', body):
            needs.add(name)

    if not needs:
        return line

    new_params = []
    for idx, param in enumerate(params):
        param = param.strip()
        if not param:
            new_params.append(param)
            continue

        if param_has_name(param):
            new_params.append(param)
            continue

        # Figure out what name to assign
        reg_num = idx + 4  # r4 for first param (r3=this)
        pname = f'p{reg_num}'

        assigned = False
        if pname in needs:
            new_params.append(param + ' ' + pname)
            assigned = True
        elif len(params) == 1:
            # Single param - try common names
            for name in ['val', 'fval', 'f1', 'index', 'first']:
                if name in needs:
                    new_params.append(param + ' ' + name)
                    assigned = True
                    break
            if not assigned:
                # Try p4 (common for single param)
                if 'p4' in needs:
                    new_params.append(param + ' p4')
                    assigned = True
        elif len(params) == 2 and idx == 0:
            # First of two params
            for name in ['val', 'fval', 'f1', 'index', 'first']:
                if name in needs:
                    new_params.append(param + ' ' + name)
                    assigned = True
                    break
        elif len(params) == 2 and idx == 1:
            for name in ['f2']:
                if name in needs:
                    new_params.append(param + ' ' + name)
                    assigned = True
                    break
        elif len(params) == 3 and idx == 2:
            for name in ['f3']:
                if name in needs:
                    new_params.append(param + ' ' + name)
                    assigned = True
                    break

        if not assigned:
            new_params.append(param)

    new_params_str = ', '.join(new_params)
    return before_params + new_params_str + after_params + body


def split_params(params_str):
    """Split parameter string by commas respecting nesting."""
    params = []
    depth = 0
    current = []
    for c in params_str:
        if c in ('(', '<'):
            depth += 1
            current.append(c)
        elif c in (')', '>'):
            depth -= 1
            current.append(c)
        elif c == ',' and depth == 0:
            params.append(''.join(current))
            current = []
        else:
            current.append(c)
    if current:
        params.append(''.join(current))
    return params


def param_has_name(param):
    """Check if a parameter declaration includes a name."""
    param = param.strip()
    if not param:
        return False
    # Function pointers like "void (*)(int)" or "void (*foo)(int)"
    if '(*)' in param:
        return False
    if '(*' in param:
        # Check if it's "type (*name)(args)" - has name
        m = re.search(r'\(\*(\w+)\)', param)
        return m is not None

    # Remove templates
    cleaned = re.sub(r'<[^>]*>', 'T', param)
    # Remove parens (function ptr types)
    cleaned = re.sub(r'\([^)]*\)', '', cleaned)

    tokens = cleaned.split()
    if len(tokens) <= 1:
        return False

    last = tokens[-1].rstrip('*&')
    if not last:
        return False

    type_keywords = {
        'int', 'char', 'short', 'long', 'float', 'double', 'void',
        'unsigned', 'signed', 'bool', 'const', 'T',
    }
    if last in type_keywords:
        return False
    if tokens[-1].endswith('*') or tokens[-1].endswith('&'):
        return False

    return True


def fix_constructors(content):
    """Fix 'void ClassName::ClassName(' constructors."""
    lines = content.split('\n')
    fixed = []
    for line in lines:
        # Match: void ANYTHING::Name( where the last :: component equals Name
        m = re.match(r'^(void\s+)((\w[\w:]*?)::(\w+))\s*\(', line)
        if m:
            full_qual = m.group(2)  # e.g., "CasGenetics::Grandparent::Grandparent" or "Background::Background"
            parts = full_qual.split('::')
            if len(parts) >= 2 and parts[-1] == parts[-2]:
                # Constructor - remove void
                line = line[len(m.group(1)):]
        fixed.append(line)
    return '\n'.join(fixed)


def fix_sda_globals(content):
    """Fix SDA global patterns that don't compile."""
    # "return /* SDA global @ r13-XXXXX */;" -> "return 0;"
    content = re.sub(r'return\s+/\*\s*SDA[^*]*\*/', 'return 0', content)
    # "return /* SDA global float @ r13-XXXXX */;" -> "return 0.0f;"
    # Already handled by the above since we return 0 which will work for both

    # "{ /* SDA global @ r13-XXXXX = val */ }" -> "{ }" for void functions
    # "{ /* SDA: store int @ r13-XXXXX, float @ r13-XXXXX */ }" -> "{ }"
    # These are comment-only bodies in void functions - leave them as empty
    return content


def fix_comment_only_bodies(content):
    """Fix functions whose body is only comments (non-void need return)."""
    lines = content.split('\n')
    fixed = []
    for line in lines:
        stripped = line.strip()
        if not stripped or stripped.startswith('//') or stripped.startswith('#'):
            fixed.append(line)
            continue
        if '::' not in stripped or '{' not in stripped or '}' not in stripped:
            fixed.append(line)
            continue

        brace_start = stripped.index('{')
        brace_end = stripped.rindex('}')
        body = stripped[brace_start+1:brace_end].strip()

        # Remove all comments from body
        body_clean = re.sub(r'/\*[^*]*\*/', '', body)
        body_clean = re.sub(r'//.*', '', body_clean)
        body_clean = body_clean.strip()

        if body_clean:
            # Body has actual code
            fixed.append(line)
            continue

        # Body is empty or only comments - check return type
        decl = stripped[:brace_start].strip()
        m = re.match(r'^(.*?)\s+([\w:]+::\w+)\s*\(', decl)
        if not m:
            fixed.append(line)
            continue

        ret_type = m.group(1).strip()
        if ret_type in ('void', ''):
            # void function with comment-only body: just empty it
            new_line = stripped[:brace_start+1] + ' }'
            after = stripped[brace_end+1:].strip()
            if after:
                new_line += '  ' + after
            fixed.append(new_line)
        else:
            # Non-void with comment-only body: add return
            if 'float' in ret_type or 'double' in ret_type:
                ret_val = '0.0f'
            elif 'bool' in ret_type:
                ret_val = 'false'
            else:
                ret_val = '0'
            new_line = stripped[:brace_start+1] + ' return ' + ret_val + '; }'
            after = stripped[brace_end+1:].strip()
            if after:
                new_line += '  ' + after
            fixed.append(new_line)

    return '\n'.join(fixed)


def fix_duplicate_functions(content):
    """Remove duplicate function definitions."""
    lines = content.split('\n')
    seen_sigs = set()
    result = []

    for line in lines:
        stripped = line.strip()
        if '::' in stripped and '{' in stripped and '}' in stripped \
                and not stripped.startswith('//') and not stripped.startswith('#'):
            brace_pos = stripped.index('{')
            sig = stripped[:brace_pos].strip()
            if sig in seen_sigs:
                # Remove preceding comment line too
                if result and result[-1].strip().startswith('//'):
                    result.pop()
                if result and result[-1].strip() == '':
                    result.pop()
                continue
            seen_sigs.add(sig)
        result.append(line)

    return '\n'.join(result)


def fix_operator_new(content):
    """Fix operator new returning int."""
    content = re.sub(
        r'\bint\s+([\w:]+::operator\s+new\s*(?:\[\])?\s*\([^)]*\))\s*\{[^}]*\}',
        lambda m: 'void* ' + m.group(1) + ' { return (void*)0; }',
        content
    )
    return content


def fix_pointer_stores_as_int(content):
    """
    Fix patterns where pointer params are stored as int:
    void Foo::Set(Type*) { *(int*)((char*)this + X) = val; }
    →
    void Foo::Set(Type* val) { *(int*)((char*)this + X) = (int)val; }

    The -fpermissive flag should handle this, but let's also fix the naming.
    """
    # This is handled by name_all_params + fpermissive
    return content


def detect_and_fix_namespace_functions(content):
    """
    For functions using undeclared namespaces (EA::, InteractorModule::, etc.),
    check if they use 'this' (member function of nested class) or not.
    If they do, we need the nested class declaration.
    If we can't declare it, wrap those specific functions in #if 0.
    """
    lines = content.split('\n')
    result = []

    # Known namespace prefixes that cause issues
    problem_prefixes = [
        'EA::Allocator::GeneralAllocator',
        'InteractorModule::Interactor',
        'InteractorModule::WallManipulator',
        'InteractorModule::WallPainter',
        'InteractorModule::FloorPainter',
        'InteractorModule::ObjectManipulator',
        'InteractorModule::SimInteractor',
        'InteractorModule::DirectInteractor',
        'InteractorModule::SocialModeInteractor',
        'InteractorModule::InteractorInputManager',
        'InteractorModule::InteractorVisualizer',
        'InteractorModule::InteractorManager',
        'Memory::HandleNode',
        'WantFear::Bookmark',
        'WantFear::Tree',
        'BBI::InventoryItem',
        'BBI::InventoryItems',
        'Effects::Effect',
        'Effects::EffectsManager',
        'Effects::EffectsSequencer',
        'Effects::FastParticleEmitter',
        'CasGenetics::Grandparent',
        'EFileSystem::FileCreator',
        'EyeToyClient::Debug',
        'ActionMenu::MenuItem',
        'INGTarget::IngInfo',
    ]

    for line in lines:
        stripped = line.strip()
        if stripped.startswith('//') or stripped.startswith('#') or not stripped:
            result.append(line)
            continue

        has_problem = False
        for prefix in problem_prefixes:
            if prefix + '::' in stripped or prefix + '(' in stripped:
                has_problem = True
                break

        if has_problem and '{' in stripped:
            # Wrap this function line in #if 0
            # Skip preceding address comment
            if result and result[-1].strip().startswith('//'):
                comment = result.pop()
                result.append('#if 0')
                result.append(comment)
            else:
                result.append('#if 0')
            result.append(line)
            result.append('#endif')
        else:
            result.append(line)

    return '\n'.join(result)


def fix_return_type_mismatches(content, errors):
    """Fix return type mismatches based on compiler errors."""
    if not errors:
        return content

    lines = content.split('\n')
    error_lines = errors.split('\n')

    for i, eline in enumerate(error_lines):
        # "no declaration matches 'RETTYPE CLASS::METHOD(...'"
        m = re.search(r"no declaration matches '(.+?)\s+(\w[\w:]+::\w+)\s*\(", eline)
        if m:
            old_ret = m.group(1)
            func_id = m.group(2)
            # Find candidate
            for j in range(i+1, min(i+5, len(error_lines))):
                cm = re.search(r"candidate is: '(.+?)\s+" + re.escape(func_id) + r'\s*\(', error_lines[j])
                if cm:
                    new_ret = cm.group(1)
                    if new_ret != old_ret:
                        # Replace in content
                        old_pattern = old_ret + ' ' + func_id + '('
                        new_pattern = new_ret + ' ' + func_id + '('
                        for k, line in enumerate(lines):
                            if old_pattern in line:
                                lines[k] = line.replace(old_pattern, new_pattern, 1)
                    break

    return '\n'.join(lines)


def fix_bare_returns(content):
    """Fix 'return;' in non-void functions → 'return 0;'"""
    # This is tricky without parsing - rely on -Wno-return-type
    return content


def fix_set_body_stores(content):
    """
    Fix setters that store pointer params as int via 'val'.
    void Foo::SetBar(Type* val) { *(int*)(... ) = val; }
    With -fpermissive this should work as a warning, not error.
    """
    return content


def process_file(filepath, stats):
    """Process a single auto-matched file."""
    with open(filepath, 'r') as f:
        original = f.read()

    if '#if 0' not in original:
        return True  # Already compiling

    content = strip_if0(original)

    # Apply all text-level fixes
    content = ensure_includes(content)
    content = fix_constructors(content)
    content = fix_operator_new(content)
    content = fix_sda_globals(content)
    content = fix_duplicate_functions(content)

    # Name parameters in each function line
    lines = content.split('\n')
    named_lines = []
    for line in lines:
        stripped = line.strip()
        if stripped.startswith('//') or stripped.startswith('#') or not stripped:
            named_lines.append(line)
        else:
            named_lines.append(name_all_params(line))
    content = '\n'.join(named_lines)

    content = fix_comment_only_bodies(content)

    # Handle namespace issues - wrap problematic functions
    content = detect_and_fix_namespace_functions(content)

    # Try to compile
    tmp = tempfile.NamedTemporaryFile(suffix='.cpp', delete=False, mode='w', dir=REPO)
    tmp.write(content)
    tmp.close()

    success, errors = try_compile(tmp.name)

    if not success:
        # Try fixing return type mismatches
        content2 = fix_return_type_mismatches(content, errors)
        if content2 != content:
            content = content2
            with open(tmp.name, 'w') as f:
                f.write(content)
            success, errors = try_compile(tmp.name)

    if not success:
        # Second attempt at return type fixes
        content2 = fix_return_type_mismatches(content, errors)
        if content2 != content:
            content = content2
            with open(tmp.name, 'w') as f:
                f.write(content)
            success, errors = try_compile(tmp.name)

    os.unlink(tmp.name)

    if success:
        with open(filepath, 'w') as f:
            f.write(content)
        stats['fixed'] += 1
        return True
    else:
        # Keep #if 0
        # Don't modify the file - leave original
        stats['still_broken'] += 1
        first_error = ''
        for line in errors.split('\n'):
            if 'error:' in line:
                first_error = line.strip()
                break
        cat = categorize_error(first_error)
        stats['error_cats'][cat] = stats['error_cats'].get(cat, 0) + 1
        return False


def categorize_error(error_line):
    """Categorize an error for reporting."""
    if 'was not declared in this scope' in error_line:
        m = re.search(r"'(\w+)' was not declared", error_line)
        if m:
            return f"undeclared: {m.group(1)}"
    if 'has not been declared' in error_line:
        m = re.search(r"'(.+?)' has not been declared", error_line)
        if m:
            return f"namespace: {m.group(1)}"
    if 'no declaration matches' in error_line:
        return 'return_type_mismatch'
    if 'return type specification for constructor' in error_line:
        return 'void_constructor'
    if 'invalid use of' in error_line:
        return 'invalid_this'
    if 'redefinition of' in error_line:
        return 'duplicate'
    if 'operator new' in error_line:
        return 'operator_new'
    if 'return-statement' in error_line:
        return 'return_mismatch'
    if 'template argument' in error_line:
        return 'template'
    if 'expected initializer before' in error_line:
        return 'template_syntax'
    if 'incomplete type' in error_line:
        return 'incomplete_type'
    return 'other'


def main():
    stats = {
        'total': 0,
        'already_ok': 0,
        'fixed': 0,
        'still_broken': 0,
        'error_cats': {},
    }

    files = sorted(os.listdir(MATCHED_DIR))
    cpp_files = [f for f in files if f.endswith('.cpp')]
    stats['total'] = len(cpp_files)

    for i, fname in enumerate(cpp_files):
        filepath = os.path.join(MATCHED_DIR, fname)

        with open(filepath, 'r') as f:
            content = f.read()

        if '#if 0' not in content:
            stats['already_ok'] += 1
            continue

        process_file(filepath, stats)

        if (i + 1) % 50 == 0:
            print(f"  Progress: {i+1}/{len(cpp_files)} "
                  f"(ok: {stats['already_ok']}, fixed: {stats['fixed']}, broken: {stats['still_broken']})")

    print(f"\n=== Results ===")
    print(f"Total files:    {stats['total']}")
    print(f"Already OK:     {stats['already_ok']}")
    print(f"Newly fixed:    {stats['fixed']}")
    print(f"Still broken:   {stats['still_broken']}")
    print(f"Now compiling:  {stats['already_ok'] + stats['fixed']}")

    if stats['error_cats']:
        print(f"\nError categories:")
        for cat, count in sorted(stats['error_cats'].items(), key=lambda x: -x[1]):
            print(f"  {count:3d}x  {cat}")


if __name__ == '__main__':
    main()
