# Variant I' — EResource + s_instanceCount + inline-EBitArray-member-dtor

**Status:** VALIDATED on ERAnim (S13 2026-05-02 Lane H, commit `5c3a9298`).

**Family:** EResource Phase 3 dtor variants. Extends Variant I (ERModel pattern) with two specific additions.

## Distinction from Variant I

Variant I (ERModel pioneer, commit `517a68e6`) is the canonical EResource-derived dtor with multiple `TArray<T, Allocator>::Destruct(2)` member-cleanup calls + `g_resourceManager->Free` operator delete.

**Variant I' adds:**
1. **s_instanceCount SDA decrement** at top — Technique #69 (no-map-symbol `extern int`).
2. **Inline ERAnimBitArray member dtor** at a specific member offset — derived-EBitArray class member whose dtor body the compiler INLINES into the enclosing class dtor, producing a 2-step vtable-swap-and-Deallocate chain.

## Disasm shape

```
prologue (stmw r29..r31 — 3 saved regs, stack -24)
lwz r11, sda21@(s_instanceCount)(r13)   ; load counter
lis/addi VT_<Class> + stw 0(this)
addi r11, r11, -1
mr r29, r4                               ; save in_charge
stw r11, sda21@(s_instanceCount)(r13)   ; store decremented

[for each TArray member at decreasing offset, in REVERSE decl order:]
addi r3, this, <member_offset>
li r4, 2
bl TArray<T, Alloc>::~TArray

[at the ERAnimBitArray member offset (e.g. +0x50):]
addi rN, this, <member_offset>           ; e.g. r30 = this+80
lis/addi VT_<DerivedBitArray>            ; e.g. VT_ERAnimBitArray @ 0x8046dcd8
mr r3, rN
stw r9, 16(rN)                           ; (member)->vtable = VT_Derived (at +16 inside member)
bl EBitArray::Deallocate
lis/addi VT_<BaseBitArray>               ; VT_EBitArray @ 0x8046a3f8
mr r3, rN
stw r9, 16(rN)                           ; (member)->vtable = VT_Base
bl EBitArray::Deallocate

[remaining TArray members in continuing reverse order]

mr r3, this; li r4, 0
bl EResource::~EResource(this, 0)
andi. r0, r29, 1                          ; in_charge gate
beq skip
lis/addi g_resourceManager + bl EResourceManager::Free
epilogue
```

## C++ source recipe (5-pattern checklist)

1. **Single-inherit from EResource** with `virtual ~T()` declared. Use `extern char g_resourceManager[16];` cast to `EResourceManager*` for `operator delete`.

2. **Declare `extern int s_instanceCount;`** at TU scope — Technique #69. No definition. The first body line must be `--s_instanceCount;`.

3. **Define EBitArray and the derived BitArray (e.g. ERAnimBitArray) with `inline` dtors:**
   ```cpp
   class EBitArray {
   public:
       int* m_pBuffer;       // +0x00
       int m_nSize;          // +0x04
       int m_nAllocSize;     // +0x08
       int m_field_C;        // +0x0C
       int* m_vtable;        // +0x10  ← manually-managed, NOT C++ vtable
       void Deallocate();
       inline ~EBitArray() {
           m_vtable = VT_EBitArray;
           Deallocate();
       }
   };

   class ERAnimBitArray : public EBitArray {
   public:
       char m_extra[<derived_size> - 20];   // pad to declared member size
       inline ~ERAnimBitArray() {
           m_vtable = VT_ERAnimBitArray;
           Deallocate();
           // ~EBitArray() chain auto
       }
   };
   ```
   **CRITICAL:** dtors must be NON-virtual (no `virtual` keyword) AND `inline`. Adding `virtual` causes the C++ compiler to add a real C++ vtable pointer that conflicts with the manually-managed `m_vtable` at +0x10. Removing `inline` causes standalone bodies to emit at .text offset 0, displacing the target class's dtor.

4. **Declare TArray<T, Alloc> with `~TArray()` non-virtual:**
   ```cpp
   template<class T, class Alloc>
   class TArray {
   public:
       void* m_begin; void* m_end; void* m_alloc_end;
       ~TArray();
   };
   ```

5. **Declare the target class with member layout matching disasm offsets, REVERSE-DECL-ORDER for the TArrays so member dtors fire in DOL order:**
   ```cpp
   class ERAnim : public EResource {
       char m_pad_04_<X>[<X> - 4];
       TArray<EAnimNodeDataPos, Alloc> m_arr_<X>;     // lowest offset
       int m_pad_<filler>;                              // 4B if needed for stride
       TArray<float, Alloc> m_arr_<Y>;
       ERAnimBitArray m_bitArray_<Z>;                  // inline dtor emits here
       TArray<EAnimNote, Alloc> m_arr_<W>;
       TArray<EAnimEvent, Alloc> m_arr_<V>;             // highest offset

       virtual ~ERAnim();
       static void operator delete(void* p);
   };

   inline void ERAnim::operator delete(void* p) {
       ((EResourceManager*)g_resourceManager)->Free(p);
   }

   ERAnim::~ERAnim() {
       --s_instanceCount;
       // Member dtors auto in REVERSE decl order, then EResource chain.
   }
   ```

## Validated targets

| Address | Symbol | Size | Member layout summary | Commit |
|---------|--------|------|------------------------|--------|
| 0x803674EC | `ERAnim::~ERAnim` | 196B | 4 TArray + 1 ERAnimBitArray (inline chain) | `5c3a9298` |

Companion sibling-twin (standalone version, NOT inline): `ERAnimBitArray::~ERAnimBitArray @ 0x803C9830` (96B, commit `60a70ef5`) — uses INVERTED inline trick (out-of-line ERAnimBitArray, inline EBitArray) and confirms the manually-managed-vtable + non-virtual-dtor invariant.

## Pitfalls

- **TArray sizes:** stride between TArrays in the member layout can vary. ERAnim has TArray<EAnimNodeDataPos> at +0x34 and TArray<float> at +0x44 (16B stride; add `int m_pad_<filler>;` after the first to absorb the 4B). Most other strides are 12B (no pad needed).
- **ERAnimBitArray total size = next-member-offset minus its-offset.** ERAnim has ERAnimBitArray at +0x50 and the next member (TArray<EAnimNote>) at +0x88, giving 56B total. Pad with `char m_extra[56 - 20]` (since EBitArray is 20B).
- **`virtual` on derived BitArray dtors is a sneaky breakage:** it compiles but lands the C++ vtable at offset 0x38 (since +0x10 is the manual one), and the dtor body uses the wrong offset for the swap. ALWAYS check disasm `stw rN, 16(rM)` — that's the manual vtable slot.
- **Member declaration order = compiler's destruct-reverse order.** Get this right or member dtor calls fire in wrong sequence.
- **Magic constants for vtables:** Use `extern int VT_EBitArray[]; extern int VT_ERAnimBitArray[];` and reference by name — `R_PPC_ADDR16_HA/LO` reloc gets masked by verify_match.

## When to reach

- DOL disasm shows EResource-derived class with `lwz r11, <offs>(r13)` SDA load + decrement + store at top.
- Member layout shows multiple TArrays + ONE inline-bit-array-style block (2 stores at +0x10 inside member with `bl Deallocate` after each).
- Tail uses `g_resourceManager->Free` (NOT MainHeap()->Free).

## When NOT to reach

- If no s_instanceCount load, fall back to plain Variant I (ERModel pattern).
- If the inline-bit-array-style member uses `vector<T>` instead, that's Variant G' (separate catalog entry).
- If multiple inline-bit-array members exist, or the member is at an unusual offset, RE the dtor structure first.

## See also

- `technique_catalog_69_sda_extern_no_map_symbol.md` — Technique #69 (the SDA-extern int piece)
- `technique_catalog_variant_G_prime.md` — sibling Variant G' (vector<T> instead of TArrays)
- `technique_catalog_extern_char_vt.md` — Technique #18 (vtable-at-non-zero-offset for the manually-managed-vtable pattern)
- Commits `5c3a9298` (ERAnim Variant I' pioneer), `60a70ef5` (ERAnimBitArray sibling-twin)
