"""anti_tail_merge — un-merge cc1plus's shared return-tail blocks.

STATUS: EXPERIMENTAL (FALLBACK ONLY) — Tech #73 source-coax is the DEFAULT.

  Decision tree for any tail-merge wall (no exceptions):

    1. Read .s diff. Confirm DOL has duplicated `(materialize-r3 ; blr)`
       epilogues vs cc1plus's single shared tail.
    2. Try Tech #73 source-coax recipe FIRST (30-min triage budget).
       See `docs/tracking/technique_catalog_anti_tail_merge_source_coax.md`.
       The recipe — positive bounds-check + inner branches as early-return
       + compute-order-aware locals — produces DOL's duplicated-tail layout
       natively from source, with no post-cc1plus mutation. This is the
       canonical path for the simple tail-merge case.
    3. Only if Tech #73 demonstrably cannot reach the layout (see CONCRETE
       FALLBACK CRITERIA below), reach for THIS mutator.

  Authors who land here while writing a directive: STOP. Read Tech #73.
  Try the source-level recipe first. Reaching this mutator without first
  exhausting source-coax is the documented anti-pattern.

  Background: As of 2026-05-02 (S13 Track I session 4 close), Tech #73 was
  promoted with N=6 cross-shape validation (EBitArray::Get @ 0x802DF780 +
  __cmpdi2 @ 0x80249088 + INGTarget::get_current_inginfo @ 0x801BBB60 +
  INGTarget::get_current_mix_inginfo @ 0x801BBBA8 + GetActionMenu @
  0x8018458C + EShader::UseOverrideTexture @ 0x802FA438) spanning 4
  fundamentally different control-flow shapes (predicate-bool / case-cascade-
  int / state-getter pointer pair / predicate + multi-store side-effect).
  The mutator's canonical primary (AptArray::get
  @ 0x802860AC, commit `0c5e1dd4`) is itself a Tech #73 retest candidate;
  if it matches under source-coax alone, the only validated invocation
  evaporates and this mutator becomes fully unused.

  CONCRETE FALLBACK CRITERIA — when source-coax CANNOT reach the layout:

    The fallback case is COMPOUNDED STRUCTURAL WALLS where tail-merge
    diffs ride alongside other RTL-level structural mutations on the
    same function body. Source-level recipe edits cannot unwind a
    multi-wall stack because they only act at one level of the IR.

    Concrete compounded-wall fingerprint (any TWO+ of these on the same
    function in addition to the tail-merge diff):
      - `rlwimi`/`rlwinm` bitfield reconstruction with non-trivial mask
        composition the source struct layout doesn't naturally produce
      - asymmetric `andis.` patterns (high-half mask test paired with
        a different low-half operation cc1plus won't emit)
      - SDA singleton load/store reordering that cc1plus's load
        scheduling doesn't reproduce from natural variable order
      - multiple register-coloring deltas requiring `region_gpr_relabel`
        or stacked `force_reg`/`force_reg_at_pos` directives
      - frame-pointer or LR save/restore reordering inside the tail body

    Worked exemplar (descoped under this status): AptCharacterInst::
    sMethod_setMask @ 0x8028A244 (212B). Has rlwimi mask reconstruction
    + asymmetric andis. + SDA singleton load + tail-merge diff stacked
    on one function. Tech #73 alone resolves the tail-merge but leaves
    the rlwimi/andis./SDA residuals — those still require asm-processor
    directives, and `anti_tail_merge` as ONE step in that pipeline is
    valid territory for this mutator.

    If you have ONLY a tail-merge diff with no other structural walls,
    you are NOT in fallback territory — go back to step 2.

  Mothball clock (60-90 days from catalog merge date 2026-05-02):
    - If NO new wall (i.e., not the AptArray::get retain) requires
      anti_tail_merge within 60-90 days: mothball candidate. Retain
      commit AptArray::get is itself a Tech #73 retest candidate; if
      it matches via source-coax, the mutator becomes fully unused
      and can be removed from REGISTRY (with the .py file kept as
      historical reference under tools/asm_processor/mutators/).
    - If REPEAT fallback invocations from real walls happen organically
      (multiple distinct walls — at least 2 NEW byte-match invocations
      beyond AptArray::get — within the clock window): mutator's status
      promotes back to STANDARD.

  FRAMEWORK-VALIDATION FRAMING (per ORG, 2026-05-02):
    A SINGLE fallback success demonstrates REACH, not REVERSAL.

    The pre-parked `filter_wallpaper @ 0x801D4F88 (64B, 3-path tail-merge)`
    is the canonical first-fallback test case. If the directive byte-
    matches there, that VALIDATES the demotion framework (the mutator
    correctly handles a wall the recipe cannot reach) — it does NOT
    promote the mutator back to STANDARD. The 60-90d clock continues.

    Reversal back to STANDARD requires a SUSTAINED PATTERN of fallback
    invocations across multiple wall classes within the clock window
    (≥2 distinct fallback walls beyond filter_wallpaper, organically
    surfaced by production work, not synthetically batched).

    The framing matters because "first success after demotion = re-promote"
    creates pressure to find a single confirmation case and re-promote
    prematurely. The actual question is whether the mutator handles a
    DENSITY of walls Tech #73 cannot reach — that's an observed pattern,
    not a single data point.

Use case (compounded-layout fallback only): cc1plus's `-O2` tail-merging
consolidates N small return-tail blocks (typically `lwz r3, GLOBAL@sda21(0);
blr`) into a single shared block at function end. SN ProDG's DOL output
keeps M>1 duplicate copies of that tail, gaining +2 instructions per extra
duplicate. When the wall ALSO requires composition with rlwimi/andis. or
RTL-level register-shape mutators, source-coax cannot reach the layout
alone and this mutator becomes the fallback.

Transformation: duplicate-and-relocate. Picks ONE predecessor branch
to the shared tail (the `anchor_branch`), inverts its condition, and
retargets it to a new `body_label` placed immediately AFTER an inlined
copy of the tail. Optionally `also_retarget`s additional predecessor
branches to the new tail label. The original tail label remains at
function end to receive any other predecessors (typically a `bclr`
fallthrough or other branch sites).

Canonical target: `AptArray::get(int) @ 0x802860AC` (56B, 14 inst).
cc1plus emits 12 inst / 48B with merged single tail; DOL has 14 inst
with the tail duplicated once. The mutator closes the +2 inst delta.

Manifest example (AptArray::get):

    pipeline:
      - mutator: anti_tail_merge
        args:
          tail_label: ".L7"
          anchor_branch: "bc 4,0,.L7"        # idx>=size → invert + retarget
          also_retarget: "bc 12,0,.L7"       # idx<0 → retarget only

Author-error conditions (ValueError, fail-loud):
  - Missing required args (tail_label, anchor_branch).
  - `tail_label` empty or doesn't start with `.` (must be a real asm label).
  - Multiple anchor_branch matches (ambiguous — caller must use a more
    specific text). Same rule applies to each `also_retarget` pattern.

Skip-not-fail conditions (NoApplicableSite, harness records skip):
  - `tail_label:` directive not found in source.
  - Tail body has > `tail_max_inst` (default 4) machine instructions.
  - Tail body contains a non-`blr` terminator (`b X`, conditional branch
    inside the body, or a call). Conservative — only flat lwz+blr-style
    tails qualify.
  - Tail body contains an internal label (would split the block — the
    `tail_label` block must be a straight-line snippet ending in blr).
  - Anchor branch not found, or anchor opcode is not `bc`.
  - Anchor's third operand (target) ≠ tail_label.
  - Anchor's BO field ∉ {4, 6, 12, 14}. Encodings 0/1/2/3/8/9/10/11
    (CTR-related) and 5/7/13/15 (rare disabled-prediction variants
    SN ProDG does not emit) are NOT invertible by this mutator.
  - Any `also_retarget` pattern's last operand ≠ `tail_label` (target-
    equality safety check; refuses to retarget a branch whose target was
    already something else, e.g., a different shared tail).
  - Post-mutation would orphan the original `tail_label` (no remaining
    branch predecessors AND the line directly above it does not fall
    through, e.g., is a `b`/`blr`).

Soft asks (OpusReviewGuy v1 verdict integrated):

  SA-1: BO ∉ {4,6,12,14} explicitly listed in skip-not-fail above.
  SA-2: also_retarget last-operand-equality check (line ops[-1] == tail_label).
  SA-3: anchor_branch / also_retarget patterns are SUBSTRING matches
        (`needle in line`). Caller controls disambiguation by including
        enough context to make the match unique. Multiple matches raise
        ValueError (author error — pattern too loose).
  SA-4: Tail body conservatism. The tail block must be a straight-line
        sequence of non-branch, non-call instructions, terminated by
        `blr`. Internal labels (`.LSomething:` between tail_label and
        blr) and conditional branches (any `bc*` other than blr) are
        rejected — they imply the tail isn't a pure shared return.
        Calls (`bl`, `bla`, `bctrl`, etc.) per `CALL_OPCODES` likewise
        rejected.
  SA-5: Module-private helpers (`_invert_bo_field`, `_split_label_block`,
        `_parse_bc_target`) live here, NOT in `_helpers.py`. Reuse from
        `_helpers.py`: `find_match_index` (when needed), `split_operands`,
        `opcode`, `CALL_OPCODES`. Keeps shared-helper surface stable.
  SA-6: DOL-stable anchor invariant — composition footgun note. If
        `anti_tail_merge` runs in a pipeline AFTER another mutator that
        rewrites the same lines (e.g., `gpr_relabel` swapping registers
        in the anchor branch's operands, or `force_alias_base` inserting
        an `addi` that moves the line indices), the anchor_branch text
        match must be authored against the POST-prior-mutation state.
        Same lesson as `force_alias_base` v5 SOFT 5: pipeline composers
        must update anchor strings after each mutation step or the next
        mutator's anchor will silently fail (NoApplicableSite).

Generalization estimate (per OpusReviewGuy verdict): 5-50 walls likely
match this pattern — Apt/cXObject/SAnimator2 sentinel-returning getters
with 2+ exit paths returning a shared global pointer.
"""
from __future__ import annotations

import re

from . import NoApplicableSite
from ._helpers import (
    CALL_OPCODES,
    opcode,
    split_operands,
)

NAME = "anti_tail_merge"


# ---------- Module-private helpers ----------

# BO field encodings supported by anti_tail_merge — pairs that toggle the
# "branch on condition true / false" bit while preserving the prediction
# hint bit. PPC BO bits: [0]=test_cond_or_ctr, [1]=cond_value, [2]=ignore_ctr,
# [3]=ctr_value, [4]=prediction_hint. For "branch on cond, ignore CTR"
# encodings (BO[0]=0, BO[2]=1) the valid values are 4,5,6,7,12,13,14,15;
# we support only the pairs without dynamic-ish / disabled-prediction bits
# that SN ProDG actually emits from C++.
_BO_INVERT: dict[int, int] = {4: 12, 12: 4, 6: 14, 14: 6}

# Branch opcodes that always transfer control unconditionally (no
# fallthrough into the next line). Used by the orphan-check to decide
# whether the line above the original tail_label falls through into it.
_UNCONDITIONAL_FLOW: frozenset[str] = frozenset({
    "b", "ba", "blr", "blrl",
    "bctr", "bctrl",
})

# Branch opcodes generally — we refuse if any appear inside the tail body.
# Conservative: a real shared-return tail is straight-line code ending in
# blr, no internal control flow.
_BRANCH_OPCODES_PREFIX: tuple[str, ...] = ("b",)  # widen with caution

# Insn line regex (mirrors _helpers._INSN_RE but kept module-private here
# per SA-5 — duplicating a tiny pattern is cheaper than growing the public
# surface of _helpers). Lowercase opcode-only matches.
_INSN_RE = re.compile(
    r"^(?P<indent>[ \t]*)(?P<op>[A-Za-z_][A-Za-z0-9._]*)(?=\s|$)(?P<rest>.*)$"
)


def _invert_bo_field(bo: int) -> int:
    """Invert the BO field of a `bc` instruction.

    Supports `{4,6,12,14}` only — these are the standard branch-on-condition
    encodings (CTR ignored). Raises ValueError for anything else; callers
    should pre-check with NoApplicableSite if the input is untrusted.
    """
    if bo not in _BO_INVERT:
        raise ValueError(
            f"BO={bo} not invertible (supported: {sorted(_BO_INVERT)})"
        )
    return _BO_INVERT[bo]


def _split_label_block(
    lines: list[str], label_idx: int, tail_max_inst: int
) -> tuple[int, int, list[str]]:
    """Extract the body of the label block at `label_idx`.

    Returns (body_start, body_end_exclusive, body_lines).

    The body is the contiguous span of non-blank lines AFTER the label
    line, up to and INCLUDING the first `blr`. Refuses (NoApplicableSite):

      - Body has > tail_max_inst real instructions.
      - Body contains a non-blr branch (any `bc*`, `b X`, `bctr`).
      - Body contains a call (per CALL_OPCODES).
      - Body contains an internal label (would split the tail block).
      - Body has no terminating `blr`.
    """
    body_start = label_idx + 1
    body_lines: list[str] = []
    inst_count = 0
    for j in range(body_start, len(lines)):
        line = lines[j]
        stripped = line.strip()
        if not stripped:
            body_lines.append(line)
            continue
        # Internal label inside the tail body — refuse.
        if (
            stripped.endswith(":")
            and not stripped.startswith((";", "#", "//", "/*"))
        ):
            raise NoApplicableSite(
                f"anti_tail_merge: tail body has internal label "
                f"{stripped!r} at line {j + 1}; refused"
            )
        op = opcode(line)
        if op is None:
            body_lines.append(line)
            continue
        op_lower = op.lower()
        if op_lower == "blr":
            body_lines.append(line)
            return body_start, j + 1, body_lines
        if op_lower in CALL_OPCODES:
            raise NoApplicableSite(
                f"anti_tail_merge: tail body contains call {op!r} at "
                f"line {j + 1}; refused (only flat lwz+blr-style tails "
                f"qualify)"
            )
        # Reject any other branch (b, ba, bc*, bctr*, blrl) — only blr
        # may terminate. _UNCONDITIONAL_FLOW would catch some, but we
        # also need conditional bc.
        if op_lower in _UNCONDITIONAL_FLOW or op_lower.startswith("bc"):
            raise NoApplicableSite(
                f"anti_tail_merge: tail body has non-blr branch {op!r} "
                f"at line {j + 1}; refused"
            )
        inst_count += 1
        if inst_count > tail_max_inst:
            raise NoApplicableSite(
                f"anti_tail_merge: tail body exceeds tail_max_inst="
                f"{tail_max_inst} (already {inst_count} insts before blr)"
            )
        body_lines.append(line)
    raise NoApplicableSite(
        f"anti_tail_merge: tail body has no terminating blr"
    )


def _parse_bc_target(line: str) -> tuple[int, int, str] | None:
    """Parse a `bc BO,BI,target` line into (BO, BI, target_str).

    Returns None for non-`bc` lines or unparseable BO/BI fields.
    """
    op = opcode(line)
    if op != "bc":
        return None
    body = line.rstrip("\r\n")
    m = _INSN_RE.match(body)
    if not m:
        return None
    operands = split_operands(m.group("rest"))
    if len(operands) != 3:
        return None
    try:
        bo = int(operands[0])
        bi = int(operands[1])
    except ValueError:
        return None
    return bo, bi, operands[2].strip()


def _last_operand(line: str) -> str | None:
    """Return the last operand of an asm instruction line, or None.

    Strips any inline `#` / `;` comment. Useful for the also_retarget
    target-equality check (SA-2) and the post-mutation orphan scan.
    """
    body = line.rstrip("\r\n")
    m = _INSN_RE.match(body)
    if not m:
        return None
    operands = split_operands(m.group("rest"))
    if not operands:
        return None
    return operands[-1].strip()


def _line_has_target(line: str, target: str) -> bool:
    """True if `line` is an instruction whose last operand is `target`."""
    last = _last_operand(line)
    return last == target


def _find_unique_substring(
    lines: list[str], needle: str, *, label: str
) -> int:
    """Locate the unique line containing `needle` (substring match).

    NoApplicableSite if no match; ValueError if multiple matches (author
    error — pattern is too loose).
    """
    hits = [i for i, ln in enumerate(lines) if needle in ln]
    if not hits:
        raise NoApplicableSite(
            f"anti_tail_merge: {label} pattern {needle!r} not found"
        )
    if len(hits) > 1:
        raise ValueError(
            f"anti_tail_merge: {label} pattern {needle!r} matches "
            f"{len(hits)} lines (author error: tighten the pattern)"
        )
    return hits[0]


def _line_ending(line: str) -> str:
    if line.endswith("\r\n"):
        return "\r\n"
    if line.endswith("\n"):
        return "\n"
    return ""


def _alloc_label_suffix(
    lines: list[str], tail_prefix: str, body_prefix: str
) -> int:
    """Pick the smallest N s.t. `<tail_prefix>_<N>:` and `<body_prefix>_<N>:`
    do not appear in `lines`. Avoids collision in pipeline composition."""
    n = 1
    while True:
        tail_marker = f"{tail_prefix}_{n}:"
        body_marker = f"{body_prefix}_{n}:"
        if not any(tail_marker in ln or body_marker in ln for ln in lines):
            return n
        n += 1


# ---------- Apply ----------

def apply(asm_text: str, args: dict) -> str:
    # ---- 1. Required args ----
    tail_label = args.get("tail_label")
    anchor_branch = args.get("anchor_branch")
    if not tail_label:
        raise ValueError("anti_tail_merge requires arg: tail_label")
    if not anchor_branch:
        raise ValueError("anti_tail_merge requires arg: anchor_branch")
    if not isinstance(tail_label, str) or not tail_label.startswith("."):
        raise ValueError(
            f"anti_tail_merge: tail_label must start with '.' (got "
            f"{tail_label!r})"
        )
    if not isinstance(anchor_branch, str):
        raise ValueError(
            f"anti_tail_merge: anchor_branch must be str (got "
            f"{type(anchor_branch).__name__})"
        )

    # ---- 2. Optional args ----
    tail_label_prefix = str(args.get("tail_label_prefix", ".L_atm"))
    if not tail_label_prefix.startswith("."):
        raise ValueError(
            f"anti_tail_merge: tail_label_prefix must start with '.' "
            f"(got {tail_label_prefix!r})"
        )
    tail_max_inst_raw = args.get("tail_max_inst", 4)
    try:
        tail_max_inst = int(tail_max_inst_raw)
    except (ValueError, TypeError):
        raise ValueError(
            f"anti_tail_merge: tail_max_inst must be int, got "
            f"{tail_max_inst_raw!r}"
        ) from None
    if tail_max_inst < 1:
        raise ValueError(
            f"anti_tail_merge: tail_max_inst must be >= 1, got "
            f"{tail_max_inst}"
        )

    # also_retarget: string = single pattern (asm patterns contain commas, so
    # NEVER comma-split); list = multiple patterns. Empty string = no extra
    # retargets.
    also_retarget_raw = args.get("also_retarget", "")
    if isinstance(also_retarget_raw, list):
        also_retarget = [str(s).strip() for s in also_retarget_raw if str(s).strip()]
    elif isinstance(also_retarget_raw, str):
        s = also_retarget_raw.strip()
        also_retarget = [s] if s else []
    else:
        raise ValueError(
            f"anti_tail_merge: also_retarget must be str or list, got "
            f"{type(also_retarget_raw).__name__}"
        )

    lines = asm_text.splitlines(keepends=True)

    # ---- 3. Locate tail_label definition ----
    label_marker = tail_label + ":"
    tail_label_idx = None
    for i, ln in enumerate(lines):
        if ln.strip() == label_marker:
            tail_label_idx = i
            break
    if tail_label_idx is None:
        raise NoApplicableSite(
            f"anti_tail_merge: tail label {tail_label!r} not found"
        )

    # ---- 4. Extract + validate tail body ----
    body_start, body_end, body_lines = _split_label_block(
        lines, tail_label_idx, tail_max_inst
    )

    # ---- 5. Locate anchor branch (substring, must be unique) ----
    anchor_idx = _find_unique_substring(
        lines, anchor_branch, label="anchor_branch"
    )

    # ---- 6. Validate anchor: bc form, target == tail_label, BO invertible ----
    parsed = _parse_bc_target(lines[anchor_idx])
    if parsed is None:
        raise NoApplicableSite(
            f"anti_tail_merge: anchor at line {anchor_idx + 1} is not "
            f"a parseable `bc BO,BI,target` instruction"
        )
    bo, bi, target = parsed
    if target != tail_label:
        raise NoApplicableSite(
            f"anti_tail_merge: anchor target {target!r} != tail_label "
            f"{tail_label!r} (line {anchor_idx + 1})"
        )
    if bo not in _BO_INVERT:
        raise NoApplicableSite(
            f"anti_tail_merge: anchor BO={bo} not invertible "
            f"(supported: {sorted(_BO_INVERT)}; refuses 0/1/2/3/5/7/8/9/"
            f"10/11/13/15)"
        )

    # ---- 7. Validate also_retarget patterns BEFORE mutation (SA-2) ----
    retarget_idxs: list[int] = []
    for pat in also_retarget:
        rt_idx = _find_unique_substring(lines, pat, label="also_retarget")
        if rt_idx == anchor_idx:
            raise ValueError(
                f"anti_tail_merge: also_retarget {pat!r} matches the "
                f"same line as anchor_branch (line {anchor_idx + 1})"
            )
        last = _last_operand(lines[rt_idx])
        if last != tail_label:
            raise NoApplicableSite(
                f"anti_tail_merge: also_retarget {pat!r} at line "
                f"{rt_idx + 1} has last operand {last!r}, expected "
                f"{tail_label!r} (target-equality safety check)"
            )
        retarget_idxs.append(rt_idx)

    # ---- 8. Post-mutation orphan check ----
    # The original tail_label survives as long as ONE of these is true:
    #   a) some remaining instruction line has its last operand == tail_label
    #      (a branch we are NOT touching)
    #   b) the line directly above tail_label_idx falls through (its opcode
    #      is not in _UNCONDITIONAL_FLOW — bc, bclr cond-form, normal insn,
    #      etc., all leave fallthrough possible)
    touched = {anchor_idx, *retarget_idxs}
    has_remaining_brancher = False
    for j, ln in enumerate(lines):
        if j == tail_label_idx or j in touched:
            continue
        if _line_has_target(ln, tail_label):
            has_remaining_brancher = True
            break

    has_fallthrough = False
    if tail_label_idx > 0:
        # Walk back over blank/comment lines to find the real predecessor
        # instruction.
        k = tail_label_idx - 1
        while k >= 0 and opcode(lines[k]) is None:
            k -= 1
        if k >= 0:
            prev_op = opcode(lines[k])
            if prev_op is not None and prev_op.lower() not in _UNCONDITIONAL_FLOW:
                has_fallthrough = True
        else:
            # No prior insn — tail label sits at function start somehow.
            # Still treat as "has fallthrough" conservatively (function entry).
            has_fallthrough = True

    if not has_remaining_brancher and not has_fallthrough:
        raise NoApplicableSite(
            f"anti_tail_merge: post-mutation would orphan {tail_label} "
            f"(no remaining branch predecessors after touching anchor + "
            f"{len(retarget_idxs)} also_retarget(s), and line above "
            f"tail label does not fall through)"
        )

    # ---- 9. Allocate fresh label suffix (collision-safe in pipelines) ----
    n = _alloc_label_suffix(
        lines, f"{tail_label_prefix}_tail", f"{tail_label_prefix}_body"
    )
    new_tail_label = f"{tail_label_prefix}_tail_{n}"
    new_body_label = f"{tail_label_prefix}_body_{n}"

    # ---- 10. Build mutated lines list ----
    new_lines = list(lines)

    # 10a. Rewrite anchor: invert BO, retarget to body label.
    new_bo = _invert_bo_field(bo)
    anchor_body = lines[anchor_idx].rstrip("\r\n")
    am = _INSN_RE.match(anchor_body)
    assert am is not None  # _parse_bc_target above already validated form
    indent = am.group("indent")
    op_text = am.group("op")
    rest = am.group("rest")
    rest_prefix_m = re.match(r"^(\s*)", rest)
    rest_prefix = rest_prefix_m.group(1) if rest_prefix_m else " "
    new_anchor_line = (
        f"{indent}{op_text}{rest_prefix}{new_bo},{bi},{new_body_label}"
        f"{_line_ending(lines[anchor_idx])}"
    )
    new_lines[anchor_idx] = new_anchor_line

    # 10b. Retarget also_retarget lines: rewrite tail_label → new_tail_label
    # in the operand list (preserve everything else).
    for rt_idx in retarget_idxs:
        rt_body = lines[rt_idx].rstrip("\r\n")
        rt_m = _INSN_RE.match(rt_body)
        if rt_m is None:
            # Should not happen — we already verified _last_operand returned.
            continue
        rt_indent = rt_m.group("indent")
        rt_op = rt_m.group("op")
        rt_rest = rt_m.group("rest")
        # Replace the FIRST instance of tail_label in operands. Last operand
        # was already verified equal to tail_label.
        new_rest = rt_rest.replace(tail_label, new_tail_label, 1)
        new_lines[rt_idx] = (
            f"{rt_indent}{rt_op}{new_rest}{_line_ending(lines[rt_idx])}"
        )

    # 10c. Build insertion block: new_tail_label, body_lines, new_body_label.
    insertion: list[str] = []
    insertion.append(f"{new_tail_label}:\n")
    insertion.extend(body_lines)
    insertion.append(f"{new_body_label}:\n")

    # Insert AFTER anchor line.
    new_lines = (
        new_lines[: anchor_idx + 1]
        + insertion
        + new_lines[anchor_idx + 1 :]
    )

    return "".join(new_lines)


# ---------- Smoke test ----------

if __name__ == "__main__":
    # Synthetic .s mirroring the AptArray::get cc1plus output shape.
    SAMPLE_BEFORE = (
        "get__test:\n"
        ".L_fget__test_s:\n"
        "\tmr. 4,4\n"
        "\tbc 12,0,.L7\n"
        "\tlwz 0,44(3)\n"
        "\tcmpw 0,4,0\n"
        "\tbc 4,0,.L7\n"
        "\tlwz 11,36(3)\n"
        "\tslwi 9,4,2\n"
        "\tlwzx 3,9,11\n"
        "\tcmpwi 0,3,0\n"
        "\tbclr 4,2\n"
        ".L7:\n"
        "\tlwz 3,g_aptUndefined@sda21(0)\n"
        "\tblr\n"
    )

    args = {
        "tail_label": ".L7",
        "anchor_branch": "bc 4,0,.L7",
        "also_retarget": "bc 12,0,.L7",
    }
    result = apply(SAMPLE_BEFORE, args)

    # Expected post-mutation invariants:
    #   - "bc 4,0,.L7" line REPLACED with "bc 12,0,.L_atm_body_1"
    #   - "bc 12,0,.L7" line REPLACED with "bc 12,0,.L_atm_tail_1"
    #   - .L_atm_tail_1: + lwz + blr block inserted after the new anchor
    #   - .L_atm_body_1: appears immediately after the inserted tail
    #   - Original .L7: still present at function end (receives bclr fallthrough)
    must_contain = [
        "bc 12,0,.L_atm_tail_1",  # idx<0 retargeted
        "bc 12,0,.L_atm_body_1",  # idx>=size inverted+retargeted
        ".L_atm_tail_1:",
        "lwz 3,g_aptUndefined@sda21(0)",
        ".L_atm_body_1:",
        ".L7:",
    ]
    for needle in must_contain:
        if needle not in result:
            print(f"smoke FAIL: missing {needle!r}")
            print("---OUTPUT---")
            print(result)
            raise SystemExit(1)
    must_not_contain = [
        "bc 4,0,.L7",  # original anchor line should be GONE
        "bc 12,0,.L7",  # original also_retarget line should be GONE
    ]
    for needle in must_not_contain:
        if needle in result:
            print(f"smoke FAIL: still present {needle!r}")
            print("---OUTPUT---")
            print(result)
            raise SystemExit(1)

    # Verify original .L7 block survives at end
    if not (
        ".L7:\n\tlwz 3,g_aptUndefined@sda21(0)\n\tblr\n" in result
    ):
        print("smoke FAIL: original .L7 tail block not preserved at end")
        print("---OUTPUT---")
        print(result)
        raise SystemExit(1)

    print("smoke PASS")
    print("---OUTPUT---")
    print(result)

    # Negative test: BO=5 (rare, refused) should NoApplicableSite, not mutate.
    SAMPLE_BO5 = SAMPLE_BEFORE.replace("bc 4,0,.L7", "bc 5,0,.L7")
    try:
        apply(SAMPLE_BO5, args)
        print("smoke FAIL: BO=5 should have raised NoApplicableSite")
        raise SystemExit(1)
    except NoApplicableSite:
        print("smoke PASS: BO=5 correctly refused (SA-1)")

    # Negative test: also_retarget with target != tail_label should refuse.
    SAMPLE_WRONG_TGT = SAMPLE_BEFORE.replace("bc 12,0,.L7", "bc 12,0,.L_other")
    try:
        apply(SAMPLE_WRONG_TGT, {
            **args,
            "also_retarget": "bc 12,0,.L_other",
        })
        print("smoke FAIL: also_retarget mismatched target should have raised")
        raise SystemExit(1)
    except NoApplicableSite:
        print("smoke PASS: also_retarget target-mismatch refused (SA-2)")

    # Negative test: tail body with internal call should refuse (SA-4).
    SAMPLE_CALL = SAMPLE_BEFORE.replace(
        "\tlwz 3,g_aptUndefined@sda21(0)\n\tblr\n",
        "\tlwz 3,g_aptUndefined@sda21(0)\n\tbl other_fn\n\tblr\n",
    )
    try:
        apply(SAMPLE_CALL, args)
        print("smoke FAIL: call in tail body should have raised")
        raise SystemExit(1)
    except NoApplicableSite:
        print("smoke PASS: call in tail body refused (SA-4)")
