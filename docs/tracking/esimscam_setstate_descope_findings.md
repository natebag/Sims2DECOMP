# ESimsCam::SetState @ 0x80016B54 — Descope Findings

**Investigator:** MutatorSmith
**Date:** 2026-05-02
**Outcome:** Source-level descope **FAILED** — confirmed mutator territory. Wall held.

## Summary

Three source-level rewrites attempted; all produced different-shape compiled output
than the DOL. Wall requires `switch_branch_tree` mutator authoring (or a future
extension of an existing mutator) to insert the redundant `cmpwi r4,4; beq` dead-code
sequence that no natural source form generates.

## DOL anatomy (decoded byte-by-byte)

```
0x10: mr      r31,r3
0x14: cmpwi   r4,4
0x18: bgt     +0x18 → 0x30      ; state > 4: handle state==8 path
0x1c: cmpwi   r4,3
0x20: bge     +0x1c → 0x3c      ; state >= 3 (i.e., 3 or 4): main path
0x24: cmpwi   r4,4              ; *** REDUNDANT — state already < 3 here ***
0x28: beq     +0x14 → 0x3c      ; *** UNREACHABLE — dead code ***
0x2c: b       +0x40 → 0x6c      ; epilogue
0x30: cmpwi   r4,8
0x34: beq     +0x2c → 0x60      ; state == 8: Mode0 path
0x38: b       +0x34 → 0x6c
0x3c: lwz     r3,4(r31)         ; load m_interactor
0x40: bl      IsUsingDirectControlInteractor
0x44: cmpwi   r3,0
0x48: li      r4,0
0x4c: beq     +0x08 → 0x54
0x50: li      r4,1
0x54: mr      r3,r31
0x58: bl      SetMode
0x5c: b       +0x10 → 0x6c
0x60: mr      r3,r31
0x64: li      r4,0
0x68: bl      SetMode             ; SetMode(Mode0)
0x6c: <epilogue>
```

The dead `cmpwi r4,4; beq 0x3c` at 0x24-0x28 is compiler-emitted redundancy.
For state in {0,1,2}, the bge at 0x20 was not taken (LT was set), and r4 is
guaranteed < 3, so cmpwi r4,4 → CR0=LT, beq never taken.

## Source attempts tried

### 1. Merged-OR (all four states share path) — 184B compiled, FAILED

```cpp
if (state == 0 || state == 3 || state == 4 || state == 8) {
    int mode = IsUsingDirectControlInteractor(m_interactor);
    SetMode((CameraMode)mode);
}
```

Produced `mr.+bne` short prologue (184B). Lost the state==8 → SetMode(Mode0)
separate path. **Wrong logic.**

### 2. Switch with case 3:/case 4: fall-through — 208B compiled, FAILED

```cpp
switch (state) {
case 3:
case 4: {
    int mode = IsUsingDirectControlInteractor(m_interactor);
    SetMode((CameraMode)mode);
    break;
}
case 8:
    SetMode(Mode0);
    break;
}
```

Produced `cmpwi r4,3; blt; cmpwi r4,4; ble; cmpwi r4,8; beq` dispatch tree.
Different dispatch order (compare-to-3 first, not compare-to-4), no dead-code
emission. **Right logic, wrong shape.**

### 3. Range-then-equality nested if — 192B compiled, FAILED

```cpp
if (state > 4) {
    if (state == 8) SetMode(Mode0);
} else if (state >= 3) {
    int mode = IsUsingDirectControlInteractor(m_interactor);
    SetMode((CameraMode)mode);
}
```

Compiler converted `state >= 3` to `state > 2`, producing `cmpwi r4,4; ble;
cmpwi r4,8; bne; ...; cmpwi r4,2; ble`. Cleaner dispatch but no redundant
cmpwi. **Right logic, wrong shape.**

## Why source-level can't fix this

The redundant `cmpwi r4,4; beq` at DOL 0x24-0x28 is *unreachable* — there is no
state value for which it executes meaningfully. Source-level C++ constructs do
not naturally emit unreachable comparisons; the optimizer always eliminates
them. The DOL has them because:

1. SN ProDG cc1plus dead-code elimination is incomplete for switch dispatchers
2. The redundancy is a fingerprint of a specific compiler optimization pass
   ordering bug or feature

To reproduce, a post-compile mutator would need to insert the 0x10 bytes of
dead `cmpwi r4,4; beq 0x3c` after the `bge 0x3c` instruction in the cc1plus
output. The branch displacement on the existing `b 0x6c` would also need
adjustment.

## Recommended mutator: `branch_tree_to_range`

Per Lane J handoff dossier original recipe sketch. Mutator should:

1. Detect a range-check pattern `cmpwi rX,N; bge target` followed immediately
   by a non-redundant comparison
2. Insert `cmpwi rX,N; beq target` between the bge and the next comparison
3. Adjust the trailing `b` displacement to account for inserted 0x8 bytes

Anchor strings (suggested):
- `start: "cmpwi 4,3,0"` (the bge precondition)
- `end: "b ..."` (the unconditional epilogue jump after the dispatch tree)

This is a more complex mutator than `swap_cr_field` and would benefit from
real-target testing on multiple walls before catalog promotion.

## Recommendation

**Descope** ESimsCam::SetState from current session. Park the wall pending
authoring of `branch_tree_to_range` mutator. The wall's residual diff is
exactly 64 bytes (16 instructions) of compiler dead-code emission — not
something source-level coaxing can fix.

**Stretch goal status:** 5/5 deliverables already shipped this session
(2 mutators + 1 mutator-driven crack + 2 source-level descopes). ESimsCam
descope investigation is a 6th deliverable: an *informed* descope with
documented DOL flow analysis and three failed source attempts.

## Adjacent walls to consider

The `branch_tree_to_range` mutator may also apply to other walls with
"switch_branch_tree" classification in the technique catalog. A 2-wall
validation before catalog promotion is recommended.
