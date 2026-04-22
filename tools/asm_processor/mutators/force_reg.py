"""force_reg — substitute one register name on an .s line that matches a predicate.

Use case: Category 2 walls (FP-coloring f0↔f13, r11/r3 base-alias, multi-zero-reg
ctor). The compiler picks the wrong register for a load/store/move; the DOL wants
a different one. This mutator rewrites a single register operand, leaving every
other `from_reg` reference intact.

Manifest example:

    pipeline:
      - mutator: force_reg
        args:
          match: "lfs f0,"            # substring that selects the line
          from_reg: f0
          to_reg: f13
          occurrence: 0               # 0 = first matching line (default)

Only rewrites the operand field (after the opcode). `from_reg` is matched with
a word-boundary so `r1` doesn't clobber `r10`/`r11`/`r12`.
"""
from __future__ import annotations

import re
from typing import Iterable

from . import NoApplicableSite

NAME = "force_reg"


def _find_matching_lines(lines: list[str], needle: str) -> Iterable[int]:
    for i, line in enumerate(lines):
        if needle in line:
            yield i


def _substitute_register_operand(line: str, from_reg: str, to_reg: str) -> str:
    """Rewrite `from_reg` to `to_reg` in the operand portion of a .s line.

    Leading opcode stays untouched (avoids rewriting e.g. `f0` inside an opcode).
    Uses a word-boundary regex on the operand tail so `r1` does not match `r10`.
    Preserves any trailing newline the caller's line had.
    """
    newline = ""
    body = line
    if body.endswith("\r\n"):
        newline = "\r\n"
        body = body[:-2]
    elif body.endswith("\n"):
        newline = "\n"
        body = body[:-1]
    m = re.match(r"^(?P<head>\s*\S+\s+)(?P<tail>.*)$", body)
    if not m:
        return line
    head = m.group("head")
    tail = m.group("tail")
    pat = re.compile(rf"\b{re.escape(from_reg)}\b")
    if not pat.search(tail):
        return line
    return head + pat.sub(to_reg, tail) + newline


def apply(asm_text: str, args: dict) -> str:
    needle = args.get("match")
    from_reg = args.get("from_reg")
    to_reg = args.get("to_reg")
    occurrence = int(args.get("occurrence", 0))
    if not (needle and from_reg and to_reg):
        raise ValueError("force_reg requires args: match, from_reg, to_reg")

    lines = asm_text.splitlines(keepends=True)
    hits = list(_find_matching_lines(lines, needle))
    if not hits:
        raise NoApplicableSite(f"no .s line contains {needle!r}")
    if occurrence >= len(hits):
        raise NoApplicableSite(
            f"requested occurrence {occurrence} but only {len(hits)} match {needle!r}"
        )

    idx = hits[occurrence]
    new_line = _substitute_register_operand(lines[idx], from_reg, to_reg)
    if new_line == lines[idx]:
        raise NoApplicableSite(
            f"line {idx!r} matched {needle!r} but did not contain register {from_reg!r}"
        )
    lines[idx] = new_line
    return "".join(lines)
