#!/usr/bin/env python3
"""
Scout unmatched functions from S14 territories:
  1. ERoom/Goals/Careers (high priority)
  2. Skin/Movie/Skillmovie/Treetab
  3. Audio / sound subsystem (fresh territory)

Source: extracted/files/u2_ngc_release_dvd.map
Collision: filename-based case-insensitive against src/matched/*.cpp
"""

import re
import sys
import json
from pathlib import Path
from collections import defaultdict

# Force UTF-8 output on Windows to avoid cp1252 emoji crashes
import io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding="utf-8")
sys.stderr = io.TextIOWrapper(sys.stderr.buffer, encoding="utf-8")

# ---------------------------------------------------------------------------
# Territory definitions: (obj_file_substrings, symbol_class_patterns)
# ---------------------------------------------------------------------------
TERRITORIES = {
    "eroom_goals_careers": {
        "objs": [
            "eorhouse.obj", "eroom.obj", "careers.obj", "goalunlock.obj",
            "house.obj", "neighborhood.obj", "simulator.obj", "skilllookup.obj",
            "e_rlevel.obj", "e_rleveltuning.obj", "e_rmodel.obj",
            "inlevel.obj", "houserecon.obj", "plumbbobmodel.obj",
            "rooms.obj", "simmodel.obj",
        ],
        "symbols": [
            "ERoom::", "ENeighborhood::", "EHouse::", "GoalUnlock::",
            "Careers::", "Skill::", "cSimulatorImpl::", "ERLevel::", "ERModel::",
            "House::", "Neighborhood::", "Simulator::", "SkillLookup::",
            "InLevel::", "HouseRecon::", "PlumbBobModel::", "Rooms::",
            "SimModel::",
        ],
    },
    "skin_movie_treetab": {
        "objs": [
            "skincompositor.obj", "e_movie.obj", "e_movieman.obj",
            "e_ngcmovie.obj", "e_rmovie.obj", "movieplayer.obj",
            "treetab.obj", "treetablequickdata.obj",
            "e_istaticmodel.obj", "e_istaticsubmodel.obj",
            "e_modelman.obj", "e_rmodel.obj", "e_submodel.obj",
        ],
        "symbols": [
            "SkinCompositor::", "EMovie::", "EMovieMan::",
            "TreeTable::", "TTabScratchEntry::", "TreeTableAdScratch::",
            "TreeTableEntry::", "EIStaticModel::", "EISubModel::",
            "MoviePlayer::", "ERModel::", "ESubModel::",
        ],
    },
    "audio_sound": {
        "objs": [
            "ambientscoreplayer.obj", "ambientsoundplayer.obj",
            "ambientsound_test.obj", "audioinfo.obj", "e_ngcaudio.obj",
            "e_ngcaudiosampleman.obj", "e_ngcraudiosample.obj",
            "e_audiosampleman.obj", "e_audiostreamman.obj",
            "e_rambientscore.obj", "e_rsoundevent.obj",
            "e_rsoundtrackdata.obj", "e_soundeventman.obj",
            "e_soundtrackdataman.obj", "gamesound.obj",
            "soundinfo.obj", "uiaudio.obj",
        ],
        "symbols": [
            "AmbientScorePlayer::", "AmbientSoundPlayer::",
            "EAudioStreamMan::", "EAmbientScoreMan::",
            "ESoundEventMan::", "ESoundtrackDataMan::",
            "GameSound::", "UIAUDIO::", "AudioInfo::", "SoundInfo::",
            "EAudiostreamMan::", "ERAmbientScore::", "ERSoundEvent::",
            "ERSoundtrackData::", "EAudioSampleMan::", "ENgcAudio::",
        ],
    },
}

SYMBOL_LINE = re.compile(r"^([0-9a-fA-F]{8})\s+([0-9a-fA-F]{8})\s+\d+(\s+)(\S.*?)\s*$")

TEXT_END = 0x803CA900
SDK_ZONE_START = 0x80240000
SDK_ZONE_END   = 0x80390000


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


def is_territory_obj(line: str, obj_patterns: list) -> str:
    low = line.lower()
    for pat in obj_patterns:
        if pat.lower() in low:
            parts = line.strip().replace("/", "\\").split("\\")
            if parts:
                return parts[-1].replace(".obj", "").replace(")", "")
    return None


def is_territory_symbol(symbol: str, sym_patterns: list) -> bool:
    for cls in sym_patterns:
        if cls.lower() in symbol.lower():
            return True
    return False


def is_excluded_symbol(symbol: str) -> bool:
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
    if "pop_heap" in low or "void partial_sort" in low:
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
    if "virtual table" in symbol.lower() or "vtable" in symbol.lower():
        return True
    return False


def priority_marker(size: int) -> str:
    if size <= 32:
        return "[LOW]"
    elif size <= 48:
        return "[MED]"
    elif size <= 128:
        return "[HIGH]"
    else:
        return "[BIG]"


def scan_territory(territory_name: str, size_min=0x10, size_max=0x200):
    root = Path(__file__).resolve().parent.parent
    map_path = root / "extracted" / "files" / "u2_ngc_release_dvd.map"
    matched_root = root / "src" / "matched"
    config = TERRITORIES[territory_name]

    print(f"\n{'='*60}")
    print(f"[*] Territory: {territory_name}")
    print(f"[*] Map:     {map_path}")
    print(f"[*] Matched: {matched_root}")

    print("[*] Indexing matched filenames...")
    index = build_matched_index(matched_root)
    print(f"[*] Indexed {len(index)} unique hex runs from matched files")

    print(f"[*] Size window: 0x{size_min:x}-0x{size_max:x} ({size_min}-{size_max}B)")

    candidates = []
    skipped_collision = 0
    skipped_sdk = 0
    skipped_excluded = 0
    current_obj = None

    with open(map_path, "r", encoding="utf-8", errors="ignore") as f:
        for line in f:
            if ".obj" in line.lower() or ".a(" in line.lower():
                current_obj = is_territory_obj(line, config["objs"])
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

            is_target = current_obj is not None or is_territory_symbol(symbol, config["symbols"])
            if not is_target:
                continue

            if is_excluded_symbol(symbol):
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

    print(f"\n[RESULTS] {len(candidates)} unmatched candidates")
    print(f"  Skipped collisions: {skipped_collision}")
    print(f"  Skipped SDK zone:   {skipped_sdk}")
    print(f"  Skipped excluded:   {skipped_excluded}")

    by_size = defaultdict(list)
    for c in candidates:
        by_size[c["size"]].append(c)

    for size in sorted(by_size):
        rows = by_size[size]
        marker = priority_marker(size)
        print(f"\n---- {marker} {size:3d}B ({len(rows)} targets) ----")
        for c in rows[:15]:
            print(f"  0x{c['addr']:08X} {c['size']:3d}B  {c['symbol'][:80]}")
        if len(rows) > 15:
            print(f"  ... and {len(rows) - 15} more")

    return candidates


def generate_batches(candidates: list, territory_name: str, batch_size: int = 20):
    """Generate batch markdown files under build/scout_batches_s14/."""
    root = Path(__file__).resolve().parent.parent
    out_dir = root / "build" / "scout_batches_s14" / territory_name
    out_dir.mkdir(parents=True, exist_ok=True)

    # Sort by size ascending (smaller = easier)
    candidates = sorted(candidates, key=lambda c: (c["size"], c["addr"]))

    batch_files = []
    for i in range(0, len(candidates), batch_size):
        batch = candidates[i:i + batch_size]
        batch_num = i // batch_size + 1
        path = out_dir / f"batch_{batch_num:02d}_{territory_name}.md"

        lines = [
            f"# S14 Scout Batch {batch_num} — {territory_name}",
            "",
            f"**Map:** extracted/files/u2_ngc_release_dvd.map",
            f"**Territory:** {territory_name}",
            f"**Batch size:** {len(batch)} targets",
            "",
            "| Marker | Address | Size | Symbol |",
            "|--------|---------|------|--------|",
        ]
        for c in batch:
            marker = priority_marker(c["size"])
            sym = c["symbol"].replace("|", "\\|")[:100]
            lines.append(f"| {marker} | 0x{c['addr']:08X} | {c['size']}B | {sym} |")

        lines.append("")
        lines.append("---")
        lines.append("*Generated by tools/scan_s14_territories.py*")

        with open(path, "w", encoding="utf-8") as f:
            f.write("\n".join(lines))
        batch_files.append(path)

    print(f"\n[*] Wrote {len(batch_files)} batch files to {out_dir}")
    return batch_files


def main():
    all_candidates = {}
    total = 0

    for territory in TERRITORIES:
        size_max = 0x200 if territory == "audio_sound" else 0x300
        cands = scan_territory(territory, size_min=0x10, size_max=size_max)
        all_candidates[territory] = cands
        total += len(cands)
        if cands:
            generate_batches(cands, territory)

    print(f"\n{'='*60}")
    print(f"TOTAL unmatched across all S14 territories: {total}")
    for t, cands in all_candidates.items():
        print(f"  {t}: {len(cands)}")

    # Save JSON for programmatic access
    root = Path(__file__).resolve().parent.parent
    json_path = root / "build" / "scout_batches_s14" / "s14_candidates.json"
    with open(json_path, "w", encoding="utf-8") as f:
        json.dump({t: [{k: v for k, v in c.items() if k != "obj"} for c in cs] for t, cs in all_candidates.items()}, f, indent=2)
    print(f"[*] Saved JSON summary to {json_path}")


if __name__ == "__main__":
    main()
