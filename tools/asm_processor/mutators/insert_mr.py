"""insert_mr — insert a `mr` instruction at a marker, with optional bounded
register relabel applied to subsequent lines.

Use case: Category 3 walls where the DOL inserts a register-rename `mr` to
free up a register for a later use (e.g., InvalidateRoutes inserts
`mr r3,r11` after the precheck so that r11 can be reused as the zero-store
constant in the loop body). GCC's allocator declines to emit this rename
from any natural source structure, so we synthesize it post-compile.

Manifest example (or directive in source):

    pipeline:
      - mutator: insert_mr
        args:
          after: "beqlr"             # substring of the line BEFORE insertion
          src: 11                    # source register (rN or bare N)
          dst: 3                     # destination register
          occurrence: 0              # 0 = first matching line (default)
          # Optional: one-way relabel applied to lines AFTER the inserted mr
          # until the function terminator (`blr` by default) or `until` match.
          relabel: "10:11,11:3"      # comma-separated from:to one-way swaps
          # until: "blr"             # optional; defaults to first blr after the insertion

Directive form in source (one line):

    // ASMPROC_insert_mr: after=beqlr src=11 dst=3 relabel=10:11,11:3

NOTE: relabel here is ONE-WAY (not the bidirectional pair used by
gpr_relabel). Order of pairs matters; they are applied left-to-right per
operand token, but in the canonical use-case the pairs do not chain
(e.g., 10:11 and 11:3 are applied to disjoint registers within a single
line so polarity is preserved).

Inserted line uses bare-numeric SN cc1plus syntax: `mr <dst>, <src>`.
"""
from __future__ import annotations

import re

from . import NoApplicableSite
from ._helpers import (
    find_anchor_index,
    find_terminator,
    norm_reg,
    parse_relabel,
    relabel_line,
)

NAME = "insert_mr"


def apply(asm_text: str, args: dict) -> str:
    after = args.get("after")
    before = args.get("before")
    if not after and not before:
        raise ValueError("insert_mr requires arg: after=<match> OR before=<match>")
    if after and before:
        raise ValueError("insert_mr: specify only one of after/before, not both")
    src_arg = args.get("src")
    dst_arg = args.get("dst")
    if src_arg is None or dst_arg is None:
        raise ValueError("insert_mr requires args: src=<reg> dst=<reg>")
    try:
        src = norm_reg(str(src_arg))
        dst = norm_reg(str(dst_arg))
    except ValueError as e:
        raise ValueError(f"insert_mr: {e}") from None
    if src == dst:
        raise ValueError("insert_mr: src and dst must differ")
    occurrence = int(args.get("occurrence", 0))

    relabel_spec = args.get("relabel", "")
    relabel_pairs = parse_relabel(relabel_spec) if relabel_spec else []
    relabel_map: dict[int, int] = dict(relabel_pairs)

    until_match = args.get("until")  # optional; default = first 'blr' after insertion

    lines = asm_text.splitlines(keepends=True)
    anchor_idx, insert_offset = find_anchor_index(
        lines, after, before, occurrence, label="insert_mr"
    )

    anchor_line = lines[anchor_idx]
    indent_match = re.match(r"^([ \t]*)", anchor_line)
    indent = indent_match.group(1) if indent_match else "\t"
    mr_line = f"{indent}mr {dst},{src}\n"

    insert_idx = anchor_idx + insert_offset
    new_lines = lines[:insert_idx] + [mr_line] + lines[insert_idx:]

    if relabel_map:
        terminator_idx = find_terminator(
            new_lines, insert_idx + 1, until_match, include_blr_line=True
        )
        for j in range(insert_idx + 1, terminator_idx):
            new_lines[j] = relabel_line(new_lines[j], relabel_map)

    return "".join(new_lines)
