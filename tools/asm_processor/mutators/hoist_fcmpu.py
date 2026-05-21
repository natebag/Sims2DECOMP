"""hoist_fcmpu — move an `fcmpu` from after a sequence of store-float
instructions to BEFORE that sequence.

Use case: SN ProDG schedules `fcmpu cr0, fX, fY` tightly behind the `lfs`
that loads its second operand, then emits the store-float run that follows.
GCC's RTL scheduler sees no data dependency between the fcmpu and the
subsequent stfs writes and moves the fcmpu down to the END of the basic
block, producing:

    DOL (original):           GCC (compiled):
    lfs    f0, off(rN)        lis/lfs   ...
    fcmpu  cr0, f1, f0        stfs      f3, ...
    stfs   f3, off(rB)        stfs      f2, ...
    stfs   f2, off(rB)        stfs      f1, ...
    stfs   f1, off(rB)        stfs      f2, ...
    stfs   f2, off(rB)        fcmpu     cr0, f1, f0    ← here
    beq    .epilog            beq       .epilog

Both forms are semantically identical — cr0 is read by the trailing branch,
and the stfs writes don't touch f0/f1. The wall is byte-position-only.

This mutator:
  1. Locates an `fcmpu` line (selectable by `occurrence`, default first).
  2. Walks backwards from that line, counting consecutive lines whose opcode
     belongs to `store_ops` (default `{stfs}`).
  3. If `min_count` or more matching stores precede the fcmpu, moves the
     fcmpu line to the position immediately before the first one.

Manifest example:

    pipeline:
      - mutator: hoist_fcmpu
        args:
          occurrence: 0       # default
          store_ops: stfs     # default; comma-list for multi-opcode
          min_count: 1        # default; refuse if fewer stores above

Directive form:

    // ASMPROC_hoist_fcmpu:
    // ASMPROC_hoist_fcmpu: occurrence=1
    // ASMPROC_hoist_fcmpu: store_ops=stfs,stfd min_count=2

Refusal modes (NoApplicableSite — runtime skip):
- No `fcmpu` line in the asm.
- `occurrence` out of range.
- Fewer than `min_count` consecutive matching stores precede the chosen fcmpu.

Author-error modes (ValueError):
- `min_count` < 1.
- `store_ops` empty.

CALLER RESPONSIBILITIES:
- The fcmpu must not depend on any value written by the stores being crossed.
  The compiler already proved this for the lfs-then-store pattern (no aliasing),
  but a caller applying this to other patterns must verify.
- Branch operands using cr0 set by the fcmpu must still come after the hoisted
  fcmpu — i.e. don't apply this when a use of cr0 sits between the original
  fcmpu and the store run.

Validation targets (S16 Phase 1):
- EAnimController::SetTrackBlendSmooth(EACTrack*, ...) @ 0x802EE324 — 4 stfs
  precede the fcmpu in GCC output. After hoist_fcmpu + 3 swap_adj for
  surrounding li/lis/stb/lfs reorder, byte-match against DOL.
"""
from __future__ import annotations

import re

from . import NoApplicableSite

NAME = "hoist_fcmpu"

_INSN_RE = re.compile(r"^(?P<indent>[ \t]*)(?P<op>[A-Za-z_][A-Za-z0-9._]*)(?=\s|$)(?P<rest>.*)$")


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


def _parse_store_ops(spec) -> frozenset[str]:
    if isinstance(spec, (list, tuple, set, frozenset)):
        parts = [str(x).strip() for x in spec]
    else:
        parts = [p.strip() for p in str(spec).split(",")]
    parts = [p for p in parts if p]
    if not parts:
        raise ValueError("hoist_fcmpu: store_ops must be a non-empty list")
    return frozenset(parts)


def apply(asm_text: str, args: dict) -> str:
    occurrence = int(args.get("occurrence", 0))
    store_ops = _parse_store_ops(args.get("store_ops", "stfs"))
    min_count = int(args.get("min_count", 1))
    if min_count < 1:
        raise ValueError("hoist_fcmpu: min_count must be >= 1")
    cmp_op = str(args.get("cmp_op", "fcmpu")).strip()
    if not cmp_op:
        raise ValueError("hoist_fcmpu: cmp_op must be non-empty")

    lines = asm_text.splitlines(keepends=True)
    fcmpu_indices = [i for i, ln in enumerate(lines) if _opcode(ln) == cmp_op]
    if not fcmpu_indices:
        raise NoApplicableSite(f"hoist_fcmpu: no {cmp_op} line in asm")
    if occurrence >= len(fcmpu_indices):
        raise NoApplicableSite(
            f"hoist_fcmpu: requested occurrence {occurrence} but only "
            f"{len(fcmpu_indices)} {cmp_op} line(s) found"
        )
    f_idx = fcmpu_indices[occurrence]

    # Walk backwards from the line above the fcmpu, counting consecutive
    # store-op lines. Stop at the first non-matching opcode (including
    # blanks/labels/directives, which return None from _opcode and are
    # therefore not in store_ops).
    first_store_idx = f_idx
    j = f_idx - 1
    while j >= 0 and _opcode(lines[j]) in store_ops:
        first_store_idx = j
        j -= 1

    store_count = f_idx - first_store_idx
    if store_count < min_count:
        raise NoApplicableSite(
            f"hoist_fcmpu: only {store_count} consecutive {sorted(store_ops)} "
            f"line(s) precede {cmp_op} at index {f_idx} "
            f"(min_count={min_count})"
        )

    # Move the fcmpu line from f_idx to first_store_idx. Pop then insert.
    fcmpu_line = lines.pop(f_idx)
    lines.insert(first_store_idx, fcmpu_line)
    return "".join(lines)
