"""this_alias_rN — insert `mr rN, 3` after the prologue and rewrite r3->rN
references downstream so subsequent `this`-relative accesses go through rN
instead of r3.

Use case: SN ProDG often allocates a callee-saved register (commonly r11 in
ctors, r9 in member methods) to hold `this` after the prologue, leaving r3
free to be the return-value register. The function emits a single
`mr rN, r3` early, then all `this->field` loads/stores read/write through
rN. GCC's allocator instead keeps `this` in r3 and uses r3 directly as the
base register for every field access. Same semantics, +1 instruction (the
mr) and different base-register in every memory operand — pure byte-position
wall.

This mutator:
  1. Locates an `after` anchor line (typically the last prologue store such
     as `stw 0,X(1)`).
  2. Inserts `mr <reg>, 3` immediately after that anchor (matching the
     anchor's indentation).
  3. From the line following the insertion to the window end, rewrites
     every r3 operand to r<reg>, EXCEPT on lines that re-define r3:
       - `li 3, ...`     (sets r3 to a return value)
       - `li.  3, ...`   (record-form variant)
       - `mr 3, ...`     (copies into r3)
       - `mr. 3, ...`    (record-form variant)
     The destination operand of these instructions intentionally stays as
     r3 so the return-value plumbing remains correct.
  4. Window end is either the line containing the `until` substring, the
     first `bl`/`bla`/`bctrl`/`blrl` call (which clobbers r3), or `blr`
     (function exit) — whichever comes first.

Manifest example:

    pipeline:
      - mutator: this_alias_rN
        args:
          reg: 11
          after: "stw 0,20(1)"      # last prologue store
          # until: "blr"             # optional explicit end

Directive form:

    // ASMPROC_this_alias_rN: reg=11 after="stw 0,20(1)"
    // ASMPROC_this_alias_rN: reg=9 after="stwu 1,-16(1)" until="bl"

Refusal modes (NoApplicableSite — runtime skip):
- `after` substring not found at any line.
- `until` substring not found (only if explicitly supplied).
- No r3 operand uses in the window (mutator would be a no-op).

Author-error modes (ValueError):
- `reg` out of range (must be 0..31, conventionally 9 or 11).
- `reg` == 3 (would be a no-op alias).
- Missing required arg `after`.

CALLER RESPONSIBILITIES (this mutator does NOT auto-verify):
- The chosen register must not be live at the insertion point — caller
  inspects the .s/disasm to confirm rN is free at that program point.
- The window must not span a `bl` or other r3-clobbering call before all
  this-uses are rewritten (default behavior stops at the first call to
  enforce this; supply `until` only if you have audited liveness).
- If the function reads r3 AFTER setting a return value (e.g. via mr 3,X
  then bl), the rewrite stops at that re-definition by design but any
  this-use beyond it would NOT be rewritten — caller must check.

Validation targets (S16 Phase 4, parked by OpusWorker 2026-05-21):
- 0x800B4214 Commander::Commander (60B) — alias to r11 (ctor pattern).
- 0x8004A2E0 BBI::InventoryItem::CopyTo (60B) — alias to r9 (member method).
2-instance pair on first ship → 2-INSTANCE-CANDIDATE.
"""
from __future__ import annotations

import re

from . import NoApplicableSite
from ._helpers import CALL_OPCODES, find_match_index, opcode, relabel_line


NAME = "this_alias_rN"

# Opcodes whose FIRST operand is a register destination we should leave
# untouched (so r3 stays as r3 when it's being re-defined as a return value
# or new alias). Includes record-form variants.
_R3_DEST_OPCODES: frozenset[str] = frozenset({
    "li", "li.",
    "lis", "lis.",
    "mr", "mr.",
    "neg", "neg.",
    "not", "not.",
})


def _line_redefines_r3(line: str) -> bool:
    """Return True if `line` is one of the opcodes whose first operand
    sets r3 directly (li/lis/mr/neg/not). We skip these so the rewrite
    leaves the destination as r3.
    """
    op = opcode(line)
    if op is None:
        return False
    if op not in _R3_DEST_OPCODES:
        return False
    # Check first operand is `3` (or `r3`). Operand spelling per SN ProDG
    # is bare numeric (`mr 3,11`); we tolerate `r` prefix defensively.
    body = line.split(op, 1)[1].strip()
    if not body:
        return False
    first = body.split(",", 1)[0].strip()
    return first in ("3", "r3", "R3")


def apply(asm_text: str, args: dict) -> str:
    if "reg" not in args:
        raise ValueError("this_alias_rN: missing required arg `reg`")
    try:
        reg = int(args["reg"])
    except (TypeError, ValueError):
        raise ValueError(
            f"this_alias_rN: `reg` must be an integer (got {args['reg']!r})"
        ) from None
    if not (0 <= reg <= 31):
        raise ValueError(f"this_alias_rN: reg out of range ({reg})")
    if reg == 3:
        raise ValueError("this_alias_rN: reg=3 would be a no-op alias")

    after = args.get("after")
    if not after:
        raise ValueError("this_alias_rN: missing required arg `after`")
    until = args.get("until")

    lines = asm_text.splitlines(keepends=True)
    anchor_idx = find_match_index(lines, after, label="this_alias_rN")

    # Match the anchor's indentation for the injected mr.
    indent_match = re.match(r"^([ \t]*)", lines[anchor_idx])
    indent = indent_match.group(1) if indent_match else "\t"
    mr_line = f"{indent}mr {reg},3\n"
    lines.insert(anchor_idx + 1, mr_line)

    # Compute window end. Default: stop at first call (which clobbers r3)
    # or blr/blrl. If `until` is supplied, prefer it.
    window_start = anchor_idx + 2  # one past the just-inserted mr line
    window_end = len(lines)
    if until:
        for j in range(window_start, len(lines)):
            if until in lines[j]:
                window_end = j + 1  # inclusive
                break
        else:
            raise NoApplicableSite(
                f"this_alias_rN: `until` substring {until!r} not found"
            )
    else:
        for j in range(window_start, len(lines)):
            op = opcode(lines[j])
            if op in CALL_OPCODES or op == "blr":
                window_end = j  # exclusive — don't rewrite the call line
                break

    mapping = {3: reg}
    any_changed = False
    for i in range(window_start, window_end):
        if _line_redefines_r3(lines[i]):
            continue
        new_line = relabel_line(lines[i], mapping)
        if new_line != lines[i]:
            lines[i] = new_line
            any_changed = True

    if not any_changed:
        # Drop the inserted mr — there's nothing to alias.
        del lines[anchor_idx + 1]
        raise NoApplicableSite(
            "this_alias_rN: no r3 operand uses in the window "
            f"(reg={reg}, after={after!r}, window=[{window_start},{window_end}))"
        )

    return "".join(lines)
