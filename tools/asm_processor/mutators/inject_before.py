"""inject_before — insert one or more new .s lines immediately BEFORE an anchor.

Use case: DOL contains a sequence of instructions that GCC's optimizer elides
or never emits (dead-load assertions, redundant loads/tests). When source-side
volatile tricks fail to materialize the sequence (GCC 2.95 O2 still elides
volatile slot-pointer dereferences in many cases), this mutator synthesizes
the missing block post-cc1plus.

Trigger: caller specifies a multi-line block (`lines`) and an anchor line
substring (`before`). The mutator parses the lines, finds the first occurrence
of the anchor (or the Nth via `occurrence`), and inserts the new lines
immediately above it. Indentation matches the anchor line.

Manifest example:

    pipeline:
      - mutator: inject_before
        args:
          before: "addi 3,3,820"
          lines: "lwz 9,8(3); lwz 9,856(9); cmpwi 9,0; lwz 3,8(3)"
          occurrence: 0

Directive form (use shlex-quoted multi-line via `;` separator):

    // ASMPROC_inject_before: before="addi 3,3,820" lines="lwz 9,8(3); lwz 9,856(9); cmpwi 9,0; lwz 3,8(3)"

Refusal modes (NoApplicableSite — runtime skip):
- `before` substring not found at any line.
- `occurrence` out of range for the number of anchor matches.

Author-error modes (ValueError — raised, surfaces during authoring):
- Missing required args (before / lines).
- Empty `lines` argument (nothing to inject).

CALLER RESPONSIBILITIES (this mutator does NOT auto-adjust):
- Branch target offsets in adjacent bc/b instructions (asm-processor's later
  passes / assembler should handle relative branch encoding, but absolute
  targets baked into operands need caller fixup).
- Register liveness across the injection point — caller must ensure the
  injected lines use registers that won't clobber a value needed later.
- Stack frame / prologue assumptions — injecting before the function prologue
  is supported but rarely sensible.

Limits:
- Single contiguous block at one anchor per directive invocation. Multiple
  injection sites require multiple directives.
- No automatic indentation normalization beyond matching the anchor's leading
  whitespace; injected lines should be unindented (mutator prepends the
  anchor's indent to each line).
- Line separator in `lines` is `;` (semicolon). To inject a literal semicolon
  inside an operand, escape it via shlex quoting or use a different separator
  via the `sep` argument.
"""
from __future__ import annotations

import re

from . import NoApplicableSite
from ._helpers import find_match_index


NAME = "inject_before"


def _parse_lines(spec: str, sep: str = ";") -> list[str]:
    """Split `spec` on `sep`, trim each piece, drop empty pieces."""
    parts = [p.strip() for p in spec.split(sep)]
    return [p for p in parts if p]


def apply(asm_text: str, args: dict) -> str:
    before = args.get("before")
    lines_arg = args.get("lines")
    occurrence = int(args.get("occurrence", 0))
    sep = args.get("sep", ";")
    # replace: if present, the anchor line is replaced instead of kept.
    # Empty string removes the anchor; any other value substitutes it.
    replace = args.get("replace")

    if not before:
        raise ValueError("inject_before requires arg: before=<anchor substring>")
    if not lines_arg:
        raise ValueError("inject_before requires arg: lines=<sep-separated insns>")

    new_insns = _parse_lines(lines_arg, sep)
    if not new_insns:
        raise ValueError(
            f"inject_before: lines={lines_arg!r} parsed to empty list "
            f"(no instructions after split on {sep!r})"
        )

    lines = asm_text.splitlines(keepends=True)
    anchor_idx = find_match_index(lines, before, occurrence, label="inject_before")

    # Match the anchor's indentation for each injected line.
    anchor_line = lines[anchor_idx]
    indent_match = re.match(r"^([ \t]*)", anchor_line)
    indent = indent_match.group(1) if indent_match else "\t"

    injected = [f"{indent}{insn}\n" for insn in new_insns]

    if replace is None:
        # Default: keep the anchor line after the injected lines.
        new_lines = lines[:anchor_idx] + injected + lines[anchor_idx:]
    elif replace == "":
        # Empty replace: delete the anchor line entirely.
        new_lines = lines[:anchor_idx] + injected + lines[anchor_idx + 1:]
    else:
        # Non-empty replace: substitute the anchor line with the replacement.
        new_lines = lines[:anchor_idx] + injected + [f"{indent}{replace}\n"] + lines[anchor_idx + 1:]

    return "".join(new_lines)
