"""remove_mr — delete a `mr` instruction at a marker, with optional bounded
register relabel applied to subsequent lines.

Use case (inverse of insert_mr): GCC's allocator emits a register-rename
`mr` that the DOL does NOT contain, e.g. GCC picks `mr r0,r3 ; ...; lwz r4,0(r0)`
where SN's allocator picked `lwz r4,0(r3)` directly. The natural source
shape can't suppress the rename — GCC's RA cost model decides to free
the register. We delete the spurious `mr` post-compile so the byte stream
matches.

Manifest example (or directive in source):

    pipeline:
      - mutator: remove_mr
        args:
          match: "mr 0,3"            # substring of the `mr` line to delete
          occurrence: 0              # 0 = first matching line (default)
          # Optional safety: assert the matched line's opcode equals this.
          # Default 'mr'. Set to '' (empty) to disable the check.
          assert_op: "mr"
          # Optional one-way relabel applied to lines AFTER the deletion
          # until the function terminator (`blr` by default) or `until` match.
          relabel: "0:3"             # comma-separated from:to one-way swaps
          # until: "blr"             # optional; defaults to first blr after the deletion

Directive form in source (one line):

    // ASMPROC_remove_mr: match=mr 0,3 relabel=0:3

NOTE: relabel here is ONE-WAY (matches insert_mr semantics). Order of pairs
matters; they are applied left-to-right per operand token, but in the
canonical use-case the pairs do not chain (e.g., 0:3 and 11:0 are applied
to disjoint registers within a single line so polarity is preserved).

The `match` substring is matched against entire lines (substring containment,
same as insert_mr / nop_before / swap_operands). To avoid accidentally
deleting a non-`mr` line that happens to contain the substring text
(e.g., a comment containing "mr 0,3"), the assert_op safety check verifies
the matched line's opcode before deletion.
"""
from __future__ import annotations

import re

from . import NoApplicableSite
from .insert_mr import _opcode, _parse_relabel, _relabel_line

NAME = "remove_mr"


def apply(asm_text: str, args: dict) -> str:
    needle = args.get("match")
    if not needle:
        raise ValueError("remove_mr requires arg: match=<substring>")
    occurrence = int(args.get("occurrence", 0))
    assert_op = args.get("assert_op", "mr")
    if assert_op is not None:
        assert_op = str(assert_op).strip().lower() or None

    relabel_spec = args.get("relabel", "")
    relabel_pairs = _parse_relabel(relabel_spec) if relabel_spec else []
    relabel_map: dict[int, int] = dict(relabel_pairs)

    until_match = args.get("until")  # optional substring; default = first 'blr' after deletion

    lines = asm_text.splitlines(keepends=True)
    hits = [i for i, line in enumerate(lines) if needle in line]
    if not hits:
        raise NoApplicableSite(f"remove_mr: no .s line contains {needle!r}")
    if occurrence >= len(hits):
        raise NoApplicableSite(
            f"remove_mr: requested occurrence {occurrence} but only {len(hits)} match {needle!r}"
        )
    target_idx = hits[occurrence]

    if assert_op is not None:
        actual_op = _opcode(lines[target_idx])
        if actual_op is None or actual_op.lower() != assert_op:
            raise NoApplicableSite(
                f"remove_mr: line {target_idx+1} matched {needle!r} but opcode is "
                f"{actual_op!r}, expected {assert_op!r} (set assert_op='' to disable)"
            )

    # Delete the line.
    new_lines = lines[:target_idx] + lines[target_idx + 1:]

    # Apply optional relabel to lines from the deletion point onward until terminator.
    # The deleted line's old index is now the index of the line that followed it.
    if relabel_map:
        terminator_idx = len(new_lines)
        for j in range(target_idx, len(new_lines)):
            line = new_lines[j]
            if until_match:
                if until_match in line:
                    terminator_idx = j  # exclusive
                    break
            else:
                op = _opcode(line)
                if op == "blr":
                    terminator_idx = j + 1  # include the blr line
                    break
        for j in range(target_idx, terminator_idx):
            new_lines[j] = _relabel_line(new_lines[j], relabel_map)

    return "".join(new_lines)
