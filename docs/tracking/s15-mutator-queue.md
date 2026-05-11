
## RESOLVED parks — S15 pre-flight audit + Phase 1 (2026-05-11)

Pre-flight audit (MutatorSmith → MainGuy 2026-05-11) found 6 of the 10 Alpha2 parks
listed below were ALREADY cracked in prior sessions and never marked resolved.
Phase 1 added 2 fresh cracks. Remaining: 2 (castSkillToString, K2YTarget pending).

| Addr | Function | Status | Commit | Recipe |
|------|----------|--------|--------|--------|
| 0x8005BDA4 | IsUsingDirectControlInteractor | ✅ RESOLVED | `dc4d3011` | inverted-logic xor+subfic+adde |
| 0x80096628 | StateMachineManager::FindMachineById | ✅ RESOLVED | `61bd7863` | region_gpr_relabel + insert_mr |
| 0x80096668 | StateMachineManager::FindMachine | ✅ RESOLVED | `a7970040` | r0_to_r9_split (twin) |
| 0x800AA9BC | AmbientSoundPlayer::IsFinished | ✅ RESOLVED | `5721efe9` | inverted-logic + early-r0-hoist |
| 0x801C10C8 | M2MTarget::OnGetNumItems | ✅ RESOLVED | `8c3ab335` | early-result-init source-coax |
| 0x80181678 | UIButtonImages::GetButtonMinSize | ✅ RESOLVED | `dc139491` | SDA pointer + non-SDA fallback float |
| 0x80143464 | SpriteSlot::Reset | ✅ RESOLVED | `eb7257fe` | swap_adj a=lfs b=lfs (S15 Phase 1) |
| 0x800F1264 | ObjectFolderImpl::GetTypeAttrBlock | ✅ RESOLVED | `e47fe1a2` | force_reg×2 + insert_mr 3-directive (S15 Phase 1) |
| 0x800D53E4 | NghResFile::GetThumbIdFromFamilyAndIndex | ✅ RESOLVED | `9b8cb9e7` | force_reg + 3×force_reg_at_pos (S15 Phase 1) |
| 0x800AAA40 | castSkillToString | ✅ RESOLVED | `9106d933` | 7-directive + new fuse_mr_recordbit mutator (S15 Phase 1) |
| 0x80066940 | SAnimator2::stopCurAnim | ✅ RESOLVED | `57c5af3d` | swap_adj which=N extension (S15 Phase 2) |
| 0x80069998 | SAnimator2::setFollowDone | ✅ RESOLVED | `ecb70d94` | 6-directive (3-swap rotation) (S15 Phase 2) |
| 0x80066F00 | SAnimator2::lockHandsUpCarryNodes | ✅ RESOLVED | `c53bc85d` | new inject_before mutator + 5 swap_adj (S15 Phase 2 drift recovery) |
| 0x802E9C0C | EAnimController::PrintTracks | ✅ RESOLVED | `a1b2029f` | force_reg_at_pos×3 + swap_adj×2 (S15 Phase 2) |
| 0x802F0A8C | EAnimController::SetNodeVisible | ✅ RESOLVED | `8c4f4a7d` | swap_adj×2 + swap_operands lwzx/stwx×4 (S15 Phase 2) |
| 0x802F0A30 | EAnimController::SetNodeIgnoreAnimatedVisibility | ✅ RESOLVED | `8c4f4a7d` | sibling-port of 0x802F0A8C (S15 Phase 2) |
| 0x80346124 | ENgcRenderer::SetBlendMode | ✅ RESOLVED | `1b2b81a6` | replace_insn + region_gpr_relabel cyclic-4 swap (S15 Phase 2) |
| 0x80349FDC | ENgcRenderer::ParticleListBegin | ✅ RESOLVED | `6d7cb23d` | insert_mr + force_reg (S15 Phase 2) |

## S15 DEFERRED WALLS — diagnostic patterns observed, carry to S16 (2026-05-11)

These walls were attempted in S15 and time-capped after 10-30 min source-coax /
mutator-recipe exploration. Each documents the SPECIFIC divergence pattern so
S16 can pick up with clean context.

### 0x8006C664 EAnimController::SetAwarenessFollowMiddle (120B) — Phase 2 deferred
- Best result: MISMATCH 8 diff offsets via no-sched + correct source
- Two adjacent line swaps doable (cmpwi/li × 2)
- Hard part: 4-instruction reorder in SetTrackBlendSmooth arg-prep block
  - DOL evaluates: lfs f2, lfs f1, addi r3, lfs f3, li r4
  - GCC evaluates: addi r3, li r4, lfs f1, lfs f2, lfs f3
- S16 recipe candidate: multi-swap_adj chain to cycle the prep block; or
  source-side coax via temp variables for f1/f2/f3 with strategic ordering.

### 0x80066F40 + 0x80066F80 SAnimator2::lockCarryArmNodes (twin) — Phase 2 deferred
- Same dead-load injection family as 0x80066F00 (Wall #9 cracked).
- Wall #9 used inject_before + 5 swap_adj — applied to these gave 40+ diffs.
- Hard part: source-driven arg-shuffle pattern (mr r11,r4; mr r4,r5; mr r5,r11)
  that GCC emits differently. Plus gpr_relabel swap=0:11 hit a
  cmpwi-immediate-clobber hazard (relabel rewrote "0" in `cmpwi r9,0` immediate).
- S16 recipe candidate: explicit force_reg per-line (not whole-function
  gpr_relabel) to preserve cmpwi immediates. Or upgrade gpr_relabel to
  skip immediates on cmpwi.

### 0x800169E8 ESimsCam::SetFov (52B) — OpusWorker T4 deferred
- Best result: MISMATCH 8 diff offsets via no-sched + 4-element FP rotation
- GCC produces algebraically-equivalent but byte-different FP arithmetic:
  - DOL emits: fsubs+fsubs+fmuls+fsubs+fmadds+fdivs (uses FMA)
  - GCC emits: fsubs×3+fmuls+fdivs+fadds (no FMA)
- Same SIZE (13 insns / 52B) but FMA pattern differs.
- S16 recipe candidate: source-side fmadds-form coax — `(a*b + c*d) / d` style
  expression. Or `__builtin_*` if available (likely not for GCC 2.95).
- Plus cyclic-3 FP-register rotation (f10→f11, f11→f12, f12→f13, f13→f10),
  which fp_relabel can't handle (rejects overlapping pairs). region_gpr_relabel
  doesn't apply to FPRs. Needs new mutator `region_fpr_relabel` or per-line
  force_reg_at_pos.

### 0x8005F548 SAnimator2::Dress (136B) — OpusReviewGuy park deferred
- MI-vcall + slot-pointer hoist + arg-shuffle complex.
- Compiles to 112B (24B / 6-insn short) — GCC drops the slot-pointer hoist
  pattern `addi r10, r9, 320` because GCC's allocator uses fully-positional
  offsets via `lwz r0, 320(r9)` and `lwz r0, 324(r9)`.
- Plus whole-function r30↔r31 swap (gpr_relabel candidate).
- S16 recipe candidate: source-side volatile slot-pointer to force the addi
  emission, then gpr_relabel for the param-register swap.

### 0x800169E8/0x8003461C/0x8007AD28/0x80344648/0x80348DDC ENgcRenderer cluster — Phase 3
- Multiple walls in ENgcRenderer with structural divergences:
  - SetGeometryModes: 3-reload pattern of `this->_4D8`, RTL if/else dispatch
  - ScrambleRect (EDLEntry*): GCC uses temp regs r10/r11 instead of direct r4/r5
  - CompositeSkin (ESim): multi-vcall + slot-pointer hoist (slot_pointer_hoist
    candidate per feedback memory)
  - CopyCharStrToWString: register + loop structure differs

### 0x8004AFA8 BBI::InventoryItems::GetNewItemIndex (68B) — Phase 2 deferred
- DOL uses r3 directly as `this` throughout; GCC immediately saves to r10
  (`mr r10, r3`). DOL uses r10 as result accumulator (mr r3, r10 at end);
  GCC uses r3 directly.
- Plus fast-return bgtlr vs separate .L_end block.
- S16 recipe candidate: gpr_relabel swap=3:10 + restructure source to use
  a goto-style structure that produces .L_end block. Combined would need
  region_gpr_relabel to avoid clobbering the cmpwi r3,N immediate paths.

### 0x80311DC8 EResource::EResource (48B) — Phase 2 deferred
- DOL saves `mr r11, r3` to keep `this` alive across writes; uses r10 as
  persistent zero literal (li r10,0 once, then sth r10 × 2 and stw r10).
- GCC uses r3 directly, recomputes `li r0, 0` for each zero store.
- S16 recipe candidate: insert_mr to add the mr save + region_gpr_relabel
  to switch r0/r3 register-roles. Or restructure source to coax separate
  registers for the zero literal vs other uses.

### 0x8000DFA8 AptLine::UnlinkWord (80B) — Phase 2 deferred
- GCC optimizes away DOL's redundant `cmpwi r3, 0; beqlr` after the loop
  break (GCC knows curr is non-NULL at that point).
- Compiled = 76B / 19 insns; DOL = 80B / 20 insns. 1 insn short.
- S16 recipe candidate: source-side obfuscation to force the redundant check.
  Or new mutator `inject_dead_check` that inserts a cmpwi+beqlr at an anchor.

### 0x800A76AC QuickStringSet::GetString (80B) — Phase 2 deferred
- Substantial register-allocation divergence — GCC immediately saves r4
  argument to r9 (`mr r9, r4`). Different RA throughout.
- S16 recipe candidate: full source rewrite + multi-mutator recipe.

## S16 MUTATOR-DESIGN CANDIDATES

1. **`cror_or_of_cr_bits`** — Synthesize the cror+mfcr+clrlwi idiom for
   compound boolean conditions (≥N as `eq||gt`, ≤N as `eq||lt`).
   Targets: K2YTarget::IsModeValid (Wall #5 classified Phase 1), KEYTarget
   sibling @ 0x801F99FC, possibly INVTarget::IsPackagedItem (per OpusWorker).

2. **`region_fpr_relabel`** — Bounded FP-register rename. Cycles allowed via
   simultaneous lookup. Target: ESimsCam::SetFov (cyclic 3-FP rotation).

3. **`inject_dead_check`** — Insert a cmpwi+conditional-branch pair at an
   anchor to materialize redundant DOL checks that GCC optimizes away.
   Target: AptLine::UnlinkWord (1-insn-short pattern).

4. **gpr_relabel + cmpwi-immediate awareness upgrade** — Current gpr_relabel
   rewrites "0" or other constants in cmpwi immediates when the same value
   matches a rename pair (e.g., relabel 0:11 corrupts `cmpwi r9, 0` to
   `cmpwi r9, 11`). Need to skip operands at positions that are immediates
   (per opcode-specific knowledge for cmpwi/cmplwi/addi etc.).

5. **`hoist_fcmpu`** — Move `fcmpu` from end of basic block to BEFORE a
   sequence of `stfs` instructions in same block. Signature: DOL emits
   `fcmpu cr0, fX, fY` before stfs sequence; GCC's RTL pass actively
   un-schedules to put fcmpu last (after stores). 2-instance class wall
   confirmed (per OpusReviewGuy 2026-05-11):
   - setAwarenessFollowMiddle @ 0x8006C664 (Wall #8 deferred, 8 diffs)
   - SetTrackBlendSmooth @ 0x802EE324 (deferred, 9 diffs)
   Day-1 STANDARD candidate with 2 validation targets ready.

## S16 MAINTENANCE CANDIDATES

1. **`wall_classification.json` refresh** — 15 of 22 STORE_ORDER walls
   verified ALREADY MATCHED in S15. Classification data is stale relative to
   actual match state. Need a script to regenerate the classification by
   scanning unmatched-only via the inclusive regex pattern.

### Added 2026-05-09 (from Alpha2 via MainGuy)
- **castSkillToString @ 0x800AAA40** (68B) — r0-vs-r9 register choice + `mr.` record-bit fusion. force_reg_at_pos + record-bit fusion mutator.
- **IsUsingDirectControlInteractor @ 0x8005BDA4** (100B) — ✅ RESOLVED `dc4d3011` — bool-via-subfic+adde wall. Compiler emits cmp+li+li instead. Beta intermediate-split-for-!x-folding may help; otherwise force_subfic_adde idiom mutator.

## 2026-05-08 ObjectFolderImpl::GetTypeAttrBlock @ 0x800F1264 (56B) — ✅ RESOLVED `e47fe1a2` (S15 Phase 1)
- Linear search through m_begin/m_end iterator pair
- DOL stages `m_end` through r0 first, then `mr r11, r0` before loop entry
- GCC folds pre-check and loop-test: `if (it != end) do {} while (it != end)` collapses to single while
- Source-coax exhausted: do-while-with-precheck still produces 52B (one mr short)
- **Mutator need:** force `mr rX, rY` insertion between two equal-register comparisons
- Track I candidate: register-rename mutator with explicit copy directive

## 2026-05-08 MainGuy update from Alpha2

### REMOVED from Phase 3 queue
- **EResource::EResource @ 0x80311DC8** — NOT standalone. Inlined fragment of WXFTarget::WXFTarget @ 0x80311804+0x1a7c. Filename misleading. Needs full-TU compilation, not individual match.

### Added (4 fresh parks)
1. **StateMachineManager::FindMachineById @ 0x80096628** ✅ RESOLVED `61bd7863` + **FindMachine @ 0x80096668** ✅ RESOLVED `a7970040` — twin pair, GCC reg-alloc r0→mr r11 vs r11-direct + branch-fold (bne→loop-top vs bne→null). Two functions, same wall.
2. **AmbientSoundPlayer::IsFinished @ 0x800AA9BC** ✅ RESOLVED `5721efe9` — SN uses callee-saved r31 for ret across vcall; GCC keeps in r3. r31-pinning candidate.
3. **K2YTarget::IsModeValid @ 0x801BE548** — SN uses cror+clrlwi for ge2; GCC simplifies >=2 to >1 + rlwinm. Idiom-divergence.
4. **M2MTarget::OnGetNumItems @ 0x801C10C8** ✅ RESOLVED `8c3ab335` — SN presets r3=0+bnelr; GCC folds (x?0:4) into addic+subfe. Pattern-match defeat needed.

## 2026-05-08 NghResFile::GetThumbIdFromFamilyAndIndex @ 0x800D53E4 (56B)
- 3-case lookup: (1,1)→3, family>4→family, else (family-20)*4+index+5
- DOL holds family in BOTH r3 (via mr) and r4 (arg), uses r4 for second-block compute
- DOL also uses r0 as multiply intermediate; GCC CSE's r3/r4 and uses r3 throughout
- Branch-hint bit diff on bgtlr (0x4c81 vs 0x4d81)
- **Mutator need:** force separate-register tracking for `family` after early `mr r3, r4`
- Variant: `int f = family;` and using `f`/`family` both didn't help — GCC CSE'd

## 2026-05-08 UIButtonImages::GetButtonMinSize @ 0x80181678 (40B) — ✅ RESOLVED `dc139491`
- Static method, SDA pointer table + abs-float fallback
- DOL emits: `slwi r0, r3, 2; addi r9, r9, 112; lfsx f1, r9, r0`
- GCC emits: `addi r9, r9, 112; slwi r0, r3, 2; lfsx f1, r9, r0` (instruction order swapped)
- Tried -fno-schedule-insns / -fno-schedule-insns2 / both — no order change
- Tried explicit `key << 2` shift in source — no change
- **Mutator need:** instruction-order swap mutator (swap two adjacent independent insns)
- Note: 8 instructions match perfectly; only 2 mid-function swap diffs

## 2026-05-08 SpriteSlot::Reset @ 0x80143464 (56B) — ✅ RESOLVED `eb7257fe` (S15 Phase 1)
- Field reset: copy m_f76→m_f12, zero 4 ints, set 4 floats from abs global
- With both no-sched flags: stores match perfectly, ONLY first 2 instructions swap (lis/lfs)
- DOL: lis r9; lfs f13, 76(r3); lfs f0, X(r9)
- Mine: lfs f13, 76(r3); lis r9; lfs f0, X(r9)
- With default sched: register f0/f13 allocation swapped between t and c
- **Mutator need:** instruction-pair swap mutator OR register-rename for f0/f13
- Note: extremely close — single 2-insn swap blocks the match
