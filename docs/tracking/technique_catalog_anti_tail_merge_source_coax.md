# Technique Catalog Entry — Source-side Early-Return Split-Tail Recipe

**Technique #73** — second source-level technique catalog entry, sibling to Tech #72 polarity-flip.

**Status:** VALIDATED across 6 functions spanning 4 distinct control-flow shapes (S13 Track I session 4 — 2026-05-02). Byte-match verified on EBitArray::Get, __cmpdi2, the INGTarget sibling pair, GetActionMenu, and EShader::UseOverrideTexture (OpusWorker N=2 confirmation `5d8c952f`, escalated to N=4 by sibling-batch crack `1c5685f6`, then N=6 by Tier-3 sweep `6cafe102`).

This catalog adopts the HOLDS/FAILS coverage map format — see [`catalog_format_conventions.md`](catalog_format_conventions.md) for the format spec.

---

## Structural diagnostic — when does this technique apply?

Apply this technique when ALL of the following hold in the cc1plus-vs-DOL diff:

1. The DOL has **two or more `(materialize-r3 ; blr)` epilogues** at the function's tail. The materializer is typically `li r3, CONST`, `mr r3, rN`, or a simple `lwz r3, GLOBAL@sda21(0)`.
2. cc1plus's `-O2` output **collapses those epilogues into a single shared tail** (one `li/lwz/mr ; blr` block reached by every fail/success path), gaining `-2..-(N-1)*2` instructions vs DOL.
3. The function has **no shared cleanup** to defend the merge — no frame restore, no destructor sequence, no late writeback. (If shared cleanup exists, the merge is forced and this technique does not apply.)
4. The return values **differ across paths** — at least one path returns a different constant or value than another. (If all paths return the same constant, DOL would merge too; the diff is something else.)

Conditions 1+2 produce the visible diff (DOL is `+(N-1)*2` instructions / `+(N-1)*8` bytes longer, with the duplicated tail visible at the function end). Conditions 3+4 are what make source-coax sufficient — they give cc1plus permission to keep the duplicates if the IR shape stops asking for the merge.

If 1+2 hold but 3 or 4 fail → reach for the `anti_tail_merge` mutator (compounded-wall fallback).

---

## The recipe (3 keys)

Write the C++ source as a sequence of `if (cond) return VALUE;` early-return statements rather than a `result = X; goto end;` accumulator pattern. cc1plus 2.95.3 SN ProDG `-O2` will then emit each early-return as its own `(li r3, VAL ; blr)` pair — matching DOL's duplicated-tail layout — when ALL three keys hold.

**KEY 1 — Positive bounds-check form, NOT inverted-and-return.**

```cpp
// good:                                  // bad:
if (index < count) {                      if (index >= count) return FALSE_VALUE;
    body...                               body...
}
return FALSE_VALUE;
```

The positive form leaves the failure tail at function end (the location DOL keeps it). The inverted-and-return form puts the failure return at function entry, which cc1plus and DOL agree on but produces a different block layout from what the rest of this recipe coaxes.

**KEY 2 — Inner branches as early-return, NOT goto-end accumulator.**

```cpp
// good:                                  // bad:
if (cond1) return VALUE_A;                int result = VALUE_B;
return VALUE_B;                           if (cond1) result = VALUE_A;
                                          return result;
```

The accumulator pattern funnels every path through one final `lwz/li r3, FINAL ; blr` — which **is** the merged tail cc1plus would normally generate. Rewriting as separate `return CONST;` statements gives every basic block its own `(li r3, VAL ; blr)` pair with a unique `VAL`, removing the merge candidate at the IR level.

**KEY 3 — Compute order shapes the register allocator.**

When two paths share an intermediate variable (e.g., both branches need a mask, or both need a pointer), declare and compute the **earlier-needed** intermediate first. cc1plus assigns matching physical registers across the diverging paths when their live ranges align in source order. For EBitArray::Get the mask must materialize before the word load, because both paths share the mask register.

This key handles the residual register-coloring nudge once the block-layout coax has worked. If you still see `r3` vs `r9` differences in the diff after applying KEY 1+2, KEY 3 is what to adjust.

---

## Why it works

cc1plus 2.95.3 SN ProDG `-O2` only tail-merges return blocks when they are **byte-identical**. When the source expresses each return path as a SEPARATE `return CONST;` statement with DIFFERENT constants, every basic block ends with a UNIQUE `li r3, VAL` followed by `blr` — and the optimizer has no merge candidates. The `goto end;` / `result = X; goto end;` shape funnels every path through ONE `lwz/li r3, FINAL` followed by ONE `blr`, which IS the merged tail cc1plus would normally generate from a unified `return result;`. Switching to early-return form removes the merge opportunity at the IR level, so the compiler emits the duplicated layout DOL ships natively.

KEY 1 (positive bounds check) places the failure-return at the source-tail location matching DOL's block ordering. KEY 2 (early-return form) is the load-bearing one — it removes the merge opportunity. KEY 3 (compute order) handles register-allocation residuals once the block layout is correct.

---

## Diagnostic checklist (apply BEFORE authoring an `anti_tail_merge` directive)

When you see a tail-merge diff in the .s output (DOL has `+(N-1)*2` inst / `+(N-1)*8` B vs cc1plus, with the duplicated tail visible at the function end):

1. Identify the return values across paths. If they DIFFER → this technique is in scope. If all paths return the SAME constant → not applicable; the merge IS the correct shape.
2. Read the source: is it written as `result = X; ... result = Y; ... return result;` style? Convert to `if (cond) return X; ... return Y;` early-return chain.
3. Check bounds-check polarity. Convert `if (idx >= count) return F;` to `if (idx < count) { body... } return F;` (KEY 1).
4. Order variable declarations / computes so the FIRST-needed variable in the post-branch path is declared FIRST (KEY 3 — register-allocator nudge).
5. Recompile. The tail-merge layout should split. Remaining diffs are register coloring — handle with `region_gpr_relabel` / `gpr_relabel` / `force_reg`.

**Triage budget:** 30 minutes from .s diff inspection to byte-match attempt. If KEYs 1+2+3 don't resolve the layout, escalate to `anti_tail_merge` mutator authoring (compounded-wall fallback).

---

## Coverage map (where the recipe HOLDS vs. where it FAILS)

Per OpusWorker's Tier 3-4 sweep across the 13-candidate `anti_tail_merge` queue (info `81427c2c`), the source-coax recipe's reach has been mapped concretely:

**HOLDS (recipe produces byte-match):**
- 2-path predicates (one early-return, one body-return) — Shape A baseline
- 3-path-with-last-test-as-beqlr (last test falls through to value-return) — INGTarget shape
- 3-path-success-fallthrough (early-fail + early-fail + success at tail) — GetActionMenu shape
- multi-path-with-side-effects + multi-store (writeback before return, multiple stores in success path) — EShader::UseOverrideTexture shape
- case-cascade int with N≥4 distinct constant returns (libgcc-style helpers)

**FAILS (recipe alone insufficient — escalate):**

Each FAILS class has a concrete pre-attempt discriminator so workers can identify them BEFORE burning the 30-min triage budget on a wall the recipe cannot reach.

- **88B+ floating-point multibranch** (e.g., AwarenessAutoRunCheck @ 0x80012258, 88B). cc1plus's fp-compare scheduling diverges from SN ProDG's at sizes ≥88B with multibranch fp paths. **Track-I scheduler-mutator territory** — source-coax cannot reach RTL-level fp instruction reordering.
  - **Discriminator (all three must hold):** function size ≥ 88B AND fp-prologue present (`fmr`/`fcmpo`/`fcmpu` in the first 8 instructions) AND `bnelr`/`beqlr` conditional return at the function end. If the wall has fp ops AND is large AND uses conditional-return, do not attempt the recipe.

- **`preset+bnelr` GCC optimization** (e.g., PADIsBarrel @ 0x80266E10, 60B). cc1plus prefers `li r3, CONST ; bnelr` (preset-then-conditional-return) where DOL keeps an explicit forward-jump split-tail. The source statement order has no leverage here — the optimization is GCC's late-RTL register-rename pass, not the IR shape's. **RTL territory** until a counter-coax is found.
  - **Discriminator:** in the cc1plus output for the same source, you see `li r3, CONST ; bnelr` (preset value, then conditional-return-if-not-equal) immediately after a comparison; in the DOL bytes, you see `bne <forward-label> ; ...; <forward-label>: li r3, CONST ; blr` (explicit forward jump to a split tail). When the cc1plus output already has `bnelr` and DOL does not, the recipe will not reach the layout — escalate.

- **Compounded structural walls** (e.g., AptCharacterInst::sMethod_setMask @ 0x8028A244, 212B). Tail-merge diff ride-along with rlwimi bitfield reconstruction + asymmetric andis. + SDA singleton load/store reorder. The recipe resolves the tail-merge but residual structural diffs remain. **Multi-mutator pipeline territory** — `anti_tail_merge` mutator may compose as ONE step alongside other directives.
  - **Discriminator (any TWO+ structural-diff types in addition to the tail-merge diff):** rlwimi/rlwinm with non-trivial mask composition / asymmetric andis. patterns / SDA-relative load/store reorder / multiple register-coloring deltas / frame save-restore reordering. Two or more of these alongside the tail-merge diff = compounded wall.

If your wall fits any FAILS discriminator above, escalate immediately to mutator authoring or Track-I queue. Do not waste the 30-min budget.

---

## Validated cases (supporting evidence — N=6, 4 control-flow shapes)

| # | Function | Size | Shape | Epilogues | Recipe Application | Validation |
|---|----------|------|-------|-----------|-------------------|------------|
| 1 | **EBitArray::Get** @ 0x802DF780 | 64B | predicate-bool | 2 (mixed value + const) | `if (idx < count) { mask = 1<<(idx&0x1F); word = m_bits[idx>>5]; return (mask&word) != 0; } return false;` | **BYTE-MATCH** (commit `4ed5fac5`) |
| 2 | **__cmpdi2** @ 0x80249088 | 60B | case-cascade int | 4 (all-const) | 4 sequential `if (hi/lo cmp) return CONST;` returns + final fallthrough `return 1;` | **BYTE-MATCH** (commit `6ba9378b`) |
| 3 | **INGTarget::get_current_inginfo** @ 0x801BBB60 | 72B | state-getter pointer | 4 (mixed null + pointer) | `if (count > 11) return 0; ig = arr[count]; if (ig == 0) return 0; if (ig->m_first == 0) return 0; return ig;` | **BYTE-MATCH** (commit `1c5685f6`) |
| 4 | **INGTarget::get_current_mix_inginfo** @ 0x801BBBA8 | 72B | state-getter pointer (mix variant) | 4 (mixed null + pointer) | sibling-batch follow-up: `if (count > 3) return 0; mig = (T*)((char*)this + offs + count*8); if (mig == 0) return 0; if (mig->m_first == 0) return 0; return mig;` | **BYTE-MATCH** (commit `1c5685f6`) |
| 5 | **GetActionMenu** @ 0x8018458C | 56B | success-fallthrough pointer | 3 (2 null + computed) | `if (idx > 1) return 0; g = *(char**)storage; if (g == 0) return 0; return g + (idx*180 + 1856);` | **BYTE-MATCH** (commit `6cafe102`) |
| 6 | **EShader::UseOverrideTexture** @ 0x802FA438 | 60B | predicate + multi-store side-effect | 3 (2 const-fail + const-success after stores) | `if ((flags & MASK) == 0) return 0; if (m_count <= idx) return 0; m_byte = idx; m_flags = flags \| BIT; return 1;` | **BYTE-MATCH** (commit `6cafe102`) |

**Cross-shape spread (4 distinct control-flow shapes):**
- **Shape A — predicate-bool** (EBitArray::Get): 2 epilogues, returns `bool`, mixes a computed value-return with a constant-return. Smallest sufficient case.
- **Shape B — case-cascade int** (__cmpdi2): 4 epilogues, returns `int`, all paths return distinct integer constants. Compiler-runtime code, not app code.
- **Shape C — state-getter pointer** (INGTarget pair, GetActionMenu): 3-4 epilogues, returns pointer, mixes null-returns with a value-return. Survives address-arithmetic variation (array index, base+offset+stride, base+computed-offset). Three instances confirm the shape is robust across pointer-arithmetic style.
- **Shape D — predicate + multi-store side-effect** (EShader::UseOverrideTexture): 3 epilogues with WRITEBACK on the success path before return. Key: the multi-store sequence (`m_byte = idx; m_flags = new_flags;`) lives between the last failure return and the success return, and the recipe still holds — cc1plus does not merge the success tail into the failure tails because the constants differ AND the writeback prevents any cleanup-share opportunity.

The recipe is **shape-agnostic across return types** (`bool` / `int` / `pointer`) and across **side-effect profiles** (pure functional / multi-store writeback). It applies wherever cc1plus would tail-merge return blocks that DOL keeps duplicated, provided the FAILS-list pre-conditions (no fp-multibranch, no preset+bnelr optimization, no compounded structural walls) hold.

---

## Worked example #1 — Shape A (predicate-bool)

```cpp
// EBitArray::Get @ 0x802DF780 — 2 epilogues (the early `return false;` and
// the body's `return (mask & word) != 0;`). Each emits its own li/blr.
bool Get(int index) const {
    if (index < this->m_count) {
        unsigned int mask = 1u << (index & 0x1F);   // KEY 3: mask first
        unsigned int word = this->m_bits[index >> 5];
        return (mask & word) != 0;                   // KEY 2: early-return
    }
    return false;                                    // KEY 1: positive form
}
```

## Worked example #2 — Shape B (case-cascade int)

```cpp
// __cmpdi2 @ 0x80249088 — 4 epilogues (gt/eq/lt/equal-equal-different return
// constants). cc1plus emits 4 separate (li, blr) pairs because every
// return value differs and no shared cleanup is needed.
int __cmpdi2(long long a, long long b) {
    if (hi_a > hi_b) return 2;        // KEY 2 ×4: each as own return
    if (hi_a < hi_b) return 0;
    if (lo_a > lo_b) return 2;
    if (lo_a < lo_b) return 0;
    return 1;
}
```

## Worked example #3 — Shape C (state-getter pointer pair)

```cpp
// INGTarget::get_current_inginfo @ 0x801BBB60 — 4 returns mixing null
// constants with a final value-return. The bounds-check (KEY 1), pointer
// chain (KEY 2 ×3), and field test compose into the DOL's 4-epilogue tail.
IngInfo* get_current_inginfo() {
    if (m_count > 11) return 0;                       // KEY 1 (positive bound flipped to >11 => return)
    IngInfo* ig = m_array[m_count];
    if (ig == 0) return 0;                            // KEY 2: each branch as own return
    if (ig->m_first == 0) return 0;
    return ig;                                        // value-return at tail
}
```

The Shape C variant for `get_current_mix_inginfo` substitutes `(MixInfo*)((char*)this + offset + count * stride)` for `m_array[count]` — recipe is unchanged. Sibling-batch crack confirmed in single commit (`1c5685f6`).

---

## When this technique does NOT apply (fall back to `anti_tail_merge` mutator or other tracks)

- **Compounded structural walls.** When tail-merge diffs ride alongside `rlwimi` bitfield reconstruction, asymmetric `andis.` patterns, SDA-singleton load reordering, or other structural mutations on the same function body (e.g., `AptCharacterInst::sMethod_setMask` @ 0x8028A244, 212B). Source-coax alone cannot unwind the multi-wall stack — the recipe fixes block layout but the residual structural diffs remain. Use `anti_tail_merge` as ONE step in a multi-mutator pipeline.
- **Backward-branch shared-epilogue cascades.** Multiple test/cleanup/return paths converging via backward branches with frame restore inside the shared tail. Source-coax cannot reach these; a frame-aware RTL-level mutator is required (queue not yet authored).
- **Same-constant tail-merges.** When ALL paths legitimately return the same constant, DOL would merge them too. The diff is not a tail-merge wall — look for a different structural cause.
- **Functions with shared cleanup before return.** Frame restores, destructor sequences, or other shared epilogue work force the merge regardless of source structure. Source-coax cannot create duplicates the compiler must funnel.

---

## Methodology citation — instruction-pattern-not-register

Per TUScout's parallel N=2 hunts on `region_gpr_relabel` (info `6790284f`, 0 candidates across 6,818 functions) and `force_reg_at_pos` (info `0a22aa88`, 0 candidates), a structural insight emerged:

> SN ProDG and GCC choose different INSTRUCTION patterns, not just different registers. Mutator-shaped walls (same opcodes, different register choice) are near-zero density. Most "register-allocation walls" are actually "opcode-idiom walls" (`cmpwi` vs `or.`, `srawi` vs `sraw`, `slwi` vs `rlwinm`, `ble` vs `bgt`) requiring source-level rewriting.

**Implication for technique selection:** source-level coax (Tech #72 polarity-flip, Tech #73 split-tail) is the dominant value path because it lets the C++ author nudge the compiler toward DOL's chosen instruction pattern at the IR level. Register-level mutators handle the near-zero-density tail of cases where opcode patterns ARE identical and only the register choice differs. When you see a register diff in the .s output, **first ask whether the underlying instruction pattern itself differs**; if yes, the fix is at the source level, not the post-cc1plus mutation level.

This is why Tech #73 reaches N=6 across 4 distinct shapes while sibling register-level mutators sit at N=1 with no organic N≥2 path: they cover different population densities.

---

## Triage outcome — `anti_tail_merge` mutator status change

Per N=6 confirmation across 4 control-flow shapes, the `anti_tail_merge` mutator is **DEMOTED to EXPERIMENTAL status** in the same commit window as this catalog entry. Rationale: its canonical primary (AptArray::get @ 0x802860AC, commit `0c5e1dd4`) is a candidate for source-coax retest under this recipe; if AptArray::get matches via source-coax alone, the mutator's only validated invocation evaporates. A 60-90d zero-invocation mothball clock starts at the catalog merge date.

**Framework-validation framing:** the mothball clock pauses/resets ONLY on REPEAT-FALLBACK invocations from real walls — that is, multiple distinct walls organically requiring `anti_tail_merge` because Tech #73 cannot reach them. A SINGLE successful fallback (e.g., the parked `filter_wallpaper @ 0x801D4F88` byte-matching under the mutator) demonstrates REACH but NOT REVERSAL of the demotion: it confirms the framework works as designed (mutator handles the recipe-fails-here case), it does not promote the mutator back to STANDARD. Reversal requires a sustained pattern of fallback invocations across multiple wall classes within the clock window.

Authors faced with a tail-merge wall **MUST** apply the source-coax recipe FIRST (30-min triage budget per the FAILS-discriminator checklist above) before reaching for the `anti_tail_merge` directive. Mutator code remains in `tools/asm_processor/mutators/anti_tail_merge.py` and the REGISTRY for the compounded-layout fallback case, but new invocations should be the exception, not the default.

---

## Cross-references

- [`anti_tail_merge`](../../tools/asm_processor/mutators/anti_tail_merge.py) — fallback mutator for compounded tail-merge walls (now EXPERIMENTAL; prefer this technique first).
- [Technique #72 — polarity flip](technique_catalog_polarity_flip.md) — sibling source-coax recipe for `bcc`-direction block-layout walls. Same N=1→catalog promotion methodology.
- [`region_gpr_relabel`](../../tools/asm_processor/mutators/region_gpr_relabel.py) — typical residual register-coloring fix once tail-merge layout is correct.
- [Methodology: triage-first protocol](feedback_triage_first_protocol.md) — 30-min source-level test before reaching for a mutator.
- [`catalog_format_conventions.md`](catalog_format_conventions.md) — meta-history of the catalog format (cross-class verification bar, HOLDS/FAILS coverage map, demotion vs Density Watch decision tree).
- N=2 confirmation post (info `5d8c952f`) — OpusWorker initial cross-class validation summary.
- TUScout register-mutator hunt results (info `6790284f` for `region_gpr_relabel`, info `0a22aa88` for `force_reg_at_pos`) — instruction-pattern-not-register methodology evidence.
- EBitArray::Get retain commit (`4ed5fac5`) — instance #1 byte-match.
- __cmpdi2 retain commit (`6ba9378b`) — instance #2 byte-match.
- INGTarget pair retain commit (`1c5685f6`) — instances #3+#4 sibling-batch byte-matches.
- GetActionMenu + EShader::UseOverrideTexture retain commit (`6cafe102`) — instances #5+#6 Tier-3 sweep byte-matches.

---

**Catalog reference:** Apply the recipe directly in source. **No `// ASMPROC_*` directive needed.** This is a source-level technique, not a post-cc1plus mutator. Author the C++ as an early-return chain with positive bounds checks and compute-order-aware locals, then recompile and verify. If the tail-merge diff resolves but residual diffs remain, those are orthogonal (register coloring, RTL-level) and handled by mutators in `tools/asm_processor/mutators/`.
