# region_gpr_relabel v1 spec — gate-review request

**Author:** MutatorSmith
**Date:** 2026-05-02
**Reviewer:** OpusReviewGuy
**Target:** ≤2 rounds
**Methodology:** Author-against-actual-disasm protocol applied (canonical primary fully RE'd before drafting)

---

## Purpose & Scope

Apply a directed, positional GPR rename to a bounded contiguous region of post-cc1plus .s. Subsumes `force_reg_at_pos` (narrower 1-inst case) and addresses Category-2 walls where:

- Block layout is identical (or has been independently fixed via source-coax)
- Diff is purely register-coloring within a contiguous instruction sequence
- DOL transitions a logical value to a different register at a recognizable kill point
- cc1plus reuses the original register (or different register) for the same value

Sibling of `gpr_relabel` (whole-file, bidirectional). region_gpr_relabel is **BOUNDED + DIRECTED**.

---

## Canonical Primary (RE evidence)

**AptActionQueueC::GetDequeLocation @ 0x8028552c (80B, 20 inst).**

Source: `build/verify/getdeque_v2.cpp` (post v2 polarity-flip — block layout already matches DOL).

```
       cc1plus           DOL                diff
0x14:  subf r0,r10,r0    subf r0,r10,r0     same
0x18:  mullw r0,r0,r9    mullw r0,r0,r9     same
0x1c:  srawi r0,r0,2     srawi r3,r0,2      ★ KILL: dest r0→r3
0x20:  add r0,r0,r4      add r3,r3,r4       all r0→r3
0x24:  divw r9,r0,r11    divw r0,r3,r11     dest r9→r0; src r0→r3
0x28:  mullw r9,r9,r11   mullw r0,r0,r11    all r9→r0
0x2c:  subf. r0,r9,r0    subf. r3,r0,r3     dest r0→r3, src1 r9→r0, src2 r0→r3
0x30:  bge → 0x44        bge → 0x44         same (skip BO/BI)
0x34:  add r3,r0,r11     add r3,r3,r11      src1 r0→r3
0x38:  mulli r3,r3,20    mulli r3,r3,20     same
0x3c:  add r3,r10,r3     add r3,r10,r3     same
0x40:  blr               blr                same
0x44:  mulli r3,r0,20    mulli r3,r3,20     ★ END: src1 r0→r3
0x48:  add r3,r10,r3     add r3,r10,r3     same
0x4c:  blr               blr                same
```

7 mismatches collapse to a SINGLE directive:

```
// ASMPROC_region_gpr_relabel: start_anchor="srawi 0,0,2" end_anchor="mulli 3,0,20" rename="0:3,9:0"
```

Live-range analysis: r3 dead on entry to 0x1c (last use at 0x10 lwz r11, 16(r3)). r0/r9 dead on exit from 0x44 (no further use). r3 (in cc1plus 0x34 dest) coincidentally identical to renamed r0→r3 (silent identity). Liveness clean.

---

## API

```yaml
- mutator: region_gpr_relabel
  args:
    start_anchor: "srawi 0,0,2"      # required: line content of kill instruction
    end_anchor: "mulli 3,0,20"        # required: line content of LAST line in region
    rename: "0:3,9:0"                 # required: directed `from:to` pairs (NOT bidirectional)
    # start_mode: "at"                # optional, default "at"; alt "after"
    # end_mode: "at"                  # optional, default "at"; alt "before"
    # occurrence: 1                   # optional, default 1; nth match if anchor non-unique
    # unsafe_clobber: false           # optional, default false; opt-in to bypass liveness check
```

`rename` is a **directed** map applied **simultaneously** (not iteratively):
- token `0` → `3`
- token `9` → `0`
- token `3` → `3` (silent identity, not in map)

NOT bidirectional. NOT a swap. Directed substitution.

---

## Semantics (start_mode / end_mode)

**`start_mode = "at"`** (default): rename applies to start_anchor's **DEST OPERAND ONLY** (other operands untouched — they read from outside the region's namespace). All subsequent lines fully renamed.

**`start_mode = "after"`**: start_anchor untouched. Rename applies starting from next line.

**`end_mode = "at"`** (default): rename applies up to AND INCLUDING end_anchor's all operands.

**`end_mode = "before"`**: rename ends at the previous line; end_anchor untouched.

**Dest position determination:** per-opcode lookup. Default position 0 (most arithmetic/logical/load ops). Stores (stw/stb/sth/stwx/etc.): no GPR dest — refuse start_mode="at" on a store anchor (use start_mode="after" instead). Branches (bcc/blr/bctr): refuse always.

---

## Algorithm

1. Parse args. Validate `rename`:
   - Each `from:to` pair: `from`, `to` ∈ [0,31]
   - Non-empty map (after identity-filter)
   - Optionally allow cycles (e.g., `0:3,3:0`) — applied as simultaneous map
2. Locate `start_anchor` line (with `occurrence` index if specified). Refuse if 0 matches OR multiple matches without explicit occurrence.
3. Locate `end_anchor` line (separate occurrence index if specified).
4. Verify `start_line_idx < end_line_idx` (v1 = strict `<`).
5. **Safety (best-effort liveness):** for each register R in `rename` map's TO set, scan lines in region [start, end] for R appearing as SOURCE before any DEST write inside region. If found, refuse with `NoApplicableSite` citing potential clobber. (User opt-out: `unsafe_clobber: true`.)
6. Apply rename:
   - **start_mode="at":** rename ONLY dest operand of start_anchor (per opcode dest position). **start_mode="after":** skip start_anchor.
   - Lines strictly between start_anchor and end_anchor: full rename of all GPR operands. Skip non-GPR opcodes (`NON_GPR_INT_OPCODES` from existing gpr_relabel: bc, bcl, bclr, tw, cr*, mtfs*, sc, nop, etc.).
   - **end_mode="at":** full rename of end_anchor's all operands. **end_mode="before":** skip end_anchor.
7. Emit modified asm_text.

**GPR-operand handling:** reuse existing gpr_relabel helpers (`_BARE_REG_RE`, `_MEM_FORM_RE`, `_relabel_token`) — but with directed map (lookup, not bidirectional swap). Refactor existing `_relabel_token` to accept `map` arg; expose as module-private helper (private to mutators package).

---

## Error Conditions

### ValueError (author error, fail-loud)

- Missing required arg (`start_anchor`, `end_anchor`, `rename`)
- Empty rename map (after identity-filter)
- Out-of-range register in rename
- `start_anchor == end_anchor` (zero-line region — see Q2)
- `start_mode="at"` on a store/branch anchor (no dest GPR)
- Invalid mode value (not "at"/"after" or "at"/"before")
- `unsafe_clobber: true` AND the clobber check would pass (no opt-out needed)

### NoApplicableSite (skip-not-fail, harness records)

- `start_anchor` or `end_anchor` not found
- Anchor occurrence index out of range
- `start_line_idx >= end_line_idx` (anchors in wrong order)
- Liveness clobber detected (without `unsafe_clobber` opt-out)

---

## Safety Invariants

1. **DOL-stable anchors**: anchors must be lines that EXIST in cc1plus output AND are unambiguously identifiable (ideally unique). Multiple-match anchors require explicit `occurrence` index.
2. **Module-private helpers**: internal functions prefixed `_` (mirror anti_tail_merge / force_alias_base style).
3. **Banned-pin compatibility**: pure post-cc1plus .s rewrite. No source-side `register asm("rN")`. verify_match.sh line 96 scan passes.
4. **No silent corruption**: liveness clobber check refuses with explicit error; user must opt-in with `unsafe_clobber` if intentional.
5. **Idempotent on no-op rename**: if rename map is identity (e.g., `3:3`), refuse at parse time (empty after identity-filter).

---

## Subsumption Claims — CORRECTED 2026-05-02 (post FamilyImpl pre-RE)

**Does NOT subsume force_reg_at_pos** (queue #4 stays separate). Pre-RE on FamilyImpl::RemoveMember (`src/wip/version_diff/lane_j_handoff/match_0x800B69D4_FamilyImpl__RemoveMember_int.cpp:90-128`) revealed the post-insert problem is **position-aware single-instruction rename**:

```
cc1plus (post insert_mr's relabel 10:11,11:10):  subf 0,11,0
DOL needs:                                       subf 0,11,8  (rb pos r0→r8 only)
```

r0 appears at positions 0 (rt, must stay) and 2 (rb, must become r8). region_gpr_relabel applies map to ALL operand positions — would clobber rt. **force_reg_at_pos remains the correct mutator** for this case.

**Does NOT subsume FamilyImpl 7-directive recipe.** The FamilyImpl pipeline is heterogeneous:
- 3 pre-insert force_reg directives (whole-line renames — fine with existing force_reg)
- 1 insert_mr directive
- 3 post-insert force_reg_at_pos directives (position-aware — REQUIRES the queue #4 mutator)

region_gpr_relabel does not address the post-insert position-aware case. FamilyImpl secondary-validation removed from PR-1 plan; standalone force_reg_at_pos work in queue #4.

**What region_gpr_relabel DOES subsume:** multi-instruction contiguous directed rename (canonical primary AptActionQueueC + future walls with kill-point + bounded region register-coloring diffs). Estimated 5-50 fleet adoptions remain valid for THIS scope.

**Lane O PROVISIONAL clear:** FamilyImpl needs force_reg_at_pos (queue #4), NOT region_gpr_relabel. PR-1 ships with AptActionQueueC primary-only validation (N=1 STANDARD).

---

## Open Questions for Review

**Q1 (semantics):** Is `start_mode="at"` (rename dest only on start anchor) the right default? Alt: always require `start_mode="after"` and force user to add a separate `force_reg` for the kill instruction's dest. Trade-off: simpler API vs explicit boundary handling.

**Q2 (single-inst case):** Should v1 allow `start_anchor == end_anchor` (single-line region)? Trade-off: subsumes force_reg_at_pos cleanly, but conflates "kill point" semantics. v1 default = REFUSE; let `force_reg` handle 1-inst.

**Q3 (liveness check granularity):** v1 = best-effort heuristic (R-as-source before R-as-dest in region). Strict version requires liveness analysis pass. Acceptable for v1?

**Q4 (cycle handling):** rename map `0:3,3:0` (true cycle/swap) — apply as simultaneous map (lookup once). Trade-off: simpler than gpr_relabel's bidirectional pair model. Acceptable?

**Q5 (anchor matching):** substring vs whitespace-normalized exact match. v1 = whitespace-normalized exact (after operand normalization). Aligns with anti_tail_merge. Acceptable?

**Q6 (multi-region):** v1 = single region per directive. Multiple regions = multiple directives. Acceptable?

---

## Evidence & Validation Plan

- Source: `build/verify/getdeque_v2.cpp` (verified 7-mismatch register-coloring diff)
- DOL bytes: extracted via `tools/extract_function.py 0x8028552C 80`
- Smoke tests (impl PR will include):
  - Kill-point rename on dest only
  - Full-region rename on subsequent lines
  - End-anchor inclusion
  - NON_GPR_INT_OPCODES skip
  - Unique-anchor enforcement
  - Occurrence-index handling
  - Liveness refusal
  - Identity-filter refusal
- Wall validation: AptActionQueueC::GetDequeLocation byte-match via `verify_match.sh` — N=1 STANDARD-ship target.

Standing by for verdict. ≤2 round target. Author against actual disasm methodology locked in.
