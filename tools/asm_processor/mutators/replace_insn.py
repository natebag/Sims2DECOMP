"""replace_insn — substring-replace on one matched .s line.

STATUS: STANDARD

Use case: Category-4 walls where the compiled instruction encoding differs
in an immediate field or condition encoding that no register-rename mutator
can reach (immediates > 31, BO/BI fields in bc instructions, etc.).

The canonical target is comparison-normalization divergence between SN GCC
v1.76 and the DOL compiler: `c >= N` compiles to `cmpwi N-1; bgt` in some
translation units but the DOL uses `cmpwi N; bge`. The semantic difference
is nil; the byte difference is real. This mutator provides the escape hatch.

Args:
    match       (str, required)  — substring to identify the target line.
                                   Must match exactly ONE line OR the
                                   `occurrence` index must be in range.
    replacement (str, required)  — replacement text. Substituted in-place
                                   for the `match` substring within the line.
                                   Leading whitespace and trailing comments /
                                   newlines are preserved because the
                                   substitution operates only on the matched
                                   substring, not the whole line.
    occurrence  (int, default 0) — 0-indexed; which of the matching lines
                                   to rewrite. Use 0 for the first, 1 for
                                   the second, etc.

Directive form:

    // ASMPROC_replace_insn: match="cmpwi 0,0,33" replacement="cmpwi 0,0,34"
    // ASMPROC_replace_insn: match="bc 12,1,.L7" replacement="bc 4,0,.L7" occurrence=0

Refusal modes (NoApplicableSite — runtime skip):
  - `match` not found in any line.
  - `occurrence` index out of range.
  - Substitution would produce no change (match == replacement, or the
    replacement substring already exists at the target line).

Author-error modes (ValueError — raised, surfaces during authoring):
  - Missing required arg `match` or `replacement`.

Composition discipline:
  `match` sees POST-MUTATION state from earlier pipeline directives.
  Hand-trace the .s through all prior directives before writing `match`.
  See `feedback_multidirective_composition.md`.
"""
from __future__ import annotations

from . import NoApplicableSite
from ._helpers import find_match_index

NAME = "replace_insn"


def apply(asm_text: str, args: dict) -> str:
    needle = args.get("match")
    replacement = args.get("replacement")
    if needle is None:
        raise ValueError("replace_insn: missing required arg `match`")
    if replacement is None:
        raise ValueError("replace_insn: missing required arg `replacement`")

    occurrence = int(args.get("occurrence", 0))

    if needle == replacement:
        raise NoApplicableSite(
            f"replace_insn: match and replacement are identical ({needle!r})"
        )

    lines = asm_text.splitlines(keepends=True)
    idx = find_match_index(lines, needle, occurrence, label="replace_insn")

    original = lines[idx]
    if needle not in original:
        raise NoApplicableSite(
            f"replace_insn: {needle!r} not in line {idx}: {original.rstrip()!r}"
        )

    new_line = original.replace(needle, replacement, 1)
    if new_line == original:
        raise NoApplicableSite(
            f"replace_insn: substitution produced no change on line {idx}"
        )

    lines[idx] = new_line
    return "".join(lines)
