# Lane J Triage Handoff → MutatorSmith

**OpusWorker, 2026-05-02**

All 7 near-miss walls from Kmiworker2's S13 session 2 catalog triaged. **All 7 require mutator authoring** — no source-level descopes this round. Source-level attempts ADVANCED 2 of them (PlumbBobModel offset, GameData offsets) but residual is mutator-territory.

Files in this directory contain the source-level recipes that landed closest. Use them as starting points; the residual diff is what your mutator needs to handle.

## Wall summary

| Wall | Symbol | Address | Diff class | Mutator |
|------|--------|---------|------------|---------|
| cr_reg_allocation | PlumbBobModel::SetShadow | 0x8005B3E0 | cr0↔cr7 swap on first/second compare | `swap_cr_field` |
| loop_body_equivalence | EGlobal::GetUrbzButtonsRow | 0x80040030 | for-i++ vs ptr-walk loop | `loop_to_ptrwalk` |
| store_order_asymmetry | GameData::GamePlayReset | 0x8003B22C | Source-order writes get rotated | `swap_adj_stores` |
| switch_branch_tree | ESimsCam::SetState | 0x80016B54 | Discrete-beq tree → range bgt/bge | `branch_tree_to_range` |
| mr_fold_to_mr_dot | BString2::assignDebug | 0x800A4870 | mr+cmpwi+bne → mr. fused | `unfold_mr_dot` |
| register_reuse_elimination | CatWsAToBuff | 0x8007AB94 | Compiler eliminates redundant mr | (TBD — see file) |
| loop_body_equivalence | FamilyImpl::RemoveMember | 0x800B69D4 | Vector erase loop shape | `loop_to_ptrwalk` |

## Per-wall details

### 1. PlumbBobModel::SetShadow (cr_reg_allocation)

**Source-level progress:** Fixed EResource layout (m_id at offset 8 via 4-byte vptr_pad). Eliminated offset 0x28 diff.

**Residual after fix:** Pure CR field swap at offsets 0x20, 0x24, 0x2c, 0x30, 0x34. DOL uses cr0 for first compare (m_shadow!=0), cr7 for second (shadowId vs oldId). Compiled flips them. Tried temp-alias rewrite; no effect.

**Recipe sketch:** `// ASMPROC_swap_cr_field cr0↔cr7` directive applied to the cmpwi r3,0/cmp r31,r29 pair and their dependent branches. Branch displacements unchanged (only BI field swap).

### 2. EGlobal::GetUrbzButtonsRow (loop_body_equivalence)

**Source-level progress:** None significant — diff is 21+ insns (extensive structural).

**Residual:** DOL uses pointer-walk loop pattern (entry pointer + addi 0x10 step), compiled uses `for (int i = 0; i < count; i++)` with array-index-style addressing.

**Recipe sketch:** `// ASMPROC_loop_to_ptrwalk` mutator that converts the array-index loop body into a pointer-walk equivalent. May share implementation with FamilyImpl::RemoveMember.

### 3. GameData::GamePlayReset (store_order_asymmetry)

**Source-level progress:** Fixed struct layout (m_field84 @ 0x84, m_flag @ 0xe4, m_fieldE8 @ 0xe8, m_fieldF0 @ 0xf0). Reduced diffs from 19 sites to 4.

**Residual diffs:**
- 0x3c-0x44: 3 stores to g_gameDataGlobal (ac/b0/b4) — DOL writes in source order (ac, b0, b4); compiled rotates (b4, ac, b0)
- 0x58: addi r31, r31, 0x10 (DOL) vs 0x1 (compiled) — loop step uses Player size vs scalar i++

**Recipe sketch:**
- `// ASMPROC_swap_adj_stores` to undo store rotation on the 3 g_gameDataGlobal writes
- Loop step needs mutator or could be source-level `Player* p = m_players; for (...) { p->Reset(idx); p++; }`

### 4. ESimsCam::SetState (switch_branch_tree)

**Source-level progress:** Source uses `if (state == 0 || state == 3 || state == 4)` which generates beq-tree. Tried `if (state >= 3 && state <= 4)` — different shape but didn't match.

**Residual:** DOL uses `cmpwi r4,4; bgt; cmpwi r4,3; bge; cmpwi r4,4; beq; b` (range-then-equality dispatch with redundant `cmpwi r4,4; beq` after bge). Compiled uses pure equality chain.

**Recipe sketch:** `// ASMPROC_branch_tree_to_range` that converts beq-tree to bgt/bge range form. The redundant `cmpwi r4,4; beq` after bge looks like compiler dead-code elimination of a switch case — a switch-statement source rewrite is worth trying first if you don't already have a mutator pattern.

### 5. BString2::assignDebug (mr_fold_to_mr_dot)

**Source-level progress:** None — `if (!str) { str = g_default; }` always folds to `mr. + bne`.

**Residual:** DOL has `mr r30,r4; cmpwi r3,0; bne` (3 insns). Compiled has `mr. r30,r4; bne` (2 insns). DOL is testing r3 separately from the mr — implies original source had a temporary that the compiler couldn't fold.

**Recipe sketch:** `// ASMPROC_unfold_mr_dot` that splits an `mr.+bne` pair into `mr; cmpwi r3,0; bne` (note: r3 is a different register than the mr's source). The DOL pattern uses cmpwi r3,0 — the testing register may be dependent on the call sequence.

### 6. CatWsAToBuff (register_reuse_elimination)

**Source-level progress:** Not deeply explored (time budget). 16-byte size diff = 4 missing instructions.

**Residual:** DOL has redundant mr instructions (e.g., setting up args via mr that compiler optimizes away). Specific pattern needs disasm comparison.

**Recipe sketch:** `// ASMPROC_insert_mr` (existing mutator) may apply. Worth checking if `force_redundant_mr` is what's needed here.

### 7. FamilyImpl::RemoveMember (loop_body_equivalence)

**Source-level progress:** None — 36-byte size diff = 9 missing instructions.

**Residual:** Source compiles to vector erase as memmove-style loop. DOL uses different shape — possibly count-down loop, or different stride pattern.

**Recipe sketch:** `// ASMPROC_loop_to_ptrwalk` (shared with EGlobal::GetUrbzButtonsRow). The two walls cataloged together might reveal a single mutator pattern.

## Suggested authoring order

1. **`swap_cr_field`** (PlumbBobModel) — simplest mutator, single-instruction transformation
2. **`swap_adj_stores`** (GameData partial) — proven feasible, you have `swap_adj` already from session 2
3. **`branch_tree_to_range`** (ESimsCam) — multi-instruction but bounded
4. **`unfold_mr_dot`** (BString2) — straightforward 2→3 insn expansion
5. **`loop_to_ptrwalk`** (EGlobal + FamilyImpl) — apply to both, validate as 2-wall unlock
6. **CatWsAToBuff** — needs deeper disasm pre-RE; may benefit from `insert_mr` extension

## What I learned

- Address-based pre-check before source-level work: the catalog was 7 walls but I confirmed all 7 still walls (initial false-positive on grep `MATCH` matching `MISMATCH` corrected — see `feedback_dupe_detection_regex.md` candidate update).
- Field-offset bugs hide CR-allocation diffs: PlumbBobModel showed unrelated diffs that resolved cleanly once layout was fixed.
- Triage-first protocol: even when descope fails (all → handoff), source-level attempts SHRINK the residual diff for the mutator — making your authoring scope smaller and clearer.
