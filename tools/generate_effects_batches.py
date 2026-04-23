#!/usr/bin/env python3
"""Batch generator for effects/animation/BBI scout candidates."""
import re
import os
import sys
from pathlib import Path

BATCH_SIZE = 20
OUT_DIR = Path("build/scout_batches_effects")

def marker(size):
    if size <= 32: return "🟢"
    if size <= 48: return "🟡"
    if size <= 64: return "🔴"
    return "⚫"

def family(sym):
    if sym.startswith("SAnimator2"): return "SAnimator2"
    if sym.startswith("BBI::Inventory"): return "BBI_Inventory"
    if "FrameEffects" in sym or sym.startswith("Handle") and "Event" in sym or sym.startswith("Override"): return "FrameEffects"
    if "Bloom" in sym or "MotionBlur" in sym or "DepthOfField" in sym: return "PostProcess"
    if "EParticle" in sym or "Effects" in sym or "Particle" in sym: return "Effects"
    if "SkinCompositor" in sym: return "SkinCompositor"
    if "RainEffect" in sym or "Weather" in sym: return "Weather"
    if "AnimTable" in sym or "AnimRef" in sym or "EAnim" in sym or "ERAnim" in sym: return "Animation"
    if "IngredientManager" in sym or "Ingredient" in sym: return "Ingredients"
    if "EIStaticModel" in sym: return "EIStaticModel"
    return "Other"

def parse_candidates(text):
    cands = []
    for line in text.splitlines():
        m = re.match(r'\s+0x([0-9A-Fa-f]+)\s+(\d+)B\s+(.+)', line)
        if m:
            cands.append({
                'addr': m.group(1),
                'size': int(m.group(2)),
                'sym': m.group(3).strip()
            })
    return cands

def main():
    text = sys.stdin.read()
    cands = parse_candidates(text)
    if not cands:
        print("No candidates parsed", file=sys.stderr)
        sys.exit(1)

    # Group by family
    families = {}
    for c in cands:
        fam = family(c['sym'])
        families.setdefault(fam, []).append(c)

    OUT_DIR.mkdir(parents=True, exist_ok=True)

    batch_num = 1
    total = 0
    for fam, items in sorted(families.items()):
        items.sort(key=lambda x: x['size'])
        for i in range(0, len(items), BATCH_SIZE):
            batch = items[i:i+BATCH_SIZE]
            path = OUT_DIR / f"effects_batch_{batch_num:02d}_{fam}.md"
            with open(path, "w", encoding="utf-8") as f:
                f.write(f"# Batch {batch_num}: {fam} — {len(batch)} targets\n")
                f.write(f"Tags: `scout`, `effects`, `s{batch_num}`\n\n")
                for c in batch:
                    f.write(f"- `{c['addr']}` {marker(c['size'])} `{c['sym']}` ({c['size']}B)\n")
            total += len(batch)
            batch_num += 1

    print(f"Generated {batch_num-1} batches covering {total} targets in {OUT_DIR}")

if __name__ == "__main__":
    main()
