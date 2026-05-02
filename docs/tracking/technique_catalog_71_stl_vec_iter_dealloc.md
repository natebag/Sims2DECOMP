# Technique #71 — STL vec-iter dealloc with `__node_alloc` / `operator delete` size dispatch

**Status:** VALIDATED across 5 classes (S13 2026-05-02 Lane G, SonnetWorker, commits `eebd6641` + `8c315161` + `acb5bb50` + `9471ff07`).

**Companion to:** Variant L recipe catalog (`technique_catalog_variant_l_recipes.md`), Variant G' SonnetWorker2 recipe (commit `4963e6e6`).

## Use case

DOL emits an STL `_Vector_base`-style dealloc tail with **size-threshold dispatch**: small allocations (≤128 bytes) go to `__node_alloc<false, 0>::_M_deallocate`, large ones go to `::operator delete` (a.k.a. `__builtin_delete` via SN convention).

Disasm shape:

```
lwz   r3, <vec.start_offset>(r31)        ; load vec.m_start
addi  r9, r31, <vec.start_offset>        ; r9 = &m_vec
cmpwi r3, 0
beq   <skip>                             ; skip if start == 0
lwz   r0, <vec.finish_offset>(r9)        ; load vec.m_finish (relative to vec base)
subf  r0, r3, r0                         ; r0 = m_finish - m_start (byte distance)
clrrwi r4, r0, <2|1|0>                   ; mask to multiple of sizeof(T)
cmplwi r4, 128
ble   <use_node_alloc>
bl    __builtin_delete                   ; > 128 path
b     <skip>
<use_node_alloc>:
bl    __node_alloc<false, 0>::_M_deallocate    ; <= 128 path
<skip>:
... flag check + delete-this branch
```

## Core recipe

```cpp
extern void __builtin_delete(void* p);
extern void __node_alloc_M_deallocate(void* p, unsigned int n);

struct VecBase {
    void* m_start;          // offset 0
    void* m_field_4;        // offset 4 (typically size or capacity, varies)
    void* m_field_8;        // offset 8 (typically size or capacity, varies)
    void* m_finish;         // offset 12
};

struct ClassName {
    // ...preceding fields
    VecBase m_vec;
    // ...trailing fields
    void dtor(int flag);
};

void ClassName::dtor(int flag) {
    // ...other body
    VecBase* vec = &m_vec;                                  // EXPLICIT pointer alias triggers correct codegen
    if (vec->m_start != 0) {
        unsigned int bytes = (unsigned int)(
            (char*)vec->m_finish - (char*)vec->m_start
        ) & ~SIZEOF_T_MASK;                                 // mask trims to integer T-count
        if (bytes > 128) {
            __builtin_delete(vec->m_start);
        } else {
            __node_alloc_M_deallocate(vec->m_start, bytes);
        }
    }
    if (flag & 1) {
        __builtin_delete(this);
    }
}
```

**Critical:** assigning `VecBase* vec = &m_vec;` BEFORE the body forces the SN compiler to emit `addi r9, r31, <vec_offset>` ONCE and then load fields via `lwz r0, NN(r9)`. Without the explicit pointer alias, the compiler may load fields directly from `r31` with absolute offsets, breaking the byte match. This is the **`&m_vec` lock-bit** discovered by SonnetWorker2 in Variant G' (commit `4963e6e6`).

## Size-variant dispatch (sizeof(T) determines mask)

The `clrrwi r4, r0, N` instruction masks the low N bits, rounding bytes down to a multiple of `2^N`. This corresponds to `sizeof(T)`:

| `clrrwi N` | `sizeof(T)` | Recipe `& ~MASK` | Validated cracks                                |
|-----------:|------------:|:-----------------|:------------------------------------------------|
| `clrrwi r4, r0, 2` | 4 (int / pointer)  | `& ~3U`        | DialogPane, MenuDialogPane, BackgroundPane, WrapperPaneBase, DialogPaneBase (5) |
| `clrrwi r4, r0, 1` | 2 (short)          | `& ~1U`        | EdithVariableSet (1)                            |
| no `clrrwi`         | 1 (char) or used raw | omit `& MASK` | ObjectDataObjDefinition (1)                     |

When the DOL has NO `clrrwi`, the bytes are taken raw (sizeof(T)=1 or the byte value is used directly without count conversion).

## Vec layout variants

The `VecBase` layout differs per class — `m_start` is always at offset 0 of the vec struct, but `m_finish` location varies based on what fields sit between:

| `m_finish` offset within vec | DOL `lwz` displacement | Vec struct shape (4-byte fields)            | Validated example       |
|:----------------------------:|:----------------------:|:---------------------------------------------|:------------------------|
| 12                           | `lwz r0, 12(r9)`       | `{ start, _4, _8, finish }`                 | DialogPane, EdithVariableSet |
| 12 (compact)                 | `lwz r0, 16(this)` (no &m_vec alias) | `{ start, _, _, finish }` accessed via outer | ObjectDataObjDefinition |

For Variant G' (SW2), the layout is `{ start, finish, end_of_storage }` (3 pointers, finish at offset 4). That variant uses `lwz r0, 4(r9)` and is documented separately.

## Why it works

The SN ProDG compiler generates the size-dispatch tree from the natural C++ source above when:
1. `vec->m_start != 0` is checked first (compiler emits `cmpwi r3, 0; beq skip`).
2. The byte computation uses `(char*)m_finish - (char*)m_start` — this is signed `subf` in PowerPC.
3. The mask `& ~3U` (or `~1U`) appears as a single `clrrwi` instruction.
4. `bytes > 128` is `cmplwi r4, 128; ble use_node_alloc` — note the `ble` not `bge` (compiler picks the inverted form for fall-through optimization).

The order of body statements before the vec dealloc is preserved naturally.

## Pitfalls

- **Forgetting the `&m_vec` alias.** Without `VecBase* vec = &m_vec;` the compiler may emit `lwz r0, this+abs_offset` instead of `lwz r0, vec+rel_offset`. The byte match will fail with `lwz` displacement diffs.
- **Wrong sizeof(T) mask.** Check the DOL's `clrrwi N` value: `N=2` → `& ~3U`, `N=1` → `& ~1U`, no clrrwi → no mask. Mask mismatch produces a 1-byte `clrrwi` diff.
- **Wrong vec field offsets.** Verify `m_finish` is at the right offset within the vec struct. The DOL `lwz r0, NN(r9)` displacement tells you exactly where m_finish lives.
- **Wrong outer struct padding.** The address of the vec member in the outer struct must produce the right `addi r9, r31, M` offset. Check the DOL's `addi r9, r31, M` to determine vec's offset within the outer.

## When to reach

Reach for Technique #71 when:
- DOL has the `cmplwi r4, 128` size-threshold dispatch shape in the dtor tail.
- DOL has `bl __node_alloc<false, 0>::_M_deallocate` AND `bl __builtin_delete` (or `bl ::operator delete`) in adjacent branches.
- The classes likely contain an STL container member (`std::vector`-like with custom allocator).

## When NOT to reach

- Don't use if the dtor doesn't have the size-threshold dispatch (just `__builtin_delete` alone is regular deleting branch — Variant L Recipe 1).
- Don't reach for raw allocator deallocs (e.g., `EAHeap::Free`, `DOGMA_PoolManager::Deallocate`) — those are Variant L Recipe 4.
- Don't apply to non-STL containers — the size-threshold logic is specific to SGI STL `__node_alloc` semantics.

## Validated targets

| Address      | Class                          | sizeof(T) | Mask     | Outer vec offset | Notes                              |
|:-------------|:-------------------------------|:---------:|:---------|:-----------------|:-----------------------------------|
| 0x803A05F0   | DialogPane                     | 4         | `& ~3U`  | 8 (vec at +8)    | 3-twin family pioneer              |
| 0x803A073C   | MenuDialogPane                 | 4         | `& ~3U`  | 8                | sibling                            |
| 0x803A1988   | BackgroundPane                 | 4         | `& ~3U`  | 8                | sibling                            |
| 0x800879E0   | WrapperPaneBase                | 4         | `& ~3U`  | 8                | parent dtor = Shutdown helper      |
| 0x80088CA4   | DialogPaneBase                 | 4         | `& ~3U`  | 8                | sibling of WrapperPaneBase         |
| 0x800E3FD4   | EdithVariableSet               | 2         | `& ~1U`  | 12               | sizeof(T)=2 variant                |
| 0x8015BE68   | ObjectDataObjDefinition        | 1 (raw)   | (none)   | 4 (no &alias)    | direct outer-offset access variant |

## See also

- `technique_catalog_variant_l_recipes.md` — Variant L pattern catalog (50/50 validated)
- Variant G' (commit `4963e6e6` by SonnetWorker2) — `_Vector_base&` 3-pointer variant for ER family
- `feedback_register_asm_policy.md` — register-asm REJECTED, asm-processor only
- `feedback_multidirective_composition.md` — asm_processor recipes when source-level fails
