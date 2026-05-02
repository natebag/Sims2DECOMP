# Variant G' — EResource + vector<T>-iter-loop dtor pattern

**Status:** VALIDATED across 2 sibling targets (S13 2026-05-02 Lane H).

**Family:** EResource Phase 2 dtor variants. Sibling to Variants F, G, H.

## Disasm shape

```
prologue (stmw r27..r31 — 5 saved regs, stack -32)
[optional: load m_field_X for raw-ptr cleanup before vtable assignment]
lis/addi VT_<Class> + stw 0(this)
[optional: cmpwi 0; beq; bl __builtin_delete  — raw-ptr cleanup body]
addi rN, this, <vec_offset>           ; rN = &m_vec base pointer
lwz r31, <vec_offset>(this)            ; r31 = m_vec.start
lwz r30, 4(rN)                         ; r30 = m_vec.finish (cached)
cmpw r31, r30
beq skip_loop
loop_top:
  mr r3, r31; li r4, 2
  bl T::~T                             ; non-trivial T only
  addi r31, r31, sizeof(T)
  cmpw r31, r30
  bne loop_top
skip_loop:
lwz r3, 0(rN)                          ; r3 = m_vec.start
cmpwi r3, 0
beq skip_dealloc
lwz r0, 12(rN)                         ; r0 = m_vec.end_of_storage (skips +8 hole!)
lis/ori magic                          ; sizeof-specific magic constant
subf r0, r3, r0                        ; bytes_diff
mullw r0, r0, magic
srawi r0, r0, 2
mulli r4, r0, sizeof(T)                ; recompute bytes
cmplwi r4, 128
ble small_path
bl __builtin_delete                    ; > 128 bytes
b done
small_path:
bl __node_alloc<false,0>::_M_deallocate ; <= 128 bytes
done:
mr r3, this; li r4, 0
bl EResource::~EResource               ; in_charge=0 to base
andi. r0, r27, 1                        ; in_charge gate
beq skip_self_delete
[bl MainHeap; mr r4, this; bl EAHeap::Free]   ; OR bl __builtin_delete depending on operator delete
epilogue
```

## C++ source recipe (7-pattern checklist)

1. **Single-inherit from EResource with `virtual ~T()` declared.**
2. **Inner struct `VecData { T* start; T* finish; int alloc_pad; T* end_of_storage; }`** — 16 bytes, with the 4-byte allocator hole at +8. Do NOT declare as 12-byte STL-style; the compiler will read end_of_storage from +12 (= +0x20 for `m_vec` at +0x14).
3. **Explicit pointer to inner vec** (`VecData* vec = &m_vec;`) — KEY lock-bit. Forces compiler to form `addi rN, this, <vec_offset>` base register that the DOL uses for repeated vec accesses. Without it, compiler emits direct `lwz` from `r31`/this.
4. **Cached `end` local + `if/do-while` loop** for non-trivial T:
   ```cpp
   T* p = vec->start; T* end = vec->finish;
   if (p != end) { do { p->~T(); ++p; } while (p != end); }
   ```
   This forces 5 saved regs (r27-r31), keeps `end` in `r30` across the loop, and emits test-at-top + test-at-bottom (Duff style). Plain `while (p != vec->finish)` yields 4 saved regs and reload-finish-each-iter.
5. **For trivial T (e.g. POD struct of ints):** `while (p != vec->finish) ++p;` is fine — empty loop body still emits the walk.
6. **Magic-div pattern** `(unsigned int)(vec->end_of_storage - vec->start) * sizeof(T)`. Pointer subtraction of typed `T*` gets compiled to `subf` + magic-div by sizeof(T); subsequent `* sizeof(T)` recovers bytes via `mulli`. Verified magic constants:
   - sizeof=12 → magic `0xAAAAAAAB` (÷3, srawi 2)
   - sizeof=52 → magic `0xC4EC4EC5` (÷13, srawi 2)
7. **Branch-on-128:** `if (bytes > 128) ::operator delete(p); else __node_alloc<false,0>::_M_deallocate(p, bytes);` — the explicit `::` global-delete prefix is important (avoids the class-specific operator delete override). `__node_alloc` declared as `template<bool,int> class { static void _M_deallocate(void*, unsigned int); };`.

## Validated targets

| Address | Symbol | Size | sizeof(T) | Magic | Commit |
|---------|--------|------|-----------|-------|--------|
| 0x80368E90 | `ERDataset::~ERDataset` | 184B | 12 (POD) | 0xAAAAAAAB ÷3 | `67fb4d40` |
| 0x80366DC0 | `ERAmbientScore::~ERAmbientScore` | 208B | 52 (ERAmbientSound) | 0xC4EC4EC5 ÷13 | `2771a223` |

## Pitfalls

- **EResource is 4 bytes (vtable only)** in this codebase, NOT 8 bytes. The matched `EResource::_dtor` reference file declares it with both vtable + manager pointer = 8B, but THAT is a different facet. For ERAnim/ERDataset/ERAmbientScore-style derived classes, EResource compiles as 4B (just the virtual dtor's vtable). Pad accordingly: `char pad[<vec_offset> - 4]`.
- **`m_vec` declared as flat fields** (m_start, m_finish, m_alloc_pad, m_end_of_storage as direct struct members) ALSO produces correct offsets, but DOES NOT generate the `addi rN` base-pointer optimization without an explicit `&m_vec` pointer. Use the inner struct `VecData` to make the base-pointer hint natural.
- **Operator delete shape determines tail.** ERDataset/ERAmbientScore use `MainHeap()->Free` (Variant G' standard); ERAnim uses `g_resourceManager->Free` (Variant I' shape). Choose based on disasm tail: `bl MainHeap` then `bl EAHeap::Free` = MainHeap; `lis/addi g_resourceManager + bl Free` = EResourceManager.
- **Iter loop shape critical for non-trivial T.** Naive `while (p != vec->finish)` produces wrong byte sequence even when offsets match. Use the cached-end + if/do-while pattern.

## When to reach

Reach for Variant G' when DOL disasm shows:
- EResource-derived class
- vector<T> member with the +0/+4/+8/+12 layout
- Inline iter-walk with sizeof(T) stride
- `__node_alloc<false, 0>::_M_deallocate` symbol referenced
- 128-byte branch on total deallocation size

## When NOT to reach

- TArray-based classes use `Destruct(2)` calls instead of inline iter-loops — that's Variant I (ERModel) shape, not G'.
- Classes without a vector member but with raw-ptr fields only — that's likely Variant E or F (no G' shape).
- Classes with sizeof(T) that doesn't match any cataloged magic constant — additional disasm needed before applying recipe.

## See also

- `technique_catalog_variant_I_prime.md` — companion Variant I' for ERAnim-style classes
- `technique_catalog_69_sda_extern_no_map_symbol.md` — when target also has s_instanceCount
- `feedback_mi_vcall_technique.md` — non-SDA singleton patterns
- Commits `67fb4d40`, `2771a223`
