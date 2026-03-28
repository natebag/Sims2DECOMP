#!/usr/bin/env python3
"""
Fix auto-matched files so they compile. V3 - iterative approach.

For each #if 0'd file:
1. Strip #if 0
2. Apply text fixes (param names, constructors, SDA globals, duplicates)
3. Try compile with -fpermissive -Wno-return-type
4. Parse errors and fix (return types, missing types)
5. If can't fix, wrap individual broken functions in #if 0 (not whole file)
6. Repeat until file compiles
"""

import os
import re
import subprocess
import tempfile

REPO = r"F:\coding\Decompiles\Sims 2"
MATCHED_DIR = os.path.join(REPO, "src", "matched")
CXX = r"F:\coding\Decompiles\Tools\devkitPro\devkitPPC\bin\powerpc-eabi-g++.exe"
CXXFLAGS = [
    "-mcpu=750", "-meabi", "-mhard-float", "-O2",
    "-fno-exceptions", "-fno-rtti", "-fno-builtin",
    "-fshort-wchar", "-nostdinc++",
    "-Wall", "-Wno-unused", "-Wno-return-type",
    "-fpermissive",
    "-Iinclude", "-Isrc", "-Ilibs/dolphinsdk", "-Ilibs/sn_runtime", "-Ilibs/apt",
    "-DNDEBUG", "-DEA_PLATFORM_GAMECUBE=1", "-DGEKKO",
]


def try_compile(content):
    """Try to compile content, return (success, error_output)."""
    tmp = os.path.join(REPO, '_test_compile.cpp')
    with open(tmp, 'w') as f:
        f.write(content)
    cmd = [CXX] + CXXFLAGS + ["-c", tmp, "-o", "NUL"]
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=30, cwd=REPO)
        os.unlink(tmp)
        return result.returncode == 0, result.stderr
    except Exception as e:
        if os.path.exists(tmp):
            os.unlink(tmp)
        return False, str(e)


def strip_if0(content):
    """Remove outermost #if 0 / #endif wrapper."""
    lines = content.split('\n')
    new = []
    found = False
    for line in lines:
        if not found and line.strip() == '#if 0':
            found = True
            continue
        new.append(line)
    if found:
        for i in range(len(new) - 1, -1, -1):
            if new[i].strip() == '#endif':
                new.pop(i)
                break
    return '\n'.join(new)


def ensure_includes(content):
    """Add missing includes."""
    needs = []
    if '#include "types.h"' not in content:
        needs.append('#include "types.h"')
    if '#include "stub_classes.h"' not in content:
        needs.append('#include "stub_classes.h"')
    if needs:
        lines = content.split('\n')
        pos = 0
        for i, line in enumerate(lines):
            if line.strip() and not line.strip().startswith('//'):
                pos = i
                break
        for j, inc in enumerate(needs):
            lines.insert(pos + j, inc)
        content = '\n'.join(lines)
    return content


def split_params(s):
    """Split parameter string by commas respecting nesting."""
    parts = []
    depth = 0
    cur = []
    for c in s:
        if c in ('(', '<'):
            depth += 1
            cur.append(c)
        elif c in (')', '>'):
            depth -= 1
            cur.append(c)
        elif c == ',' and depth == 0:
            parts.append(''.join(cur))
            cur = []
        else:
            cur.append(c)
    if cur:
        parts.append(''.join(cur))
    return parts


def param_is_unnamed(p):
    """Check if a parameter is unnamed (just a type, no identifier)."""
    p = p.strip()
    if not p:
        return False
    # Function pointers are always "unnamed" for our purposes
    if '(*)' in p or ('(*' in p and ')' in p):
        return True
    # Remove template args
    cleaned = re.sub(r'<[^<>]*>', 'T', p)
    cleaned = re.sub(r'<[^<>]*>', 'T', cleaned)  # nested
    # Remove array brackets
    cleaned = re.sub(r'\[[^\]]*\]', '', cleaned)

    tokens = cleaned.split()
    if len(tokens) <= 1:
        return True  # "int" or "float" or "Type*"

    last = tokens[-1]
    # If last token ends with * or &, it's part of type
    if last.endswith('*') or last.endswith('&'):
        return True

    # Known type keywords
    type_kw = {'int','char','short','long','float','double','void',
               'unsigned','signed','bool','const','T','volatile'}
    if last in type_kw:
        return True

    return False


def find_param_section(line):
    """
    Find the parameter list in a function definition line.
    Returns (start_idx, end_idx) of the parentheses content, or None.
    """
    if '{' not in line:
        return None

    brace = line.index('{')
    # Work backward from { to find )
    search = line[:brace].rstrip()
    # Skip const qualifier
    if search.endswith('const'):
        search = search[:-5].rstrip()

    if not search.endswith(')'):
        return None

    end = len(search) - 1
    depth = 1
    i = end - 1
    while i >= 0 and depth > 0:
        if search[i] == ')':
            depth += 1
        elif search[i] == '(':
            depth -= 1
        i -= 1
    if depth != 0:
        return None

    start = i + 1
    return (start + 1, end)  # indices of content between ( and )


def name_params(line):
    """Name all unnamed parameters in a function definition line."""
    if '{' not in line or '::' not in line:
        return line

    brace = line.index('{')
    body = line[brace:]

    result = find_param_section(line)
    if result is None:
        return line

    pstart, pend = result
    params_str = line[pstart:pend]
    params = split_params(params_str)

    # Collect names used in body
    used_names = set()
    for name in ['val', 'fval', 'f1', 'f2', 'f3', 'index', 'first',
                 'p4', 'p5', 'p6', 'p7', 'p8', 'key', 'count']:
        if re.search(r'\b' + name + r'\b', body):
            used_names.add(name)

    if not used_names:
        return line

    new_params = []
    for idx, param in enumerate(params):
        p = param.strip()
        if not p or not param_is_unnamed(p):
            new_params.append(param)
            continue

        # Figure out name for this param
        reg = idx + 4  # r4, r5, r6...
        pname = f'p{reg}'

        assigned = None

        # Check register-named params first
        if pname in used_names:
            assigned = pname
        elif len(params) == 1:
            # Single param: try val, fval, index, first, f1
            for candidate in ['val', 'fval', 'index', 'first', 'f1', 'key', 'count', 'p4']:
                if candidate in used_names:
                    assigned = candidate
                    break
        elif len(params) >= 2:
            if idx == 0:
                for candidate in ['val', 'fval', 'f1', 'index', 'first', 'key']:
                    if candidate in used_names:
                        assigned = candidate
                        break
            elif idx == 1:
                for candidate in ['f2']:
                    if candidate in used_names:
                        assigned = candidate
                        break
            elif idx == 2:
                for candidate in ['f3']:
                    if candidate in used_names:
                        assigned = candidate
                        break

        if assigned:
            # Don't add name to function pointers
            if '(*)' in p or ('(*' in p and ')' in p):
                # For function pointers, we need to insert name: void(*)(int) → void(*name)(int)
                # Actually with -fpermissive we can just cast. Let's use a simpler approach:
                # Replace "void (*)(int)" with "void (*assigned)(int)"
                new_p = p.replace('(*)', f'(*{assigned})', 1)
                new_params.append(new_p)
            else:
                new_params.append(p + ' ' + assigned)
            used_names.discard(assigned)
        else:
            new_params.append(param)

    new_params_str = ', '.join(new_params)
    # Reconstruct line
    new_line = line[:pstart] + new_params_str + line[pend:]
    return new_line


def fix_constructors(content):
    """Remove 'void' from constructor definitions."""
    lines = content.split('\n')
    result = []
    for line in lines:
        m = re.match(r'^void\s+((\w[\w:]*?)::(\w+))\s*\(', line)
        if m:
            parts = m.group(1).split('::')
            if len(parts) >= 2 and parts[-1] == parts[-2]:
                line = line[5:]  # Remove "void "
        result.append(line)
    return '\n'.join(result)


def fix_sda_returns(content):
    """Fix 'return /* SDA global ... */;' patterns."""
    content = re.sub(r'return\s+/\*[^*]*\*/\s*;', 'return 0;', content)
    return content


def fix_duplicate_funcs(content):
    """Remove duplicate function definitions (keep first)."""
    lines = content.split('\n')
    seen = set()
    result = []
    for line in lines:
        s = line.strip()
        if '::' in s and '{' in s and '}' in s and not s.startswith('//') and not s.startswith('#'):
            sig = s[:s.index('{')].strip()
            if sig in seen:
                if result and result[-1].strip().startswith('//'):
                    result.pop()
                if result and not result[-1].strip():
                    result.pop()
                continue
            seen.add(sig)
        result.append(line)
    return '\n'.join(result)


def fix_operator_new(content):
    """Fix operator new returning int."""
    content = re.sub(
        r'\bint\s+([\w:]+::operator\s+new\s*(?:\[\s*\])?\s*\([^)]*\))\s*\{[^}]*\}',
        lambda m: 'void* ' + m.group(1) + ' { return (void*)0; }',
        content
    )
    return content


def fix_comment_bodies(content):
    """Fix functions with comment-only bodies."""
    lines = content.split('\n')
    result = []
    for line in lines:
        s = line.strip()
        if '::' not in s or '{' not in s or '}' not in s or s.startswith('//') or s.startswith('#'):
            result.append(line)
            continue

        brace_start = s.index('{')
        brace_end = s.rindex('}')
        body = s[brace_start+1:brace_end].strip()

        # Check if body is entirely comments
        body_clean = re.sub(r'/\*.*?\*/', '', body).strip()
        body_clean = re.sub(r'//.*', '', body_clean).strip()

        if body_clean:
            result.append(line)
            continue

        # Get return type
        decl = s[:brace_start].strip()
        m = re.match(r'^(.*?)\s+\w[\w:]*::\w+\s*\(', decl)
        if not m:
            result.append(line)
            continue

        ret = m.group(1).strip()
        if ret == 'void' or ret == '' or '::' in ret:
            # void function or constructor - just empty body
            new_line = s[:brace_start+1] + ' }'
            trail = s[brace_end+1:].strip()
            if trail:
                new_line += '  ' + trail
            result.append(new_line)
        else:
            # Non-void: add return
            new_line = s[:brace_start+1] + ' return 0; }'
            trail = s[brace_end+1:].strip()
            if trail:
                new_line += '  ' + trail
            result.append(new_line)

    return '\n'.join(result)


def get_error_line_numbers(errors, tmp_name=None):
    """Parse error messages and return dict of line_number -> error_type."""
    result = {}
    for line in errors.split('\n'):
        m = re.search(r':(\d+):\d+: error: (.+)', line)
        if m:
            lineno = int(m.group(1))
            err = m.group(2)
            if lineno not in result:
                result[lineno] = err
    return result


def get_return_type_fixes(errors):
    """Parse return type mismatch errors. Returns {func_pattern: new_ret_type}."""
    fixes = {}
    lines = errors.split('\n')
    for i, line in enumerate(lines):
        m = re.search(r"no declaration matches '(.+?)\s+(\w[\w:]+::\w+)\s*\(", line)
        if m:
            old_ret = m.group(1)
            func = m.group(2)
            for j in range(i+1, min(i+5, len(lines))):
                cm = re.search(r"candidate is: '(.+?)\s+" + re.escape(func) + r'\s*\(', lines[j])
                if cm:
                    new_ret = cm.group(1)
                    if new_ret != old_ret:
                        fixes[func] = (old_ret, new_ret)
                    break
    return fixes


def apply_return_type_fixes(content, fixes):
    """Apply return type fixes to content."""
    for func, (old_ret, new_ret) in fixes.items():
        # Replace "old_ret func(" with "new_ret func("
        old_pat = old_ret + ' ' + func + '('
        new_pat = new_ret + ' ' + func + '('
        content = content.replace(old_pat, new_pat)
    return content


def wrap_error_lines(content, errors):
    """Wrap individual error lines in #if 0 / #endif."""
    error_lines = get_error_line_numbers(errors)
    if not error_lines:
        return content

    lines = content.split('\n')
    result = []
    for i, line in enumerate(lines):
        lineno = i + 1
        if lineno in error_lines:
            s = line.strip()
            # Only wrap actual function definition lines
            if '::' in s and '{' in s and '}' in s and not s.startswith('#'):
                # Also wrap preceding comment
                if result and result[-1].strip().startswith('// 0x'):
                    comment = result.pop()
                    if result and not result[-1].strip():
                        blank = result.pop()
                    result.append('#if 0')
                    if 'blank' in dir():
                        result.append(blank)
                    result.append(comment)
                else:
                    result.append('#if 0')
                result.append(line)
                result.append('#endif')
                continue
        result.append(line)

    return '\n'.join(result)


def has_any_active_code(content):
    """Check if content has any actual function definitions not inside #if 0."""
    in_if0 = 0
    for line in content.split('\n'):
        s = line.strip()
        if s == '#if 0':
            in_if0 += 1
        elif s == '#endif' and in_if0 > 0:
            in_if0 -= 1
        elif in_if0 == 0 and '::' in s and '{' in s and '}' in s and not s.startswith('//'):
            return True
    return False


def count_active_functions(content):
    """Count function definitions not inside #if 0."""
    count = 0
    in_if0 = 0
    for line in content.split('\n'):
        s = line.strip()
        if s == '#if 0':
            in_if0 += 1
        elif s == '#endif' and in_if0 > 0:
            in_if0 -= 1
        elif in_if0 == 0 and '::' in s and '{' in s and '}' in s \
                and not s.startswith('//') and not s.startswith('#'):
            count += 1
    return count


def process_file(filepath, stats):
    """Process a single file. Returns number of active functions."""
    with open(filepath, 'r') as f:
        original = f.read()

    if '#if 0' not in original:
        n = count_active_functions(original)
        stats['already_ok_funcs'] += n
        return n

    content = strip_if0(original)

    # Apply text fixes
    content = ensure_includes(content)
    content = fix_constructors(content)
    content = fix_operator_new(content)
    content = fix_sda_returns(content)
    content = fix_duplicate_funcs(content)

    # Name parameters
    lines = content.split('\n')
    named = []
    for line in lines:
        s = line.strip()
        if s.startswith('//') or s.startswith('#') or not s:
            named.append(line)
        else:
            named.append(name_params(line))
    content = '\n'.join(named)

    content = fix_comment_bodies(content)

    # Iterative compile-fix loop
    max_iters = 5
    for iteration in range(max_iters):
        ok, errors = try_compile(content)
        if ok:
            break

        # Try return type fixes
        rt_fixes = get_return_type_fixes(errors)
        if rt_fixes:
            content = apply_return_type_fixes(content, rt_fixes)
            ok2, errors2 = try_compile(content)
            if ok2:
                ok = True
                break
            errors = errors2

        # Try wrapping individual error lines
        old_content = content
        content = wrap_error_lines(content, errors)
        if content == old_content:
            # No progress possible - wrap all remaining active code
            break

    if not ok:
        # Final attempt after wrapping
        ok, errors = try_compile(content)

    if not ok:
        # Still failing - just re-wrap in #if 0
        # But check if SOME functions compile
        # Wrap entire content in #if 0
        content = '#if 0\n' + strip_if0(original).strip() + '\n#endif\n'
        stats['still_broken'] += 1
        # Categorize
        for line in errors.split('\n'):
            if 'error:' in line:
                cat = categorize_error(line)
                stats['cats'][cat] = stats['cats'].get(cat, 0) + 1
                break
        with open(filepath, 'w') as f:
            f.write(content)
        return 0

    # File compiles - check how many active functions
    n = count_active_functions(content)
    if n > 0:
        stats['fixed_files'] += 1
        stats['fixed_funcs'] += n
        with open(filepath, 'w') as f:
            f.write(content)
    else:
        # All functions got wrapped - no point
        content = '#if 0\n' + strip_if0(original).strip() + '\n#endif\n'
        stats['still_broken'] += 1
        with open(filepath, 'w') as f:
            f.write(content)

    return n


def categorize_error(line):
    if 'was not declared in this scope' in line:
        m = re.search(r"'(\w+)' was not declared", line)
        return f"undeclared_{m.group(1)}" if m else "undeclared"
    if 'has not been declared' in line:
        m = re.search(r"'(.+?)' has not been declared", line)
        return f"ns_{m.group(1)}" if m else "namespace"
    if 'no declaration matches' in line:
        return 'ret_type'
    if 'constructor' in line:
        return 'constructor'
    if 'invalid use of' in line:
        return 'invalid_this'
    if 'redefinition' in line:
        return 'duplicate'
    if 'operator new' in line:
        return 'op_new'
    if 'template' in line:
        return 'template'
    if 'incomplete type' in line:
        return 'incomplete'
    return 'other'


def main():
    stats = {
        'total_files': 0,
        'already_ok_files': 0,
        'already_ok_funcs': 0,
        'fixed_files': 0,
        'fixed_funcs': 0,
        'still_broken': 0,
        'cats': {},
    }

    files = sorted(f for f in os.listdir(MATCHED_DIR) if f.endswith('.cpp'))
    stats['total_files'] = len(files)

    for i, fname in enumerate(files):
        fp = os.path.join(MATCHED_DIR, fname)
        with open(fp, 'r') as f:
            content = f.read()

        if '#if 0' not in content:
            stats['already_ok_files'] += 1
            n = count_active_functions(content)
            stats['already_ok_funcs'] += n
        else:
            process_file(fp, stats)

        if (i + 1) % 50 == 0:
            total_funcs = stats['already_ok_funcs'] + stats['fixed_funcs']
            print(f"  [{i+1}/{len(files)}] ok_files={stats['already_ok_files']} "
                  f"fixed={stats['fixed_files']} broken={stats['still_broken']} "
                  f"total_funcs={total_funcs}")

    total_ok = stats['already_ok_files'] + stats['fixed_files']
    total_funcs = stats['already_ok_funcs'] + stats['fixed_funcs']

    print(f"\n=== RESULTS ===")
    print(f"Total .cpp files:        {stats['total_files']}")
    print(f"Already compiling:       {stats['already_ok_files']} files ({stats['already_ok_funcs']} funcs)")
    print(f"Newly fixed:             {stats['fixed_files']} files ({stats['fixed_funcs']} funcs)")
    print(f"Still broken:            {stats['still_broken']} files")
    print(f"Total compiling:         {total_ok} files ({total_funcs} funcs)")

    if stats['cats']:
        print(f"\nRemaining error categories:")
        for cat, count in sorted(stats['cats'].items(), key=lambda x: -x[1]):
            print(f"  {count:3d}x  {cat}")


if __name__ == '__main__':
    main()
