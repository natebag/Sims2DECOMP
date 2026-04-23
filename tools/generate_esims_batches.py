#!/usr/bin/env python3
"""Generate scout batches for ESims* / ESim subsystem."""

import re
import os
from pathlib import Path
from collections import defaultdict

SIM_OBJ_PATTERNS = [
    "sim", "person", "behavior", "motive", "want", "fear",
    "interact", "cas", "thesims", "esim", "simsdataman",
    "simulator", "treesim", "simhead", "simimagemaker",
    "simrenderer", "simsmemcardwrap", "simlogging", "simmemory",
    "objectsim", "objtestsim", "isiminstance",
    "cassim", "casperson", "casbody", "casclothing", "cascostume",
    "casgenetic", "casfashion", "casmediator", "casmorph", "casmisc",
    "casnpceditor", "casroommate", "casscene", "cassimdescription",
    "cassimparts", "cassimrenderer", "cassimrendererdynamic",
    "cassimstate", "castarget", "castattoo", "castweak",
    "casselection", "cassimdescriptions2c", "cassimpartss2c",
    "awarenessmanager",
]

SIM_CLASS_PATTERNS = [
    "ESims", "ESim", "ESimsApp", "ESimsCam", "ESimsScene",
    "Behavior", "BehaviorTree", "Motive", "WantFear", "Interaction",
    "Person", "cXPerson", "ISimInstance",
    "Skill", "Skills", "Family", "Neighbor",
    "TreeSim", "SimModel", "SimHead", "Simulator",
    "SimInteractor", "DirectInteractor", "Interactor",
    "CAS", "CasScene", "CasSim", "CasEvent",
    "AwarenessManager", "SimMemory", "SimLogging",
    "Want", "Fear", "Motive", "Need",
    "UnlockDisplayObjectSim",
]

SYMBOL_LINE = re.compile(r"^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+\d+(\s+)(\S.*?)\s*$")
TEXT_END = 0x803CA900
SDK_ZONE_START = 0x80240000
SDK_ZONE_END = 0x80390000


def build_matched_index():
    hex_run = re.compile(r"[0-9a-fA-F]{6,10}")
    index = set()
    for f in Path("src/matched").rglob("*.cpp"):
        for run in hex_run.findall(f.name):
            index.add(run.lower())
    return index


def collides(addr, index):
    return f"{addr:x}" in index or f"{addr:08x}" in index


def is_sim_obj(line):
    low = line.lower()
    for pat in SIM_OBJ_PATTERNS:
        if pat in low:
            parts = line.strip().replace("/", "\\").split("\\")
            if parts:
                return parts[-1].replace(".obj", "")
    return None


def is_sim_symbol(symbol):
    for cls in SIM_CLASS_PATTERNS:
        if cls.lower() in symbol.lower():
            return True
    return False


def is_excluded_symbol(symbol):
    low = symbol.lower()
    if low.startswith("__"):
        return True
    if "_m_do_" in low or "_m_create_nodes" in low or "_m_initialize_map" in low:
        return True
    if "_unguarded_" in low or "_insertion_sort" in low or "_partial_sort" in low:
        return True
    if "_partition" in low or "_equal_range" in low or "_lower_bound" in low or "_upper_bound" in low:
        return True
    if "_merge" in low or "_transfer" in low:
        return True
    if "pop_heap" in low or "void partial_sort" in low or "void sort" in low or "void make_heap" in low:
        return True
    if "_deque_base" in low or "_list_global" in low:
        return True
    if "_s_chunk_alloc" in low or "_s_refill" in low or "_m_allocate" in low or "_m_deallocate" in low:
        return True
    if "operator new" in low and "unsigned int" in low:
        return True
    if "operator delete" in low and "void *" in low:
        return True
    if "global constructors keyed to" in low:
        return True
    if low.startswith("k") and not low.startswith("known"):
        return True
    if "::s_" in symbol:
        return True
    if "zodiac" in low or "matrix" in low or "blendweights" in low:
        return True
    if "_perptilepointtab" in low:
        return True
    if symbol.startswith("{") and "anonymous" in symbol and "::k" in symbol:
        return True
    return False


def marker(size):
    if size <= 32:
        return "🟢"
    elif size <= 48:
        return "🟡"
    elif size <= 64:
        return "🔴"
    elif size <= 128:
        return "🟡"
    else:
        return "🔴"


def main():
    index = build_matched_index()
    candidates = []
    current_obj = None

    map_path = Path("extracted/files/u2_ngc_release_dvd.map")
    with open(map_path, "r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            if ".obj" in line.lower() or ".a(" in line.lower():
                current_obj = is_sim_obj(line)
                continue
            m = SYMBOL_LINE.match(line)
            if not m:
                continue
            indent_len = len(m.group(3))
            symbol = m.group(4)
            if indent_len < 24:
                continue
            if symbol.startswith(".") or symbol.startswith("<") or ".obj" in symbol:
                continue
            if "virtual table" in symbol or "vtable" in symbol.lower():
                continue
            try:
                addr = int(m.group(1), 16)
                size = int(m.group(2), 16)
            except ValueError:
                continue
            if addr >= TEXT_END:
                continue
            if size < 0x10 or size > 0x100:
                continue
            if SDK_ZONE_START <= addr < SDK_ZONE_END:
                continue
            is_sim = current_obj is not None or is_sim_symbol(symbol)
            if not is_sim:
                continue
            if is_excluded_symbol(symbol):
                continue
            if collides(addr, index):
                continue
            candidates.append({"addr": addr, "size": size, "symbol": symbol})

    # Group by class prefix
    by_class = defaultdict(list)
    for c in candidates:
        sym = c["symbol"]
        if "::" in sym:
            cls = sym.split("::")[0]
        else:
            cls = "FreeFunctions"
        by_class[cls].append(c)

    class_groups = {
        "ESimsCam": ["ESimsCam"],
        "cXPersonImpl": ["cXPersonImpl"],
        "InteractorModule": ["InteractorModule"],
        "Neighbor_NeighborhoodImpl": ["Neighbor", "NeighborhoodImpl"],
        "Behavior_BehaviorTree": [
            "Behavior", "BehaviorTree", "IFFBehavior", "ResourceBehavior",
            "IFFBehaviorTree", "ResourceBehaviorTree", "ObjectDataBehaviorConstants",
            "QuickDataBehaviorConstants", "ObjectDataBehaviorTree",
        ],
        "SimModel_SimRenderer": ["SimModel", "SimRenderer", "SimImageMaker", "ESims3DHead"],
        "CAS_Core": ["CASTarget", "CasSimDescriptionS2C", "CasSimPartsS2C", "CasSimState", "CasSimRenderer", "CasSimRendererDynamic"],
        "CAS_UI": ["CasClothingUnlocks", "CasCostumes", "CasGenetics", "CasMediator", "CasNpcEditor", "CasScene", "CasTweakTool"],
        "CAS_Events": ["CasEventChangeFocus", "CasEventChangeSimS2C", "CasEventMorphSimS2C", "CasEventResetSim", "CasEventResetSimDraw", "CasEventStoreSim"],
        "AwarenessManager": ["AwarenessManager"],
        "ESim_ESimsApp_TreeSim": ["ESim", "ESimsApp", "ESimsDataManager", "TreeSim", "TreeSimImpl", "TreeStack", "StackElem", "cSimulatorImpl"],
        "INV_PCT_WXF_FAM": [
            "INVTarget", "PCTTarget", "WXFTarget", "FAMTarget", "ACTTarget", "HUDTarget",
            "CASBodyTarget", "CASRoommateTarget", "CASSelectionTarget", "CASFashionTarget",
            "CASGeneticsTarget", "CASMorphTarget", "CASTattooTarget", "CASPersonalTarget",
            "CASMiscTarget",
        ],
        "SimsMemCardWrap": ["SimsMemCardWrap"],
        "FreeFunctions": ["FreeFunctions"],
        "ObjectModuleImpl_cXObjectImpl": ["ObjectModuleImpl", "cXObjectImpl"],
        "WantFear_WantFearManager": ["WantFear", "WantFearManager"],
    }

    batch_num = 1
    batches = []
    for group_name, class_list in class_groups.items():
        items = []
        for cls in class_list:
            items.extend(by_class.get(cls, []))
        if not items:
            continue
        items.sort(key=lambda x: x["size"])
        for i in range(0, len(items), 20):
            chunk = items[i:i + 20]
            batches.append((batch_num, group_name, chunk))
            batch_num += 1

    os.makedirs("build/scout_batches", exist_ok=True)
    for num, gname, items in batches:
        fname = f"build/scout_batches/batch_{num:02d}_{gname}.txt"
        with open(fname, "w", encoding="utf-8") as f:
            f.write(f"Batch {num}: {gname} — {len(items)} targets\n")
            f.write(f"Tag: scout, sims_ai, s{num}\n\n")
            for c in items:
                f.write(f"  0x{c['addr']:08X} {c['size']:3d}B  {marker(c['size'])} {c['symbol']}\n")

    print(f"Wrote {len(batches)} batch files to build/scout_batches/")
    for num, gname, items in batches:
        sizes = [c["size"] for c in items]
        print(f"Batch {num:2d}: {gname:30s} — {len(items):2d} targets ({min(sizes):3d}-{max(sizes):3d}B)")


if __name__ == "__main__":
    main()
