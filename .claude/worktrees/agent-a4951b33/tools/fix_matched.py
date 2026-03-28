#!/usr/bin/env python3
"""
Fix auto-matched files so they compile.

Common issues:
1. val/fval/p4/p5/index not declared (unnamed params)
2. Return type mismatches (int vs bool, int vs void*, etc.)
3. Duplicate function definitions
4. Constructor with void return type
5. Namespace issues (EA::, WantFear::, InteractorModule::)
6. SDA global patterns that don't compile
7. Comment-only bodies in non-void functions
8. operator new returning int instead of void*
"""

import os
import re
import sys
import subprocess
import tempfile
import shutil

REPO = r"F:\coding\Decompiles\Sims 2"
MATCHED_DIR = os.path.join(REPO, "src", "matched")
CXX = r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC\bin\powerpc-eabi-g++.exe"
CXXFLAGS = [
    "-mcpu=750", "-meabi", "-mhard-float", "-O2",
    "-fno-exceptions", "-fno-rtti", "-fno-builtin",
    "-fshort-wchar", "-nostdinc++", "-Wall", "-Wno-unused",
    "-Iinclude", "-Isrc", "-Ilibs/dolphinsdk", "-Ilibs/sn_runtime", "-Ilibs/apt",
    "-DNDEBUG", "-DEA_PLATFORM_GAMECUBE=1", "-DGEKKO",
]


def try_compile(filepath):
    """Try to compile a file, return (success, error_output)."""
    cmd = [CXX] + CXXFLAGS + ["-c", filepath, "-o", os.devnull]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=30, cwd=REPO)
        return result.returncode == 0, result.stderr
    except Exception as e:
        return False, str(e)


def strip_if0(content):
    """Remove #if 0 / #endif wrapper."""
    lines = content.split('\n')
    # Remove leading #if 0
    new_lines = []
    found_if0 = False
    for i, line in enumerate(lines):
        if not found_if0 and line.strip() == '#if 0':
            found_if0 = True
            continue
        new_lines.append(line)
    # Remove trailing #endif
    if found_if0:
        for i in range(len(new_lines) - 1, -1, -1):
            if new_lines[i].strip() == '#endif':
                new_lines.pop(i)
                break
    return '\n'.join(new_lines)


def fix_unnamed_params(content):
    """
    Fix unnamed parameters that reference val/fval/p4/p5/p6/p7/index in the body.

    Pattern: void Foo::Bar(Type) { ... = val; }
    Fix:     void Foo::Bar(Type val) { ... = val; }
    """
    lines = content.split('\n')
    fixed_lines = []

    for line in lines:
        # Skip comments and preprocessor
        stripped = line.strip()
        if stripped.startswith('//') or stripped.startswith('#') or not stripped:
            fixed_lines.append(line)
            continue

        # Check if this line has a function definition with a body
        # Match: returntype Class::Method(params) [const] { body }
        if '{' not in line or '::' not in line:
            fixed_lines.append(line)
            continue

        # Extract the part before { and the body
        brace_pos = line.index('{')
        decl_part = line[:brace_pos]
        body_part = line[brace_pos:]

        # Check what variables the body uses
        body_uses_val = bool(re.search(r'\bval\b', body_part))
        body_uses_fval = bool(re.search(r'\bfval\b', body_part))
        body_uses_index = bool(re.search(r'\bindex\b', body_part))
        body_uses_p4 = bool(re.search(r'\bp4\b', body_part))
        body_uses_p5 = bool(re.search(r'\bp5\b', body_part))
        body_uses_p6 = bool(re.search(r'\bp6\b', body_part))
        body_uses_p7 = bool(re.search(r'\bp7\b', body_part))

        if not any([body_uses_val, body_uses_fval, body_uses_index,
                     body_uses_p4, body_uses_p5, body_uses_p6, body_uses_p7]):
            fixed_lines.append(line)
            continue

        # Find the parameter list
        # Find the matching parens for the parameter list
        paren_start = None
        paren_end = None
        depth = 0
        # Search backward from brace_pos for the closing )
        for i in range(brace_pos - 1, -1, -1):
            c = decl_part[i]
            if c == ')':
                if paren_end is None:
                    # Skip past optional const/qualifiers
                    rest = decl_part[i+1:brace_pos].strip()
                    if rest in ('', 'const', 'const '):
                        paren_end = i
                        depth = 1
                    else:
                        break
                else:
                    depth += 1
            elif c == '(':
                depth -= 1
                if depth == 0:
                    paren_start = i
                    break

        if paren_start is None or paren_end is None:
            fixed_lines.append(line)
            continue

        params_str = decl_part[paren_start+1:paren_end]

        # Parse parameters - split by comma respecting nested parens/templates
        params = split_params(params_str)

        # Now name the unnamed parameters
        new_params = []
        param_index = 0  # 0-based, but p4 means register r4 (2nd param after this)

        for param in params:
            param = param.strip()
            param_index += 1

            if not param:
                new_params.append(param)
                continue

            # Check if param already has a name (has a word after the type)
            # A named param looks like "int foo" or "Type* bar"
            # An unnamed param looks like "int" or "Type*" or "float"
            has_name = param_has_name(param)

            if has_name:
                new_params.append(param)
                continue

            # This parameter is unnamed - figure out what name to give it
            # For single-param functions, if body uses 'val' or 'fval'
            if len(params) == 1:
                if body_uses_val:
                    new_params.append(param + ' val')
                elif body_uses_fval:
                    new_params.append(param + ' fval')
                elif body_uses_index:
                    new_params.append(param + ' index')
                elif body_uses_p4:
                    new_params.append(param + ' p4')
                else:
                    new_params.append(param)
            else:
                # Multi-param: figure out by register index
                # r3 = this, r4 = param1, r5 = param2, etc.
                reg_num = param_index + 3  # param 1 → r4, param 2 → r5, etc.
                pname = f'p{reg_num}'

                # Check which names the body actually uses
                needed = False
                if pname == 'p4' and body_uses_p4:
                    needed = True
                elif pname == 'p5' and body_uses_p5:
                    needed = True
                elif pname == 'p6' and body_uses_p6:
                    needed = True
                elif pname == 'p7' and body_uses_p7:
                    needed = True

                if needed:
                    new_params.append(param + ' ' + pname)
                elif body_uses_val and param_index == 1:
                    new_params.append(param + ' val')
                elif body_uses_fval and param_index == 1:
                    new_params.append(param + ' fval')
                elif body_uses_index and param_index == 1:
                    new_params.append(param + ' index')
                else:
                    new_params.append(param)

        new_params_str = ', '.join(new_params)
        new_decl = decl_part[:paren_start+1] + new_params_str + decl_part[paren_end:]
        fixed_lines.append(new_decl + body_part)

    return '\n'.join(fixed_lines)


def split_params(params_str):
    """Split parameter string by commas, respecting nested parens and templates."""
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

    # Handle function pointer params like "void (*)(int)" - these are unnamed types
    if '(*)' in param or '(*' in param:
        # Function pointer - check if there's a name after the closing paren
        # e.g., "void (*foo)(int)" has name, "void (*)(int)" doesn't
        return False  # Simplified - treat all fn ptrs as unnamed for our purposes

    # Remove trailing const, *, & from the end to isolate potential name
    # "int" -> unnamed, "int val" -> named, "int*" -> unnamed, "int* val" -> named
    # Strategy: split by spaces, if last token is purely alphanumeric (not a type keyword)
    # and doesn't end with *, &, then it's a name

    # Remove everything in angle brackets (template params)
    cleaned = re.sub(r'<[^>]*>', '', param)
    # Remove everything in parens (function ptrs)
    cleaned = re.sub(r'\([^)]*\)', '', cleaned)

    tokens = cleaned.split()
    if len(tokens) <= 1:
        return False

    last = tokens[-1].rstrip('*&')
    if not last:
        return False

    # If the last token (stripped of * and &) is a known type keyword, it's unnamed
    type_keywords = {
        'int', 'char', 'short', 'long', 'float', 'double', 'void',
        'unsigned', 'signed', 'bool', 'const',
    }
    if last.lower() in type_keywords:
        return False

    # If last token ends with * or & (after the full token), it's a type not a name
    if tokens[-1].endswith('*') or tokens[-1].endswith('&'):
        return False

    # Otherwise it's likely a name
    return True


def fix_constructor_void_return(content):
    """
    Fix 'void ClassName::ClassName(...)' → 'ClassName::ClassName(...)'
    Constructors cannot have a return type.
    """
    lines = content.split('\n')
    fixed = []
    for line in lines:
        # Match: void ClassName::ClassName(
        m = re.match(r'^void\s+(\w[\w:]*?)::(\w+)\s*\(', line)
        if m:
            # Extract the class part and method name
            full_class = m.group(1)
            method = m.group(2)
            # Get just the last class name (for nested like EA::Allocator::GeneralAllocator)
            class_name = full_class.split('::')[-1]
            if method == class_name:
                # This is a constructor - remove 'void '
                line = line.replace('void ' + full_class + '::' + method,
                                   full_class + '::' + method, 1)
        fixed.append(line)
    return '\n'.join(fixed)


def fix_duplicate_functions(content):
    """
    Remove duplicate function definitions (same signature, different addresses).
    Keep the first occurrence.
    """
    lines = content.split('\n')
    seen_sigs = set()
    result = []
    skip_next_comment = False

    i = 0
    while i < len(lines):
        line = lines[i]
        stripped = line.strip()

        # Check if this is a function definition line (has ::, {, and })
        if '::' in stripped and '{' in stripped and '}' in stripped and not stripped.startswith('//') and not stripped.startswith('#'):
            # Extract signature (everything up to the {)
            brace_pos = stripped.index('{')
            sig = stripped[:brace_pos].strip()

            if sig in seen_sigs:
                # Skip this line and its preceding comment if any
                # Check if previous line in result is a comment for this function
                if result and result[-1].strip().startswith('//'):
                    result.pop()
                # Also skip any blank line before the comment
                if result and result[-1].strip() == '':
                    result.pop()
                i += 1
                continue
            seen_sigs.add(sig)

        result.append(line)
        i += 1

    return '\n'.join(result)


def fix_sda_global_return(content):
    """
    Fix patterns like:
      return /* SDA global @ r13-XXXXX */;
    These don't compile because the comment replaces the return value.
    Replace with: return 0;  (for int) or appropriate default.
    """
    # Pattern: return /* ... */;
    content = re.sub(
        r'return\s+/\*[^*]*\*/\s*;',
        'return 0;',
        content
    )
    return content


def fix_comment_only_body(content):
    """
    Fix functions with comment-only bodies that need a return value.
    Pattern: int Foo::Bar() { /* ... */ }
    Fix:     int Foo::Bar() { /* ... */ return 0; }
    """
    lines = content.split('\n')
    fixed = []

    for line in lines:
        stripped = line.strip()
        if stripped.startswith('//') or stripped.startswith('#') or not stripped:
            fixed.append(line)
            continue

        # Match function definition with body
        if '::' not in stripped or '{' not in stripped or '}' not in stripped:
            fixed.append(line)
            continue

        brace_start = stripped.index('{')
        brace_end = stripped.rindex('}')
        body = stripped[brace_start+1:brace_end].strip()

        # Check if body is comment-only (or has comments + assignments but no return)
        # Extract the return type
        decl = stripped[:brace_start].strip()

        # Get return type - first word(s) before Class::Method
        # Find the :: to identify where class::method starts
        m = re.match(r'^(.*?)\s+([\w:]+::\w+)\s*\(', decl)
        if not m:
            fixed.append(line)
            continue

        ret_type = m.group(1).strip()

        # If return type is void, no fix needed
        if ret_type == 'void' or ret_type == '':
            fixed.append(line)
            continue

        # Check if body has a return statement
        if 'return' in body:
            fixed.append(line)
            continue

        # Body has no return but function is non-void
        # Check if body is only comments
        body_no_comments = re.sub(r'/\*[^*]*\*/', '', body).strip()
        if body_no_comments == '':
            # Body is entirely comments - add return 0
            if 'float' in ret_type or 'double' in ret_type:
                new_body = body + ' return 0.0f;'
            elif 'bool' in ret_type:
                new_body = body + ' return false;'
            elif '*' in ret_type:
                new_body = body + ' return 0;'
            else:
                new_body = body + ' return 0;'
            new_line = stripped[:brace_start+1] + ' ' + new_body + ' }'
            # Preserve any trailing comment
            after_brace = stripped[brace_end+1:].strip()
            if after_brace:
                new_line += '  ' + after_brace
            fixed.append(new_line)
        else:
            fixed.append(line)
            continue

    return '\n'.join(fixed)


def fix_sda_global_store(content):
    """
    Fix patterns like:
      void Foo::SetBar(int) { /* SDA global @ r13-XXXXX = val */ }
    or:
      void Foo::SetBar(int) { /* SDA global @ r13-XXXXX = param */ }
    These are stores to SDA globals - replace body with empty or with the actual store.
    Since we can't know the global address, just empty the body.
    """
    lines = content.split('\n')
    fixed = []

    for line in lines:
        stripped = line.strip()
        if '::' in stripped and '{' in stripped and '}' in stripped:
            brace_start = stripped.index('{')
            brace_end = stripped.rindex('}')
            body = stripped[brace_start+1:brace_end].strip()

            # Check if body is only an SDA store comment
            if re.match(r'^/\*\s*SDA[^*]*\*/$', body):
                # Get return type
                decl = stripped[:brace_start].strip()
                m = re.match(r'^(.*?)\s+[\w:]+::\w+\s*\(', decl)
                if m:
                    ret_type = m.group(1).strip()
                    if ret_type == 'void':
                        # Just empty the body
                        new_line = stripped[:brace_start+1] + ' }'
                        after_brace = stripped[brace_end+1:].strip()
                        if after_brace:
                            new_line += '  ' + after_brace
                        fixed.append(new_line)
                        continue

        fixed.append(line)

    return '\n'.join(fixed)


def fix_return_type_from_errors(content, errors):
    """
    Parse compiler errors about return type mismatches and fix them.

    Error pattern:
      error: no declaration matches 'TYPE CLASS::METHOD(PARAMS)'
      note: candidate is: 'CORRECT_TYPE CLASS::METHOD(PARAMS)'
    """
    lines = content.split('\n')

    # Parse all type mismatches from errors
    fixes = {}  # (line_num) -> (old_ret_type, new_ret_type)

    error_lines = errors.split('\n')
    for i, eline in enumerate(error_lines):
        m = re.search(r"error: no declaration matches '(\S+)\s+(\S+::\S+)\((.*?)\)'", eline)
        if not m:
            m = re.search(r"error: no declaration matches '(\S+)\s+(\S+::\S+)\((.*?)\)(\s+const)?'", eline)
        if m:
            old_ret = m.group(1)
            func_name = m.group(2)
            # Look for the candidate line
            for j in range(i+1, min(i+5, len(error_lines))):
                cm = re.search(r"note: candidate is: '(\S+)\s+", error_lines[j])
                if not cm:
                    # Try multi-word return type like "const char*"
                    cm = re.search(r"note: candidate is: '(.+?)\s+\w+::\w+\(", error_lines[j])
                if cm:
                    new_ret = cm.group(1)
                    if new_ret != old_ret:
                        fixes[func_name] = (old_ret, new_ret)
                    break

    if not fixes:
        return content

    # Apply fixes to the content
    for func_name, (old_ret, new_ret) in fixes.items():
        # Find and replace the return type for this specific function
        # func_name is like "AptCIH::getHasClass"
        # We need to find the line with "old_ret func_name("
        escaped_func = re.escape(func_name)
        pattern = re.compile(r'^(' + re.escape(old_ret) + r')\s+(' + escaped_func + r'\s*\()')
        new_lines = []
        for line in lines:
            stripped = line.strip()
            m = pattern.match(stripped)
            if m:
                line = stripped.replace(old_ret + ' ' + m.group(2).rstrip('('),
                                       new_ret + ' ' + m.group(2).rstrip('('), 1)
                # If changing to void*, need to fix return value too
                if new_ret in ('void*', 'void *') and old_ret in ('int', 'bool'):
                    # Change "return 0;" to "return (void*)0;" etc.
                    line = re.sub(r'return\s+0\s*;', 'return (void*)0;', line)
                    line = re.sub(r'return\s+false\s*;', 'return (void*)0;', line)
                    line = re.sub(r'return\s+true\s*;', 'return (void*)1;', line)
                elif new_ret == 'void' and old_ret in ('int', 'bool'):
                    # Remove return value
                    line = re.sub(r'return\s+\d+\s*;', '', line)
                    line = re.sub(r'return\s+(true|false)\s*;', '', line)
            new_lines.append(line)
        lines = new_lines

    return '\n'.join(lines)


def fix_operator_new_return(content):
    """
    Fix 'int ClassName::operator new [](unsigned int) { return 0; }'
    to  'void* ClassName::operator new [](unsigned int) { return (void*)0; }'
    """
    content = re.sub(
        r'\bint\s+([\w:]+::operator\s+new\s*\[\]\s*\([^)]*\))\s*\{[^}]*\}',
        lambda m: 'void* ' + m.group(1) + ' { return (void*)0; }',
        content
    )
    content = re.sub(
        r'\bint\s+([\w:]+::operator\s+new\s*\([^)]*\))\s*\{[^}]*\}',
        lambda m: 'void* ' + m.group(1) + ' { return (void*)0; }',
        content
    )
    return content


def fix_return_statement_mismatch(content):
    """Fix return-statement with no value in non-void function."""
    # This pattern: "return;" in a function returning non-void
    # We can't easily detect this without parsing, so we handle it via compile errors
    pass
    return content


def ensure_includes(content):
    """Ensure the file has the needed #include directives."""
    has_types = '#include "types.h"' in content
    has_stub = '#include "stub_classes.h"' in content

    lines = content.split('\n')

    # Find first non-comment, non-blank line
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


def wrap_in_if0(content):
    """Re-wrap content in #if 0 / #endif."""
    return '#if 0\n' + content + '\n#endif\n'


def process_file(filepath, stats):
    """Process a single auto-matched file. Returns True if now compiling."""
    with open(filepath, 'r') as f:
        original = f.read()

    # Check if already compiling (no #if 0)
    if '#if 0' not in original:
        return True  # Already compiling

    content = strip_if0(original)

    # Apply all fixes
    content = ensure_includes(content)
    content = fix_constructor_void_return(content)
    content = fix_operator_new_return(content)
    content = fix_sda_global_return(content)
    content = fix_sda_global_store(content)
    content = fix_unnamed_params(content)
    content = fix_duplicate_functions(content)
    content = fix_comment_only_body(content)

    # Write to temp file and try to compile
    tmp = tempfile.NamedTemporaryFile(suffix='.cpp', delete=False, mode='w')
    tmp.write(content)
    tmp.close()

    success, errors = try_compile(tmp.name)

    if not success:
        # Try to fix return type mismatches from error messages
        content2 = fix_return_type_from_errors(content, errors)
        if content2 != content:
            content = content2
            with open(tmp.name, 'w') as f:
                f.write(content)
            success, errors = try_compile(tmp.name)

    if not success:
        # Second pass: try to fix more issues
        # Parse errors for specific patterns
        content = fix_from_errors_pass2(content, errors)
        with open(tmp.name, 'w') as f:
            f.write(content)
        success, errors = try_compile(tmp.name)

    os.unlink(tmp.name)

    if success:
        # Write the fixed content (without #if 0)
        with open(filepath, 'w') as f:
            f.write(content)
        stats['fixed'] += 1
        return True
    else:
        # Keep the #if 0 wrapper
        stats['still_broken'] += 1
        # Print first error for debugging
        first_error = ''
        for line in errors.split('\n'):
            if 'error:' in line:
                first_error = line.strip()
                break
        stats['error_types'][first_error[:120] if first_error else 'unknown'] = \
            stats['error_types'].get(first_error[:120] if first_error else 'unknown', 0) + 1
        return False


def fix_from_errors_pass2(content, errors):
    """Second pass: fix issues based on compiler error messages."""
    error_lines = errors.split('\n')

    for i, eline in enumerate(error_lines):
        # Fix "return type specification for constructor invalid"
        # This means we still have void on a constructor somewhere
        if 'return type specification for constructor invalid' in eline:
            content = fix_constructor_void_return(content)

        # Fix "'p4' was not declared" etc.
        m = re.search(r"'(p[4-9]|val|fval|index)' was not declared", eline)
        if m:
            content = fix_unnamed_params(content)

        # Fix "has not been declared" for namespaces like EA::, WantFear::
        m = re.search(r"'(\w+)' has not been declared", eline)
        if m:
            ns = m.group(1)
            # Add namespace declaration at top
            if f'namespace {ns}' not in content:
                # Insert after includes
                lines = content.split('\n')
                insert_pos = 0
                for j, line in enumerate(lines):
                    if line.strip().startswith('#include'):
                        insert_pos = j + 1
                lines.insert(insert_pos, f'namespace {ns} {{ }}')
                content = '\n'.join(lines)
                # Actually we need to be smarter - wrap the functions in the namespace
                # For now, just skip these files

        # Fix "redefinition of" - duplicate functions
        if 'redefinition of' in eline:
            content = fix_duplicate_functions(content)

        # Fix "return-statement with no value" - add return 0
        if 'return-statement with no value' in eline:
            # Find the function and add a return value
            m2 = re.search(r"In member function '(\S+)\s+", eline)
            if m2:
                ret_type = m2.group(1)
                # Replace bare "return;" with "return 0;"
                if ret_type in ('int', 'short', 'long'):
                    content = content.replace('return;', 'return 0;')
                elif ret_type == 'bool':
                    content = content.replace('return;', 'return false;')
                elif '*' in ret_type:
                    content = content.replace('return;', 'return 0;')

    return content


def main():
    stats = {
        'total': 0,
        'already_ok': 0,
        'fixed': 0,
        'still_broken': 0,
        'error_types': {},
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

        ok = process_file(filepath, stats)

        if (i + 1) % 50 == 0:
            print(f"  Progress: {i+1}/{len(cpp_files)} "
                  f"(fixed: {stats['fixed']}, broken: {stats['still_broken']})")

    print(f"\n=== Results ===")
    print(f"Total files:    {stats['total']}")
    print(f"Already OK:     {stats['already_ok']}")
    print(f"Newly fixed:    {stats['fixed']}")
    print(f"Still broken:   {stats['still_broken']}")
    print(f"Now compiling:  {stats['already_ok'] + stats['fixed']}")

    if stats['error_types']:
        print(f"\nTop error types ({len(stats['error_types'])} unique):")
        sorted_errors = sorted(stats['error_types'].items(), key=lambda x: -x[1])
        for err, count in sorted_errors[:20]:
            print(f"  {count:3d}x  {err}")


if __name__ == '__main__':
    main()
