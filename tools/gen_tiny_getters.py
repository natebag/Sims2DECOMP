#!/usr/bin/env python3
"""Generate trivial 8B getter/setter .cpp files from a pattern table.
Each entry: (addr_hex, size, pattern_kind, params, name, class_name)

CRITICAL: Before adding new entries, verify the address is NOT already
matched. Use this to enumerate matched addresses (handles BOTH naming
conventions: `match_0xADDR_*` AND `match_ADDR_*`):

    python -c "import os, re; m=set();
    [m.add(g.group(2).upper()) for r,_,fs in os.walk('src/matched')
     for f in fs for g in [re.search(r'match_(0[xX])?([0-9A-Fa-f]{8})_', f)] if g];
    print(len(m))"

The pre-commit hook will REJECT duplicate addresses, even across
naming conventions. Earlier sessions used the `match_ADDR_` (no-0x)
form; current convention is `match_0xADDR_`.

Empirical finding (2026-04-23): the fleet has already matched nearly
every trivial 8B getter/setter in non-SDK code. SDK functions
(0x8024xxxx-0x8039xxxx) are Metrowerks-compiled and cannot byte-match.
This generator's main value is for future sessions if new tiny
candidates surface (e.g., from newly-extracted symbol info).
"""
import os, subprocess, sys

OUT = "src/wip/tiny_blast"
os.makedirs(OUT, exist_ok=True)

# (addr, size, kind, offset_or_const, name, class_name, type_hint)
ENTRIES = [
    # Pattern A: float getter — lfs f1,OFF(r3); blr
    (0x8000FC68, 8, "fget", 48,   "GetParagraphHeight", "AptParagraph", "float"),
    (0x8000FC70, 8, "fget", 36,   "GetPrintWidth",      "AptParagraph", "float"),
    (0x8001EA7C, 8, "fget", 1104, "GetTilt",            "ESimsCam",     "float"),
    (0x8001EA94, 8, "fget", 1100, "GetRotAng",          "ESimsCam",     "float"),
    (0x800690C0, 8, "fget", 48,   "GetRealDir",         "SAnimator2",   "float"),
    (0x800690D0, 8, "fget", 252,  "GetTimeMultiplier",  "SAnimator2",   "float"),

    # Pattern B: int/ptr getter — lwz r3,OFF(r3); blr
    (0x8001ADA0, 8, "iget", 1376, "GetControllerFilterId",     "ESimsCam",          "unsigned int"),
    (0x8001CAF8, 8, "iget", 720,  "GetFrameEffectsManager",    "CameraDirector",    "void*"),
    (0x8001EA9C, 8, "iget", 972,  "GetMode",                   "ESimsCam",          "int"),
    (0x8001EAA4, 8, "iget", 4,    "GetPlayerId",               "ESimsCam",          "int"),
    (0x8001EAB4, 8, "iget", 1356, "IsForceFullScreen",         "ESimsCam",          "int"),
    (0x8001EACC, 8, "iget", 1352, "GetRoomWallsOpaque",        "ESimsCam",          "int"),
    (0x800226A0, 8, "iget", 44,   "Tell",                      "EDummyFile",        "int"),
    (0x80036E70, 8, "iget", 8,    "GetObject",                 "ESpriteRender",     "void*"),
    (0x80036E78, 8, "iget", 0,    "GetMarked",                 "ESpriteRender",     "int"),
    (0x80036E80, 8, "iget", 4,    "GetMarkedAsNew",            "ESpriteRender",     "int"),
    (0x8003DDA0, 8, "iget", 296,  "GetBuildBuyPlayer",         "GameData",          "int"),
    (0x80068A40, 8, "iget", 1596, "GetAwareOfObject",          "SAnimator2",        "int"),

    # Pattern C: signed short getter — lha r3,OFF(r3); blr
    (0x8002B99C, 8, "shget", 858, "GetAdjacentRoom", "EIWallPart", "short"),

    # Pattern D: int setter — stw r4,OFF(r3); blr (param r4 is value)
    (0x8001EAAC, 8, "iset", 1356, "ForceFullScreen",                                    "ESimsCam",   "int"),
    (0x8001EABC, 8, "iset", 1344, "SetCenterNew",                                       "ESimsCam",   "int"),
    (0x8001EAD4, 8, "iset", 1380, "SetInterpolatingToOrFromSocialModeCameraFlag",       "ESimsCam",   "int"),
    (0x8001EADC, 8, "iset", 1384, "SetInterpolatingFromLotIntroCameraFlag",             "ESimsCam",   "int"),
    (0x80030654, 8, "iset", 944,  "SetForceFadeOff",                                    "EIWallPart", "int"),
    (0x800689F4, 8, "iset", 288,  "SetIdleInitialized",                                 "SAnimator2", "int"),
    (0x8003FA14, 8, "iset", 208,  "SetCam",                                             "EGlobal",    "void*"),

    # Pattern E: return constant — li r3,N; blr
    (0x800226B0, 8, "iconst", 0,  "GetLastError",        "EDummyFile",  "int"),
    (0x800226B8, 8, "iconst", 0,  "GetSystemHandle",     "EDummyFile",  "int"),
    (0x80030898, 8, "iconst", 0,  "IsOpaque",            "EIFenceWall", "int"),
    (0x80038CD8, 8, "iconst", 12, "GetFunframeCount",    "EyeToyClient","int"),
    (0x80038CE0, 8, "iconst", 5,  "GetFilterCount",      "EyeToyClient","int"),
    (0x80038CE8, 8, "iconst", 5,  "GetTargetSlotCount",  "EyeToyClient","int"),
]

def gen_fget(off, name, cls, ty):
    return f"""// 0x{addr:08X} (8B) {cls}::{name}(void) const

struct {cls} {{
    char pad[{off}];
    {ty} m_field;

    {ty} {name}() const;
}};

{ty} {cls}::{name}() const {{ return m_field; }}
"""

def gen_iget(off, name, cls, ty):
    return f"""// 0x{addr:08X} (8B) {cls}::{name}(void) const

struct {cls} {{
    char pad[{off}];
    {ty} m_field;

    {ty} {name}() const;
}};

{ty} {cls}::{name}() const {{ return m_field; }}
"""

def gen_shget(off, name, cls, ty):
    return f"""// 0x{addr:08X} (8B) {cls}::{name}(void)

struct {cls} {{
    char pad[{off}];
    {ty} m_field;

    {ty} {name}();
}};

{ty} {cls}::{name}() {{ return m_field; }}
"""

def gen_iset(off, name, cls, ty):
    return f"""// 0x{addr:08X} (8B) {cls}::{name}({ty})

struct {cls} {{
    char pad[{off}];
    {ty} m_field;

    void {name}({ty} v);
}};

void {cls}::{name}({ty} v) {{ m_field = v; }}
"""

def gen_iconst(const_val, name, cls, ty):
    return f"""// 0x{addr:08X} (8B) {cls}::{name}(void)

struct {cls} {{
    {ty} {name}();
}};

{ty} {cls}::{name}() {{ return {const_val}; }}
"""

results = []
for addr, size, kind, val, name, cls, ty in ENTRIES:
    globals()['addr'] = addr
    if kind == "fget":
        src = gen_fget(val, name, cls, ty)
    elif kind == "iget":
        src = gen_iget(val, name, cls, ty)
    elif kind == "shget":
        src = gen_shget(val, name, cls, ty)
    elif kind == "iset":
        src = gen_iset(val, name, cls, ty)
    elif kind == "iconst":
        src = gen_iconst(val, name, cls, ty)
    fname = f"match_0x{addr:08X}_{cls}_{name}.cpp"
    fpath = os.path.join(OUT, fname)
    with open(fpath, "w", newline="\n") as f:
        f.write(src)
    # Verify
    r = subprocess.run(
        ["C:\\Program Files\\Git\\usr\\bin\\bash.exe", "tools/verify_match.sh", fpath, f"0x{addr:08X}", str(size)],
        capture_output=True, text=True
    )
    out = r.stdout + r.stderr
    verdict = "FAIL"
    for line in out.splitlines():
        if line.startswith(("MATCH", "MISMATCH", "SIZE_MISMATCH", "REJECTED", "ERROR")):
            verdict = line.split("!")[0].split()[0]
            break
    results.append((addr, name, cls, verdict, fpath))
    print(f"0x{addr:08X} {cls}::{name} => {verdict}")

print(f"\nResults: {sum(1 for r in results if r[3]=='MATCH')}/{len(results)} matched")
