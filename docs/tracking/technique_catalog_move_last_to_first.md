# Technique Candidate: Move-Last-to-First Scheduler Quirk

**Logged by:** MutatorSmith
**Date:** 2026-05-02
**First evidence:** GameData::GamePlayReset @ 0x8003B22C — commit `99763dc4`
**Wall class:** `store_order_asymmetry`
**Resolution:** Source-level (no mutator authoring)

## Pattern

When the SN ProDG scheduler emits 3 (or more) adjacent stores to consecutive
struct members in **rotated** order vs. source-line order, a deterministic
"move-last-to-first" rotation is observed:

  Source order:   `[A, B, C]`
  Emitted order:  `[C, A, B]`     (last source line is moved to first emit slot)

To match a DOL that has stores in source order `[A, B, C]`, rewrite the C++
source as `[B, C, A]`. The scheduler then rotates that to `[A, B, C]` and
matches the DOL.

## Confirmed instance

`GameData::GamePlayReset` writes 3 zero-stores to global `g_gameDataGlobal`
fields at offsets `0xac`, `0xb0`, `0xb4`:

  DOL emit:        stw r0,172(r9) ; stw r0,176(r9) ; stw r0,180(r9)
  Source [ac,b0,b4] → emit [b4,ac,b0]   (compiler rotated source)
  Source [b0,b4,ac] → emit [ac,b0,b4]   (matches DOL)

Verified with default flags (no `-fno-schedule-insns` needed). Both `-fno-schedule-insns`
and `-fno-schedule-insns2` made the diff worse — additional rotation/aliasing
sites appeared. Default scheduler is the right setting; the rotation is a
source-order issue, not a flag issue.

## Recipe

1. Identify the 3+ adjacent global stores (typically `stw r<src>,off(r9)` or
   to a local pointer).
2. Read the DOL emit-order from disasm (offsets `off1, off2, off3`).
3. Read the current source-line order (member assignments).
4. If source order differs from DOL emit order by a +1 cyclic rotation
   (move last to first), rewrite source by rotating in the opposite direction
   (move first to last).

## When this applies

  - 3+ adjacent stores to **non-overlapping** memory locations (no aliasing
    between them, otherwise reordering would be unsafe).
  - All stores write the same source register (typically `r0` from a previous
    `li r0,0`) — most often a zero-init batch.
  - Default flag matrix; the rotation is the scheduler's natural ordering
    decision.

## When this does NOT apply

  - Mixed read/write or store-load pairs in the sequence (RAW/WAR hazards
    block reordering).
  - Stores using different source registers — each may have different
    register-pressure cost models.
  - More than 3 stores: the rotation pattern may not be a simple +1 cyclic.
    Pattern needs to be re-confirmed per case.
  - Walls where the diff includes register reuse or CR allocation in addition
    to store order (those need a mutator: `swap_cr_field`).

## Adjacent walls to test

  - GameData::GamePlayReset (0x8003B22C) — RESOLVED via this technique.
  - Anywhere the diff is exactly 3 consecutive `stw` lines with offsets
    permuted by +1 cyclic rotation.

## Sibling techniques

  - **Empty-struct loop-stride fix** (also from GameData): when iterating
    an array of empty struct (`Player m_players[N]` with empty Player) and
    DOL pointer-walk uses stride `K` bytes, add `char pad[K]` to give the
    struct sizeof `K`. Compiler then emits `addi rN,rN,K` for the step.
    Often co-occurs with this technique on the same function.

## Catalog status

  - **Technique #N+1** candidate (numbering pending OpusReviewGuy gate review).
  - **Confidence:** Medium — single confirmed instance. Needs 2-3 more hits
    on different walls before promotion to a proven technique.
  - **Suggested test bench:** scan unmatched 64-256B functions in classes
    with global-state init patterns (e.g., GameData, EFx singletons,
    Manager-class Reset/Init methods). Look for 3 adjacent `stw` lines
    targeting consecutive offsets of the same base register where the
    diff signature is offset-rotation only (same source register, same
    base, only the offset bytes permute).
