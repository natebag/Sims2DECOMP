# Technique Catalog Entry — Source-side `if (!cond)` Polarity Flip for Block Layout

**Technique #72** — first source-level technique catalog entry with cross-class verification at first promotion.

**Status:** VALIDATED across 6 functions spanning 5 distinct class families (S13 Track I session 4 — 2026-05-02). Byte-match validation on AptActionQueueC; author-against-disasm pattern verification on 5 additional instances (TUScout scout `7626f129`).

**Use case:** When the cc1plus-emitted block layout has the OPPOSITE ordering of DOL — DOL emits `bcc → tail` followed by inline-block + late-block, and cc1plus chooses the inverted branch direction — flipping the source-level `if (cond)` to `if (!cond)` AND swapping the if/else branch bodies makes cc1plus reproduce DOL's block layout natively. **No mutator needed.**

**Recipe:**

```cpp
// Universal source pattern for any single-bcc function with converging paths.
// `cond_for_bcc` is the boolean test that DOL evaluates.

if (!cond_for_bcc) {
    fallthrough_block;       // matches DOL's inline (then-fallthrough) path
} else {
    branch_target_block;     // matches DOL's late (else-jump) path
}
```

For functions where one path is an early-return:

```cpp
if (positive_path_predicate) {
    return positive_result;  // fast-path early return matches DOL's bcc→tail
}
return negative_corrected_result;  // late-block matches DOL's fallthrough
```

**Why it works:** cc1plus 2.95.3 SN ProDG respects source statement order for block layout when generating `bcc` branches. The compiler does NOT reorder basic blocks based on profile or heuristic — what you write first lands first. Writing the source with the polarity DOL implies (i.e., the negated form of the `bcc` test) produces DOL's exact block ordering, branch direction, and inline-vs-late placement. Any remaining diffs after polarity-flip are orthogonal problems (typically register coloring, reachable via `region_gpr_relabel` / `gpr_relabel` / `force_reg`).

**Validated cases:**

| # | Function | Size | DOL Pattern | Matching Source | Validation |
|---|----------|------|-------------|-----------------|------------|
| 1 | **AptActionQueueC::GetDequeLocation** @ 0x8028552C | 80B | `bge → positive-tail; fallthrough = negative correction` | `if (wrapped >= 0) { return m_begin + wrapped; } return m_begin + (wrapped + m_capacity);` | **BYTE-MATCH** (commit `25fdb045`, region_gpr_relabel residual register-coloring fixed post-flip) |
| 2 | **GetVar_LockedStatus::Handler** | 68B | `beq → str="0"` | `if (locked) { str="1"; } else { str="0"; }` | RE+source analysis (TUScout `7626f129`) |
| 3 | **EResourceManager::DelRef** | 188B | `bne → DelRef(res)` | `if (found==0) { virt_call(); } else { DelRef(res, mode); }` | RE+source analysis (TUScout `7626f129`) |
| 4 | **StateMachine::PushStatus** | 176B | `beq → _M_push_back_aux_v` | `if (!full) { normal_push; } else { aux_push; }` | RE+source analysis (TUScout `7626f129`) |
| 5 | **FamilyImpl::SaveFamily** | 128B | `beq → return 0` | `if (familyId != -1) { save_logic; } return 0;` | RE+source analysis (TUScout `7626f129`) |
| 6 | **IFFSlotDescList::LoadFromDataID** | 212B | `beq → return 0` | `if (result != nullptr) { load_slots; } return 0;` | RE+source analysis (TUScout `7626f129`) |

Cross-class spread: `AptActionQueueC` (Apt deque), `GetVar_LockedStatus` (varhandler), `EResourceManager` (resource refcount), `StateMachine` (state push), `FamilyImpl` (family save), `IFFSlotDescList` (IFF loader). The recipe is class-shape-agnostic — it applies wherever cc1plus and DOL disagree on `bcc`-direction polarity for a single converging-path branch.

**Diagnostic checklist (apply BEFORE authoring a new mutator):**

When you see a block-layout diff in the .s output:

1. Identify the DOL `bcc` test (e.g., `bge`, `beq`, `bne`).
2. Determine which path is inline (fallthrough) and which is late (jump-target) in DOL.
3. Read the cc1plus output: is the layout INVERTED relative to DOL?
4. If yes → flip the source `if (cond)` to `if (!cond)` and swap branch bodies.
5. Recompile. Block layout should match. Remaining diffs are register coloring or RTL-level — handle with `region_gpr_relabel` / `gpr_relabel` / `force_reg` / `force_alias_base`.

**When this fails (separate technique territory):**

- **Tail-merging walls** — DOL has DUPLICATED tail blocks; cc1plus collapses them into a single shared tail. Use [`anti_tail_merge`](../../tools/asm_processor/mutators/anti_tail_merge.py) mutator (Technique #71 sibling — Track I queue #2 ship).
- **Backward-branch shared-epilogue cascades** — multiple test/cleanup/return paths converging via backward branches. Source-coax cannot reach these; needs RTL-level mutator (queue not yet authored).
- **CR-field reuse across `mr`** — DOL keeps a CR field live across an intermediate move that cc1plus would clobber. RTL territory.
- **GCC version-specific block-layout heuristics** — extremely rare; would require cc1plus patch, not source-coax.

**Triage outcome (TUScout descope `7626f129`):**

`branch_layout_coerce` mutator was **PERMANENTLY DESCOPED** based on this technique's validation. After triaging 268 block-layout candidate functions across the unmatched pool, ZERO true block-layout walls survived after applying the polarity-flip recipe. Every candidate either resolved via source-coax OR fell into anti_tail_merge / RTL territory (separate mutator concerns). The fleet should invest matching effort in source polarity-flip BEFORE designing any block-layout-coerce mutator.

**Cross-references:**

- [`anti_tail_merge`](../../tools/asm_processor/mutators/anti_tail_merge.py) — when the tail block is duplicated rather than just polarity-inverted (different problem class).
- [`region_gpr_relabel`](../../tools/asm_processor/mutators/region_gpr_relabel.py) — typical residual register-coloring fix once block layout is correct (the AptActionQueueC pipeline post-polarity-flip).
- [Methodology: triage-first protocol](feedback_triage_first_protocol.md) — the 30-min source-level test that surfaced this technique on AptActionQueueC.
- TUScout descope finding (info `7626f129`) — the cross-class validation pool.
- MutatorSmith methodology note (info `20d3f663`) — first articulation of the recipe on AptActionQueueC.

**Catalog reference:** Apply the recipe directly in source. **No `// ASMPROC_*` directive needed.** This is a source-level technique, not a post-cc1plus mutator. Author the C++ with the polarity DOL implies, recompile, and verify. If the block layout matches but residual diffs remain, those are orthogonal (register coloring, RTL-level) and handled by mutators in `tools/asm_processor/mutators/`.
