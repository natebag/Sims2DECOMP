"""_helpers — shared primitives for `.s` line manipulation across mutators.

Used by `insert_mr`, `remove_mr`, and `force_alias_base` (Lane O, S13). Centralises
the line tokenization, register parsing, anchor/terminator scanning, and one-way
register-relabel logic that was previously duplicated.

Naming convention: public symbols (no leading underscore) are part of the
inter-mutator API; module-private regex constants keep a leading underscore.

Soft-soft notes from OpusReviewGuy v5 verdict:
  - Call-opcode set (`CALL_OPCODES`) is an EXPLICIT list rather than a regex
    so a quick grep for any opcode tells you whether the abort-scan covers it.
    Including `bcl/bcla/bdnzl/bdzl` per the v5 spec.
  - `bdnzla`/`bdzla` (link-form absolute decrement branches) are NOT in the
    list because SN ProDG never emits them from C++. If a future target
    actually triggers them, add explicitly — do not regex-widen the set.
"""
from __future__ import annotations

import re
from typing import Iterable

from . import NoApplicableSite

# ---------- Regex primitives ----------

_INSN_RE = re.compile(
    r"^(?P<indent>[ \t]*)(?P<op>[A-Za-z_][A-Za-z0-9._]*)(?=\s|$)(?P<rest>.*)$"
)
_BARE_REG_RE = re.compile(r"^r?(\d{1,2})$")
_MEM_FORM_RE = re.compile(r"^(?P<imm>[^(]+)\((?P<reg>r?\d{1,2})\)$")


# Opcodes that aren't subject to GPR relabel (branch hint encoding etc).
NON_GPR_INT_OPCODES: frozenset[str] = frozenset({
    "bc", "bca", "bcl", "bcla", "bclr", "bcctr", "bclrl", "bcctrl",
    "tw", "twi", "td", "tdi",
    "crand", "crandc", "creqv", "crnand", "crnor", "cror", "crorc", "crxor",
    "mcrf", "mcrxr",
    "mtfsfi", "mtfsf", "mtfsb0", "mtfsb1",
    "sc", "nop",
})


# Branch-and-link / call opcodes that clobber LR and the SN ABI volatile
# registers r9-r12. Used by `force_alias_base` to abort if any call
# instruction lies inside the alias-live window — the alias register would
# not survive across the call. Explicit list (per ORG verdict): grep-friendly
# and avoids the under-coverage trap of regex shortcuts.
CALL_OPCODES: frozenset[str] = frozenset({
    "bl", "bla",
    "bctrl", "bclrl", "bcctrl", "blrl",
    "bcl", "bcla",
    "bdnzl", "bdzl",
})


# ---------- Register parsing ----------

def norm_reg(spec: str) -> int:
    """Normalise a register spec (`r9`, `R9`, `9`) to its integer index.

    Raises ValueError for anything outside the 32-register file. Author errors
    surface here — runtime skips are NoApplicableSite, raised by callers.
    """
    s = spec.strip().lstrip("rR")
    if not s.isdigit():
        raise ValueError(f"bad register {spec!r}")
    n = int(s)
    if not (0 <= n <= 31):
        raise ValueError(f"register out of range {spec!r}")
    return n


def parse_relabel(spec: str) -> list[tuple[int, int]]:
    """Parse a comma-separated `from:to` relabel spec into ordered pairs.

    Identity pairs (`a:a`) are silently dropped. Order is preserved so callers
    that depend on left-to-right application semantics behave predictably.
    """
    pairs: list[tuple[int, int]] = []
    for pair in spec.split(","):
        pair = pair.strip()
        if not pair:
            continue
        if ":" not in pair:
            raise ValueError(f"bad relabel pair {pair!r} (need 'a:b')")
        a_s, b_s = [s.strip() for s in pair.split(":", 1)]
        a = norm_reg(a_s)
        b = norm_reg(b_s)
        if a == b:
            continue
        pairs.append((a, b))
    return pairs


# ---------- Line tokenization ----------

def opcode(line: str) -> str | None:
    """Return the opcode of an asm line, or None for blanks/labels/directives.

    Comments (`;`, `#`, `/* */`, `//`) and assembler directives (`.foo`) are
    skipped. Useful for terminator scans (`opcode(line) == "blr"`) and for
    asserting the opcode of a matched line before mutating it.
    """
    stripped = line.strip()
    if not stripped or stripped.startswith((";", "#", "/*", "//")):
        return None
    if stripped.endswith(":"):
        return None
    if stripped.startswith("."):
        return None
    m = _INSN_RE.match(line)
    return m.group("op") if m else None


def split_operands(rest: str) -> list[str]:
    """Split the post-opcode portion of a line into a list of operand strings.

    Strips inline `;` and `#` comments. Returns [] for blank tails.
    """
    body = rest.strip()
    if not body or body.startswith((";", "#")):
        return []
    if "#" in body:
        body = body.split("#", 1)[0].rstrip()
    if ";" in body:
        body = body.split(";", 1)[0].rstrip()
    return [op.strip() for op in body.split(",")]


# ---------- One-way GPR relabel ----------

def relabel_token(token: str, mapping: dict[int, int]) -> str:
    """Apply a one-way `from:to` mapping to one operand token.

    Handles bare-register tokens (`r9`, `9`) and memory form tokens
    (`12(r9)`). Returns the token unchanged if no mapping applies.
    """
    t = token.strip()
    if not t:
        return token
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


def relabel_line(line: str, mapping: dict[int, int]) -> str:
    """Apply a one-way `from:to` mapping to GPR operands on a single line.

    Skips opcodes in `NON_GPR_INT_OPCODES` (branch-hint and CR-bit ops, where
    the operand fields encode something other than GPR indices).
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
    op = m.group("op").lower()
    if op in NON_GPR_INT_OPCODES:
        return line
    head = m.group("indent") + m.group("op")
    rest = m.group("rest")
    operands = split_operands(rest)
    if not operands:
        return line
    new_ops = [relabel_token(o, mapping) for o in operands]
    if new_ops == operands:
        return line
    prefix_match = re.match(r"^(\s*)", rest)
    prefix = prefix_match.group(1) if prefix_match else " "
    return head + prefix + ", ".join(new_ops) + newline


# ---------- Anchor / terminator scans ----------

def find_match_index(
    lines: list[str],
    needle: str,
    occurrence: int = 0,
    *,
    label: str = "",
) -> int:
    """Return the index of the Nth line containing `needle`.

    Raises NoApplicableSite if no line matches or `occurrence` is out of range.
    `label` is a short prefix for the error message (e.g. mutator name).
    """
    prefix = f"{label}: " if label else ""
    hits = [i for i, line in enumerate(lines) if needle in line]
    if not hits:
        raise NoApplicableSite(f"{prefix}no .s line contains {needle!r}")
    if occurrence >= len(hits):
        raise NoApplicableSite(
            f"{prefix}requested occurrence {occurrence} but only {len(hits)} match {needle!r}"
        )
    return hits[occurrence]


def find_anchor_index(
    lines: list[str],
    after: str | None,
    before: str | None,
    occurrence: int = 0,
    *,
    label: str = "",
) -> tuple[int, int]:
    """Locate an insertion anchor and return (anchor_idx, insert_offset).

    `insert_offset` is 1 when `after` was supplied (insert AFTER the anchor)
    and 0 when `before` was supplied (insert AT the anchor's index, pushing it
    down). Exactly one of `after`/`before` must be set; this function does NOT
    enforce that — the caller's argument validation is responsible.
    """
    needle = after if after else before
    if needle is None:
        raise ValueError("find_anchor_index needs after or before")
    anchor_idx = find_match_index(lines, needle, occurrence, label=label)
    insert_offset = 1 if after else 0
    return anchor_idx, insert_offset


def find_terminator(
    lines: list[str],
    start_idx: int,
    until: str | None,
    *,
    include_blr_line: bool = True,
) -> int:
    """Return the exclusive end index for a relabel/scan window.

    Scan starts at `start_idx`. If `until` is supplied, stop at the FIRST line
    containing that substring (returned exclusive). If `until` is None, walk
    until the first line whose opcode is `blr`; by default the blr line is
    INCLUDED in the window (returned index is one past blr). Pass
    `include_blr_line=False` to terminate exclusive of the blr.

    Returns `len(lines)` if no terminator is found — callers can treat that
    as "to end of file" without a special case.
    """
    for j in range(start_idx, len(lines)):
        line = lines[j]
        if until is not None:
            if until in line:
                return j
        else:
            if opcode(line) == "blr":
                return j + 1 if include_blr_line else j
    return len(lines)


# ---------- Convenience iterator ----------

def iter_match_indices(lines: list[str], needle: str) -> Iterable[int]:
    """Yield indices of every line containing `needle`. Useful for scans
    that don't follow the single-occurrence selector pattern."""
    for i, line in enumerate(lines):
        if needle in line:
            yield i
