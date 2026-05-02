"""force_reg_at_pos — rename a register at a SPECIFIC operand position on
a single .s line, leaving same-named registers at OTHER positions intact.

Use case (Track I queue #4, S13 session 4): Category 3 walls where a single
instruction needs an asymmetric register rename — the same logical register
appears at multiple operand positions on one line, and ONLY one of them
should change. Existing `force_reg` does whole-line `\\b<reg>\\b` rewrite,
which would clobber every position. `region_gpr_relabel` operates on
multi-instruction regions and applies its rename map uniformly across all
operand positions — also wrong shape for this case.

Canonical wall (FamilyImpl::RemoveMember @ 0x800B69D4, after insert_mr's
relabel cascade):

    cc1plus emits:    subf 0,11,0        ; rt=r0, rb=r11, ra=r0
    DOL needs:        subf 0,11,8        ; rt=r0, rb=r11, ra=r8

The `r0` at rt (pos 0) MUST stay; the `r0` at ra (pos 2) MUST become `r8`.
A whole-line `r0 → r8` rewrite would corrupt rt; a multi-line rename map
would over-apply. force_reg_at_pos targets ONE operand at ONE position on
ONE line.

Manifest example (or directive in source):

    pipeline:
      - mutator: force_reg_at_pos
        args:
          match: "subf 0,11,0"           # exact substring of the pre-mutation line
          pos: 2                          # 0-indexed comma-separated operand index
          from_reg: 0                     # register currently at that position
          to_reg: 8                       # register the position should become
          occurrence: 0                   # 0 = first matching line (default)

Directive form in source (one line):

    // ASMPROC_force_reg_at_pos: match="subf 0,11,0" pos=2 from_reg=0 to_reg=8

Operand position semantics:
- `pos=0` → first comma-separated operand after the opcode (typically rt for
  arith/load, rs for store)
- `pos=1` → second operand (typically rb / first source register)
- `pos=2` → third operand (typically ra / second source register or address base)
- For `lwz r3, 4(r9)` style: `pos=1` refers to the whole `4(r9)` operand;
  the from_reg/to_reg substitution is applied within that operand only,
  so renaming `r9 → r10` produces `4(r10)`.

Refusal modes (NoApplicableSite — runtime skip, harness records, doesn't fail):
- `match` substring not found in any line
- `occurrence` index out of range
- `pos` index out of range for the matched line's operand list
- Operand at `pos` does not contain `from_reg` (word-boundary match)

Author-error modes (ValueError — raised, surfaces during authoring):
- Missing required args (match / pos / from_reg / to_reg)
- `pos` not a non-negative integer
- `from_reg == to_reg` (no-op rename)
"""
from __future__ import annotations

import re

from . import NoApplicableSite
from ._helpers import _INSN_RE, norm_reg, opcode

NAME = "force_reg_at_pos"


def _split_with_indices(rest: str) -> list[tuple[int, int, str]]:
    """Split the post-opcode tail into (start, end, text) tuples for each
    comma-separated operand, preserving original column positions so the
    rewriter can reconstruct the line with the operand's surrounding whitespace
    intact. Trailing comments are stripped before splitting.

    Returns [] for blank tails. Whitespace-only operands (rare) become empty
    text but keep their position span.
    """
    body = rest
    if "#" in body:
        body = body.split("#", 1)[0]
    if ";" in body:
        body = body.split(";", 1)[0]
    operands: list[tuple[int, int, str]] = []
    pos = 0
    while pos < len(body):
        comma_idx = body.find(",", pos)
        if comma_idx < 0:
            chunk = body[pos:]
            text = chunk.strip()
            if text or operands:
                operands.append((pos, len(body), text))
            break
        chunk = body[pos:comma_idx]
        text = chunk.strip()
        operands.append((pos, comma_idx, text))
        pos = comma_idx + 1
    return operands


def _rewrite_operand(operand: str, from_reg: int, to_reg: int) -> str | None:
    """Substitute `from_reg` for `to_reg` inside ONE operand, preserving the
    optional `r` prefix per token. Returns None if `from_reg` does not appear
    in the operand at a word boundary.

    Handles bare-register (`9`, `r9`) and memory-form (`4(r9)`) operands.
    """
    pat = re.compile(rf"\br?{from_reg}\b")
    if not pat.search(operand):
        return None

    def _sub(m: re.Match[str]) -> str:
        token = m.group(0)
        prefix = "r" if token[:1].lower() == "r" else ""
        return f"{prefix}{to_reg}"

    new_operand = pat.sub(_sub, operand)
    return new_operand if new_operand != operand else None


def _find_match_indices(lines: list[str], needle: str) -> list[int]:
    return [i for i, line in enumerate(lines) if needle in line]


def apply(asm_text: str, args: dict) -> str:
    needle = args.get("match")
    pos_raw = args.get("pos")
    from_raw = args.get("from_reg")
    to_raw = args.get("to_reg")
    occurrence = int(args.get("occurrence", 0))

    if needle is None or pos_raw is None or from_raw is None or to_raw is None:
        raise ValueError(
            "force_reg_at_pos requires args: match, pos, from_reg, to_reg"
        )

    try:
        pos = int(pos_raw)
    except (TypeError, ValueError):
        raise ValueError(f"force_reg_at_pos: pos must be an integer, got {pos_raw!r}") from None
    if pos < 0:
        raise ValueError(f"force_reg_at_pos: pos must be non-negative, got {pos}")

    try:
        from_reg = norm_reg(str(from_raw))
        to_reg = norm_reg(str(to_raw))
    except ValueError as e:
        raise ValueError(f"force_reg_at_pos: {e}") from None
    if from_reg == to_reg:
        raise ValueError("force_reg_at_pos: from_reg and to_reg must differ")

    lines = asm_text.splitlines(keepends=True)
    hits = _find_match_indices(lines, needle)
    if not hits:
        raise NoApplicableSite(f"force_reg_at_pos: no .s line contains {needle!r}")
    if occurrence >= len(hits):
        raise NoApplicableSite(
            f"force_reg_at_pos: requested occurrence {occurrence} but only "
            f"{len(hits)} match {needle!r}"
        )

    idx = hits[occurrence]
    line = lines[idx]

    newline = ""
    body = line
    if body.endswith("\r\n"):
        newline = "\r\n"
        body = body[:-2]
    elif body.endswith("\n"):
        newline = "\n"
        body = body[:-1]

    m = _INSN_RE.match(body)
    if not m:
        raise NoApplicableSite(
            f"force_reg_at_pos: matched line is not an instruction: {body!r}"
        )

    head_end = m.end("op")
    head = body[: head_end]
    rest = body[head_end:]

    operands = _split_with_indices(rest)
    if pos >= len(operands):
        raise NoApplicableSite(
            f"force_reg_at_pos: pos={pos} out of range "
            f"(line has {len(operands)} operand(s): {[o[2] for o in operands]!r})"
        )

    op_start, op_end, op_text = operands[pos]
    new_text = _rewrite_operand(op_text, from_reg, to_reg)
    if new_text is None:
        raise NoApplicableSite(
            f"force_reg_at_pos: operand at pos={pos} ({op_text!r}) does not "
            f"contain register r{from_reg}"
        )

    raw_chunk = rest[op_start:op_end]
    new_chunk = raw_chunk.replace(op_text, new_text, 1) if op_text else raw_chunk
    new_rest = rest[:op_start] + new_chunk + rest[op_end:]
    new_body = head + new_rest

    if new_body == body:
        raise NoApplicableSite(
            f"force_reg_at_pos: substitution produced no change "
            f"(operand pos={pos}, from r{from_reg} to r{to_reg})"
        )

    lines[idx] = new_body + newline
    return "".join(lines)
