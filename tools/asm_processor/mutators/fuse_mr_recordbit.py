"""fuse_mr_recordbit — collapse an adjacent `cmpwi cr0, <r>, 0` + `mr` pair
into the record-bit-fused `mr.` form.

Use case: SN ProDG's PPC backend emits record-bit-fused `mr.` for the common
"copy register AND test for zero" idiom. GCC 2.95.3 emits the unfused
`cmpwi cr0, <src>, 0; mr <dst>, <src>` pair (in either order, depending on
register allocation and scheduling). This mutator collapses the pair back to
the fused form, recovering 4 bytes per fusion site.

Trigger patterns (either order; blank lines, labels, and comments between the
two anchor lines are tolerated):

    cmpwi 0,<src>,0          # cr0 test against zero
    mr <dst>,<src>           # copy

OR

    mr <dst>,<src>           # copy
    cmpwi 0,<dst>,0          # cr0 test against the copy result

The cmpwi MUST target cr0 — mr. only updates cr0, so any downstream bc that
expects another cr field would break. The cmpwi's source register must match
the mr's source (case A) or destination (case B) — semantically equivalent
because mr is a register copy.

Replacement: single line `mr. <dst>,<src>` (records cr0 from the result).
The intervening label/comment lines (if any) are preserved.

Manifest example:

    pipeline:
      - mutator: fuse_mr_recordbit
        args:
          src: 9             # optional filter on mr source register
          dst: 3             # optional filter on mr dest register
          occurrence: 0      # 0 = first matching pair (default)

Directive form in source:

    // ASMPROC_fuse_mr_recordbit: src=9 dst=3

Refusal modes (NoApplicableSite — runtime skip):
- No adjacent cmpwi-cr0+mr fusion pair found in the .s
- All candidate pairs filtered out by src/dst args
- occurrence out of range

Limits:
- cmpwi vs 0 only (the "test for zero" idiom). cmpw r,r form is not fused —
  that would require a different mutator (mr-of-result + cmp-of-two-regs is
  not a single-instruction PPC operation).
- cmpwi targeting cr1-cr7 is refused on safety grounds.
"""
from __future__ import annotations

import re

from . import NoApplicableSite
from ._helpers import norm_reg, opcode

NAME = "fuse_mr_recordbit"

_CMPWI_ZERO_RE = re.compile(
    r"^[ \t]*cmpwi\s+(?P<cr>\d+)\s*,\s*(?P<src>\d+)\s*,\s*0\s*(?:[;#].*)?$"
)
_MR_RE = re.compile(
    r"^[ \t]*mr\s+(?P<dst>\d+)\s*,\s*(?P<src>\d+)\s*(?:[;#].*)?$"
)


def _parse_cmpwi_zero(line: str):
    body = line.rstrip("\r\n")
    m = _CMPWI_ZERO_RE.match(body)
    if not m:
        return None
    return int(m.group("cr")), int(m.group("src"))


def _parse_mr(line: str):
    body = line.rstrip("\r\n")
    m = _MR_RE.match(body)
    if not m:
        return None
    return int(m.group("dst")), int(m.group("src"))


def _is_skippable(line: str) -> bool:
    """True for blank lines, labels, comments, and directives — tolerated
    between the two anchor lines of a fusion pair."""
    stripped = line.strip()
    if not stripped:
        return True
    if stripped.startswith((";", "#", "/*", "//")):
        return True
    if stripped.endswith(":"):
        return True
    if stripped.startswith("."):
        return True
    return False


def _next_instr_index(lines, start):
    """Return the index of the next non-skippable line at or after start,
    or len(lines) if none."""
    for k in range(start, len(lines)):
        if not _is_skippable(lines[k]):
            return k
    return len(lines)


def _find_fusion_sites(lines, src_filter, dst_filter):
    """Yield (anchor_idx, partner_idx, dst, src) tuples for each fusable
    cmpwi+mr (in either order) on cr0, with optional src/dst filters."""
    n = len(lines)
    i = 0
    while i < n:
        line = lines[i]
        if _is_skippable(line):
            i += 1
            continue

        # Try case A: cmpwi at i, mr at next-instr
        cmpwi = _parse_cmpwi_zero(line)
        if cmpwi is not None:
            cr, cmpwi_src = cmpwi
            j = _next_instr_index(lines, i + 1)
            if j < n and cr == 0:
                mr_ = _parse_mr(lines[j])
                if mr_ is not None:
                    mr_dst, mr_src = mr_
                    if cmpwi_src == mr_src:
                        if (src_filter is None or mr_src == src_filter) and \
                           (dst_filter is None or mr_dst == dst_filter):
                            yield (i, j, mr_dst, mr_src)
                            i = j + 1
                            continue

        # Try case B: mr at i, cmpwi at next-instr
        mr_ = _parse_mr(line)
        if mr_ is not None:
            mr_dst, mr_src = mr_
            j = _next_instr_index(lines, i + 1)
            if j < n:
                cmpwi = _parse_cmpwi_zero(lines[j])
                if cmpwi is not None:
                    cr, cmpwi_src = cmpwi
                    if cr == 0 and cmpwi_src == mr_dst:
                        if (src_filter is None or mr_src == src_filter) and \
                           (dst_filter is None or mr_dst == dst_filter):
                            yield (i, j, mr_dst, mr_src)
                            i = j + 1
                            continue

        i += 1


def apply(asm_text: str, args: dict) -> str:
    src_arg = args.get("src")
    dst_arg = args.get("dst")
    occurrence = int(args.get("occurrence", 0))

    src_filter = norm_reg(str(src_arg)) if src_arg is not None else None
    dst_filter = norm_reg(str(dst_arg)) if dst_arg is not None else None

    lines = asm_text.splitlines(keepends=True)
    hits = list(_find_fusion_sites(lines, src_filter, dst_filter))
    if not hits:
        suffix = ""
        filt = []
        if src_filter is not None: filt.append(f"src={src_filter}")
        if dst_filter is not None: filt.append(f"dst={dst_filter}")
        if filt: suffix = f" ({' '.join(filt)})"
        raise NoApplicableSite(
            f"fuse_mr_recordbit: no adjacent cmpwi-cr0+mr fusion site{suffix}"
        )
    if occurrence >= len(hits):
        raise NoApplicableSite(
            f"fuse_mr_recordbit: requested occurrence {occurrence} but only "
            f"{len(hits)} fusable site(s) exist"
        )

    anchor, partner, dst, src = hits[occurrence]
    # Preserve indentation from the anchor (first) line
    anchor_line = lines[anchor]
    indent_match = re.match(r"^([ \t]*)", anchor_line)
    indent = indent_match.group(1) if indent_match else "\t"
    fused = f"{indent}mr. {dst},{src}\n"

    # Build new line list: replace anchor with fused, preserve everything
    # between anchor and partner (typically just labels/blank lines), drop
    # the partner line.
    new_lines = (
        lines[:anchor]
        + [fused]
        + lines[anchor + 1:partner]
        + lines[partner + 1:]
    )
    return "".join(new_lines)
