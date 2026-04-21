"""nop_before — insert a `nop` before the first .s line matching a predicate.

Experimental: used to emulate a scheduler fence when we suspect GCC hoisted an
instruction ahead of where the DOL wants it. OpusWorker may deprecate this
once the real SWAP_ADJ flow covers those cases.

Manifest example:

    pipeline:
      - mutator: nop_before
        args:
          match: "lfs f1,"
          occurrence: 0
"""
from __future__ import annotations

from . import NoApplicableSite

NAME = "nop_before"


def apply(asm_text: str, args: dict) -> str:
    needle = args.get("match")
    occurrence = int(args.get("occurrence", 0))
    if not needle:
        raise ValueError("nop_before requires arg: match")

    lines = asm_text.splitlines(keepends=True)
    hits = [i for i, line in enumerate(lines) if needle in line]
    if not hits:
        raise NoApplicableSite(f"no .s line contains {needle!r}")
    if occurrence >= len(hits):
        raise NoApplicableSite(
            f"requested occurrence {occurrence} but only {len(hits)} match {needle!r}"
        )

    idx = hits[occurrence]
    # Preserve the same indent as the target line for cosmetics.
    indent = lines[idx][: len(lines[idx]) - len(lines[idx].lstrip())]
    lines.insert(idx, f"{indent}nop\n")
    return "".join(lines)
