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
from typing import Iterable

from . import NoApplicableSite

NAME = "insert_mr"


_INSN_RE = re.compile(
    r"^(?P<indent>[ \t]*)(?P<op>[A-Za-z_][A-Za-z0-9._]*)(?=\s|$)(?P<rest>.*)$"
)
_BARE_REG_RE = re.compile(r"^r?(\d{1,2})$")
_MEM_FORM_RE = re.compile(r"^(?P<imm>[^(]+)\((?P<reg>r?\d{1,2})\)$")


def _norm_reg(spec: str) -> int:
    s = spec.strip().lstrip("rR")
    if not s.isdigit():
        raise ValueError(f"insert_mr: bad register {spec!r}")
    n = int(s)
    if not (0 <= n <= 31):
        raise ValueError(f"insert_mr: register out of range {spec!r}")
    return n


def _parse_relabel(spec: str) -> list[tuple[int, int]]:
    pairs: list[tuple[int, int]] = []
    for pair in spec.split(","):
        pair = pair.strip()
        if not pair:
            continue
        if ":" not in pair:
            raise ValueError(f"insert_mr: bad relabel pair {pair!r} (need 'a:b')")
        a_s, b_s = [s.strip() for s in pair.split(":", 1)]
        a = _norm_reg(a_s)
        b = _norm_reg(b_s)
        if a == b:
            continue
        pairs.append((a, b))
    return pairs


def _opcode(line: str) -> str | None:
    stripped = line.strip()
    if not stripped or stripped.startswith((";", "#", "/*", "//")):
        return None
    if stripped.endswith(":"):
        return None
    if stripped.startswith("."):
        return None
    m = _INSN_RE.match(line)
    return m.group("op") if m else None


def _relabel_token(token: str, mapping: dict[int, int]) -> str:
    """Apply one-way relabel to a single operand token."""
    t = token.strip()
    if not t:
        return token
    # Memory form imm(rN)
    mm = _MEM_FORM_RE.match(t)
    if mm:
        reg_tok = mm.group("reg").strip()
        rm = _BARE_REG_RE.match(reg_tok)
        if rm:
            n = int(rm.group(1))
            if n in mapping:
                prefix = "r" if reg_tok[:1].lower() == "r" else ""
                return token.replace(
                    f"({reg_tok})", f"({prefix}{mapping[n]})", 1
                )
        return token
    bm = _BARE_REG_RE.match(t)
    if bm:
        n = int(bm.group(1))
        if n not in mapping:
            return token
        prefix = "r" if t[:1].lower() == "r" else ""
        return token.replace(t, f"{prefix}{mapping[n]}", 1)
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


# Opcodes that aren't subject to GPR relabel (branch hint encoding etc).
_NON_GPR_INT_OPCODES = frozenset({
    "bc", "bca", "bcl", "bcla", "bclr", "bcctr", "bclrl", "bcctrl",
    "tw", "twi", "td", "tdi",
    "crand", "crandc", "creqv", "crnand", "crnor", "cror", "crorc", "crxor",
    "mcrf", "mcrxr",
    "mtfsfi", "mtfsf", "mtfsb0", "mtfsb1",
    "sc", "nop",
})


def _relabel_line(line: str, mapping: dict[int, int]) -> str:
    """Apply one-way mapping to GPR operands on one .s line."""
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
    op = m.group("op").lower()
    if op in _NON_GPR_INT_OPCODES:
        return line
    head = m.group("indent") + m.group("op")
    rest = m.group("rest")
    operands = _split_operands(rest)
    if not operands:
        return line
    new_ops = [_relabel_token(o, mapping) for o in operands]
    if new_ops == operands:
        return line
    # Preserve any spacing prefix in `rest` (between op and first operand).
    prefix_match = re.match(r"^(\s*)", rest)
    prefix = prefix_match.group(1) if prefix_match else " "
    return head + prefix + ", ".join(new_ops) + newline


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
    src = _norm_reg(str(src_arg))
    dst = _norm_reg(str(dst_arg))
    if src == dst:
        raise ValueError("insert_mr: src and dst must differ")
    occurrence = int(args.get("occurrence", 0))

    relabel_spec = args.get("relabel", "")
    relabel_pairs = _parse_relabel(relabel_spec) if relabel_spec else []
    relabel_map: dict[int, int] = dict(relabel_pairs)

    until_match = args.get("until")  # optional substring; default = first 'blr' after insertion

    needle = after if after else before
    lines = asm_text.splitlines(keepends=True)
    hits = [i for i, line in enumerate(lines) if needle in line]
    if not hits:
        raise NoApplicableSite(f"insert_mr: no .s line contains {needle!r}")
    if occurrence >= len(hits):
        raise NoApplicableSite(
            f"insert_mr: requested occurrence {occurrence} but only {len(hits)} match {needle!r}"
        )
    anchor_idx = hits[occurrence]

    # Build the inserted mr line (cc1plus bare-numeric form).
    # Use the same indent as the anchor line (after stripping \r\n).
    anchor_line = lines[anchor_idx]
    indent_match = re.match(r"^([ \t]*)", anchor_line)
    indent = indent_match.group(1) if indent_match else "\t"
    mr_line = f"{indent}mr {dst},{src}\n"

    insert_idx = anchor_idx + 1 if after else anchor_idx
    new_lines = lines[:insert_idx] + [mr_line] + lines[insert_idx:]

    # Apply optional relabel to lines after the insertion until terminator.
    if relabel_map:
        terminator_idx = len(new_lines)
        for j in range(insert_idx + 1, len(new_lines)):
            line = new_lines[j]
            if until_match:
                if until_match in line:
                    terminator_idx = j  # exclusive
                    break
            else:
                op = _opcode(line)
                if op == "blr":
                    terminator_idx = j + 1  # include blr line; actually relabel up to AND including the blr line
                    break
        for j in range(insert_idx + 1, terminator_idx):
            new_lines[j] = _relabel_line(new_lines[j], relabel_map)

    return "".join(new_lines)
