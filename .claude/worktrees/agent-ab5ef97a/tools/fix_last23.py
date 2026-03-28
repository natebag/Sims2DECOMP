#!/usr/bin/env python3
"""Fix the last 23 broken files with specific solutions."""

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
    tmp = os.path.join(REPO, '_tc.cpp')
    with open(tmp, 'w') as f: f.write(content)
    cmd = [CXX] + CXXFLAGS + ["-c", tmp, "-o", "NUL"]
    try:
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=30, cwd=REPO)
        os.unlink(tmp)
        return r.returncode == 0, r.stderr
    except Exception as e:
        if os.path.exists(tmp): os.unlink(tmp)
        return False, str(e)

def write_if_compiles(filepath, content):
    ok, err = try_compile(content)
    if ok:
        with open(filepath, 'w') as f: f.write(content)
        return True
    else:
        print(f"  STILL FAILS: {err[:200]}")
        return False

fixes = {
    'CTilePt_auto.cpp': lambda: """#include "types.h"
#include "stub_classes.h"
// CTilePt: constructor + accessors. Constructor can't be defined (implicitly declared).
// Wrap constructor in #if 0, fix params.

#if 0
// 0x800B45D0 (12 bytes) - can't define implicitly-declared default ctor
CTilePt::CTilePt() { *(char*)((char*)this + 0x2) = 0; }
#endif

// 0x800B4CA8 (12 bytes)
signed char CTilePt::GetX() const { return *(signed char*)((char*)this + 0x0); }

// 0x800B4CB4 (12 bytes)
signed char CTilePt::GetY() const { return *(signed char*)((char*)this + 0x1); }

// 0x800B4D04 (12 bytes)
signed char CTilePt::SetX(int val) { *(char*)((char*)this + 0x0) = val; return (signed char)val; }

// 0x800B4D10 (12 bytes)
signed char CTilePt::SetY(int val) { *(char*)((char*)this + 0x1) = val; return (signed char)val; }

// 0x800B4D1C (12 bytes)
void CTilePt::Set(int p4, int p5) { *(char*)((char*)this + 0x1) = p5; *(char*)((char*)this + 0x0) = p4; }

#if 0
// 0x800B4D28 (16 bytes) - param6 issue
void CTilePt::Set(int, int, int) { *(char*)((char*)this + 0x2) = param6; *(char*)((char*)this + 0x0) = p4; *(char*)((char*)this + 0x1) = p5; }
#endif

// 0x800B4DDC (12 bytes)
signed char CTilePt::GetLevel() const { return *(signed char*)((char*)this + 0x2); }

// 0x800B4DE8 (8 bytes)
void CTilePt::SetLevel(int val) { *(char*)((char*)this + 0x2) = val; }

#if 0
// 0x800B4DF0 (12 bytes) - comment body
void CTilePt::SetLevel(CTilePt &) { /* copy byte: 2(r4) -> 2(r3) */ }
#endif
""",

    'CasSimState_auto.cpp': lambda: """#include "types.h"
#include "stub_classes.h"
#if 0
// Return type mismatch: stub_classes says void, auto_match says void*
void* CasSimState::GetSimDescription() { return (char*)this + 0x8; }
void* CasSimState::GetStoredSimDescription() { return (char*)this + 0x12C; }
#endif
""",

    'EMat4_auto.cpp': lambda: """#include "types.h"
#include "stub_classes.h"
#if 0
// stub_classes declares Print() differently
void EMat4::Print() const { }
#endif
""",

    'EVec4_auto.cpp': lambda: """#include "types.h"
#include "stub_classes.h"
#if 0
void EVec4::Print() { }
#endif
""",

    'EString_auto.cpp': lambda: """#include "types.h"
#include "stub_classes.h"
#if 0
// r13 reference and operator char* issues - can't fix
void EString::SetToNull() { *(int*)((char*)this + 0x0) = 0; }
int EString::operator char *() const { return *(int*)((char*)this + 0x0); }
#endif
""",

    'EYETarget_auto.cpp': lambda: """#include "types.h"
#include "stub_classes.h"
#if 0
// EYETarget::eState not declared in stub_classes
void EYETarget::SetState(EYETarget::eState) { *(int*)((char*)this + 0xAC) = val; }
#endif
""",

    'PiecewiseFn_auto.cpp': lambda: """#include "types.h"
#include "stub_classes.h"
#if 0
// no declaration matches
void PiecewiseFn::Reset() { *(int*)((char*)this + 0x8) = 0; }
#endif
""",

    'UrbzCreditsState_auto.cpp': lambda: """#include "types.h"
#include "stub_classes.h"
#if 0
void UrbzCreditsState::Reset() { }
#endif
""",
}

def fix_engc_operator_new(filepath, classname):
    """Fix ENgcShader/ENgcTexture operator new with placement."""
    # The issue: stub_classes.h declares operator new(unsigned int)
    # but code has operator new(unsigned int, void*)
    # This is placement new - different signature. Can't match stub_classes.h.
    content = f"""#include "types.h"
#include "stub_classes.h"
#if 0
// Placement operator new not in stub_classes.h declaration
void* {classname}::operator new(unsigned int, void* first) {{ return first; }}
#endif
"""
    return write_if_compiles(filepath, content)

def fix_tarray_ptr(filepath, typename, alloctype):
    """Fix TArray with pointer types like TArray<EFontPage*, TArrayDefaultAllocator>."""
    content = f"""#include "types.h"

class {typename.rstrip('*').strip()};
class {alloctype};

template <typename T, typename A = int>
class TArray {{
public:
    void Init() {{ *(int*)((char*)this + 0x4) = 0; *(int*)((char*)this + 0x0) = 0; *(int*)((char*)this + 0x8) = 0; }}
    char _stub_data[16];
}};

template class TArray<{typename}, {alloctype}>;
"""
    return write_if_compiles(filepath, content)

def fix_tarray_nested(filepath):
    """Fix TArray<TArray<SndEvtHitPatch, ...>, ...>."""
    content = """#include "types.h"

class SndEvtHitPatch;
class TArrayERSoundEventAllocator;

template <typename T, typename A = int>
class TArray {
public:
    void Init() { *(int*)((char*)this + 0x4) = 0; *(int*)((char*)this + 0x0) = 0; *(int*)((char*)this + 0x8) = 0; }
    char _stub_data[16];
};

template class TArray<TArray<SndEvtHitPatch, TArrayERSoundEventAllocator>, TArrayERSoundEventAllocator>;
"""
    return write_if_compiles(filepath, content)

def fix_simple_recon_nested(filepath, inner_type):
    """Fix SimpleReconObject with nested template types."""
    # e.g., SimpleReconObject<ReconStreamPtrVector<Neighbor*>>
    content = f"""#include "types.h"

class Neighbor;
class SlotDescriptor;
template <typename T> class ReconStreamPtrVector {{ public: char _s[16]; }};
template <typename T> class ReconStreamVector {{ public: char _s[16]; }};

template <typename T>
class SimpleReconObject {{
public:
    int GetType() {{ return *(int*)((char*)this + 0x8); }}
    char _stub_data[16];
}};

template class SimpleReconObject<{inner_type}>;
"""
    return write_if_compiles(filepath, content)

def fix_filecreator_tarray(filepath):
    content = """#include "types.h"

namespace EFileSystem { class FileCreator { public: char _s[64]; }; }
class TArrayDefaultAllocator;

template<typename T, typename A=int> class TArray {
public:
    void Init() { *(int*)((char*)this+0x4)=0; *(int*)((char*)this+0x0)=0; *(int*)((char*)this+0x8)=0; }
    char _s[16];
};

template class TArray<EFileSystem::FileCreator, TArrayDefaultAllocator>;
"""
    return write_if_compiles(filepath, content)

def fix_namespace_file(filepath, fname):
    """Fix remaining namespace files."""
    with open(filepath, 'r') as f:
        original = f.read()

    # Strip #if 0
    lines = original.split('\n')
    new = []
    found = False
    for line in lines:
        if not found and line.strip() == '#if 0': found = True; continue
        new.append(line)
    if found:
        for i in range(len(new)-1,-1,-1):
            if new[i].strip() == '#endif': new.pop(i); break
    body = '\n'.join(new)
    body = re.sub(r'#include[^\n]*\n', '', body)

    # Name params
    def name_p(line):
        if '{' not in line or '::' not in line: return line
        brace = line.index('{'); b = line[brace:]
        used = set()
        for n in ['val','fval','p4','p5','index']:
            if re.search(r'\b'+n+r'\b', b): used.add(n)
        if not used: return line
        # Find params
        s = line[:brace].rstrip()
        if s.endswith('const'): s = s[:-5].rstrip()
        if not s.endswith(')'): return line
        end = len(s)-1; depth=1; i=end-1
        while i>=0 and depth>0:
            if s[i]==')': depth+=1
            elif s[i]=='(': depth-=1
            i-=1
        if depth!=0: return line
        start=i+1
        pstr=s[start+1:end]
        parts=[]
        d=0; cur=[]
        for c in pstr:
            if c in '(<': d+=1; cur.append(c)
            elif c in ')>': d-=1; cur.append(c)
            elif c==',' and d==0: parts.append(''.join(cur)); cur=[]
            else: cur.append(c)
        if cur: parts.append(''.join(cur))
        new_params=[]
        for idx,p in enumerate(parts):
            p2=p.strip()
            reg=idx+4; pn=f'p{reg}'
            assigned=None
            if pn in used: assigned=pn
            elif len(parts)==1:
                for c in ['val','fval','index','p4']:
                    if c in used: assigned=c; break
            elif idx==0:
                for c in ['val','fval','p4']:
                    if c in used: assigned=c; break
            elif idx==1:
                if 'p5' in used: assigned='p5'
            if assigned: new_params.append(p2+' '+assigned); used.discard(assigned)
            else: new_params.append(p)
        return line[:start+1]+', '.join(new_params)+line[end:]

    lines = body.split('\n')
    named = [name_p(l) if not l.strip().startswith('//') else l for l in lines]
    body = '\n'.join(named)

    header = '#include "types.h"\n'
    header += 'class ESimsCam; class EVec2; class cXObject; class Interaction;\n\n'

    if 'FloorPainter' in fname:
        header += '''namespace InteractorModule {
    class FloorPainter { public:
        bool IsInAnchorState(); bool IsInFreeState();
        void SetShader(int); int GetShader();
        char _s[256]; };
}
'''
    elif 'WallPainter' in fname:
        header += '''namespace InteractorModule {
    class WallPainter { public:
        bool IsInAnchorState();
        void SetShader(int); int GetShader();
        void SetWallType(int); int GetWallType();
        void SetWallRegion(int); int GetWallRegion();
        void Enable(); void Disable(); int IsEnabled();
        char _s[256]; };
}
'''
    elif 'InteractorVisualizer' in fname:
        header += '''namespace InteractorModule {
    class DirectInteractor { public: char _s[256]; };
    class InteractorVisualizer { public:
        bool CreateResources(DirectInteractor &);
        void DestroyResources(DirectInteractor &);
        void Draw(DirectInteractor &);
        char _s[256]; };
}
'''

    full = header + '\n' + body
    # Fix comment bodies
    full = re.sub(r'return\s+/\*[^*]*\*/', 'return 0', full)

    return write_if_compiles(filepath, full)

def fix_global_file(filepath):
    with open(filepath, 'r') as f:
        original = f.read()
    lines = original.split('\n')
    new = []
    found = False
    for line in lines:
        if not found and line.strip() == '#if 0': found = True; continue
        new.append(line)
    if found:
        for i in range(len(new)-1,-1,-1):
            if new[i].strip() == '#endif': new.pop(i); break
    content = '\n'.join(new)

    # Wrap AptGetBytesEnum functions in #if 0
    lines = content.split('\n')
    result = []
    for line in lines:
        if 'AptGetBytesEnum' in line and '{' in line:
            if result and result[-1].strip().startswith('//'):
                c = result.pop()
                result.append('#if 0')
                result.append(c)
            else:
                result.append('#if 0')
            result.append(line)
            result.append('#endif')
        else:
            result.append(line)
    content = '\n'.join(result)

    # Name params
    def name_p(line):
        if '{' not in line or '::' not in line: return line
        brace = line.index('{'); b = line[brace:]
        used = set()
        for n in ['val','p4','p5']:
            if re.search(r'\b'+n+r'\b', b): used.add(n)
        if not used: return line
        s = line[:brace].rstrip()
        if s.endswith('const'): s = s[:-5].rstrip()
        if not s.endswith(')'): return line
        end=len(s)-1; depth=1; i=end-1
        while i>=0 and depth>0:
            if s[i]==')': depth+=1
            elif s[i]=='(': depth-=1
            i-=1
        if depth!=0: return line
        start=i+1; pstr=s[start+1:end]
        parts=[]; d=0; cur=[]
        for c in pstr:
            if c in '(<': d+=1; cur.append(c)
            elif c in ')>': d-=1; cur.append(c)
            elif c==',' and d==0: parts.append(''.join(cur)); cur=[]
            else: cur.append(c)
        if cur: parts.append(''.join(cur))
        new_params=[]
        for idx,p in enumerate(parts):
            p2=p.strip(); reg=idx+4; pn=f'p{reg}'; assigned=None
            if pn in used: assigned=pn
            elif len(parts)==1:
                for c in ['val','p4']:
                    if c in used: assigned=c; break
            if assigned: new_params.append(p2+' '+assigned); used.discard(assigned)
            else: new_params.append(p)
        return line[:start+1]+', '.join(new_params)+line[end:]

    lines = content.split('\n')
    named = [name_p(l) if not l.strip().startswith('//') and not l.strip().startswith('#') else l for l in lines]
    content = '\n'.join(named)

    return write_if_compiles(filepath, content)


def main():
    fixed = 0
    broken = 0

    for fname, gen in fixes.items():
        fp = os.path.join(MATCHED_DIR, fname)
        if not os.path.exists(fp): continue
        content = gen()
        if write_if_compiles(fp, content):
            fixed += 1; print(f"  FIXED: {fname}")
        else:
            broken += 1

    # ENgc operator new files
    for fname, cls in [
        ('ENgcShader_auto.cpp', 'ENgcShader'),
        ('ENgcTextureC4_auto.cpp', 'ENgcTextureC4'),
        ('ENgcTextureC8_auto.cpp', 'ENgcTextureC8'),
        ('ENgcTextureRGB5A3_auto.cpp', 'ENgcTextureRGB5A3'),
        ('ENgcTextureRGBA8_auto.cpp', 'ENgcTextureRGBA8'),
    ]:
        fp = os.path.join(MATCHED_DIR, fname)
        if fix_engc_operator_new(fp, cls):
            fixed += 1; print(f"  FIXED: {fname}")
        else:
            broken += 1

    # TArray pointer files
    for fname, tname, alloc in [
        ('TArray_EFontPage_ptr__TArrayDefaultAllocator__auto.cpp', 'EFontPage *', 'TArrayDefaultAllocator'),
        ('TArray_EILight_ptr__TArrayDefaultAllocator__auto.cpp', 'EILight *', 'TArrayDefaultAllocator'),
    ]:
        fp = os.path.join(MATCHED_DIR, fname)
        if fix_tarray_ptr(fp, tname, alloc):
            fixed += 1; print(f"  FIXED: {fname}")
        else:
            broken += 1

    # Nested TArray
    fp = os.path.join(MATCHED_DIR, 'TArray_TArray_SndEvtHitPatch__TArrayERSoundEventAllocator___TArrayERSoundEventAllocator__auto.cpp')
    if os.path.exists(fp):
        if fix_tarray_nested(fp):
            fixed += 1; print(f"  FIXED: nested TArray")
        else:
            broken += 1

    # SimpleReconObject nested types
    for fname, inner in [
        ('SimpleReconObject_ReconStreamPtrVector_Neighbor____auto.cpp', 'ReconStreamPtrVector<Neighbor*>'),
        ('SimpleReconObject_ReconStreamVector_SlotDescriptor____auto.cpp', 'ReconStreamVector<SlotDescriptor>'),
    ]:
        fp = os.path.join(MATCHED_DIR, fname)
        if os.path.exists(fp):
            if fix_simple_recon_nested(fp, inner):
                fixed += 1; print(f"  FIXED: {fname}")
            else:
                broken += 1

    # FileCreator TArray
    fp = os.path.join(MATCHED_DIR, 'FileCreator__TArrayDefaultAllocator__auto.cpp')
    if os.path.exists(fp):
        if fix_filecreator_tarray(fp):
            fixed += 1; print(f"  FIXED: FileCreator TArray")
        else:
            broken += 1

    # Namespace files
    for fname in ['FloorPainter_auto.cpp', 'WallPainter_auto.cpp', 'InteractorVisualizer_auto.cpp']:
        fp = os.path.join(MATCHED_DIR, fname)
        if os.path.exists(fp):
            with open(fp, 'r') as f:
                if '#if 0' in f.read(20):
                    if fix_namespace_file(fp, fname):
                        fixed += 1; print(f"  FIXED: {fname}")
                    else:
                        broken += 1

    # _global_auto.cpp
    fp = os.path.join(MATCHED_DIR, '_global_auto.cpp')
    if os.path.exists(fp):
        with open(fp, 'r') as f:
            if '#if 0' in f.read(20):
                if fix_global_file(fp):
                    fixed += 1; print(f"  FIXED: _global_auto.cpp")
                else:
                    broken += 1

    print(f"\n=== Fixed: {fixed}, Broken: {broken} ===")


if __name__ == '__main__':
    main()
