"""swap_operands — transpose two operand positions on a matched .s line.

Use case: instructions whose semantics are commutative across two operand
positions but whose byte encoding differs based on operand order. The most
common cases on PowerPC:

  - `add rD, rA, rB`        (rA and rB are commutative; encoding is asymmetric)
  - `or  rD, rA, rB`        (same)
  - `xor rD, rA, rB`        (same)
  - `and rD, rA, rB`        (same)
  - `stwx rS, rA, rB`       (rA and rB form base+index; semantically same
                             memory location but encoded asymmetrically)

GCC's allocator picks one ordering (e.g. `add r9, r11, r9`) while the DOL
emits the other (`add r9, r9, r0` post register-relabel). gpr_relabel can
fix the register names but NOT the operand POSITIONS — that's what this
mutator is for.

Manifest example (or directive in source):

    pipeline:
      - mutator: swap_operands
        args:
          match: "stwx 7,11,"        # substring that selects the line
          pos: "1,2"                 # 0-indexed operand positions to swap
          occurrence: 0              # 0 = first matching line (default)

Directive form in source (one line):

    // ASMPROC_swap_operands: match=stwx 7,11, pos=1,2

Operand positions are 0-indexed across the operand list (NOT including the
opcode). For `stwx r7, r11, r0`: pos 0 = r7, pos 1 = r11, pos 2 = r0.

This mutator does NOT validate semantic commutativity — the caller is
responsible for choosing a swap that preserves function behavior. Common
safe swaps: rA<->rB on add/or/xor/and/stwx/lwzx/stbx/lbzx/sthx/lhzx/lhax.
NEVER swap on subf/sub/divw/mulli/mullw — those are non-commutative.
"""
from __future__ import annotations

from . import NoApplicableSite

NAME = "swap_operands"


def _split_line(line: str) -> tuple[str, str, str, str]:
    """Split a .s line into (leading_ws, opcode, operand_body, trailing_with_newline).

    Operand_body is the comma-joined operand list as raw text (no leading ws).
    Trailing carries any comment/eol whitespace + newline.
    """
    newline = ""
    body = line
    if body.endswith("\r\n"):
        newline = "\r\n"
        body = body[:-2]
    elif body.endswith("\n"):
        newline = "\n"
        body = body[:-1]
    # Find leading whitespace
    i = 0
    while i < len(body) and body[i] in " \t":
        i += 1
    leading = body[:i]
    rest = body[i:]
    # Find opcode (until first whitespace)
    j = 0
    while j < len(rest) and rest[j] not in " \t":
        j += 1
    opcode = rest[:j]
    operands_with_comment = rest[j:].lstrip()
    # Strip trailing comment if present (preserve as part of trailing)
    # Comments start with # or ; for cc1plus PowerPC asm.
    comment_idx = -1
    in_quotes = False
    for k, ch in enumerate(operands_with_comment):
        if ch == '"':
            in_quotes = not in_quotes
        elif not in_quotes and ch in "#;":
            comment_idx = k
            break
    if comment_idx >= 0:
        operand_body = operands_with_comment[:comment_idx].rstrip()
        trailing = operands_with_comment[comment_idx:]
    else:
        operand_body = operands_with_comment.rstrip()
        trailing = operands_with_comment[len(operand_body):]
    return leading, opcode, operand_body, trailing + newline


def _split_operands(operand_body: str) -> list[str]:
    if not operand_body:
        return []
    return [op.strip() for op in operand_body.split(",")]


def _build_line(leading: str, opcode: str, operands: list[str], trailing: str) -> str:
    if not operands:
        return f"{leading}{opcode}{trailing}"
    return f"{leading}{opcode} {','.join(operands)}{trailing}"


def apply(asm_text: str, args: dict) -> str:
    needle = args.get("match")
    pos_arg = args.get("pos")
    occurrence = int(args.get("occurrence", 0))
    if not needle or not pos_arg:
        raise ValueError("swap_operands requires args: match, pos (e.g. pos=1,2)")
    pos_parts = [p.strip() for p in str(pos_arg).split(",") if p.strip()]
    if len(pos_parts) != 2:
        raise ValueError(f"swap_operands: pos must be 2 indices (got {pos_arg!r})")
    try:
        i, j = int(pos_parts[0]), int(pos_parts[1])
    except ValueError:
        raise ValueError(f"swap_operands: non-numeric pos {pos_arg!r}") from None
    if i == j:
        raise ValueError("swap_operands: pos indices must differ")
    if i < 0 or j < 0:
        raise ValueError(f"swap_operands: pos indices must be non-negative (got {i},{j})")

    lines = asm_text.splitlines(keepends=True)
    hits = [k for k, line in enumerate(lines) if needle in line]
    if not hits:
        raise NoApplicableSite(f"swap_operands: no .s line contains {needle!r}")
    if occurrence >= len(hits):
        raise NoApplicableSite(
            f"swap_operands: requested occurrence {occurrence} but only {len(hits)} match {needle!r}"
        )

    idx = hits[occurrence]
    leading, opcode, operand_body, trailing = _split_line(lines[idx])
    operands = _split_operands(operand_body)
    if max(i, j) >= len(operands):
        raise NoApplicableSite(
            f"swap_operands: line has {len(operands)} operands but pos requires index {max(i,j)}"
        )
    operands[i], operands[j] = operands[j], operands[i]
    lines[idx] = _build_line(leading, opcode, operands, trailing)
    return "".join(lines)
