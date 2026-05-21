"""self_return_blr — collapse a `cmpwi rA, K; beq .case_K; ... .case_K: li
rA, K; blr` pattern into the single `beqlr` PowerPC self-return idiom.

Use case: switch statements where one case returns the SAME value as the
case label (e.g. `case 16: return 16;`). DOL exploits the fact that the
switch argument is already in rA (typically r3) and emits a single `beqlr`
— branch-and-return — instead of GCC's `beq .case_X; ...; .case_X: li rA, X;
blr` 3-instruction sequence. Pure compiler-choice byte-position wall; same
semantics.

DOL pattern (target):
    cmpwi cr0, rA, K
    beqlr

GCC compiled pattern (current):
    cmpwi 0, rA, K
    bc 12, 2, .L<label>   ; beq cr0
    ...
    .L<label>:
    li rA, K
    blr

The mutator:
  1. Locates a `cmpwi 0, rA, K` line (occurrence-th, default 0).
  2. Confirms the next non-blank/non-comment line is `bc 12, 2, .L<label>`
     (the `beq` extended-mnemonic decoded form GCC emits).
  3. Confirms a `.L<label>:` block exists later with EXACTLY:
       .L<label>:
       li rA, K
       blr
  4. Rewrites the `bc 12,2,.L<label>` line to `bclr 12,2,0` (= beqlr).
  5. Deletes the 3-line case block.

After the transformation, no instruction references .L<label> anymore so
the assembler resolves cleanly.

Manifest example:

    pipeline:
      - mutator: self_return_blr
        args:
          reg: 3                # register holding the value (default 3)
          # value: 16            # optional — restrict to a specific K
          # occurrence: 0        # which matching site to act on (default 0)

Directive form:

    // ASMPROC_self_return_blr: reg=3 value=16
    // ASMPROC_self_return_blr: reg=3 occurrence=1

Refusal modes (NoApplicableSite — runtime skip):
- No `cmpwi 0,rA,K` line matches the (reg, value, occurrence) selector.
- The `bc 12,2,.L*` line is not immediately after the cmpwi.
- The target label block is missing OR its `li`/`blr` shape is wrong OR
  the loaded immediate doesn't equal the cmpwi immediate.

Author-error modes (ValueError):
- `reg` out of range.
- `value` not an integer.

Validation targets (S16 — parked by OpusWorker 2026-05-21):
- 0x80146614 TileWalls::GetOppositeSegment (108B) — 2 sites (case 16, case 32)
- 0x801466D4 TileWalls::GetWallBetween (120B) — likely same pattern (2nd instance)
2-instance pair → 2-INSTANCE-CANDIDATE on first ship if both crack.
"""
from __future__ import annotations

import re

from . import NoApplicableSite


NAME = "self_return_blr"


_CMPWI_RE = re.compile(
    r"^(?P<indent>[ \t]*)cmpwi[ \t]+0[ \t]*,[ \t]*(?P<reg>\d{1,2})[ \t]*,[ \t]*(?P<imm>-?\d+)\b"
)
_BEQ_RE = re.compile(
    r"^(?P<indent>[ \t]*)bc[ \t]+12[ \t]*,[ \t]*2[ \t]*,[ \t]*(?P<label>\.L\w+)"
)
_LABEL_RE_TMPL = r"^[ \t]*{label}[ \t]*:[ \t]*$"
_LI_RE = re.compile(r"^[ \t]*li[ \t]+(?P<reg>\d{1,2})[ \t]*,[ \t]*(?P<imm>-?\d+)\b")
_BLR_RE = re.compile(r"^[ \t]*blr\b")
_BLANK_OR_COMMENT_RE = re.compile(r"^[ \t]*(#|;|$)")


def _next_real_line(lines: list[str], start: int) -> int:
    """Return the index of the next non-blank/non-comment line at/after start.
    Returns len(lines) if none."""
    for i in range(start, len(lines)):
        if _BLANK_OR_COMMENT_RE.match(lines[i]):
            continue
        return i
    return len(lines)


def apply(asm_text: str, args: dict) -> str:
    try:
        reg = int(args.get("reg", 3))
    except (TypeError, ValueError):
        raise ValueError(
            f"self_return_blr: reg must be an integer (got {args.get('reg')!r})"
        ) from None
    if not (0 <= reg <= 31):
        raise ValueError(f"self_return_blr: reg out of range ({reg})")

    value_filter = args.get("value")
    if value_filter is not None:
        try:
            value_filter = int(value_filter)
        except (TypeError, ValueError):
            raise ValueError(
                f"self_return_blr: value must be an integer (got {args.get('value')!r})"
            ) from None

    occurrence = int(args.get("occurrence", 0))

    lines = asm_text.splitlines(keepends=True)

    # Collect candidate (cmpwi_idx, beq_idx, label, K) tuples by scanning.
    candidates: list[tuple[int, int, str, int]] = []
    for i in range(len(lines)):
        m = _CMPWI_RE.match(lines[i])
        if not m:
            continue
        if int(m.group("reg")) != reg:
            continue
        K = int(m.group("imm"))
        if value_filter is not None and K != value_filter:
            continue
        # Check next non-blank line is the beq.
        j = _next_real_line(lines, i + 1)
        if j == len(lines):
            continue
        beq_m = _BEQ_RE.match(lines[j])
        if not beq_m:
            continue
        candidates.append((i, j, beq_m.group("label"), K))

    if occurrence >= len(candidates):
        raise NoApplicableSite(
            f"self_return_blr: requested occurrence {occurrence}, found "
            f"{len(candidates)} cmpwi/beq candidate(s) "
            f"(reg={reg}, value={value_filter})"
        )

    cmpwi_idx, beq_idx, label, K = candidates[occurrence]

    # Find the target label block.
    label_re = re.compile(_LABEL_RE_TMPL.format(label=re.escape(label)))
    label_idx = -1
    for k in range(len(lines)):
        if label_re.match(lines[k]):
            label_idx = k
            break
    if label_idx < 0:
        raise NoApplicableSite(
            f"self_return_blr: target label {label} not found for "
            f"cmpwi/beq at lines {cmpwi_idx+1}/{beq_idx+1}"
        )

    # Confirm shape: label, li rA,K, blr (allowing blank/comment lines between
    # the label and the li, but conventionally they are consecutive).
    li_idx = _next_real_line(lines, label_idx + 1)
    blr_idx = _next_real_line(lines, li_idx + 1)
    if li_idx == len(lines) or blr_idx == len(lines):
        raise NoApplicableSite(
            f"self_return_blr: label {label} block truncated (no li/blr lines)"
        )
    li_m = _LI_RE.match(lines[li_idx])
    if not li_m:
        raise NoApplicableSite(
            f"self_return_blr: expected `li` after {label}, got: "
            f"{lines[li_idx].rstrip()!r}"
        )
    if int(li_m.group("reg")) != reg or int(li_m.group("imm")) != K:
        raise NoApplicableSite(
            f"self_return_blr: {label} block has `li {li_m.group('reg')},"
            f"{li_m.group('imm')}` but expected `li {reg},{K}`"
        )
    if not _BLR_RE.match(lines[blr_idx]):
        raise NoApplicableSite(
            f"self_return_blr: expected `blr` after `li` in {label}, got: "
            f"{lines[blr_idx].rstrip()!r}"
        )

    # Confirm the label is referenced ONLY by the beq we're transforming.
    # If anything else references this label, removing the block would orphan
    # those references. We check by counting non-defining mentions.
    label_token = label
    ref_count = 0
    for k, ln in enumerate(lines):
        if k == label_idx:
            continue  # the definition itself
        if label_token in ln:
            ref_count += 1
    if ref_count != 1:
        raise NoApplicableSite(
            f"self_return_blr: label {label} has {ref_count} references "
            f"(expected exactly 1 — the beq we're transforming). "
            f"Other references would be orphaned by block removal."
        )

    # Apply mutation:
    #   1. Rewrite the bc line to bclr (= beqlr).
    indent_match = re.match(r"^([ \t]*)", lines[beq_idx])
    indent = indent_match.group(1) if indent_match else "\t"
    lines[beq_idx] = f"{indent}bclr 12,2,0\n"

    #   2. Delete the (label, li, blr) block — accounting for possible blank
    #      lines between them by deleting the inclusive range from label_idx
    #      to blr_idx.
    del lines[label_idx:blr_idx + 1]

    return "".join(lines)
