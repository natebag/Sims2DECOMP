"""swap_adj — swap adjacent .s lines whose opcodes match the given pair.

Use case: Category 1 walls (lfs-vs-andi hoist, fcmpu-vs-stfs swap, scheduler
2-insn-pair order). The SN compiler emits two semantically-interchangeable
instructions in the wrong order; this mutator flips them.

Manifest example:

    pipeline:
      - mutator: swap_adj
        args:
          a: lfs
          b: andi.
          which: first   # or "all" to swap every adj pair that matches

"which" defaults to "first" — deterministic, reproducible. "all" is still
deterministic (left-to-right, non-overlapping) but catches multi-site cases.
"""
from __future__ import annotations

import re
from typing import Iterable

from . import NoApplicableSite

NAME = "swap_adj"

# Match an instruction line: leading whitespace + opcode + rest.
# Allows . suffix (record forms like andi., cmpw.) and numeric/dot suffixes.
_INSN_RE = re.compile(r"^(?P<indent>[ \t]*)(?P<op>[A-Za-z_][A-Za-z0-9._]*)\b(?P<rest>.*)$")


def _opcode(line: str) -> str | None:
    """Return the opcode of a .s instruction line, or None for blanks/labels/directives."""
    stripped = line.strip()
    if not stripped or stripped.startswith((";", "#", "/*", "//")):
        return None
    if stripped.endswith(":"):
        return None
    if stripped.startswith("."):
        return None
    m = _INSN_RE.match(line)
    return m.group("op") if m else None


def _find_pairs(asm_lines: list[str], op_a: str, op_b: str) -> Iterable[int]:
    """Yield indices i where lines[i] has opcode op_a and lines[i+1] has op_b."""
    for i in range(len(asm_lines) - 1):
        if _opcode(asm_lines[i]) == op_a and _opcode(asm_lines[i + 1]) == op_b:
            yield i


def apply(asm_text: str, args: dict) -> str:
    op_a = args.get("a")
    op_b = args.get("b")
    which = args.get("which", "first")
    if not op_a or not op_b:
        raise ValueError("swap_adj requires args: a=<opcode>, b=<opcode>")
    if which not in ("first", "all"):
        raise ValueError(f"swap_adj: which must be 'first' or 'all' (got {which!r})")

    lines = asm_text.splitlines(keepends=True)
    hits = list(_find_pairs(lines, op_a, op_b))
    if not hits:
        raise NoApplicableSite(f"no adjacent {op_a}/{op_b} pair in asm")

    if which == "first":
        targets = [hits[0]]
    else:
        # Non-overlapping left-to-right walk so we don't swap a pair twice.
        targets = []
        i = 0
        while i < len(hits):
            targets.append(hits[i])
            # Skip any hit that overlaps the one we just consumed.
            j = i + 1
            while j < len(hits) and hits[j] <= hits[i] + 1:
                j += 1
            i = j

    for idx in targets:
        lines[idx], lines[idx + 1] = lines[idx + 1], lines[idx]
    return "".join(lines)
