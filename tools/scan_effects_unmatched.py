#!/usr/bin/env python3
"""
Scout unmatched Effects / Animation / SkinCompositor / BBI territory.
Reuses pattern from scan_esims_unmatched.py.
"""

import re
import sys
from pathlib import Path
from collections import defaultdict

# Territory .obj file patterns
TERRITORY_OBJ_PATTERNS = [
    "sanimator2", "skincompositor", "animtable",
    "gameeffectsmanager", "animeventhandlersupport",
    "inventory", "motiveeffects",
    "frameeffects", "frameeffectsmanager", "frameeffectsngc",
    "effect", "effectsfunctions", "effectsinterface",
    "effectsmanager", "effectsmath",
    "effects_attachment", "effects_emitter", "effects_sequencer",
    "e_animcontroller", "e_animman", "e_ranim", "e_animnodedata",
]

# Territory class/symbol patterns
TERRITORY_CLASS_PATTERNS = [
    "SAnimator2", "AnimTable", "AnimRef", "AnimController",
    "SkinCompositor",
    "FrameEffects", "FrameEffectsManager", "FrameEffectsNGC",
    "GameEffectsManager",
    "MotionBlur", "Bloom", "DepthOfField", "PostProcess",
    "Effect", "EffectsManager", "EffectsMath",
    "BBI", "InventoryItem", "InventoryItems",
    "MotiveEffects",
    "AnimeEventHandler", "AnimeEventHandlerSupport",
]

# EXCLUDE: TUScout territory + already-scanned sim territory
EXCLUDE_CLASS_PATTERNS = [
    "cXPersonImpl", "Interaction", "InteractionItem",
    "WrapperPaneBase", "PaneItem", "cSoundPlayer",
    # Already scanned in ESims scout:
    "ESims", "ESim", "ESimsApp", "ESimsCam", "ESimsScene",
    "Behavior", "BehaviorTree", "Motive", "WantFear",
    "Person", "ISimInstance",
    "Skill", "Skills", "Family", "Neighbor",
    "TreeSim", "SimModel", "SimHead", "Simulator",
    "SimInteractor", "DirectInteractor", "Interactor",
    "CAS", "CasScene", "CasSim", "CasEvent",
    "AwarenessManager", "SimMemory", "SimLogging",
    "Want", "Fear", "Need",
    "UnlockDisplayObjectSim",
]

SYMBOL_LINE = re.compile(r"^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+\d+(\s+)(\S.*?)\s*$")
TEXT_END = 0x803CA900
SDK_ZONE_START = 0x80240000
SDK_ZONE_END = 0x80390000


def build_matched_index(matched_root: Path) -> set:
    hex_run = re.compile(r"[0-9a-fA-F]{6,10}")
    index = set()
    for f in matched_root.rglob("*.cpp"):
        for run in hex_run.findall(f.name):
            index.add(run.lower())
    return index


def collides(addr: int, index: set) -> bool:
    addr_hex = f"{addr:x}"
    addr_hex_padded = f"{addr:08x}"
    return addr_hex in index or addr_hex_padded in index


def is_territory_obj(line: str) -> str:
    low = line.lower()
    for pat in TERRITORY_OBJ_PATTERNS:
        if pat in low:
            parts = line.strip().replace("/", "\\").split("\\")
            if parts:
                return parts[-1].replace(".obj", "")
    return None


def is_territory_symbol(symbol: str) -> bool:
    for cls in TERRITORY_CLASS_PATTERNS:
        if cls.lower() in symbol.lower():
            return True
    return False


def is_excluded_symbol(symbol: str) -> bool:
    low = symbol.lower()
    for cls in EXCLUDE_CLASS_PATTERNS:
        if cls.lower() in low:
            return True
    return False


def is_excluded_compiler_symbol(symbol: str) -> bool:
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


def scan(size_min=0x10, size_max=0x80):
    root = Path(__file__).resolve().parent.parent
    map_path = root / "extracted" / "files" / "u2_ngc_release_dvd.map"
    matched_root = root / "src" / "matched"

    print(f"[*] Map:     {map_path}")
    print(f"[*] Matched: {matched_root}")

    print("[*] Indexing matched filenames...")
    index = build_matched_index(matched_root)
    print(f"[*] Indexed {len(index)} unique hex runs from matched files")

    print(f"[*] Size window: 0x{size_min:x}-0x{size_max:x} ({size_min}-{size_max}B)")
    print(f"[*] Text end: 0x{TEXT_END:08X}")
    print(f"[*] SDK zone: 0x{SDK_ZONE_START:08X}-0x{SDK_ZONE_END:08X}")

    candidates = []
    skipped_collision = 0
    skipped_sdk = 0
    skipped_excluded = 0
    skipped_territory_excluded = 0
    current_obj = None

    with open(map_path, "r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            if ".obj" in line.lower() or ".a(" in line.lower():
                current_obj = is_territory_obj(line)
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
            if size < size_min or size > size_max:
                continue
            if SDK_ZONE_START <= addr < SDK_ZONE_END:
                skipped_sdk += 1
                continue

            # Is this in our territory?
            is_territory = current_obj is not None or is_territory_symbol(symbol)
            if not is_territory:
                continue

            # Exclude overlapping territories
            if is_excluded_symbol(symbol):
                skipped_territory_excluded += 1
                continue

            if is_excluded_compiler_symbol(symbol):
                skipped_excluded += 1
                continue

            if collides(addr, index):
                skipped_collision += 1
                continue

            candidates.append({
                "addr": addr,
                "addr_hex": f"{addr:08x}",
                "size": size,
                "symbol": symbol,
                "obj": current_obj or "symbol-match",
            })

    print(f"\n[RESULTS] {len(candidates)} unmatched territory candidates")
    print(f"  Skipped collisions: {skipped_collision}")
    print(f"  Skipped SDK zone:   {skipped_sdk}")
    print(f"  Skipped excluded:   {skipped_excluded}")
    print(f"  Skipped territory overlap: {skipped_territory_excluded}")

    by_size = defaultdict(list)
    for c in candidates:
        by_size[c["size"]].append(c)

    for size in sorted(by_size):
        rows = by_size[size]
        print(f"\n---- {size:3d}B ({len(rows)} targets) ----")
        for c in rows[:20]:
            print(f"  0x{c['addr']:08X} {c['size']:3d}B  {c['symbol']}")
        if len(rows) > 20:
            print(f"  ... and {len(rows) - 20} more")

    return candidates


if __name__ == "__main__":
    size_min = int(sys.argv[1], 0) if len(sys.argv) > 1 else 0x10
    size_max = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x80
    scan(size_min, size_max)
