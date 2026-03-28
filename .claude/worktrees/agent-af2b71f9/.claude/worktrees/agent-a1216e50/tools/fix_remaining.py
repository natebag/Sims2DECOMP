#!/usr/bin/env python3
"""
Fix the remaining ~96 broken files.

Key insight: files using namespaces (InteractorModule::, EA::, etc.)
CANNOT include stub_classes.h because it declares these as classes,
not namespaces. For these files, we replace stub_classes.h with
local forward declarations + namespace declarations.
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


# All classes that might be referenced in function params/returns
FORWARD_DECLS = """
class ACTTarget; class ARAMBlock; class ActionMenu; class ActionQueue;
class ActionQueueItem; class AmbientScorePlayer; class AmbientSoundPlayer;
class AnimRef; class AptCIH; class AptValue; class AptActionInterpreter;
class AptCharacterInst; class AptDisplayListState; class AptFile;
class AptObject; class AptPrototype; class BString; class BString2;
class Behavior; class Bloom; class CASTarget;
class CUIButtonWidget; class CUIPane; class CUIWidget;
class CameraDirector; class CameraManager; class CameraMotionSystem;
class DirtyXml; class EApp; class EEvent; class EMemoryReadStream;
class EMemoryWriteStream; class ENgcRenderer; class ENgcShader;
class ERAmbientScore; class ERAmbientSound; class ERBitmap;
class ERModel; class ERSkin; class ERSoundTrackData; class ESimsCam;
class EVec2; class EVec3; class EVec4; class EMat4;
class ESim; class ESimsApp; class EString; class EString2;
class FTilePt; class CTilePt; class HUDTarget; class IBaseSimInstance;
class INGTarget; class Interaction; class Interests;
class Neighbor; class ObjSelector; class ReconBuffer;
class SimsCameraParameters; class TileWallsSegment; class TreeSim;
class cXObject; class cXObjectImpl; class cXPerson; class cXPersonImpl;
class cXMTObjectImpl; class cXPortalImpl; class ISimInstance;
class DiagonalSideSelector; class TilePtDir;
class EAStringC; class Intersection;
template<typename T> class TNodeList;
template<typename T, typename A> class vector;
template<typename T, typename A> class allocator;
"""

# Namespace declarations for files that need them
NS_INTERACTOR_BASE = """
namespace InteractorModule {
    class InteractorInputManager { public: typedef int InteractorCommand;
        struct InstanceData { int GetControllerFilterId() const; char _s[64]; };
        char _s[256]; };
    struct InteractorInfo { char _s[64]; };
"""

NS_INTERACTOR_INTERACTOR = NS_INTERACTOR_BASE + """
    class Interactor {
    public:
        struct OverlapData;
        void AttachCamera(ESimsCam *); int GetAttachedCamera();
        void SetExtents(EVec2 &);
        void OnCommandPressed(InteractorInputManager::InteractorCommand, float);
        void AddIdleTime(float); void ResetIdleTime();
        void UpdateOverlapIntersection(OverlapData *);
        void ExecuteObjectActionMenu(cXObject *); void StopInObjectMenu();
        int ChooseAction(Interaction *); void* GetPos(); void* GetSnappedPos();
        int GetPlayerId(); void SetDrawState(int); int GetDrawState();
        char _s[256];
    };
}
"""

NS_INTERACTOR_DIRECT = NS_INTERACTOR_BASE + """
    class DirectInteractor {
    public:
        void ExitDirectControl(); int GetControlStatus();
        int GetSelectionRadius(); int IsAutonomous();
        char _s[256];
    };
}
"""

NS_INTERACTOR_SIM = NS_INTERACTOR_BASE + """
    class SimInteractor {
    public:
        void GetFadeSquare(); void ReturnPlumbobToSim(); void SetupCutToSim();
        char _s[256];
    };
}
"""

NS_INTERACTOR_SOCIAL = NS_INTERACTOR_BASE + """
    class SocialModeInteractor {
    public:
        void GetInteractorInfo(InteractorInfo *); int GetSelectionRadius();
        int GetTimout(); void SetTimout(int);
        void OnCommandPressed(int, float); void OnCommandReleased(int, float);
        void OnCommandUpdate(int, float); void ResetChosenAction();
        char _s[256];
    };
}
"""

NS_INTERACTOR_WALL_MANIP = NS_INTERACTOR_BASE + """
    class WallManipulator {
    public:
        void* GetAnchorDrawPos(); void* GetAnchorPos();
        int GetWallHeight(); int IsBuyMode(); int IsDestructMode();
        int IsFenceMode(); int IsRoomPreview(); int IsSellMode(); int IsValidWallSegment();
        char _s[256];
    };
}
"""

NS_INTERACTOR_WALL_PAINT = NS_INTERACTOR_BASE + """
    class WallPainter {
    public:
        void SetShader(int); int GetShader(); int IsActive(); void Reset();
        void SetWallType(int); int GetWallType(); void SetWallRegion(int);
        int GetWallRegion(); void Enable(); void Disable(); int IsEnabled();
        char _s[256];
    };
}
"""

NS_INTERACTOR_FLOOR_PAINT = NS_INTERACTOR_BASE + """
    class FloorPainter {
    public:
        void SetShader(int); int GetShader(); int IsActive(); void Reset();
        void SetFloorType(int); int GetFloorType(); void Enable(); void Disable();
        int IsEnabled(); void SetFloorRegion(int); int GetFloorRegion();
        char _s[256];
    };
}
"""

NS_INTERACTOR_OBJ_MANIP = NS_INTERACTOR_BASE + """
    class ObjectManipulator {
    public:
        int GetIsCursorModelEnabled(); int GetPlacementObject();
        void OnCommandPressed(InteractorInputManager::InteractorCommand, float);
        void SetIsCursorModelEnabled(int); void SetUIDebugName(const char *);
        char _s[256];
    };
}
"""

NS_INTERACTOR_INPUT_MGR = NS_INTERACTOR_BASE + """
}
"""

NS_INTERACTOR_MGR = NS_INTERACTOR_BASE + """
    class InteractorManager {
    public:
        int GetInputManager(); int GetVisualizer(); int IsInitialized();
        char _s[256];
    };
}
"""

NS_INTERACTOR_VIS = NS_INTERACTOR_BASE + """
    class DirectInteractor { public: char _s[256]; };
    class InteractorVisualizer {
    public:
        void CreateResources(DirectInteractor *, int);
        void DestroyResources(DirectInteractor *); void Draw(DirectInteractor *);
        char _s[256];
    };
}
"""

NS_EA_ALLOCATOR = """
namespace EA { namespace Allocator {
    class GeneralAllocator {
    public:
        struct HookInfo; struct Chunk;
        void SetMallocFailureFunction(bool (*)(GeneralAllocator *, unsigned int, unsigned int, void *), void *);
        void SetHookFuncton(void (*)(HookInfo *, void *), void *);
        void SetTraceFunction(void (*)(char *, void *), void *);
        void SetTraceFieldDelimiters(unsigned char, unsigned char);
        int GetPageSize(); void AdjustHighFence();
        int ChunkMatchesLowHigh(int, Chunk *, unsigned int) const;
        void SetAssertionFailureFunction(void (*)(char *, void *), void *);
        static void TraceFunctionDefault(char *, void *);
        unsigned int GetBlockSize(void *) const;
        char _s[2048];
    };
} }
"""

NS_WANTFEAR = """
namespace WantFear {
    class Bookmark {
    public:
        short GetNumBranches() const; bool IsHidden() const;
        const void* GetAdData() const; unsigned int GetOverlayShader(Neighbor *) const;
        char _s[256];
    };
    class Tree {
    public:
        void* GetNodeById(short) const; char _s[256];
    };
}
"""

NS_BBI = """
namespace BBI {
    class InventoryItem {
    public:
        signed char GetItemCategory() const; signed char GetItemSubcategory() const;
        int GetItemGuid() const; int GetItemCount() const;
        unsigned char GetItemColorIndex() const; char _s[64];
    };
    class InventoryItems {
    public:
        int GetContainerSize() const; char _s[256];
    };
}
"""

NS_EFFECTS = """
namespace Effects {
    class Effect { public: struct ClientParams; char _s[256]; };
    class EffectsManager {
    public:
        static int CreateEffect(Effect::ClientParams *); static void Shutdown();
        char _s[256];
    };
    class EffectsSequencer { public: char _s[256]; };
    class FastParticleEmitter {
    public:
        float GetAlphaScale(); void SetAlphaScale(float);
        static int GetTotalPacketsInPool(); static void InitPlatform();
        void* operator new(unsigned int); char _s[256];
    };
}
"""

NS_CASGENETICS = """
namespace CasGenetics {
    class Grandparent { public: Grandparent(); char _s[64]; };
}
"""

NS_EFILESYSTEM = """
namespace EFileSystem {
    class FileCreator { public: int GetCreatorCB() const; char _s[64]; };
}
"""

NS_EYETOY = """
namespace EyeToyClient {
    class Debug { public: static void WriteTGAToHost(); };
}
"""

NS_INGTARGET = """
namespace INGTarget {
    class IngInfo { public: IngInfo(); void erase(); char _s[64]; };
}
"""

NS_ACTIONMENU_MENUITEM = """
class ActionMenu {
public:
    class MenuItem {
    public:
        void AddItem(MenuItem *); int GetNext(); int GetNextConst() const;
        int GetSubMenu(); char _s[64];
    };
    void CompleteMenu(); char _s[256];
};
"""

# Map from filename patterns to namespace declarations needed
FILE_NS_MAP = {
    'Interactor_auto.cpp': NS_INTERACTOR_INTERACTOR,
    'DirectInteractor_auto.cpp': NS_INTERACTOR_DIRECT,
    'SimInteractor_auto.cpp': NS_INTERACTOR_SIM,
    'SocialModeInteractor_auto.cpp': NS_INTERACTOR_SOCIAL,
    'WallManipulator_auto.cpp': NS_INTERACTOR_WALL_MANIP,
    'WallPainter_auto.cpp': NS_INTERACTOR_WALL_PAINT,
    'FloorPainter_auto.cpp': NS_INTERACTOR_FLOOR_PAINT,
    'ObjectManipulator_auto.cpp': NS_INTERACTOR_OBJ_MANIP,
    'InteractorInputManager_InstanceData_auto.cpp': NS_INTERACTOR_INPUT_MGR,
    'InteractorManager_auto.cpp': NS_INTERACTOR_MGR,
    'InteractorVisualizer_auto.cpp': NS_INTERACTOR_VIS,
    'Allocator_GeneralAllocator_auto.cpp': NS_EA_ALLOCATOR,
    'Bookmark_auto.cpp': NS_WANTFEAR,
    'WantFear_Tree_auto.cpp': NS_WANTFEAR,
    'InventoryItem_auto.cpp': NS_BBI,
    'InventoryItems_auto.cpp': NS_BBI,
    'FastParticleEmitter_auto.cpp': NS_EFFECTS,
    'EffectsManager_auto.cpp': NS_EFFECTS,
    'EffectsSequencer_auto.cpp': NS_EFFECTS,
    'Grandparent_auto.cpp': NS_CASGENETICS,
    'FileCreator_auto.cpp': NS_EFILESYSTEM,
    'Debug_auto.cpp': NS_EYETOY,
    'IngInfo_auto.cpp': NS_INGTARGET,
    'MenuItem_auto.cpp': NS_ACTIONMENU_MENUITEM,
}


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


def apply_text_fixes(content):
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

    # Fix comment-only bodies
    lines = content.split('\n')
    result = []
    for line in lines:
        s = line.strip()
        if '::' not in s or '{' not in s or '}' not in s or s.startswith('//') or s.startswith('#'):
            result.append(line); continue
        brace_start = s.index('{')
        brace_end = s.rindex('}')
        body = s[brace_start+1:brace_end].strip()
        body_clean = re.sub(r'/\*.*?\*/', '', body).strip()
        if body_clean: result.append(line); continue
        decl = s[:brace_start].strip()
        m = re.match(r'^(.*?)\s+\w[\w:]*::\w+\s*\(', decl)
        if not m: result.append(line); continue
        ret = m.group(1).strip()
        if ret in ('void', '') or ret.endswith('::'):
            new_line = s[:brace_start+1] + ' }'
        else:
            new_line = s[:brace_start+1] + ' return 0; }'
        trail = s[brace_end+1:].strip()
        if trail: new_line += '  ' + trail
        result.append(new_line)
    content = '\n'.join(result)

    return content


def get_return_type_fixes(errors):
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
                    if new_ret != old_ret: fixes[func] = (old_ret, new_ret)
                    break
    return fixes


def wrap_error_lines(content, errors):
    error_linenos = set()
    for line in errors.split('\n'):
        m = re.search(r':(\d+):\d+: error:', line)
        if m: error_linenos.add(int(m.group(1)))
    if not error_linenos: return content
    lines = content.split('\n')
    result = []
    for i, line in enumerate(lines):
        lineno = i + 1
        if lineno in error_linenos:
            s = line.strip()
            if '::' in s and '{' in s and '}' in s and not s.startswith('#'):
                if result and result[-1].strip().startswith('// 0x'):
                    comment = result.pop()
                    result.append('#if 0')
                    result.append(comment)
                else:
                    result.append('#if 0')
                result.append(line)
                result.append('#endif')
                continue
        result.append(line)
    return '\n'.join(result)


def count_active_functions(content):
    count = 0
    in_if0 = 0
    for line in content.split('\n'):
        s = line.strip()
        if s == '#if 0': in_if0 += 1
        elif s == '#endif' and in_if0 > 0: in_if0 -= 1
        elif in_if0 == 0 and '::' in s and '{' in s and '}' in s \
                and not s.startswith('//') and not s.startswith('#'):
            count += 1
    return count


def build_namespace_file(original_content, fname, ns_decl):
    """Build a file using namespace declarations instead of stub_classes.h."""
    content = strip_if0(original_content)

    # Remove existing includes
    lines = content.split('\n')
    new_lines = []
    for line in lines:
        if '#include "stub_classes.h"' in line:
            continue  # Skip stub_classes.h
        new_lines.append(line)
    content = '\n'.join(new_lines)

    # Build new header
    header = '#include "types.h"\n'
    header += FORWARD_DECLS + '\n'
    header += ns_decl + '\n'

    # Ensure types.h include exists and add our header
    if '#include "types.h"' in content:
        content = content.replace('#include "types.h"', header, 1)
    else:
        content = header + content

    return content


def process_file(filepath, fname, stats):
    with open(filepath, 'r') as f:
        original = f.read()

    if '#if 0' not in original:
        return

    # Check if this file needs namespace handling
    ns_decl = FILE_NS_MAP.get(fname)
    if ns_decl:
        content = build_namespace_file(original, fname, ns_decl)
    else:
        content = strip_if0(original)
        if '#include "types.h"' not in content:
            content = '#include "types.h"\n' + content
        if '#include "stub_classes.h"' not in content:
            content = '#include "stub_classes.h"\n' + content

    content = apply_text_fixes(content)

    # Iterative compile
    for iteration in range(6):
        ok, errors = try_compile(content)
        if ok: break

        # Return type fixes
        rt_fixes = get_return_type_fixes(errors)
        if rt_fixes:
            for func, (old_ret, new_ret) in rt_fixes.items():
                content = content.replace(old_ret + ' ' + func + '(', new_ret + ' ' + func + '(')
            ok, errors = try_compile(content)
            if ok: break

        # Wrap error lines
        old = content
        content = wrap_error_lines(content, errors)
        if content == old: break

    if not ok:
        ok, errors = try_compile(content)

    if ok:
        n = count_active_functions(content)
        if n > 0:
            with open(filepath, 'w') as f:
                f.write(content)
            stats['fixed'] += 1
            stats['funcs'] += n
            return

    stats['broken'] += 1
    for line in (errors or '').split('\n'):
        if 'error:' in line:
            m = re.search(r'error: (.{0,80})', line)
            if m:
                stats['cats'][m.group(1)[:60]] = stats['cats'].get(m.group(1)[:60], 0) + 1
            break


def main():
    stats = {'fixed': 0, 'funcs': 0, 'broken': 0, 'cats': {}}

    files = sorted(f for f in os.listdir(MATCHED_DIR) if f.endswith('.cpp'))
    broken = []
    for fname in files:
        fp = os.path.join(MATCHED_DIR, fname)
        with open(fp, 'r') as f:
            first = f.read(50)
        if '#if 0' in first:
            broken.append((fp, fname))

    print(f"Processing {len(broken)} broken files...")

    for i, (fp, fname) in enumerate(broken):
        process_file(fp, fname, stats)
        if (i+1) % 20 == 0:
            print(f"  [{i+1}/{len(broken)}] fixed={stats['fixed']} ({stats['funcs']} funcs) broken={stats['broken']}")

    print(f"\n=== RESULTS ===")
    print(f"Newly fixed: {stats['fixed']} files ({stats['funcs']} funcs)")
    print(f"Still broken: {stats['broken']} files")
    if stats['cats']:
        print(f"\nRemaining errors:")
        for cat, count in sorted(stats['cats'].items(), key=lambda x: -x[1]):
            print(f"  {count:3d}x  {cat}")


if __name__ == '__main__':
    main()
