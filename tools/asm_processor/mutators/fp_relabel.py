"""fp_relabel — bidirectional FP-register relabeling across the .s.

Use case: Category 2 walls where the compiler picks a self-consistent but
different FP register assignment than the DOL (e.g. ESimsCam fmadds chain
picks f0/f12/f13/f11 where DOL wants f13/f11/f0/f12). A single force_reg
substitution breaks the chain because each SN-chosen register appears in
~3-8 instructions. This mutator applies a swap map to every FP-register
operand position in one pass, so the relabel is atomic and self-consistent.

SN cc1plus 2.95 emits registers as bare numbers (`lfs 13,44(11)` not
`lfs f13,44(r11)`). We filter by opcode to know which operand POSITIONS
are FP-register-valued (opposed to GPR or immediate) — see FP_POSITIONS
table below.

Manifest example:

    pipeline:
      - mutator: fp_relabel
        args:
          swap: "0:13,11:12"        # bidirectional: f0<->f13, f11<->f12

Syntax of `swap`: comma-separated `a:b` pairs. Each pair is bidirectional.
Parsing is tolerant of `fN` or bare `N` forms; `f` prefix is stripped.

Non-destructive against GPR operands — `lfs 13,44(11)` with swap 13:0
becomes `lfs 0,44(11)` (f13 changes, r11 untouched).
"""
from __future__ import annotations

import re

from . import NoApplicableSite

NAME = "fp_relabel"


FP_POSITIONS: dict[str, tuple[int, ...]] = {
    "lfs":     (0,),
    "lfd":     (0,),
    "lfsu":    (0,),
    "lfdu":    (0,),
    "lfsx":    (0,),
    "lfdx":    (0,),
    "stfs":    (0,),
    "stfd":    (0,),
    "stfsu":   (0,),
    "stfdu":   (0,),
    "stfsx":   (0,),
    "stfdx":   (0,),

    "fmr":     (0, 1),
    "fabs":    (0, 1),
    "fneg":    (0, 1),
    "fnabs":   (0, 1),
    "frsp":    (0, 1),
    "fctiw":   (0, 1),
    "fctiwz":  (0, 1),
    "fsqrt":   (0, 1),
    "fsqrts":  (0, 1),
    "fres":    (0, 1),
    "frsqrte": (0, 1),

    "fadd":    (0, 1, 2),
    "fadds":   (0, 1, 2),
    "fsub":    (0, 1, 2),
    "fsubs":   (0, 1, 2),
    "fmul":    (0, 1, 2),
    "fmuls":   (0, 1, 2),
    "fdiv":    (0, 1, 2),
    "fdivs":   (0, 1, 2),

    "fmadd":   (0, 1, 2, 3),
    "fmadds":  (0, 1, 2, 3),
    "fmsub":   (0, 1, 2, 3),
    "fmsubs":  (0, 1, 2, 3),
    "fnmadd":  (0, 1, 2, 3),
    "fnmadds": (0, 1, 2, 3),
    "fnmsub":  (0, 1, 2, 3),
    "fnmsubs": (0, 1, 2, 3),
    "fsel":    (0, 1, 2, 3),

    "fcmpu":   (1, 2),
    "fcmpo":   (1, 2),
}


_OPCODE_RE = re.compile(r"^(?P<indent>[ \t]*)(?P<op>[A-Za-z_][A-Za-z0-9._]*)(?=\s|$)(?P<rest>.*)$")
_REG_TOKEN_RE = re.compile(r"^f?(\d{1,2})$")


def _parse_swap(spec: str) -> dict[int, int]:
    m: dict[int, int] = {}
    for pair in spec.split(","):
        pair = pair.strip()
        if not pair:
            continue
        if ":" not in pair:
            raise ValueError(f"fp_relabel: bad swap pair {pair!r} (need 'a:b')")
        a_s, b_s = [s.strip().lstrip("fF") for s in pair.split(":", 1)]
        try:
            a, b = int(a_s), int(b_s)
        except ValueError:
            raise ValueError(f"fp_relabel: non-numeric swap pair {pair!r}") from None
        if not (0 <= a <= 31 and 0 <= b <= 31):
            raise ValueError(f"fp_relabel: register out of range in {pair!r}")
        if a == b:
            continue
        if a in m or b in m:
            raise ValueError(f"fp_relabel: overlapping swap pair {pair!r} (register reused)")
        m[a] = b
        m[b] = a
    return m


def _split_operands(rest: str) -> list[str]:
    body = rest.strip()
    if not body or body.startswith((";", "#")):
        return []
    if "#" in body:
        body = body.split("#", 1)[0].rstrip()
    if ";" in body:
        body = body.split(";", 1)[0].rstrip()
    return [op.strip() for op in body.split(",")]


def _apply_to_token(token: str, swap: dict[int, int]) -> str:
    t = token.strip()
    m = _REG_TOKEN_RE.match(t)
    if not m:
        return token
    n = int(m.group(1))
    if n not in swap:
        return token
    prefix = "f" if t[:1].lower() == "f" else ""
    return token.replace(t, f"{prefix}{swap[n]}", 1)


def apply(asm_text: str, args: dict) -> str:
    spec = args.get("swap")
    if not spec:
        raise ValueError("fp_relabel requires arg: swap (e.g. swap=0:13,11:12)")
    swap = _parse_swap(spec)
    if not swap:
        raise ValueError("fp_relabel: empty swap map")

    lines = asm_text.splitlines(keepends=True)
    any_changed = False
    for i, line in enumerate(lines):
        m = _OPCODE_RE.match(line)
        if not m:
            continue
        op = m.group("op")
        positions = FP_POSITIONS.get(op)
        if positions is None:
            continue
        newline_suffix = "\n" if line.endswith("\n") else ""
        rest = m.group("rest").rstrip("\r\n")
        operands = _split_operands(rest)
        if not operands:
            continue

        changed = False
        new_ops = list(operands)
        for pos in positions:
            if pos >= len(operands):
                continue
            new = _apply_to_token(operands[pos], swap)
            if new != operands[pos]:
                new_ops[pos] = new
                changed = True
        if changed:
            indent = m.group("indent")
            lines[i] = f"{indent}{op} {','.join(new_ops)}{newline_suffix}"
            any_changed = True

    if not any_changed:
        raise NoApplicableSite(
            f"fp_relabel swap={spec} matched no FP-operand site in the asm"
        )
    return "".join(lines)
