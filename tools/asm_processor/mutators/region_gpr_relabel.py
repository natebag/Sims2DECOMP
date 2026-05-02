"""region_gpr_relabel — bounded directed GPR rename.

STATUS: STANDARD — Density Watch.

  0 N=2 hunt hits across 6,818 functions as of S13 (TUScout, info
  `6790284f`). Implementation is sound; production code at commit
  `25fdb045` (AptActionQueueC::GetDequeLocation) stands. Mutator stays
  in REGISTRY as escape hatch.

  Default to source-level Tech #72 (polarity flip, `technique_catalog_polarity_flip.md`)
  and Tech #73 (split-tail, `technique_catalog_anti_tail_merge_source_coax.md`)
  FIRST. Most "register-allocation walls" turn out to be "opcode-idiom
  walls" (cmpwi vs or., srawi vs sraw, slwi vs rlwinm, ble vs bgt) where
  the underlying instruction pattern itself differs and source-level
  rewriting is the right tool. Invoke this mutator only if structural
  inspection confirms the cc1plus output and DOL agree on opcode patterns
  AND only the register choice differs — that is a genuinely rare wall
  class.

  No mothball clock — STANDARD status retained pending S14 retrospective
  with one more session of usage data. If sustained zero-invocation
  through S14, demotion conversation reopens.

Sibling of `gpr_relabel` (whole-file, bidirectional). region_gpr_relabel
applies a DIRECTED `from:to` rename map to a BOUNDED contiguous region of
post-cc1plus .s, identified by start/end anchor lines (substring-with-uniqueness).

Use case: Category-2 walls where DOL transitions a logical value to a
different register at a recognizable kill point inside a function, and
cc1plus reuses the original (or a different) register for the same value.
The diff is purely register-coloring within a contiguous instruction
sequence; block layout already matches DOL (or has been independently
fixed via source-level coaxing).

Canonical target: `AptActionQueueC::GetDequeLocation @ 0x8028552c (80B,
20 inst)`. Block layout matches DOL after v2 source polarity-flip
(`build/verify/getdeque_v2.cpp`); 7 register-coloring mismatches at
offsets 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x34, 0x44 collapse to a single
directive. cc1plus picks r0 for the post-mullw "wrapped" intermediate
through the divw quotient; DOL transitions the value to r3 at the srawi
kill point and reuses r0 for the divw quotient.

Manifest example (AptActionQueueC::GetDequeLocation):

    pipeline:
      - mutator: region_gpr_relabel
        args:
          start_anchor: "srawi 0,0,2"      # kill instruction (dest r0 transitions to r3)
          end_anchor: "mulli 3,0,20"        # last region line (positive-tail multiply)
          rename: "0:3,9:0"                 # directed simultaneous map

start_mode / end_mode semantics (asymmetric — intentional):

  - `start_mode="at"` (default): rename DEST OPERAND ONLY of start_anchor
    (the kill point — its source operands read from outside the region's
    namespace, untouched). All subsequent lines in the region are fully
    renamed.
  - `start_mode="after"`: start_anchor untouched; rename applies starting
    from the line AFTER start_anchor.
  - `end_mode="at"` (default): rename includes end_anchor's all operands.
  - `end_mode="before"`: rename ends at the previous line; end_anchor
    untouched.

If your start_anchor is NOT a kill point (its source operands ALSO need
renaming because they're inside the region's namespace), use
`start_mode="after"` and the previous line as start_anchor.

Rename map: directed `from:to` pairs applied SIMULTANEOUSLY (single map
lookup per token, not iterative substitution). Map `0:3,9:0` means:
  - token `0` -> `3`
  - token `9` -> `0`
  - token `3` -> `3` (silent identity, not in map)
This is NOT bidirectional. NOT a swap. Cycles allowed (e.g., `0:3,3:0`
applies as a true swap via simultaneous lookup).

Author-error conditions (ValueError, fail-loud):
  - Missing required args (`start_anchor`, `end_anchor`, `rename`).
  - Empty rename map (after identity-filter).
  - Out-of-range register in rename pair.
  - Duplicate FROM register in rename (e.g., `0:3,0:5` — ambiguous).
  - Invalid start_mode (not "at"/"after") or end_mode (not "at"/"before").
  - `start_mode="at"` but start_anchor's opcode has no GPR dest at
    position 0 (must be in `DEST_AT_POS_0_GPR_OPCODES`).
  - Single-line region (start_idx == end_idx) — refused in v1; use
    `force_reg` for single-instruction renames.

Skip-not-fail conditions (NoApplicableSite, harness records):
  - start_anchor or end_anchor not found.
  - Anchor matched multiple lines without explicit `occurrence_*` index.
  - Anchor occurrence index out of range.
  - start_idx >= end_idx (anchors in wrong order).
  - In-region clobber: TO register R (NOT in FROM set) used as source
    BEFORE used as dest within region — potential live-in clobber.
  - Post-region clobber: FROM register F used as source AFTER end_anchor
    without intervening redefinition — stale data after rename.

Soft asks (OpusReviewGuy v1 verdict integrated):

  SA-1: Post-region liveness check — symmetric to in-region check.
        For each FROM register F, scan lines after end_anchor for F as
        source before F as dest. Refuse if F is used post-region without
        a redefinition. Mid-function regions hit this; AptActionQueueC
        doesn't (function ends at blr after end_anchor).

  SA-2: start_mode="at" asymmetry documented sharply (see semantics
        above). Two modes only in v1 (`at` + `after`); 3rd mode deferred
        until a real wall demands it.

  SA-3: start_mode="at" accept-list — `DEST_AT_POS_0_GPR_OPCODES`
        explicitly enumerates opcodes whose dest is a GPR at position 0
        (most arithmetic, logical, loads, mfspr-family). Anything not
        in the list refuses with ValueError on start_mode="at".

  SA-4: `unsafe_clobber: true` is a no-op when liveness passes (no
        ValueError for "unnecessary opt-in"). Discipline is review's
        job, not the mutator's. Keeps API stable across heuristic
        improvements.

  SA-5: `_helpers.py::relabel_token` and `relabel_line` used directly.
        NO `_helpers.py` growth, NO refactor of `gpr_relabel.py`. Module-
        private helpers (`_ensure_unique`, `_relabel_dest_only`,
        `_check_inregion_clobber`, `_check_postregion_clobber`) live
        here only. Single-consumer scope.

  SA-6: FP_POSITIONS handling — `relabel_line` (used for in-region full
        rename) inherits gpr_relabel's behavior of skipping non-GPR
        opcodes via `NON_GPR_INT_OPCODES`. For FP load/store ops the
        memory base register (a GPR) is renamed via `relabel_token`'s
        mem-form handling. FP-typed operand positions are NOT renamed.

  SA-7: Subsumption claims — does NOT subsume `force_reg_at_pos`
        (queue #4); single-line region refused in v1 per Q2. FamilyImpl
        7-directive recipe collapse SPECULATIVE; would require single-
        line region support to subsume the 3 post-insert position-aware
        renames (which v1 explicitly refuses). Concrete value remains
        the AptActionQueueC 7->1 collapse and analogous multi-instruction
        contiguous diffs.

Generalization estimate (per OpusReviewGuy verdict): 5-30 walls plausibly
match this pattern — Category-2 residuals across FamilyImpl, NeighborhoodImpl,
ObjectFolder, SAnimator2 ctor/member-init colorings, BString/EString
idiom mismatches.
"""
from __future__ import annotations

import re

from . import NoApplicableSite
from ._helpers import (
    NON_GPR_INT_OPCODES,
    find_match_index,
    opcode,
    parse_relabel,
    relabel_line,
    relabel_token,
    split_operands,
)

NAME = "region_gpr_relabel"


# ---------- Regex primitives (module-private; mirror _helpers.py) ----------

_INSN_RE = re.compile(
    r"^(?P<indent>[ \t]*)(?P<op>[A-Za-z_][A-Za-z0-9._]*)(?=\s|$)(?P<rest>.*)$"
)
_BARE_REG_RE = re.compile(r"^r?(\d{1,2})$")
_MEM_FORM_RE = re.compile(r"^(?P<imm>[^(]+)\((?P<reg>r?\d{1,2})\)$")


# ---------- Accept-list for start_mode="at" (SA-3) ----------
#
# Opcodes whose DEST OPERAND is a GPR at position 0. start_mode="at"
# requires this so the rename applies cleanly to the dest only. Outside
# this list, callers must use start_mode="after" or pick a different
# start_anchor. Stores (rs at pos 0 is SOURCE), compares (CR field is
# dest), branches, traps, CR-bit ops, and FP-status ops are NOT here.
DEST_AT_POS_0_GPR_OPCODES: frozenset[str] = frozenset({
    # Integer arithmetic
    "add", "add.", "addc", "addc.", "adde", "adde.",
    "addi", "addic", "addic.", "addis",
    "addme", "addme.", "addze", "addze.",
    "subf", "subf.", "subfc", "subfc.", "subfe", "subfe.",
    "subfic", "subfme", "subfme.", "subfze", "subfze.",
    "neg", "neg.",
    "mulhw", "mulhw.", "mulhwu", "mulhwu.",
    "mulli", "mullw", "mullw.",
    "divw", "divw.", "divwu", "divwu.",
    # Logical
    "and", "and.", "andc", "andc.", "andi.", "andis.",
    "or", "or.", "orc", "orc.", "ori", "oris",
    "xor", "xor.", "xori", "xoris",
    "eqv", "eqv.", "nand", "nand.", "nor", "nor.",
    "mr", "mr.",  # alias of `or rA, rS, rS`
    # Shifts and rotates
    "slw", "slw.", "sraw", "sraw.", "srawi", "srawi.", "srw", "srw.",
    "rlwnm", "rlwnm.", "rlwinm", "rlwinm.", "rlwimi", "rlwimi.",
    # Sign/zero extend, count-leading-zeros
    "cntlzw", "cntlzw.", "extsb", "extsb.", "extsh", "extsh.",
    # Loads (dest at pos 0)
    "lbz", "lbzu", "lbzux", "lbzx",
    "lha", "lhau", "lhaux", "lhax",
    "lhz", "lhzu", "lhzux", "lhzx",
    "lwz", "lwzu", "lwzux", "lwzx",
    "lhbrx", "lwbrx",
    # Move-from-special
    "mflr", "mfctr", "mfcr", "mfxer", "mfspr",
})


# ---------- Module-private helpers ----------


def _extract_reg_int(token: str) -> int | None:
    """Parse a bare-register or memory-form token; return reg integer or None."""
    t = token.strip()
    if not t:
        return None
    bm = _BARE_REG_RE.match(t)
    if bm:
        return int(bm.group(1))
    mm = _MEM_FORM_RE.match(t)
    if mm:
        rm = _BARE_REG_RE.match(mm.group("reg").strip())
        if rm:
            return int(rm.group(1))
    return None


def _ensure_unique(lines: list[str], needle: str, label: str) -> int:
    """Find the unique line containing `needle` (substring match).

    Refuse with NoApplicableSite if 0 or >1 matches. Mirrors anti_tail_merge's
    `_find_unique_substring` discipline (per Q5 verdict — substring with
    uniqueness, NOT whitespace-normalized exact).
    """
    hits = [i for i, line in enumerate(lines) if needle in line]
    if len(hits) == 0:
        raise NoApplicableSite(
            f"region_gpr_relabel: {label} {needle!r} not found in .s"
        )
    if len(hits) > 1:
        raise NoApplicableSite(
            f"region_gpr_relabel: {label} {needle!r} matched {len(hits)} lines "
            f"(expected 1); narrow the substring or use occurrence_{label.split('_')[0]}."
        )
    return hits[0]


def _relabel_dest_only(line: str, mapping: dict[int, int]) -> str:
    """Apply mapping to position-0 (dest) operand only; preserve sources.

    Used at start_anchor when start_mode="at" (kill-point semantic — source
    operands read from outside the region's namespace and must NOT be renamed).
    """
    newline = ""
    body = line
    if body.endswith("\r\n"):
        newline, body = "\r\n", body[:-2]
    elif body.endswith("\n"):
        newline, body = "\n", body[:-1]

    m = _INSN_RE.match(body)
    if not m:
        return line

    indent = m.group("indent")
    op_text = m.group("op")
    rest = m.group("rest")
    operands = split_operands(rest)
    if not operands:
        return line

    new_operands = list(operands)
    new_operands[0] = relabel_token(operands[0], mapping)
    if new_operands == operands:
        return line  # no-op (dest token unaffected by mapping)

    prefix_match = re.match(r"^(\s*)", rest)
    prefix = prefix_match.group(1) if prefix_match else " "
    return indent + op_text + prefix + ", ".join(new_operands) + newline


def _check_inregion_clobber(
    lines: list[str],
    region_start: int,
    region_end: int,
    mapping: dict[int, int],
) -> None:
    """Best-effort live-in clobber check.

    For each register R in the TO set that is NOT also in the FROM set, scan
    operands in lines [region_start, region_end] (inclusive). If R appears as
    a SOURCE operand BEFORE any DEST write of R within the region, refuse —
    R was holding a value live across region entry that we'd silently clobber.

    R-in-both-FROM-and-TO is skipped (the rename eliminates the original R
    references; no clobber possible).
    """
    from_set = set(mapping.keys())
    to_set = set(mapping.values())
    floating_to = to_set - from_set
    if not floating_to:
        return

    for r_check in floating_to:
        first_dest_idx = -1
        first_src_idx = -1
        for i in range(region_start, region_end + 1):
            line = lines[i]
            op = opcode(line)
            if op is None:
                continue
            op_lower = op.lower()
            if op_lower in NON_GPR_INT_OPCODES:
                continue
            m = _INSN_RE.match(line.rstrip("\r\n"))
            if not m:
                continue
            operands = split_operands(m.group("rest"))
            dest_pos = 0 if op_lower in DEST_AT_POS_0_GPR_OPCODES else None
            for pos, tok in enumerate(operands):
                reg_int = _extract_reg_int(tok)
                if reg_int != r_check:
                    continue
                if dest_pos is not None and pos == dest_pos:
                    if first_dest_idx == -1:
                        first_dest_idx = i
                else:
                    if first_src_idx == -1:
                        first_src_idx = i
        if first_src_idx != -1 and (
            first_dest_idx == -1 or first_src_idx < first_dest_idx
        ):
            raise NoApplicableSite(
                f"region_gpr_relabel: TO register r{r_check} appears as source "
                f"before dest in region (potential live-in clobber at line "
                f"{first_src_idx}). Use unsafe_clobber=true to bypass if intentional."
            )


def _check_postregion_clobber(
    lines: list[str], end_idx: int, mapping: dict[int, int]
) -> None:
    """SA-1: post-region clobber check.

    For each FROM register F in the rename map, scan lines AFTER end_idx
    (until function-end blr OR label boundary) for F as source BEFORE F as
    dest. If F is used post-region without an intervening redefinition,
    refuse — the rename leaves stale data in F (downstream code expects the
    value the rename moved away).

    Conservative: stops at any label (basic-block boundary or function
    boundary). v1 simplification; tighter analysis defers to follow-up.
    """
    from_set = set(mapping.keys())

    for f_check in from_set:
        for i in range(end_idx + 1, len(lines)):
            line = lines[i]
            stripped = line.strip()
            if not stripped:
                continue
            if stripped.startswith(("//", "#", ";", "/*")):
                continue
            if stripped.endswith(":"):
                # Label boundary — conservative stop (basic block or function).
                break
            op = opcode(line)
            if op is None:
                continue
            op_lower = op.lower()
            if op_lower == "blr":
                break  # function end
            if op_lower in NON_GPR_INT_OPCODES:
                continue
            m = _INSN_RE.match(line.rstrip("\r\n"))
            if not m:
                continue
            operands = split_operands(m.group("rest"))
            dest_pos = 0 if op_lower in DEST_AT_POS_0_GPR_OPCODES else None
            f_as_src = False
            f_as_dest = False
            for pos, tok in enumerate(operands):
                reg_int = _extract_reg_int(tok)
                if reg_int != f_check:
                    continue
                if dest_pos is not None and pos == dest_pos:
                    f_as_dest = True
                else:
                    f_as_src = True
            # Source-first wins (sources read before dest writes within an instruction).
            if f_as_src:
                raise NoApplicableSite(
                    f"region_gpr_relabel: FROM register r{f_check} used as source "
                    f"after end_anchor (line {i}) without intervening redefinition "
                    f"(post-region clobber). Use unsafe_clobber=true to bypass "
                    f"if intentional, or extend region_gpr_relabel's end_anchor."
                )
            if f_as_dest:
                # Cleanly redefined — safe; stop scanning for this F.
                break


# ---------- Public entry ----------


def apply(asm_text: str, args: dict) -> str:
    # ---- Parse args ----
    start_anchor = args.get("start_anchor")
    end_anchor = args.get("end_anchor")
    rename_spec = args.get("rename")
    if not start_anchor:
        raise ValueError("region_gpr_relabel: missing required arg `start_anchor`")
    if not end_anchor:
        raise ValueError("region_gpr_relabel: missing required arg `end_anchor`")
    if not rename_spec:
        raise ValueError("region_gpr_relabel: missing required arg `rename`")

    start_mode = args.get("start_mode", "at")
    end_mode = args.get("end_mode", "at")
    if start_mode not in ("at", "after"):
        raise ValueError(
            f"region_gpr_relabel: invalid start_mode {start_mode!r} "
            f"(need 'at' or 'after')"
        )
    if end_mode not in ("at", "before"):
        raise ValueError(
            f"region_gpr_relabel: invalid end_mode {end_mode!r} "
            f"(need 'at' or 'before')"
        )

    occurrence_start_raw = args.get("occurrence_start", None)
    occurrence_end_raw = args.get("occurrence_end", None)
    unsafe_clobber = bool(args.get("unsafe_clobber", False))

    # ---- Parse rename map ----
    pairs = parse_relabel(rename_spec)
    if not pairs:
        raise ValueError(
            f"region_gpr_relabel: rename {rename_spec!r} is empty after identity-filter"
        )
    # Build simultaneous map. Reject duplicate FROM (ambiguous direction).
    mapping: dict[int, int] = {}
    for a, b in pairs:
        if a in mapping and mapping[a] != b:
            raise ValueError(
                f"region_gpr_relabel: duplicate FROM register r{a} in rename "
                f"(r{a}->r{mapping[a]} and r{a}->r{b})"
            )
        mapping[a] = b

    # ---- Locate anchors ----
    lines = asm_text.splitlines(keepends=True)

    if occurrence_start_raw is None:
        start_idx = _ensure_unique(lines, start_anchor, "start_anchor")
    else:
        start_idx = find_match_index(
            lines, start_anchor, int(occurrence_start_raw),
            label="region_gpr_relabel/start_anchor",
        )
    if occurrence_end_raw is None:
        end_idx = _ensure_unique(lines, end_anchor, "end_anchor")
    else:
        end_idx = find_match_index(
            lines, end_anchor, int(occurrence_end_raw),
            label="region_gpr_relabel/end_anchor",
        )

    if start_idx == end_idx:
        # Q2 verdict: refuse single-line region in v1.
        raise ValueError(
            "region_gpr_relabel: single-line region (start_anchor == end_anchor) "
            "refused in v1; use force_reg for single-instruction renames."
        )
    if start_idx > end_idx:
        raise NoApplicableSite(
            f"region_gpr_relabel: start_anchor (line {start_idx}) > end_anchor "
            f"(line {end_idx}); region requires start before end."
        )

    # ---- Validate start_anchor opcode (SA-3) ----
    if start_mode == "at":
        start_op = opcode(lines[start_idx])
        if start_op is None:
            raise ValueError(
                f"region_gpr_relabel: start_anchor line is not an instruction "
                f"(line {start_idx}: {lines[start_idx].strip()!r})"
            )
        if start_op.lower() not in DEST_AT_POS_0_GPR_OPCODES:
            raise ValueError(
                f"region_gpr_relabel: start_mode='at' requires opcode with GPR "
                f"dest at pos 0; got {start_op!r} (line {start_idx}). Use "
                f"start_mode='after' or pick a different start_anchor."
            )

    # ---- Liveness checks ----
    # In-region check: scan lines (start_idx, end_idx_effective] where the
    # full rename applies. start_anchor's sources are excluded (kill-point
    # semantic). end_anchor included if end_mode="at", excluded if "before".
    inregion_end = end_idx if end_mode == "at" else end_idx - 1
    if not unsafe_clobber:
        _check_inregion_clobber(lines, start_idx + 1, inregion_end, mapping)
        # SA-1: post-region check.
        _check_postregion_clobber(lines, inregion_end, mapping)

    # ---- Apply rename ----
    # 1. start_anchor: rename dest only (start_mode="at") or skip (start_mode="after").
    if start_mode == "at":
        lines[start_idx] = _relabel_dest_only(lines[start_idx], mapping)

    # 2. Lines strictly between start_anchor and end_anchor: full rename.
    for i in range(start_idx + 1, end_idx):
        lines[i] = relabel_line(lines[i], mapping)

    # 3. end_anchor: full rename (end_mode="at") or skip (end_mode="before").
    if end_mode == "at":
        lines[end_idx] = relabel_line(lines[end_idx], mapping)

    return "".join(lines)
