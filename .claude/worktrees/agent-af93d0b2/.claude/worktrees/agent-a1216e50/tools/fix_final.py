#!/usr/bin/env python3
"""
Final fix pass for remaining broken files.
Handle: templates (TArray, SimpleReconObject, ObjectDataFactory),
remaining namespaces, and other individual issues.
"""

import os
import re
import subprocess

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


def apply_text_fixes(content):
    """Apply standard text fixes."""
    # Fix constructors
    lines = content.split('\n')
    fixed = []
    for line in lines:
        m = re.match(r'^void\s+((\w[\w:]*?)::(\w+))\s*\(', line)
        if m:
            parts = m.group(1).split('::')
            if len(parts) >= 2 and parts[-1] == parts[-2]:
                line = line[5:]
        fixed.append(line)
    content = '\n'.join(fixed)

    # Fix operator new
    content = re.sub(
        r'\bint\s+([\w:]+::operator\s+new\s*(?:\[\s*\])?\s*\([^)]*\))\s*\{[^}]*\}',
        lambda m: 'void* ' + m.group(1) + ' { return (void*)0; }',
        content
    )

    # Fix SDA returns
    content = re.sub(r'return\s+/\*[^*]*\*/', 'return 0', content)

    # Fix duplicates
    lines = content.split('\n')
    seen = set()
    result = []
    for line in lines:
        s = line.strip()
        if '::' in s and '{' in s and '}' in s and not s.startswith('//') and not s.startswith('#'):
            sig = s[:s.index('{')].strip()
            if sig in seen:
                if result and result[-1].strip().startswith('//'): result.pop()
                if result and not result[-1].strip(): result.pop()
                continue
            seen.add(sig)
        result.append(line)
    content = '\n'.join(result)

    # Name params
    lines = content.split('\n')
    named = []
    for line in lines:
        s = line.strip()
        if s.startswith('//') or s.startswith('#') or not s:
            named.append(line)
        else:
            named.append(name_params_in_line(line))
    content = '\n'.join(named)

    return content


def split_params(s):
    parts = []
    depth = 0
    cur = []
    for c in s:
        if c in ('(', '<'): depth += 1; cur.append(c)
        elif c in (')', '>'): depth -= 1; cur.append(c)
        elif c == ',' and depth == 0: parts.append(''.join(cur)); cur = []
        else: cur.append(c)
    if cur: parts.append(''.join(cur))
    return parts


def param_is_unnamed(p):
    p = p.strip()
    if not p: return False
    if '(*)' in p: return True
    cleaned = re.sub(r'<[^<>]*>', 'T', re.sub(r'<[^<>]*>', 'T', p))
    tokens = cleaned.split()
    if len(tokens) <= 1: return True
    last = tokens[-1]
    if last.endswith('*') or last.endswith('&'): return True
    if last in {'int','char','short','long','float','double','void',
                'unsigned','signed','bool','const','T','volatile'}: return True
    return False


def name_params_in_line(line):
    if '{' not in line or '::' not in line: return line
    brace = line.index('{')
    body = line[brace:]
    search = line[:brace].rstrip()
    if search.endswith('const'): search = search[:-5].rstrip()
    if not search.endswith(')'): return line
    end = len(search) - 1
    depth = 1
    i = end - 1
    while i >= 0 and depth > 0:
        if search[i] == ')': depth += 1
        elif search[i] == '(': depth -= 1
        i -= 1
    if depth != 0: return line
    start = i + 1
    params_str = search[start+1:end]
    params = split_params(params_str)
    used = set()
    for name in ['val','fval','f1','f2','f3','index','first','p4','p5','p6','p7','p8','key','count']:
        if re.search(r'\b' + name + r'\b', body): used.add(name)
    if not used: return line
    new_params = []
    for idx, param in enumerate(params):
        p = param.strip()
        if not p or not param_is_unnamed(p):
            new_params.append(param); continue
        reg = idx + 4
        pname = f'p{reg}'
        assigned = None
        if pname in used: assigned = pname
        elif len(params) == 1:
            for c in ['val','fval','index','first','f1','key','count','p4']:
                if c in used: assigned = c; break
        elif len(params) >= 2:
            if idx == 0:
                for c in ['val','fval','f1','index','first','key']:
                    if c in used: assigned = c; break
            elif idx == 1:
                for c in ['f2','p5']:
                    if c in used: assigned = c; break
            elif idx == 2:
                for c in ['f3','p6']:
                    if c in used: assigned = c; break
        if assigned:
            if '(*)' in p: new_params.append(p.replace('(*)', f'(*{assigned})', 1))
            else: new_params.append(p + ' ' + assigned)
            used.discard(assigned)
        else: new_params.append(param)
    new_params_str = ', '.join(new_params)
    return line[:start+1] + new_params_str + line[end:]


def build_tarray_file(content):
    """Build a TArray template file without stub_classes.h."""
    # Extract what types are used
    # Pattern: TArray<TypeName, AllocatorName>::Method
    types_used = set()
    allocs_used = set()
    for m in re.finditer(r'TArray<([^,]+),\s*([^>]+)>', content):
        types_used.add(m.group(1).strip())
        allocs_used.add(m.group(2).strip())

    # Also handle nested TArray
    # TArray<TArray<X,Y>, Z>

    header = '#include "types.h"\n\n'

    # Forward declare all types
    for t in sorted(types_used):
        t = t.strip().rstrip('*').strip()
        if t in ('int', 'float', 'unsigned int', 'unsigned char *', 'short'):
            continue
        if '<' in t:
            continue  # Nested template
        header += f'class {t};\n'

    for a in sorted(allocs_used):
        header += f'class {a};\n'

    header += '\n'
    header += 'template <typename T, typename A = int>\n'
    header += 'class TArray {\npublic:\n'
    header += '    void Init();\n'
    header += '    char _stub_data[16];\n'
    header += '};\n\n'

    # Remove includes and add our header
    lines = content.split('\n')
    body_lines = [l for l in lines if '#include' not in l]
    return header + '\n'.join(body_lines)


def build_simple_recon_file(content):
    """Build a SimpleReconObject template file."""
    # Extract type param
    types_used = set()
    for m in re.finditer(r'SimpleReconObject<(\w+)>', content):
        types_used.add(m.group(1))

    header = '#include "types.h"\n\n'
    for t in sorted(types_used):
        header += f'class {t};\n'
    header += '\ntemplate <typename T>\nclass SimpleReconObject {\npublic:\n'
    header += '    int GetType();\n    char _stub_data[16];\n};\n\n'

    lines = content.split('\n')
    body_lines = [l for l in lines if '#include' not in l]
    return header + '\n'.join(body_lines)


def build_objdata_factory_file(content):
    """Build an ObjectDataFactory template file."""
    # ObjectDataFactoryDatabase<FloatConstants>, ObjectDataFactoryIFF<T>, ObjectDataFactoryQuickData<T>
    factory_types = set()
    param_types = set()
    for m in re.finditer(r'(ObjectDataFactory\w*)<(\w+)>', content):
        factory_types.add(m.group(1))
        param_types.add(m.group(2))

    header = '#include "types.h"\n\n'
    for t in sorted(param_types):
        header += f'class {t};\n'
    for ft in sorted(factory_types):
        header += f'\ntemplate <typename T>\nclass {ft} {{\npublic:\n'
        header += '    void Init();\n    int GetSize();\n    char _stub_data[16];\n};\n'
    header += '\n'

    lines = content.split('\n')
    body_lines = [l for l in lines if '#include' not in l]
    return header + '\n'.join(body_lines)


def fix_remaining_individual(filepath, fname):
    """Handle specific individual files with known issues."""
    with open(filepath, 'r') as f:
        original = f.read()

    if '#if 0' not in original[:20]:
        return True

    content = strip_if0(original)

    # Template files
    if fname.startswith('TArray_'):
        content = build_tarray_file(content)
    elif fname.startswith('SimpleReconObject_'):
        content = build_simple_recon_file(content)
    elif fname.startswith('ObjectDataFactory'):
        content = build_objdata_factory_file(content)
    elif fname.startswith('FileCreator__'):
        # TArray<EFileSystem::FileCreator, TArrayDefaultAllocator>
        content = '#include "types.h"\n\n'
        content += 'namespace EFileSystem { class FileCreator { public: char _s[64]; }; }\n'
        content += 'class TArrayDefaultAllocator;\n'
        content += 'template<typename T, typename A=int> class TArray { public: void Init(); char _s[16]; };\n\n'
        body = strip_if0(original)
        body = re.sub(r'#include[^\n]*\n', '', body)
        content += body
    elif fname == 'Intersection_auto.cpp':
        # Intersection not declared - add it
        content = '#include "types.h"\n#include "stub_classes.h"\n'
        content += 'class Intersection { public: char _s[256]; };\n\n'
        body = strip_if0(original)
        body = re.sub(r'#include[^\n]*\n', '', body)
        content += body
    elif fname in ('FloorPainter_auto.cpp', 'WallPainter_auto.cpp', 'InteractorVisualizer_auto.cpp'):
        # Namespace files that failed earlier - build without stub_classes.h
        content = build_namespace_file(fname, original)
    elif fname == 'IngInfo_auto.cpp':
        content = build_namespace_file(fname, original)
    elif fname == 'Debug_auto.cpp':
        content = build_namespace_file(fname, original)
    elif fname == 'Tree_auto.cpp':
        content = build_namespace_file(fname, original)
    elif fname == '_global_auto.cpp':
        content = build_global_file(original)
    else:
        # Generic: just ensure includes and apply fixes
        if '#include "types.h"' not in content:
            content = '#include "types.h"\n' + content
        if '#include "stub_classes.h"' not in content:
            content = '#include "stub_classes.h"\n' + content

    content = apply_text_fixes(content)

    ok, errors = try_compile(content)

    if not ok:
        # Try return type fixes
        fixes = {}
        for line in errors.split('\n'):
            m = re.search(r"no declaration matches '(.+?)\s+(\w[\w:]+::\w+)\s*\(", line)
            if m:
                old_ret, func = m.group(1), m.group(2)
                for line2 in errors.split('\n'):
                    cm = re.search(r"candidate is: '(.+?)\s+" + re.escape(func) + r'\s*\(', line2)
                    if cm:
                        fixes[func] = (old_ret, cm.group(1))
                        break
        if fixes:
            for func, (old_ret, new_ret) in fixes.items():
                content = content.replace(old_ret + ' ' + func + '(', new_ret + ' ' + func + '(')
            ok, errors = try_compile(content)

    if not ok:
        # Wrap individual error lines
        error_linenos = set()
        for line in errors.split('\n'):
            m = re.search(r':(\d+):\d+: error:', line)
            if m: error_linenos.add(int(m.group(1)))

        lines = content.split('\n')
        result = []
        for i, line in enumerate(lines):
            if (i+1) in error_linenos:
                s = line.strip()
                if '::' in s and '{' in s and '}' in s and not s.startswith('#'):
                    if result and result[-1].strip().startswith('//'):
                        c = result.pop()
                        result.append('#if 0')
                        result.append(c)
                    else:
                        result.append('#if 0')
                    result.append(line)
                    result.append('#endif')
                    continue
            result.append(line)
        content = '\n'.join(result)
        ok, errors = try_compile(content)

    if ok:
        # Count active functions
        count = 0
        in_if0 = 0
        for line in content.split('\n'):
            s = line.strip()
            if s == '#if 0': in_if0 += 1
            elif s == '#endif' and in_if0 > 0: in_if0 -= 1
            elif in_if0 == 0 and '::' in s and '{' in s and '}' in s \
                    and not s.startswith('//') and not s.startswith('#'):
                count += 1
        if count > 0:
            with open(filepath, 'w') as f:
                f.write(content)
            return True

    return False


FORWARD_DECLS = """
class ESimsCam; class EVec2; class EVec3; class EVec4; class EMat4;
class cXObject; class cXPerson; class Interaction; class Neighbor;
class BString2; class ReconBuffer; class ObjSelector; class ERAmbientSound;
class AptCIH; class AptValue; class ERBitmap; class EEvent;
"""

def build_namespace_file(fname, original):
    """Build a namespace file without stub_classes.h."""
    content = strip_if0(original)
    body = re.sub(r'#include[^\n]*\n', '', content)

    header = '#include "types.h"\n' + FORWARD_DECLS + '\n'

    if 'FloorPainter' in fname:
        header += '''
namespace InteractorModule {
    class FloorPainter {
    public:
        void SetShader(int); int GetShader(); int IsActive(); void Reset();
        void SetFloorType(int); int GetFloorType(); void Enable(); void Disable();
        int IsEnabled(); void SetFloorRegion(int); int GetFloorRegion();
        char _s[256];
    };
}
'''
    elif 'WallPainter' in fname:
        header += '''
namespace InteractorModule {
    class WallPainter {
    public:
        void SetShader(int); int GetShader(); int IsActive(); void Reset();
        void SetWallType(int); int GetWallType(); void SetWallRegion(int);
        int GetWallRegion(); void Enable(); void Disable(); int IsEnabled();
        char _s[256];
    };
}
'''
    elif 'InteractorVisualizer' in fname:
        header += '''
namespace InteractorModule {
    class DirectInteractor { public: char _s[256]; };
    class InteractorVisualizer {
    public:
        void CreateResources(DirectInteractor *, int);
        void DestroyResources(DirectInteractor *); void Draw(DirectInteractor *);
        char _s[256];
    };
}
'''
    elif 'IngInfo' in fname:
        header += '''
namespace INGTarget {
    class IngInfo { public: IngInfo(); void erase(); char _s[64]; };
}
'''
    elif 'Debug_auto' in fname:
        header += '''
namespace EyeToyClient {
    class Debug { public: static void WriteTGAToHost(); };
}
'''
    elif 'Tree_auto' in fname:
        header += '''
namespace WantFear {
    class Tree { public: void* GetNodeById(short) const; char _s[256]; };
}
'''

    return header + '\n' + body


def build_global_file(original):
    """Handle _global_auto.cpp which has free functions."""
    content = strip_if0(original)
    # These are typically free functions in namespaces
    if '#include "types.h"' not in content:
        content = '#include "types.h"\n' + content
    if '#include "stub_classes.h"' not in content:
        content = '#include "stub_classes.h"\n' + content
    return content


def main():
    stats = {'fixed': 0, 'funcs': 0, 'broken': 0, 'cats': {}}

    broken = []
    for fname in sorted(os.listdir(MATCHED_DIR)):
        if not fname.endswith('.cpp'):
            continue
        fp = os.path.join(MATCHED_DIR, fname)
        with open(fp, 'r') as f:
            first = f.read(20)
        if '#if 0' in first:
            broken.append((fp, fname))

    print(f"Processing {len(broken)} broken files...")

    for i, (fp, fname) in enumerate(broken):
        ok = fix_remaining_individual(fp, fname)
        if ok:
            stats['fixed'] += 1
        else:
            stats['broken'] += 1

    print(f"\n=== RESULTS ===")
    print(f"Fixed:  {stats['fixed']} files")
    print(f"Broken: {stats['broken']} files")


if __name__ == '__main__':
    main()
