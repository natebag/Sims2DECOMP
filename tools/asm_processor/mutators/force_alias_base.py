"""force_alias_base — synthesize a base-register alias and rewrite memops.

STATUS: PROVISIONAL (2026-05-02). The mutator is correctness-validated
(smoke + 4-target run) but has NOT YET produced a real-world byte-match.
The 4-target validation surfaced a source-level shape mismatch on the
primary target (FamilyImpl::RemoveMember). This block is removed by the
first cracker who lands a successful byte-match using this mutator —
that PR is then the seed of catalog promotion conversation (multi-
instance threshold still applies; need >=2 instances total).

Use case: Category-2 register-allocation walls where the DOL sets up an alias
register early in the function via `addi rALIAS, rBASE, OFFBASE`, then accesses
subsequent struct fields via `lwz/stw rA, K(rALIAS)`. GCC's RA declines to
materialize the alias, instead emitting `lwz/stw rA, OFFBASE+K(rBASE)` directly.
Source-level coaxing (`register T& alias = ...`) does not force the alias —
GCC sees no reuse benefit and skips the addi.

Two modes (mutually exclusive — pick one explicitly):

  - **fresh-alias** (default, `alias_reg != base_reg`):
      Inserts `addi rALIAS, rBASE, OFFBASE` at the anchor, then rewrites
      `IMM(rBASE)` memops in a bounded window to `IMM-OFFBASE(rALIAS)`.
      The window is `window` lines long (default 16). Liveness check
      ensures `alias_reg` is not used by other instructions in the window.

  - **in-place** (`in_place: true`, requires `alias_reg == base_reg`):
      Inserts `addi rBASE, rBASE, OFFBASE` at the anchor, REASSIGNING rBASE
      for the rest of the span. Rewrites `IMM(rBASE)` memops to
      `IMM-OFFBASE(rBASE)` over the full span [insertion_point, until]. The
      full-span exhaustiveness check refuses if ANY rBASE memop with IMM
      not in `imm_whitelist` appears in the span (its semantics would
      silently break post-reassignment).

Structural parallel with `insert_mr`: both insert one synthetic instruction
at an anchor and apply a bounded post-anchor transformation. Where insert_mr
relabels GPR operands across a window, force_alias_base rewrites memop
displacement+base operand pairs across a window or full span.

Manifest example (FamilyImpl::RemoveMember stage 2 — in-place):

    pipeline:
      - mutator: force_alias_base
        args:
          after: "bne+ "
          base_reg: 3
          alias_reg: 3
          base_offset: 36
          imm_whitelist: [4]
          until: "blr"
          in_place: true            # required when alias_reg == base_reg

Manifest example (fresh-alias mode, hypothetical):

    pipeline:
      - mutator: force_alias_base
        args:
          after: "stwu r1,"
          base_reg: 3
          alias_reg: 11
          base_offset: 36
          imm_whitelist: [0, 4]
          window: 16

Author-error conditions (ValueError, fail-loud):
  - Missing required args (after/before, base_reg, alias_reg, base_offset, imm_whitelist).
  - Both `after` and `before` specified.
  - `base_reg` or `alias_reg` ∈ {r1, r2, r13} (frame/TOC/SDA — never aliasable).
  - Fresh-alias mode + `alias_reg` outside default policy whitelist (r9..r12)
    without `unsafe_alias_reg: true`.
  - `imm_whitelist` empty.
  - `in_place: true` AND `alias_reg != base_reg`.
  - `alias_reg == base_reg` AND `in_place != true` (forces explicit opt-in).
  - `in_place: true` AND `unsafe_alias_reg: true` (mutually exclusive intents).

Skip-not-fail conditions (NoApplicableSite, harness records skip):
  - Anchor needle not found / occurrence out of range.
  - Any call-instruction opcode in scan span (per CALL_OPCODES; the alias
    register would not survive across a call under the SN ABI).
  - No qualifying memop with IMM(rBASE), IMM ∈ imm_whitelist, in the span.
  - In_place: any rBASE memop in [insertion_point, until_terminator] with
    IMM ∉ imm_whitelist (full-span exhaustiveness violation).
  - Fresh-alias: alias_reg referenced by any non-rewriteable instruction
    in the rewrite window (liveness violation — the addi would clobber
    a live value).

CALL_OPCODES note (per OpusReviewGuy v5 verdict, soft-soft #1):
  Explicit list `{bl, bla, bctrl, bclrl, bcctrl, blrl, bcl, bcla, bdnzl, bdzl}`
  in `_helpers.CALL_OPCODES`. The link-form absolute decrement variants
  `bdnzla` / `bdzla` are deliberately NOT in the list — SN ProDG does not
  emit them from C++ compilation. If a target ever surfaces them, add
  explicitly to the helpers' set rather than collapsing the deny-list to
  a regex.

Liveness check limitations (fresh-alias mode):
  The naive scan flags any operand whose bare-numeric token equals
  `alias_reg`. PowerPC opcodes like `slwi`, `rlwinm`, `rlwimi` carry
  small-integer immediate operands (SH, MB, ME) that share the syntactic
  form `\\d{1,2}`; if any such immediate happens to equal `alias_reg`'s
  index, the scan will conservatively raise NoApplicableSite. False-positive
  skip is the safer failure mode here — author can pick a different alias
  register (e.g., move r9 → r10 if r9 collides with a shift count).
"""
from __future__ import annotations

import re
from typing import Iterable

from . import NoApplicableSite
from ._helpers import (
    CALL_OPCODES,
    NON_GPR_INT_OPCODES,
    _BARE_REG_RE,
    _INSN_RE,
    _MEM_FORM_RE,
    find_anchor_index,
    find_terminator,
    norm_reg,
    opcode,
    split_operands,
)

NAME = "force_alias_base"


# ---------- Module-private helpers ----------

# Memops whose address operand is `IMM(rN)` form. These are eligible for
# displacement/base rewriting. Indexed forms (lwzx/stwx/etc.) use `rA, rB`
# instead of `IMM(rN)` and are NOT rewritten by this mutator.
_MEMOP_OPCODES: frozenset[str] = frozenset({
    "lwz", "lwzu", "lhz", "lhzu", "lha", "lhau", "lbz", "lbzu",
    "lfs", "lfsu", "lfd", "lfdu",
    "stw", "stwu", "sth", "sthu", "stb", "stbu",
    "stfs", "stfsu", "stfd", "stfdu",
})

# Frame pointer (r1), TOC pointer (r2), SDA base (r13) — never aliasable as
# either base or alias. These are fixed by the SN ABI / SDK contract.
_PROTECTED_REGS: frozenset[int] = frozenset({1, 2, 13})

# Default policy whitelist for `alias_reg` in fresh-alias mode: SN volatile
# scratch r9..r12. Anything outside this in r3-r8 / r14+ requires an explicit
# `unsafe_alias_reg: true` opt-in.
_DEFAULT_ALIAS_WHITELIST: frozenset[int] = frozenset({9, 10, 11, 12})

_IMM_FORM_RE = re.compile(
    r"^\s*(?P<imm>-?\d+|0[xX][0-9a-fA-F]+|-0[xX][0-9a-fA-F]+)\((?P<reg>r?\d{1,2})\)\s*$"
)


def _parse_imm(imm_str: str) -> int:
    s = imm_str.strip()
    if s.lower().startswith(("0x", "-0x")):
        return int(s, 16)
    return int(s)


def _parse_memop(line: str) -> tuple[str, str, int, int, str] | None:
    """Parse `OP rA, IMM(rN)` lines; return (op, dst_token, imm, reg, addr_token).

    Returns None for non-memop lines and indexed-memop lines.
    """
    op_str = opcode(line)
    if op_str is None:
        return None
    op_lower = op_str.lower()
    if op_lower not in _MEMOP_OPCODES:
        return None
    body = line.rstrip("\r\n")
    m = _INSN_RE.match(body)
    if not m:
        return None
    operands = split_operands(m.group("rest"))
    if len(operands) != 2:
        return None
    dst_token = operands[0]
    addr_token = operands[1]
    am = _IMM_FORM_RE.match(addr_token)
    if not am:
        return None
    try:
        imm = _parse_imm(am.group("imm"))
    except ValueError:
        return None
    reg_str = am.group("reg").lstrip("rR")
    if not reg_str.isdigit():
        return None
    reg = int(reg_str)
    return op_lower, dst_token, imm, reg, addr_token


def _rewrite_memop_addr(line: str, new_imm: int, new_reg: int) -> str:
    """Rewrite the address operand of a memop line to `new_imm(rNEW)`.

    Preserves the original register-prefix style (`r9` vs bare `9`) of the
    address operand's register token. Returns the line unchanged if the
    address operand cannot be parsed.
    """
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
        return line
    head = m.group("indent") + m.group("op")
    rest = m.group("rest")
    operands = split_operands(rest)
    if len(operands) != 2:
        return line
    am = _IMM_FORM_RE.match(operands[1])
    if not am:
        return line
    reg_tok = am.group("reg")
    has_r_prefix = reg_tok[:1].lower() == "r"
    new_reg_str = f"r{new_reg}" if has_r_prefix else str(new_reg)
    operands[1] = f"{new_imm}({new_reg_str})"
    prefix_match = re.match(r"^(\s*)", rest)
    prefix = prefix_match.group(1) if prefix_match else " "
    return head + prefix + ", ".join(operands) + newline


def _line_references_register(line: str, reg_num: int) -> bool:
    """True if `line` has an operand syntactically referencing GPR `reg_num`.

    Conservative — skips opcodes in NON_GPR_INT_OPCODES and treats everything
    else as potentially register-bearing. May false-positive on shift/mask
    immediates that share the bare-numeric form (see module docstring).
    """
    op_str = opcode(line)
    if op_str is None:
        return False
    if op_str.lower() in NON_GPR_INT_OPCODES:
        return False
    body = line.rstrip("\r\n")
    m = _INSN_RE.match(body)
    if not m:
        return False
    operands = split_operands(m.group("rest"))
    for tok in operands:
        t = tok.strip()
        if not t:
            continue
        bm = _BARE_REG_RE.match(t)
        if bm and int(bm.group(1)) == reg_num:
            return True
        mm = _MEM_FORM_RE.match(t)
        if mm:
            reg_tok = mm.group("reg").lstrip("rR")
            if reg_tok.isdigit() and int(reg_tok) == reg_num:
                return True
    return False


def _scan_for_calls(lines: list[str], start: int, end: int) -> int | None:
    for j in range(start, end):
        op = opcode(lines[j])
        if op is None:
            continue
        if op.lower() in CALL_OPCODES:
            return j
    return None


def _coerce_imm_list(spec) -> list[int]:
    """Accept list[int] or comma-separated string. Returns list[int]."""
    if isinstance(spec, list):
        out = []
        for x in spec:
            if isinstance(x, int):
                out.append(x)
            elif isinstance(x, str):
                out.append(_parse_imm(x))
            else:
                raise ValueError(f"imm_whitelist entry must be int or str, got {type(x).__name__}")
        return out
    if isinstance(spec, str):
        return [_parse_imm(p) for p in spec.split(",") if p.strip()]
    raise ValueError(f"imm_whitelist must be list or comma-separated string, got {type(spec).__name__}")


# ---------- Apply ----------

def apply(asm_text: str, args: dict) -> str:
    # ---- 1a. Required args ----
    after = args.get("after")
    before = args.get("before")
    if not after and not before:
        raise ValueError("force_alias_base requires arg: after=<match> OR before=<match>")
    if after and before:
        raise ValueError("force_alias_base: specify only one of after/before, not both")

    if "base_reg" not in args or "alias_reg" not in args:
        raise ValueError("force_alias_base requires args: base_reg, alias_reg")
    if "base_offset" not in args:
        raise ValueError("force_alias_base requires arg: base_offset")
    if "imm_whitelist" not in args:
        raise ValueError("force_alias_base requires arg: imm_whitelist (non-empty list of ints)")

    try:
        base_reg = norm_reg(str(args["base_reg"]))
        alias_reg = norm_reg(str(args["alias_reg"]))
    except ValueError as e:
        raise ValueError(f"force_alias_base: {e}") from None

    base_offset = args["base_offset"]
    if not isinstance(base_offset, int):
        try:
            base_offset = _parse_imm(str(base_offset))
        except ValueError:
            raise ValueError(f"force_alias_base: base_offset must be int, got {args['base_offset']!r}") from None

    imm_whitelist = _coerce_imm_list(args["imm_whitelist"])
    if not imm_whitelist:
        raise ValueError("force_alias_base: imm_whitelist must be non-empty")
    imm_whitelist_set = set(imm_whitelist)

    in_place = bool(args.get("in_place", False))
    unsafe_alias_reg = bool(args.get("unsafe_alias_reg", False))
    until_match = args.get("until")  # None → default "blr" terminator
    window = int(args.get("window", 16))
    if window < 1:
        raise ValueError(f"force_alias_base: window must be >= 1, got {window}")
    occurrence = int(args.get("occurrence", 0))

    # ---- 1b. Mutual-exclusion + policy validation (4 ValueError rules) ----
    # Rule: protected regs (frame/TOC/SDA) are never aliasable.
    if base_reg in _PROTECTED_REGS:
        raise ValueError(
            f"force_alias_base: base_reg r{base_reg} is protected (frame/TOC/SDA); "
            f"aliasing not permitted"
        )
    if alias_reg in _PROTECTED_REGS:
        raise ValueError(
            f"force_alias_base: alias_reg r{alias_reg} is protected (frame/TOC/SDA); "
            f"aliasing not permitted"
        )
    # Rule 1 (v5): in_place: true AND alias_reg != base_reg → ValueError.
    if in_place and alias_reg != base_reg:
        raise ValueError(
            f"force_alias_base: in_place=true requires alias_reg == base_reg "
            f"(got alias_reg=r{alias_reg}, base_reg=r{base_reg})"
        )
    # Rule 2 (v5): alias_reg == base_reg AND in_place != true → ValueError.
    if alias_reg == base_reg and not in_place:
        raise ValueError(
            f"force_alias_base: alias_reg == base_reg (r{base_reg}) requires "
            f"in_place=true to confirm in-place reassignment intent"
        )
    # Rule 4 (v5): in_place + unsafe_alias_reg → ValueError.
    if in_place and unsafe_alias_reg:
        raise ValueError(
            "force_alias_base: in_place and unsafe_alias_reg are mutually exclusive"
        )
    # Rule 3 (v5): in_place + base_reg ∈ {r1, r2, r13} → already rejected above.
    # Fresh-alias policy whitelist: alias_reg ∈ r9..r12 default; r3..r8 / r14+
    # require unsafe_alias_reg: true.
    if not in_place and alias_reg not in _DEFAULT_ALIAS_WHITELIST and not unsafe_alias_reg:
        raise ValueError(
            f"force_alias_base: alias_reg r{alias_reg} outside default whitelist "
            f"(r9..r12); set unsafe_alias_reg=true to opt in (rare; document in commit message)"
        )

    # ---- 2. Find anchor; 3. Compute insertion point + terminator ----
    lines = asm_text.splitlines(keepends=True)
    anchor_idx, insert_offset = find_anchor_index(
        lines, after, before, occurrence, label="force_alias_base"
    )
    insert_idx = anchor_idx + insert_offset
    terminator_idx = find_terminator(
        lines, insert_idx, until_match, include_blr_line=True
    )

    # ---- Determine scan window per mode ----
    if in_place:
        scan_start, scan_end = insert_idx, terminator_idx
    else:
        scan_end = min(insert_idx + window, terminator_idx)
        scan_start = insert_idx

    if scan_start >= scan_end:
        raise NoApplicableSite(
            f"force_alias_base: empty scan span [{scan_start}..{scan_end}); "
            f"anchor at line {anchor_idx + 1} likely past terminator"
        )

    # ---- 4. Call-clobber abort scan ----
    call_idx = _scan_for_calls(lines, scan_start, scan_end)
    if call_idx is not None:
        call_op = opcode(lines[call_idx])
        raise NoApplicableSite(
            f"force_alias_base: call-instruction {call_op!r} at line {call_idx + 1} "
            f"would clobber alias register; abort"
        )

    # ---- 6. Collect qualifying memops (rBASE base, IMM in whitelist) ----
    rewrite_targets: list[tuple[int, int]] = []  # (line_idx, new_imm)
    for j in range(scan_start, scan_end):
        parsed = _parse_memop(lines[j])
        if parsed is None:
            continue
        _, _, imm, reg, _ = parsed
        if reg != base_reg:
            continue
        if imm in imm_whitelist_set:
            rewrite_targets.append((j, imm - base_offset))

    if not rewrite_targets:
        raise NoApplicableSite(
            f"force_alias_base: no qualifying memop with r{base_reg} base and "
            f"IMM in {sorted(imm_whitelist_set)} found in span [{scan_start}..{scan_end})"
        )

    # ---- 7. In-place full-span exhaustiveness check ----
    if in_place:
        for j in range(insert_idx, terminator_idx):
            parsed = _parse_memop(lines[j])
            if parsed is None:
                continue
            _, _, imm, reg, _ = parsed
            if reg != base_reg:
                continue
            if imm not in imm_whitelist_set:
                raise NoApplicableSite(
                    f"force_alias_base: in_place exhaustiveness - line {j + 1} has "
                    f"r{base_reg} memop with IMM={imm} not in whitelist "
                    f"{sorted(imm_whitelist_set)}; rewrite would silently break "
                    f"semantics post-reassignment"
                )

    # ---- 8. Fresh-alias liveness check ----
    if not in_place:
        rewrite_idxs = {j for j, _ in rewrite_targets}
        for j in range(scan_start, scan_end):
            if j in rewrite_idxs:
                continue
            if _line_references_register(lines[j], alias_reg):
                op_at_j = opcode(lines[j]) or "?"
                raise NoApplicableSite(
                    f"force_alias_base: alias_reg r{alias_reg} live at line {j + 1} "
                    f"({op_at_j!r}); inserting addi would clobber"
                )

    # ---- 9. Insert addi; 10. Rewrite per mode ----
    anchor_line = lines[anchor_idx]
    indent_match = re.match(r"^([ \t]*)", anchor_line)
    indent = indent_match.group(1) if indent_match else "\t"
    addi_line = f"{indent}addi {alias_reg},{base_reg},{base_offset}\n"

    new_lines = list(lines)
    for j, new_imm in rewrite_targets:
        new_lines[j] = _rewrite_memop_addr(new_lines[j], new_imm, alias_reg)

    new_lines = new_lines[:insert_idx] + [addi_line] + new_lines[insert_idx:]
    return "".join(new_lines)
