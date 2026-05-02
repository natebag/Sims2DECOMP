# Variant L Dtor Recipes — pattern catalog (Lane G S13 session 3)

**Status:** VALIDATED 50/50 (S13 2026-05-02 Lane G, SonnetWorker, +50 stretch hit in 165 min).

**Companion to:** Technique #71 (STL vec-iter dealloc), Technique #18 (`extern char globalName[]`), Technique #69 (SDA-extern integer).

## Scope

Eight pattern-winners covering the **deleting-destructor band** for non-pure-EResource classes that follow the SN ProDG dtor convention (r3=this, r4=flag, conditional `if (flag & 1) operator delete(this)` tail). All recipes are `Variant L` family — single-helper or multi-helper bl chains terminating in a flag-controlled deleting branch.

Validated across these 50 dtors: ESleep, ESubModel, CasSimPartsS2C, InLevelBaseState+InLevelStoryState, AptRegister+AptLookup, AptValueVector, cSampleChannel, ObjectManipulator, BitMatrix64, PAZTarget+PZ1Target, ESpriteRender, IFFBehResFile, TheSimsMainMenuState, EApp, ObjFnTableQuickData, EWindow, IconGroupImpl, EShader, ELiveMode, cSoundCacheItem, ProtectedAllocPool, ENgcFileSystem, EThread, ESubModelShader, EAnimController, EScratchBuffMan, EMemoryWriteStream, BString2, AmbientSoundPlayer, ERC, PlumbBobModel, FadeSquare, AptXmlNode+AptXmlAttributes, TextBaseItem+TextItem+MenuItem+ButtonItem (4-twin), DialogPane+MenuDialogPane+BackgroundPane (3-twin), WrapperPaneBase+DialogPaneBase, ObjectDataObjDefinition, EdithVariableSet, Neighbor, EFontData.

## Recipe 1 — non-virtual `dtor(int flag)` method (always start here)

**Why:** sidesteps `__dt$0`/`__dt$1` (base subobject vs deleting variant) emission ambiguity. The original symbol at the dtor address is the deleting variant; trying to coax the SN compiler into emitting the deleting variant at the named symbol via `virtual ~Class()` is unreliable. A non-virtual `dtor(int flag)` member function with the same body produces the deleting-variant bytes directly.

```cpp
struct ClassName {
    // ...fields...
    void dtor(int flag);
};

void ClassName::dtor(int flag) {
    // body
    if (flag & 1) {
        __builtin_delete(this);
    }
}
```

**100% hit rate across 50 cracks.** Use for every Variant L target.

## Recipe 2 — MI vtable-transition (dual `m_vt_X = vt_a` / `vt_b`)

**Why:** classes with vtable at non-zero offset (multi-inheritance secondary base, or member object with vtable) need to *transition through two vtables* during destruction. The first stores `vt_a` before calling the inner-object dtor, the second stores `vt_b` after — representing the "during destruction" and "post destruction" vtable states.

```cpp
extern char vt_ClassName_a[];
extern char vt_ClassName_b[];

void ClassName::dtor(int flag) {
    m_vt_at_offset = vt_ClassName_a;
    InnerMember_dtor(&m_inner, 2);     // or other helper bls
    m_vt_at_offset = vt_ClassName_b;
    if (flag & 1) {
        __builtin_delete(this);
    }
}
```

**Validated:** 8 classes (InLevelBaseState/Story, ObjectManipulator, ObjFnTableQuickData, EMemoryWriteStream, TextBaseItem family, EFontData).

## Recipe 3 — `if (this != 0)` null-this guard

**Why:** SN ProDG (GCC 2.95-based) does not optimize away an explicit null-this check inside a member function body. Modern compilers treat this as UB; SN does not. Emit the check directly when the DOL has a `mr.` or `cmpwi` against `r3` at function entry that branches around the dtor body.

```cpp
void ClassName::dtor(int flag) {
    if (this != 0) {
        // body that accesses members
    }
    if (flag & 1) {
        __builtin_delete(this);
    }
}
```

**Validated:** BitMatrix64 (array-of-element dtor with backward iteration).

## Recipe 4 — custom delete vectors (replace `__builtin_delete`)

**Why:** classes route their delete through a custom allocator instead of the global `operator delete`. Replace the deleting branch's `__builtin_delete(this)` call with the appropriate custom routine.

| Custom delete                              | Tail-bl target | Recipe (deleting branch body)                                       | Validated cracks                                  |
|--------------------------------------------|----------------|---------------------------------------------------------------------|---------------------------------------------------|
| `MainHeap()->Free(this)`                   | `0x802CFF00` + `0x802D0D78` | `MainHeap()->Free(this);`                                           | EWindow, ESpriteRender, ELiveMode, BString2, EScratchBuffMan, Neighbor (8 total) |
| `EResourceManager::Free`                   | `0x803276AC`   | `EResourceManager_Free(g_eshaderHeap, this);`                       | EShader (1)                                       |
| `DOGMA_PoolManager::Deallocate`            | `0x802B598C`   | `DOGMA_PoolManager_Deallocate(g_dogmaPool, this, NN);`             | AptRegister, AptLookup, AptValueVector, AptDisplayListState (4) |
| `AptValueGC_PoolManager::DeallocateAptValueGC` | `0x802B5180` | `AptValueGC_PoolManager_DeallocateAptValueGC(g_aptValueGCPool, this, NN);` | AptXmlNode, AptXmlAttributes (2) |
| `HeapStaticFree(g_<x>Heap, this)`          | varies         | `HeapStaticFree(g_<x>Heap, this);`                                  | (template; ENgcShader baseline) |

The pool/heap pointer for DOGMA / AptValueGC is read via SDA `lwz r3, -<offset>(r13)`, then `mr r4, r31; li r5, <SIZE>`. The size is *fixed at compile time per class* — find it from the `li r5, NN` immediately before the bl.

## Recipe 5 — singleton clear patterns

**Why:** singleton classes clear a global pointer to themselves at destruction time. Two patterns based on global size + SDA threshold:

### 5a. SDA singleton (small global, fits in 8-byte SDA threshold)

```cpp
extern void* g_singletonInstance;   // < 8 bytes → goes to .sdata, accessed via r13

void ClassName::dtor(int flag) {
    g_singletonInstance = 0;
    // ...
}
```

DOL emits `stw r0, -<offset>(r13)`. Validated: TheSimsMainMenuState, EApp.

### 5b. Non-SDA singleton (force lis/lwz absolute addressing)

```cpp
struct LiveModePtr {
    char data[16];                  // > 8 bytes → forced to .data, lis/lwz access
};
extern LiveModePtr g_liveModeHandle;

void ClassName::dtor(int flag) {
    *(int*)&g_liveModeHandle = 0;
    // ...
}
```

DOL emits `lis r11, hi; stw r0, lo(r11)`. Validated: ELiveMode.

## Recipe 6 — switch-case dispatch in dtor body

**Why:** SN ProDG generates the standard branch-tree pattern (cmpwi + beq + bgt + cmpwi cluster) for switch statements. Use the natural C++ switch.

```cpp
void ClassName::dtor() {
    m_vt = vt_ClassName;
    switch (m_field_bc) {
    case 26: g_snap26 = m_field_8c; break;
    case 30: g_snap30 = m_field_8c; break;
    case 39: g_snap39 = m_field_8c; break;
    }
    ParentBase_dtor(this);
}
```

Validated: PZ1Target.

## Recipe 7 — virtual call via vtable slot N

**Why:** the EA SN ProDG vtable has 8-byte slots: `(short thunk, _, fn_ptr)` triples (with thunk at byte offset 0 of slot, fn_ptr at offset 4 of slot). The compiler emits `lha r3, slot_byte_offset(vtable); lwz r0, slot_byte_offset+4(vtable); add r3, this, r3; mtlr r0; blrl`. **Important:** the destructor takes 2 vtable slots (deleting + non-deleting). So slot count for non-dtor virtuals starts at 2.

```cpp
class TargetClass {
public:
    virtual ~TargetClass();           // takes slots 0+1
    virtual void f1();                // slot 2
    virtual void Cleanup();           // slot 3 — byte offset 24 (lha 24) / fn at 28 (lwz 28)
};
```

For a target whose DOL has `lha r3, 24(r9); lwz r0, 28(r9)` → declare exactly 1 leading non-dtor virtual + the called virtual at slot 3. Validated: IconGroupImpl (cleanup at slot 3), AmbientSoundPlayer (Stop at slot 3).

## Recipe 8 — field-clear + flag-check interleaving

**Why:** the SN scheduler will sometimes route the `andi.` flag-check result to `r9` instead of `r0` to preserve a `li r0, 0` value across the test (so `r0` can still be used for a follow-up `stw r0, ...`). This generates `andi. r9, r30, 1` rather than `andi. r0, r30, 1`. Don't fight it — write the source naturally and let the scheduler interleave.

```cpp
void ClassName::dtor(int flag) {
    Helper(this, flag);
    m_field_4 = 0;
    m_field_0 = 0;
    if (flag & 1) {
        __builtin_delete(this);
    }
}
```

Compiler produces `bl Helper; li r0, 0; andi. r9, r30, 1; stw r0, 4(r31); stw r0, 0(r31); beq + bl __builtin_delete`. Validated: cSampleChannel, ESpriteRender, AmbientSoundPlayer.

**Sub-pitfall:** field-clear *order* matters. Write the order that matches the DOL — the SN scheduler does not always sort store offsets predictably. When 2-3 stws differ in order, swap the source statements. Walls observed: ArcCopier, EResPrefetchFile, CasGenetics::Grandparent (all >2 store interleavings the scheduler reorders unpredictably).

## When to reach

Reach for Variant L recipes when:
- Function is 32-127B (Variant L sweet spot, per `feedback_opus_band_fit.md`).
- DOL has `andi. r0, r30, 1` (or `r9`) flag check + conditional bl tail (deleting branch).
- Up to 4 body bls (more than 4 typically Variant B/C/D/E territory — needs additional recipes).
- Class is NOT in Lane H reserved (ERAnim, ERAmbientScore, ERDataset, Phase 2/3 EResource).

## When NOT to reach

- Don't use for direct `~EResource` callers in the 128-256B band — those are Kmiworker2's sweep + Lane H's territory.
- Don't apply Recipe 7 (virtual call) without confirming the vtable slot offset from disasm — slot count miscalibration is the most common waste.
- Don't try Recipe 1 with a virtual destructor declaration — the deleting variant emission is unreliable. Use the non-virtual `dtor(int flag)` method form instead.

## Walls (Variant L recipes do NOT solve these)

| Wall                          | Symptom                                          | Recommended track                  |
|-------------------------------|--------------------------------------------------|------------------------------------|
| Field-clear order non-determinism | 2-3 stws shuffled by scheduler unpredictably   | Track I `swap_adj_stores` mutator  |
| 1-instruction scheduler swap  | `addi` and `mr` swapped pre-stw                  | Track I `swap_adj` mutator         |
| Helper-load timing            | `lwz` of secondary field hoisted across `stw`   | Source-level reorder rarely fixes  |

Walls observed during this campaign: ArcCopier (field-clear order), EResPrefetchFile (same), EGraphics (1-insn scheduler swap), CasGenetics::Grandparent (m_4 load timing).

## See also

- `technique_catalog_71_stl_vec_iter_dealloc.md` — STL `_Vector_base&` dealloc dispatch (Technique #71)
- `technique_catalog_extern_char_vt.md` — vtable-at-non-zero-offset
- `feedback_opus_band_fit.md` — 65-100B simple-template band guidance
- `feedback_multidirective_composition.md` — asm_processor multi-directive recipes (for Variant B/C/D/E)
- `feedback_register_asm_policy.md` — register-asm pinning REJECTED, asm-processor only

## Lane G S13 session 3 stats

- 50 matches in 165 min (3.3 min/match average)
- Sibling-twin share: 14/50 (28%) across 5 sibling families
- Walls: 4 abandoned (~15min total = 9% of session time)
- Throughput: 18.2 matches/hour sustained
