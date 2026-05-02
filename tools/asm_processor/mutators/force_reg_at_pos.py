"""force_reg_at_pos — rename a register at a SPECIFIC operand position on
a single .s line, leaving same-named registers at OTHER positions intact.

STATUS: STANDARD — Density Watch.

  0 N=2 hunt hits as of S13 (TUScout, info `0a22aa88`). Implementation is
  sound; production code at commit `7c3dd3ee` (FamilyImpl::RemoveMember,
  7-directive recipe with insert_mr cascade) stands. Mutator stays in
  REGISTRY as escape hatch.

  Default to source-level Tech #72 (polarity flip) and Tech #73 (split-tail)
  FIRST. The TUScout hunt confirmed the methodology insight that cc1plus
  and SN ProDG diverge on INSTRUCTION patterns more than on register
  choice — most apparent register-rename walls are actually opcode-idiom
  walls requiring source-level rewriting. Invoke this mutator only when
  structural inspection confirms a single instruction needs an asymmetric
  register rename (same logical register at multiple operand positions on
  one line, only one of which should change) — the genuinely-rare position-
  aware case.

  No mothball clock — STANDARD status retained pending S14 retrospective.
  If sustained zero-invocation through S14, demotion conversation reopens.

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
  so renaming `r9 → r10` produces `4(r10)`. Memory-form operands are
  detected explicitly so the immediate value cannot be confused with the
  base register when their numeric values collide (e.g. `0(r0)` with
  `from_reg=0` substitutes ONLY the base register, leaving the imm intact).

Refusal modes (NoApplicableSite — runtime skip, harness records, doesn't fail):
- `match` substring not found in any line
- `occurrence` index out of range
- `pos` index out of range for the matched line's operand list
- Operand at `pos` does not contain `from_reg` (word-boundary match)

Author-error modes (ValueError — raised, surfaces during authoring):
- Missing required args (match / pos / from_reg / to_reg)
- `pos` not a non-negative integer
- `from_reg == to_reg` (no-op rename)

Composition with insert_mr / force_reg / region_gpr_relabel (FOOTGUN):
  The `match` substring sees POST-MUTATION state from earlier directives in
  the same pipeline. The canonical FamilyImpl 7-directive recipe is exactly
  this scenario:

    1-3. force_reg (whole-line renames, pre-insert)
    4.   insert_mr (with relabel cascade, e.g. relabel=10:11,11:10)
    5-7. force_reg_at_pos (post-insert position-aware fixes)

  After step 4 relabels `subf 0,10,0` → `subf 0,11,0`, the post-insert
  directives must match against the POST-relabel form (`subf 0,11,0`), NOT
  the pre-relabel form. Authoring tip: hand-trace the .s through every
  prior directive before writing the `match` substring for a later one,
  or capture the intermediate .s by running the harness with a partial
  pipeline. See `feedback_multidirective_composition.md` for the broader
  recipe-authoring discipline.

  Use one of these to disambiguate when multiple positions on similar
  lines need different rewrites:
    - distinct surrounding-context substrings in `match`
    - explicit `occurrence` index per ordered hit list
    - split a mass rename across multiple force_reg_at_pos directives
      rather than collapsing into one over-broad match

Verify-before-save: always run `verify_match.sh` (or the asm_processor
wall harness) before committing a directive recipe. Mutator authoring is
deterministic per (asm_text, args), so a passing verify on the target
function is sufficient evidence of byte-match.
"""
from __future__ import annotations

import re

from . import NoApplicableSite
from ._helpers import norm_reg

NAME = "force_reg_at_pos"


# Local regex primitives — leading-underscore module-private names per
# the convention shared with region_gpr_relabel / anti_tail_merge /
# force_alias_base / swap_adj. Each mutator owns its own parsing primitives.
_INSN_RE = re.compile(
    r"^(?P<indent>[ \t]*)(?P<op>[A-Za-z_][A-Za-z0-9._]*)(?=\s|$)(?P<rest>.*)$"
)
_MEM_FORM_RE = re.compile(r"^(?P<imm>[^(]+)\((?P<reg>r?\d{1,2})\)$")


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
    at a register slot inside the operand.

    Handles two operand shapes explicitly:
      - bare-register tokens: `9`, `r9` (rare: any non-mem-form text)
      - memory-form tokens:   `4(r9)`, `0(r0)` — substitution happens ONLY
        inside the parens, so an immediate whose numeric value collides
        with the base register cannot be rewritten by accident.

    The mem-form path closes the SA-2 hole flagged in the v1 impl review:
    `lwz r3, 0(r0)` with `from_reg=0,to_reg=8` produces `lwz r3, 0(r8)`,
    NOT `lwz r3, 8(r8)`.
    """
    pat = re.compile(rf"\br?{from_reg}\b")

    mm = _MEM_FORM_RE.match(operand)
    if mm:
        reg_tok = mm.group("reg")
        if not pat.fullmatch(reg_tok):
            return None
        prefix = "r" if reg_tok[:1].lower() == "r" else ""
        new_reg = f"{prefix}{to_reg}"
        return operand.replace(f"({reg_tok})", f"({new_reg})", 1)

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
