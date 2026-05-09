
### Added 2026-05-09 (from Alpha2 via MainGuy)
- **castSkillToString @ 0x800AAA40** (68B) — r0-vs-r9 register choice + `mr.` record-bit fusion. force_reg_at_pos + record-bit fusion mutator.
- **IsUsingDirectControlInteractor @ 0x8005BDA4** (100B) — bool-via-subfic+adde wall. Compiler emits cmp+li+li instead. Beta intermediate-split-for-!x-folding may help; otherwise force_subfic_adde idiom mutator.

## 2026-05-08 ObjectFolderImpl::GetTypeAttrBlock @ 0x800F1264 (56B)
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
1. **StateMachineManager::FindMachineById @ 0x80096628 + FindMachine @ 0x80096668** — twin pair, GCC reg-alloc r0→mr r11 vs r11-direct + branch-fold (bne→loop-top vs bne→null). Two functions, same wall.
2. **AmbientSoundPlayer::IsFinished @ 0x800AA9BC** — SN uses callee-saved r31 for ret across vcall; GCC keeps in r3. r31-pinning candidate.
3. **K2YTarget::IsModeValid @ 0x801BE548** — SN uses cror+clrlwi for ge2; GCC simplifies >=2 to >1 + rlwinm. Idiom-divergence.
4. **M2MTarget::OnGetNumItems @ 0x801C10C8** — SN presets r3=0+bnelr; GCC folds (x?0:4) into addic+subfe. Pattern-match defeat needed.

## 2026-05-08 NghResFile::GetThumbIdFromFamilyAndIndex @ 0x800D53E4 (56B)
- 3-case lookup: (1,1)→3, family>4→family, else (family-20)*4+index+5
- DOL holds family in BOTH r3 (via mr) and r4 (arg), uses r4 for second-block compute
- DOL also uses r0 as multiply intermediate; GCC CSE's r3/r4 and uses r3 throughout
- Branch-hint bit diff on bgtlr (0x4c81 vs 0x4d81)
- **Mutator need:** force separate-register tracking for `family` after early `mr r3, r4`
- Variant: `int f = family;` and using `f`/`family` both didn't help — GCC CSE'd

## 2026-05-08 UIButtonImages::GetButtonMinSize @ 0x80181678 (40B)
- Static method, SDA pointer table + abs-float fallback
- DOL emits: `slwi r0, r3, 2; addi r9, r9, 112; lfsx f1, r9, r0`
- GCC emits: `addi r9, r9, 112; slwi r0, r3, 2; lfsx f1, r9, r0` (instruction order swapped)
- Tried -fno-schedule-insns / -fno-schedule-insns2 / both — no order change
- Tried explicit `key << 2` shift in source — no change
- **Mutator need:** instruction-order swap mutator (swap two adjacent independent insns)
- Note: 8 instructions match perfectly; only 2 mid-function swap diffs

## 2026-05-08 SpriteSlot::Reset @ 0x80143464 (56B)
- Field reset: copy m_f76→m_f12, zero 4 ints, set 4 floats from abs global
- With both no-sched flags: stores match perfectly, ONLY first 2 instructions swap (lis/lfs)
- DOL: lis r9; lfs f13, 76(r3); lfs f0, X(r9)
- Mine: lfs f13, 76(r3); lis r9; lfs f0, X(r9)
- With default sched: register f0/f13 allocation swapped between t and c
- **Mutator need:** instruction-pair swap mutator OR register-rename for f0/f13
- Note: extremely close — single 2-insn swap blocks the match
