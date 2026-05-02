# Technique Catalog Entry #70 — vtable-at-offset SI ctor with member-in-derived

**Status:** VALIDATED across 7 classes / 3 distinct vtable offsets (S13 session 3 Lane J 2026-05-02). Promotion approved by MainGuy.

**Use case:** SI ctor where DOL emits vtable pointer at a non-zero `this` offset (e.g., `stw r9, 0x24(this)`, `stw r9, 0x54(this)`, `stw r9, 0xF0(this)`). Naive C++ inheritance produces wrong codegen because the vtable would land at offset 0.

**Companion to:** `technique_catalog_extern_char_vt.md` (which covers the dtor side of the same pattern). This entry adds the ctor recipe + member-init ordering rule.

## Core recipe

```cpp
extern char vt_<DerivedClass>[];

class BaseClass {
public:
    void* m_base_vt;                  // base's own vtable at offset 0
    BaseClass(/* args */);            // base ctor (called as bl from derived)
};

class DerivedClass : public BaseClass {
public:
    char pad[VTABLE_OFFSET - 4];      // pad from base end (4 bytes after m_base_vt) to vtable offset
    void* m_vt_at_offset;             // becomes the secondary vtable slot
    // ...remaining fields
    DerivedClass();
};

DerivedClass::DerivedClass() : BaseClass(/* args */) {
    m_vt_at_offset = (void*)vt_<DerivedClass>;
    // ...other field inits
}
```

**Critical layout rule:** any data member at offset N where N < VTABLE_OFFSET must be declared in the **derived** class, NOT the base. Base class layout ends BEFORE the vtable insertion point; derived class layout begins AFTER.

**Why this matters:** GCC emits ctor body in the canonical order:
1. **Base class ctor call** (`bl Base::Base`)
2. **Vtable set** at the derived's vtable offset (compiler-inserted or explicit assignment)
3. **Member ctor calls** (e.g., `bl TArray::TArray()`)
4. **Body assignments**

If a sub-object member (e.g., `TArray<X> m_arr` at offset 0x48) is declared in BASE, the base ctor calls the member ctor BEFORE the derived's vtable set — wrong order. If declared in DERIVED, the member ctor runs AFTER vtable set — matches DOL.

## Validated cases (7 classes, 3 offsets)

### Offset +0x24 — ENgcTexture family (5-twin sibling batch)
| Class | Address | Size | Base ctor args |
|-------|---------|------|----------------|
| ENgcTextureC4 | 0x8035061C | 72B | `(8, 8, 8)` |
| ENgcTextureC8 | 0x80350C84 | 72B | `(9, 8, 4)` |
| ENgcTextureCMPR | 0x80351494 | 72B | `(14, 8, 8)` |
| ENgcTextureRGB5A3 | 0x8035159C | 72B | `(5, 4, 4)` |
| ENgcTextureRGBA8 | 0x80351700 | 72B | `(6, 4, 4)` |
| ENgcTextureC4_32 | 0x80350750 | 84B | `(8, 8, 8)` + extra fields at +0xCC/0xD0 |

All call `ENgcTextureBase(format, w, h)`, then assign vtable at +0x24.

### Offset +0x54 — ENCamera (member-in-derived case)
| Class | Address | Size | Notes |
|-------|---------|------|-------|
| ENCamera | 0x8035CA0C | 84B | Has `TArray<ENCameraPoint> m_arr` member at offset 0x48 — MUST be declared in derived ENCamera, NOT in ENCameraBase. Base must end at 0x44 (just 4 base + pad) so derived's first member lands at 0x48. |

This was the pioneer case for the layout rule. Initial attempt with TArray in base failed because base ctor called TArray::TArray BEFORE derived vtable set. Moving TArray to derived flipped the order to match DOL.

### Offset +0xF0 — ENgcShader (Phase 3 EResource)
| Class | Address | Size | Base | Notes |
|-------|---------|------|------|-------|
| ENgcShader | 0x8034DC04 | 60B | EShader | Simplest variant — no extra fields, just base call + explicit second-vtable assignment. |

## Recipe variations

### Pure SI (no extra members between base and vtable offset)
```cpp
extern char vt_X[];
class Base { void* m_base_vt; Base(); };
class X : public Base {
    char pad[OFFSET - 4];
    void* m_vt_at_offset;
    X();
};
X::X() { m_vt_at_offset = (void*)vt_X; }
```
Used by: ENgcShader, ENgcFileSystem (offset 0), ERenderer (offset 0x338), ENgcControllerManager (offset 0x20 + SDA singleton register).

### Base ctor with args
```cpp
class Base { void* m_base_vt; Base(int, int, int); };
class X : public Base {
    char pad[OFFSET - 4];
    void* m_vt_at_offset;
    char pad_extras[...];
    int m_field_extra;
    X();
};
X::X() : Base(a, b, c) {
    m_vt_at_offset = (void*)vt_X;
    m_field_extra = 0;  // body init order matters; reverse compiler reorder if needed
}
```
Used by: ENgcTexture×6 (3-arg base), ENgcTextureC4_32 (extra fields at +0xCC/0xD0).

### Member-in-derived (TArray-style)
```cpp
class Base { /* ends before VTABLE_OFFSET */ };
class X : public Base {
    /* members at offsets > VTABLE_OFFSET — wait, MEMBERS BEFORE the vtable too can live here */
    SomeStruct m_member_at_low_offset;  // e.g., TArray at +0x48 < +0x54
    void* m_vt_at_offset;               // at VTABLE_OFFSET
    /* trailing fields */
    X();
};
X::X() {
    /* member ctor called implicitly */
    /* body assignments after */
}
```
Used by: ENCamera (TArray at +0x48, vtable at +0x54).

### Multi-call ctor (heap allocation)
```cpp
extern HeapType* GetHeap();
class X : public BaseFile {
    char pad[OFFSET - 4];
    void* m_vt_at_offset;
    char padN[...];
    void* m_buffer;
    X();
};
X::X() {
    m_vt_at_offset = (void*)vt_X;
    m_buffer = GetHeap()->MallocAligned(size, align, flag, idx);
}
```
Used by: ENgcSNFile (vtable @ +0x28, buffer @ +0x34, MallocAligned(2048,32,0,0)), ENgcFile (same shape, sizes 4096/2048, buffer @ +0x6C).

## Triage outcome

**No mutator needed** — the recipe is pure source-level. Compiler emits canonical `lis/addi` + `stw` with R_PPC_ADDR16_HA/LO relocations against `vt_<DerivedClass>` symbol. The verify_match.sh script masks these reloc bytes during comparison.

**Track I impact:** This catalog entry COMPLEMENTS the existing `vtable_at_offset` mutator (which still applies to MI-virtual cases that need post-mutation thunk dispatch — see `technique_catalog_extern_char_vt.md`). Pure-SI ctor cases do NOT need that mutator.

## Cross-class portability

Validated across 3 different vtable offsets (0x24, 0x54, 0xF0) and 4 different base classes (ENgcTextureBase, ENCameraBase, EShader, EResource via Phase 3 family). Recipe generalizes — no per-class authoring needed beyond declaring the right offset + base call args.

## Recognition fingerprint (scout pre-classifier)

| Signal | Indicator |
|--------|-----------|
| `bl <base ctor>` followed by `lis/addi/stw <vt>, OFFSET(this)` | This recipe applies |
| OFFSET == 0 | Standard inheritance with vptr override (not this recipe) |
| OFFSET > 0 | This recipe applies; check OFFSET for member-in-derived layout rule |
| Multiple `bl` calls + setup | Multi-call variant; identify each helper symbol |

## See also

- `technique_catalog_extern_char_vt.md` — companion entry covering the dtor side
- `feedback_mi_vcall_technique.md` — MI vcall via filler pure-virtuals (different mechanism)
- `feedback_ctor_store_order_technique.md` — Technique #63 ctor store-order polarity (relevant for body assignment order)
