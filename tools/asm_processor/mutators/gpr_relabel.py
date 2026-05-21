"""gpr_relabel — bidirectional GPR relabeling across the .s.

Sibling of `fp_relabel`. Use case: Category 2 walls where GCC picks a
self-consistent but different GPR assignment than the DOL (e.g. BBI ctor
uses r10/r0 zero-registers in the opposite polarity of DOL; InvalidateRoutes
picks r3 as the loop base where DOL picks r11). A single force_reg
substitution breaks register liveness because each reg typically appears
in 3-6 instructions. This mutator applies a swap map to every GPR-operand
position in one pass, so the relabel is atomic and self-consistent.

Handles the two GPR syntaxes SN cc1plus emits:
  - bare register: `add 3,4,5`, `li 0,0`, `stw 11,8(9)`
  - memory form:   `lwz 3,8(11)` / `stw 11,8(9)` — the parenthesized rA

SN cc1plus 2.95 uses bare numeric register names (no `r` prefix). Mutator
accepts `rN` or bare `N` in the swap spec; prefix is normalized away.

Manifest example:

    pipeline:
      - mutator: gpr_relabel
        args:
          swap: "0:10"               # bidirectional r0 ↔ r10
          # opcodes: "add,or,stb,...."  # optional — restrict to these opcodes
          # skip_opcodes: "mr,mflr"     # optional — skip these opcodes entirely

Syntax of `swap`: comma-separated `a:b` pairs. Each pair is bidirectional.

Opcodes that have FP-register operands (listed in `fp_relabel.FP_POSITIONS`)
are handled specially: the FP positions are untouched and any remaining
positions (typically the memory base register `rA` inside `imm(rA)`) are
relabeled as GPRs. So `lfs 0,136(11)` with swap 11:3 becomes `lfs 0,136(3)`
(the FP dest f0 is untouched, the base GPR r11 is swapped).

Counter-example (DO NOT RELABEL) — the branch hint `bc 4,2,.L4` has integer
operands that are NOT GPRs (they're BO/BI fields). Those bare-integer
opcodes are kept in a `NON_GPR_INT_OPCODES` block list.
"""
from __future__ import annotations

import re

from . import NoApplicableSite
from .fp_relabel import FP_POSITIONS

NAME = "gpr_relabel"


# Opcodes whose bare-integer operands are NOT register numbers.
# - Branch-on-condition: bc, bca, bcl, bcla, bclr, bcctr use BO/BI encoding.
# - Traps use TO encoding.
# - Immediate-only ops (no register operand) never appear in practice, but
#   we're defensive.
NON_GPR_INT_OPCODES = frozenset({
    "bc", "bca", "bcl", "bcla", "bclr", "bcctr", "bclrl", "bcctrl",
    "tw", "twi", "td", "tdi",
    "crand", "crandc", "creqv", "crnand", "crnor", "cror", "crorc", "crxor",
    "mcrf", "mcrxr",
    "mtfsfi", "mtfsf", "mtfsb0", "mtfsb1",
    "sc", "nop",
})


# Positions whose bare-integer operands are IMMEDIATES, not register
# numbers. The relabel rewrite must skip these or it corrupts immediate
# fields — most notoriously, `cmpwi rA, 0` with swap=0:N gets rewritten
# to `cmpwi rA, N` because the bare `0` is mistakenly identified as a
# register reference. S15 note: lockCarryArmNodes twin hit this exact
# hazard (gpr_relabel swap=0:11 broke cmpwi r9,0). Positions use the
# operand index AFTER the opcode (0-based). For multi-immediate opcodes
# (rlwinm 2/3/4) all immediate slots are listed. Opcodes with optional
# CR-field prefix (cmpwi can be `cmpwi rA,IMM` or `cmpwi cr,rA,IMM`)
# use a negative `-1` sentinel meaning "the LAST operand."
IMMEDIATE_POSITIONS: dict[str, tuple[int, ...]] = {
    # Plain immediate loads
    "li":      (1,),
    "lis":     (1,),

    # Comparison-with-immediate. The cr-field prefix is optional in SN
    # syntax (`cmpwi 0,8` vs `cmpwi 7,0,1`) so the immediate is always
    # the LAST operand — use the -1 sentinel.
    "cmpi":    (-1,),
    "cmpwi":   (-1,),
    "cmpwi.":  (-1,),
    "cmplwi":  (-1,),
    "cmplwi.": (-1,),
    "cmpdi":   (-1,),
    "cmpldi":  (-1,),

    # Three-operand arithmetic with immediate at position 2.
    "addi":    (2,),
    "addic":   (2,),
    "addic.":  (2,),
    "addis":   (2,),
    "subfic":  (2,),
    "mulli":   (2,),

    # Three-operand logical with immediate at position 2.
    "andi.":   (2,),
    "andis.":  (2,),
    "ori":     (2,),
    "oris":    (2,),
    "xori":    (2,),
    "xoris":   (2,),

    # Rotate-and-mask family. Standard 5-operand form has imms at 2,3,4;
    # SN's 4-operand compact form (`rlwinm rD,rA,SH,MASK`) has imms at 2,3.
    # Listing (2,3,4) covers both — out-of-range positions are ignored.
    "rlwinm":  (2, 3, 4),
    "rlwinm.": (2, 3, 4),
    "rlwimi":  (2, 3, 4),
    "rlwimi.": (2, 3, 4),
    "rlwnm":   (3, 4),
    "rlwnm.":  (3, 4),

    # Shift-amount immediate.
    "srawi":   (2,),
    "srawi.":  (2,),

    # Extended mnemonics for rlwinm (compact 1-or-2 imm forms).
    "slwi":    (2,),
    "srwi":    (2,),
    "clrlwi":  (2,),
    "clrrwi":  (2,),
    "rotlwi":  (2,),
    "rotrwi":  (2,),
    "extlwi":  (2, 3),
    "extrwi":  (2, 3),
}


def _resolve_immediate_positions(op: str, n_operands: int) -> frozenset[int]:
    """Return concrete operand indices that are immediates for `op`.

    `IMMEDIATE_POSITIONS` may contain `-1` as a sentinel meaning "last
    operand index", used for opcodes like cmpwi whose CR-field prefix is
    optional in SN syntax. This helper resolves that to a concrete index
    based on the actual operand count of the line being processed.
    """
    spec = IMMEDIATE_POSITIONS.get(op)
    if spec is None:
        return frozenset()
    resolved = set()
    for p in spec:
        if p < 0:
            idx = n_operands + p
            if idx >= 0:
                resolved.add(idx)
        else:
            if p < n_operands:
                resolved.add(p)
    return frozenset(resolved)


# Opcodes whose LAST operand is a label (branch target), not a register.
# The label is a symbol or `.L.*` — it parses as a non-register anyway, so
# no special-casing needed in the rewrite loop; the regex won't match it.
# Listed here for documentation only.


_OPCODE_RE = re.compile(r"^(?P<indent>[ \t]*)(?P<op>[A-Za-z_][A-Za-z0-9._]*)(?=\s|$)(?P<rest>.*)$")
_BARE_REG_RE = re.compile(r"^r?(\d{1,2})$")
_MEM_FORM_RE = re.compile(r"^(?P<imm>[^(]+)\((?P<reg>r?\d{1,2})\)$")


def _parse_swap(spec: str) -> dict[int, int]:
    m: dict[int, int] = {}
    for pair in spec.split(","):
        pair = pair.strip()
        if not pair:
            continue
        if ":" not in pair:
            raise ValueError(f"gpr_relabel: bad swap pair {pair!r} (need 'a:b')")
        a_s, b_s = [s.strip().lstrip("rR") for s in pair.split(":", 1)]
        try:
            a, b = int(a_s), int(b_s)
        except ValueError:
            raise ValueError(f"gpr_relabel: non-numeric swap pair {pair!r}") from None
        if not (0 <= a <= 31 and 0 <= b <= 31):
            raise ValueError(f"gpr_relabel: register out of range in {pair!r}")
        if a == b:
            continue
        if a in m or b in m:
            raise ValueError(f"gpr_relabel: overlapping swap pair {pair!r} (register reused)")
        m[a] = b
        m[b] = a
    return m


def _relabel_token(token: str, swap: dict[int, int]) -> str:
    """Relabel a single operand token: bare reg, mem-form imm(reg), or unchanged."""
    t = token.strip()
    if not t:
        return token
    # Try mem-form `imm(reg)` first — common in load/stores.
    mm = _MEM_FORM_RE.match(t)
    if mm:
        reg_tok = mm.group("reg").strip()
        rm = _BARE_REG_RE.match(reg_tok)
        if rm:
            n = int(rm.group(1))
            if n in swap:
                prefix = "r" if reg_tok[:1].lower() == "r" else ""
                return token.replace(
                    f"({reg_tok})", f"({prefix}{swap[n]})", 1
                )
        return token
    # Bare register form.
    bm = _BARE_REG_RE.match(t)
    if bm:
        n = int(bm.group(1))
        if n not in swap:
            return token
        prefix = "r" if t[:1].lower() == "r" else ""
        return token.replace(t, f"{prefix}{swap[n]}", 1)
    return token


def _split_operands(rest: str) -> list[str]:
    body = rest.strip()
    if not body or body.startswith((";", "#")):
        return []
    if "#" in body:
        body = body.split("#", 1)[0].rstrip()
    if ";" in body:
        body = body.split(";", 1)[0].rstrip()
    return [op.strip() for op in body.split(",")]


def apply(asm_text: str, args: dict) -> str:
    spec = args.get("swap")
    if not spec:
        raise ValueError("gpr_relabel requires arg: swap (e.g. swap=0:10)")
    swap = _parse_swap(spec)
    if not swap:
        raise ValueError("gpr_relabel: empty swap map")

    only_opcodes = args.get("opcodes")
    skip_opcodes = args.get("skip_opcodes")
    only_set = (
        frozenset(s.strip() for s in only_opcodes.split(",") if s.strip())
        if only_opcodes else None
    )
    skip_set = (
        frozenset(s.strip() for s in skip_opcodes.split(",") if s.strip())
        if skip_opcodes else frozenset()
    )

    lines = asm_text.splitlines(keepends=True)
    any_changed = False

    for i, line in enumerate(lines):
        m = _OPCODE_RE.match(line)
        if not m:
            continue
        op = m.group("op")

        if only_set is not None and op not in only_set:
            continue
        if op in skip_set:
            continue
        if op in NON_GPR_INT_OPCODES:
            continue

        newline_suffix = "\n" if line.endswith("\n") else ""
        rest = m.group("rest").rstrip("\r\n")
        operands = _split_operands(rest)
        if not operands:
            continue

        fp_positions = FP_POSITIONS.get(op, ())
        imm_positions = _resolve_immediate_positions(op, len(operands))

        changed = False
        new_ops = list(operands)
        for pos in range(len(operands)):
            if pos in fp_positions:
                # FP-register slot — leave for fp_relabel (if any).
                continue
            if pos in imm_positions:
                # Immediate operand — relabeling would corrupt the value
                # (e.g. swap=0:11 would rewrite `cmpwi rA,0` to `cmpwi rA,11`).
                continue
            relabeled = _relabel_token(operands[pos], swap)
            if relabeled != operands[pos]:
                new_ops[pos] = relabeled
                changed = True
        if changed:
            indent = m.group("indent")
            lines[i] = f"{indent}{op} {','.join(new_ops)}{newline_suffix}"
            any_changed = True

    if not any_changed:
        raise NoApplicableSite(
            f"gpr_relabel swap={spec} matched no GPR-operand site in the asm"
        )
    return "".join(lines)
