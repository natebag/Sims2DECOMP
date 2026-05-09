#!/usr/bin/env python3
"""
Scan unmatched DOL functions for NaN-coax sibling candidates.

Signature: fcmpu (FC..0000) followed by bnglr/bgelr (4c810020) WITHOUT
intervening cror (4c4..382 family). Indicates source originally written
as `!(a > b)` style — solvable by single-instruction `!(>)` recipe.

Also catches: fcmpu + cror so,eq,lt + bsolr — the NaN-strict tell where
source was `<=` and we can rewrite as `!(>)` to match.
"""

import re
import struct
import sys
from pathlib import Path

DOL_PATH = Path("extracted/sys/main.dol")
UNMATCHED_LIST = Path("tools/unmatched_64_128b_real.txt")

# DOL header: 7 text segments, 11 data segments
def load_dol_text():
    data = DOL_PATH.read_bytes()
    segments = []
    for i in range(18):
        offset = struct.unpack(">I", data[i*4:i*4+4])[0]
        addr = struct.unpack(">I", data[0x48 + i*4:0x48 + i*4 + 4])[0]
        size = struct.unpack(">I", data[0x90 + i*4:0x90 + i*4 + 4])[0]
        if size > 0 and offset > 0:
            segments.append((addr, addr+size, offset, data[offset:offset+size]))
    return segments

def get_func_bytes(segments, addr, size):
    for start, end, offset, blob in segments:
        if start <= addr < end:
            o = addr - start
            return blob[o:o+size]
    return None

def scan_func(addr, size, blob):
    """Return list of NaN-coax indicators found."""
    if not blob or len(blob) < 8:
        return []
    insns = []
    for i in range(0, len(blob), 4):
        if i + 4 > len(blob):
            break
        insns.append((i, struct.unpack(">I", blob[i:i+4])[0]))

    findings = []
    for idx, (pc, w) in enumerate(insns):
        # fcmpu cr0..7,fA,fB: opcode=63, xo=0, rc=0
        # mask: 0xFC60_07FF (allow any BF/FRA/FRB; require opcode+xo+rc)
        # match: 0xFC00_0000
        if (w & 0xFC60_07FF) == 0xFC00_0000:
            # check next 1-2 instructions
            if idx + 1 < len(insns):
                _, nxt = insns[idx + 1]
                # bnglr: 4c810020 (BO=4, BI=1)
                # bgelr: 4c800020 (BO=4, BI=0)
                # blelr: 4c810020 also (same encoding as bnglr)
                # bgtlr: 4cc10020 (BO=12, BI=1)
                # bltlr: 4cc00020 (BO=12, BI=0)
                if nxt == 0x4c810020:
                    # NaN-loose tell: bnglr without cror -> source was !(a > b)
                    findings.append((pc, "fcmpu+bnglr (NaN-loose: source was !(>))"))
                elif nxt == 0x4c800020:
                    findings.append((pc, "fcmpu+bgelr (NaN-loose: source was !(<))"))
                elif (nxt & 0xFC1F_FFFE) == 0x4C00_0382:
                    # cror — NaN-strict tell
                    if idx + 2 < len(insns):
                        _, nxt2 = insns[idx + 2]
                        if nxt2 in (0x4d810020, 0x4d800020, 0x4d830020,
                                    0x4c810020, 0x4c800020):
                            findings.append((pc, "fcmpu+cror+bso* (NaN-strict <=/>=)"))
                # ble/bge with full conditional branch (not lr): 4081/4080
                elif (nxt & 0xFFFF_0003) == 0x4081_0000 or \
                     (nxt & 0xFFFF_0003) == 0x4080_0000:
                    findings.append((pc, "fcmpu+ble/bge cond branch"))
    return findings

def parse_unmatched():
    """Return list of (addr_int, size, name)."""
    targets = []
    pat = re.compile(r"^\s+(0x[0-9a-fA-F]+)\s+(\d+)B\s+(.+)$")
    for line in UNMATCHED_LIST.read_text().splitlines():
        m = pat.match(line)
        if m:
            targets.append((int(m.group(1), 16), int(m.group(2)), m.group(3).strip()))
    return targets

def main():
    segments = load_dol_text()
    targets = parse_unmatched()
    print(f"# Scanning {len(targets)} unmatched 64-128B functions for NaN-coax patterns")
    print(f"# DOL segments: {len(segments)}")
    hits = []
    for addr, size, name in targets:
        blob = get_func_bytes(segments, addr, size)
        if blob is None:
            continue
        f = scan_func(addr, size, blob)
        if f:
            hits.append((addr, size, name, f))
    print(f"# Found {len(hits)} candidates\n")
    by_kind = {}
    for addr, size, name, findings in hits:
        for pc, kind in findings:
            by_kind.setdefault(kind, []).append((addr, size, name, pc))
    for kind, items in by_kind.items():
        print(f"\n=== {kind} ({len(items)} hits) ===")
        for addr, size, name, pc in items[:30]:
            print(f"  0x{addr:08x}+0x{pc:02x}  {size:4}B  {name}")
        if len(items) > 30:
            print(f"  ... and {len(items)-30} more")

if __name__ == "__main__":
    main()
