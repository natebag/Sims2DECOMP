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

        changed = False
        new_ops = list(operands)
        for pos in range(len(operands)):
            if pos in fp_positions:
                # FP-register slot — leave for fp_relabel (if any).
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
