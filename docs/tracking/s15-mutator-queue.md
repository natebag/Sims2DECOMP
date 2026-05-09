
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
