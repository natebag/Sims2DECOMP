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
          which: first   # or "all", or integer N (0-indexed pair index)

"which" defaults to "first" — deterministic, reproducible. "all" is still
deterministic (left-to-right, non-overlapping) but catches multi-site cases.
Integer `which=N` selects the N-th non-overlapping matched pair (N=0 is the
first, equivalent to "first"; N=1 the second; etc.) — use when there are
3+ adjacent same-opcode lines forming overlapping pairs and you need to
target a middle/late pair while preserving an earlier one.

Aliases: "first" == 0. "last" == -1 (selects the last pair in the walk).
"""
from __future__ import annotations

import re
from typing import Iterable

from . import NoApplicableSite

NAME = "swap_adj"

# Match an instruction line: leading whitespace + opcode + rest.
# Allows . suffix (record forms like andi., cmpw.) and numeric/dot suffixes.
_INSN_RE = re.compile(r"^(?P<indent>[ \t]*)(?P<op>[A-Za-z_][A-Za-z0-9._]*)(?=\s|$)(?P<rest>.*)$")


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


def _non_overlapping_walk(hits: list[int]) -> list[int]:
    """Left-to-right walk picking pairs that don't share a line with a prior pick."""
    walked: list[int] = []
    i = 0
    while i < len(hits):
        walked.append(hits[i])
        # Skip any hit that overlaps the one we just consumed.
        j = i + 1
        while j < len(hits) and hits[j] <= hits[i] + 1:
            j += 1
        i = j
    return walked


def _parse_which(which) -> tuple[str, int]:
    """Return (mode, index) where mode is 'all', 'index'.

    Accepts:
      - "all" → ("all", -1) — sentinel index unused
      - "first" → ("index", 0)
      - "last"  → ("index", -1) — last element of the walk
      - integer N or numeric string → ("index", N)
    Raises ValueError on anything else.
    """
    if isinstance(which, int) and not isinstance(which, bool):
        return ("index", which)
    if isinstance(which, str):
        s = which.strip().lower()
        if s == "all":
            return ("all", -1)
        if s == "first":
            return ("index", 0)
        if s == "last":
            return ("index", -1)
        try:
            return ("index", int(s))
        except ValueError:
            pass
    raise ValueError(
        f"swap_adj: which must be 'first', 'all', 'last', or integer (got {which!r})"
    )


def apply(asm_text: str, args: dict) -> str:
    op_a = args.get("a")
    op_b = args.get("b")
    which_arg = args.get("which", "first")
    if not op_a or not op_b:
        raise ValueError("swap_adj requires args: a=<opcode>, b=<opcode>")
    mode, n = _parse_which(which_arg)

    lines = asm_text.splitlines(keepends=True)
    hits = list(_find_pairs(lines, op_a, op_b))
    if not hits:
        raise NoApplicableSite(f"no adjacent {op_a}/{op_b} pair in asm")

    if mode == "all":
        # 'all' mode preserves prior semantics: non-overlapping walk so we
        # don't swap a pair twice when 3+ same-opcode lines run together.
        targets = _non_overlapping_walk(hits)
    else:
        # Mode 'index': N indexes the RAW hits list (every adjacent pair,
        # including overlapping ones). Caller is responsible for picking a
        # non-overlapping site OR for sequencing multiple swap_adj calls
        # whose effects don't interfere.
        if not hits:
            raise NoApplicableSite(
                f"swap_adj: no {op_a}/{op_b} adjacent pair available"
            )
        try:
            targets = [hits[n]]
        except IndexError:
            raise NoApplicableSite(
                f"swap_adj: which={which_arg} out of range (only "
                f"{len(hits)} {op_a}/{op_b} adjacent pair(s))"
            ) from None

    for idx in targets:
        lines[idx], lines[idx + 1] = lines[idx + 1], lines[idx]
    return "".join(lines)
