"""swap_cr_field — bidirectional swap of two CR fields across a region.

Use case: GCC's allocator picks a CR field for a compare (e.g., cr7 for
`cmpwi r3,0`) where the DOL allocator picked the other end of the CR
register file (e.g., cr0). The natural source structure cannot dictate
the CR allocation, so we synthesize the swap post-compile.

The swap is bidirectional (cr_a ↔ cr_b) within a bounded region of the .s
text. It transforms two PowerPC instruction families:

  - **cmp family** (`cmp`, `cmpi`, `cmpl`, `cmpli`, `cmpw`, `cmpwi`,
    `cmplw`, `cmplwi`, `cmpd`, `cmpdi`, `cmpld`, `cmpldi`): the first
    operand is the CR field (0-7). The mutator swaps that token.

  - **bc family** (`bc`, `bca`, `bcl`, `bcla`): the second operand is the
    BI field, encoded as `crfield*4 + cond_bit` (0=LT, 1=GT, 2=EQ, 3=SO).
    The mutator preserves the cond_bit and swaps the crfield.

Mnemonic conditional branches (`beq cr0, target`, `bne cr7, target`) are
also handled: when the first operand is `cr<N>` and N ∈ {a, b}, swap.

cc1plus typically emits `bc BO,BI,target` rather than mnemonic forms,
so the bc-handling is the primary path.

Manifest example (or directive in source):

    pipeline:
      - mutator: swap_cr_field
        args:
          cr_a: 0                    # first CR field
          cr_b: 7                    # second CR field
          start: "cmpwi 7,3,0"       # substring of first line in scope (inclusive)
          # One of:
          end: "cmpwi 0,31,0"        # substring of terminator (exclusive)
          # OR
          # count: 6                 # apply to N consecutive instruction lines

Directive form in source (one line):

    // ASMPROC_swap_cr_field: cr_a=0 cr_b=7 start=cmpwi 7,3,0 end=cmpwi 0,31,0

Scope semantics:
  - `start` is a substring matching the first line to include (inclusive).
    First occurrence is used.
  - `end` is a substring matching the terminator line (exclusive). The
    first occurrence AFTER `start` is used.
  - `count` is an alternative to `end`: process N consecutive lines from
    the start line (inclusive). Non-instruction lines (labels, directives,
    comments) are skipped but COUNTED toward the count.
  - If neither `end` nor `count` is given, the mutator processes only the
    `start` line (just that one).

Out-of-scope opcodes (raise unhandled for safety): `mcrf`, `mfcr`,
`mtcrf`, `crand`, `crandc`, `creqv`, `crnand`, `crnor`, `cror`, `crorc`,
`crxor`, `mcrxr`. If any of these appear in the swap region, the mutator
raises NoApplicableSite — extending it for those is a separate exercise.

Verify-before-save: always run `verify_match.sh` before committing a
directive recipe. Mutator authoring is deterministic per (asm_text, args),
so a passing verify on the target function is sufficient evidence of
byte-match.
"""
from __future__ import annotations

import re

from . import NoApplicableSite
from .insert_mr import _opcode

NAME = "swap_cr_field"


_CMP_OPCODES = frozenset({
    "cmp", "cmpi", "cmpl", "cmpli",
    "cmpw", "cmpwi", "cmplw", "cmplwi",
    "cmpd", "cmpdi", "cmpld", "cmpldi",
})

_BC_OPCODES = frozenset({"bc", "bca", "bcl", "bcla"})

# Mnemonic conditional branches that take an optional explicit CR field as
# their FIRST operand (e.g., `beq cr7, target`). When the first operand is
# `cr<N>`, it means that CR field — swap if N matches.
_MNEMONIC_BRANCH_OPCODES = frozenset({
    "beq", "bne", "bgt", "blt", "bge", "ble",
    "beq+", "bne+", "bgt+", "blt+", "bge+", "ble+",
    "beq-", "bne-", "bgt-", "blt-", "bge-", "ble-",
    "bso", "bns", "bun", "bnu",
})

# Opcodes that MUTATE CR fields directly (out of scope for this mutator).
_CR_MUTATING_OPCODES = frozenset({
    "mcrf", "mfcr", "mtcrf", "mtocrf", "mcrxr",
    "crand", "crandc", "creqv", "crnand", "crnor",
    "cror", "crorc", "crxor", "crset", "crclr", "crmove", "crnot",
})

# Match a CR token: optional 'cr' prefix + digit.
_CR_TOKEN_RE = re.compile(r"^(cr)?(\d)$", re.IGNORECASE)
_INSN_LINE_RE = re.compile(r"^([ \t]*)([A-Za-z_][A-Za-z0-9._+-]*)(\s+)(.*?)(\s*(?:[#;].*)?)$")


def _norm_cr(spec) -> int:
    s = str(spec).strip().lower()
    if s.startswith("cr"):
        s = s[2:]
    if not s.isdigit():
        raise ValueError(f"swap_cr_field: bad cr field {spec!r}")
    n = int(s)
    if not (0 <= n <= 7):
        raise ValueError(f"swap_cr_field: cr field out of range {spec!r}")
    return n


def _split_operands_no_strip(rest: str) -> list[str]:
    """Split operand body on commas; preserve each part (only outer strip done by caller)."""
    if not rest:
        return []
    return rest.split(",")


def _swap_cr_in_token(token: str, a: int, b: int) -> str:
    """If token is a bare CR field (e.g., '7' or 'cr7') matching a/b, swap.

    Preserves the original `cr` prefix style if present.
    """
    t = token.strip()
    m = _CR_TOKEN_RE.match(t)
    if not m:
        return token
    n = int(m.group(2))
    if n != a and n != b:
        return token
    new_n = b if n == a else a
    prefix = m.group(1) or ""
    return token.replace(t, f"{prefix}{new_n}", 1)


def _swap_bi_field(token: str, a: int, b: int) -> str:
    """If token is a numeric BI value in [a*4..a*4+3] or [b*4..b*4+3],
    swap field while preserving cond bit.
    """
    t = token.strip()
    if not t.isdigit():
        return token
    bi = int(t)
    if not (0 <= bi <= 31):
        return token
    field = bi // 4
    cond = bi % 4
    if field == a:
        new_bi = b * 4 + cond
    elif field == b:
        new_bi = a * 4 + cond
    else:
        return token
    return token.replace(t, str(new_bi), 1)


def _process_line(line: str, a: int, b: int) -> str:
    """Apply CR swap to a single .s line. Returns the (possibly) modified line."""
    op = _opcode(line)
    if op is None:
        return line
    op_lower = op.lower()
    if op_lower in _CR_MUTATING_OPCODES:
        raise NoApplicableSite(
            f"swap_cr_field: CR-mutating opcode {op!r} encountered in scope; "
            f"this mutator only handles cmp/bc families"
        )

    m = _INSN_LINE_RE.match(line.rstrip("\r\n"))
    if not m:
        return line
    leading, opcode, sep, operands_raw, comment_tail = m.groups()
    newline = ""
    if line.endswith("\r\n"):
        newline = "\r\n"
    elif line.endswith("\n"):
        newline = "\n"

    operands = _split_operands_no_strip(operands_raw)
    if not operands:
        return line
    changed = False

    if op_lower in _CMP_OPCODES:
        # First operand is CR field.
        new_first = _swap_cr_in_token(operands[0], a, b)
        if new_first != operands[0]:
            operands[0] = new_first
            changed = True
    elif op_lower in _BC_OPCODES:
        # bc BO, BI, target — second operand is BI.
        if len(operands) >= 2:
            new_second = _swap_bi_field(operands[1], a, b)
            if new_second != operands[1]:
                operands[1] = new_second
                changed = True
    elif op_lower in _MNEMONIC_BRANCH_OPCODES:
        # First operand may be cr<N>; if so, swap.
        if operands:
            new_first = _swap_cr_in_token(operands[0], a, b)
            if new_first != operands[0]:
                operands[0] = new_first
                changed = True

    if not changed:
        return line
    return f"{leading}{opcode}{sep}{','.join(operands)}{comment_tail}{newline}"


def apply(asm_text: str, args: dict) -> str:
    if "cr_a" not in args or "cr_b" not in args:
        raise ValueError("swap_cr_field requires args: cr_a, cr_b")
    a = _norm_cr(args["cr_a"])
    b = _norm_cr(args["cr_b"])
    if a == b:
        raise ValueError("swap_cr_field: cr_a and cr_b must differ")

    start_match = args.get("start")
    if not start_match:
        raise ValueError("swap_cr_field requires arg: start=<substring>")
    end_match = args.get("end")
    count = args.get("count")
    if end_match and count is not None:
        raise ValueError("swap_cr_field: specify only one of end/count, not both")
    if count is not None:
        try:
            count = int(count)
        except (TypeError, ValueError):
            raise ValueError(f"swap_cr_field: count must be int, got {count!r}") from None
        if count < 1:
            raise ValueError(f"swap_cr_field: count must be >= 1, got {count}")

    lines = asm_text.splitlines(keepends=True)
    start_idx = None
    for i, line in enumerate(lines):
        if start_match in line:
            start_idx = i
            break
    if start_idx is None:
        raise NoApplicableSite(f"swap_cr_field: no .s line contains start={start_match!r}")

    if end_match:
        end_idx = None
        for j in range(start_idx + 1, len(lines)):
            if end_match in lines[j]:
                end_idx = j  # exclusive
                break
        if end_idx is None:
            raise NoApplicableSite(
                f"swap_cr_field: no .s line after start contains end={end_match!r}"
            )
    elif count is not None:
        end_idx = min(start_idx + count, len(lines))  # exclusive
    else:
        end_idx = start_idx + 1  # only the start line

    new_lines = list(lines)
    any_changed = False
    for k in range(start_idx, end_idx):
        new_line = _process_line(new_lines[k], a, b)
        if new_line != new_lines[k]:
            new_lines[k] = new_line
            any_changed = True

    if not any_changed:
        raise NoApplicableSite(
            f"swap_cr_field: scope [{start_idx}..{end_idx}) had no cmp/bc lines using cr{a} or cr{b}"
        )

    return "".join(new_lines)
