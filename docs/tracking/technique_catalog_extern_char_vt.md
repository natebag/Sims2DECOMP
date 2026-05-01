# Technique Catalog Entry — `extern char vt[]` for vtable-at-non-zero-offset

**Status:** VALIDATED across SI and MI cases (S13 Track I Phase 3 triage 2026-05-01).

**Use case:** When DOL stores a vtable pointer at a non-zero `this` offset (e.g. `stw r9, 0x144(this)`), GCC will not emit this directly from a virtual class declaration because the vtable-ptr would land at offset 0 by default.

**Recipe:**

```cpp
extern char vt_<ClassName>[];   // forward-declared external symbol

class ClassName {
public:
    char pad_to_offset[VTABLE_OFFSET];   // pad to whatever offset DOL uses
    void* m_vt;                          // becomes the vtable slot
    // ...remaining fields after m_vt
};

ClassName::ClassName() {
    m_vt = vt_<ClassName>;
    // ...other field inits
}
```

**Why it works:** Treating the vtable slot as an ordinary `void*` member assigned from an `extern char vt[]` forces GCC to emit the canonical `lis/addi` + `stw` sequence with `R_PPC_HA16` / `R_PPC_LO16` relocations against the symbol — same encoding the DOL uses for vtable placement, irrespective of inheritance shape.

**Validated cases:**
- **EVibrate (SI, +0x208)** — info `4cb18ac7` (S13 session 2)
- **Effect family ctors (MI, +0x144)** — Effects::Effect::Effect(void) compiles vtable at +0x144 byte-exactly via this recipe (S13 session 2 triage 2026-05-01). Remaining diffs in the body are store-ordering, NOT vtable-related.
- **ENgcRenderer dtor (MI, +0x338)** — same recipe expected to work (52B function out of 65-128B sweep band; not blocked here).

**Triage outcome (E-1 task):** vtable_at_offset MI-subset mutator was DESCOPED based on this triage. The recipe is inheritance-agnostic — the asm-processor already handles it via standard relocation infrastructure. No new mutator needed for the vtable-placement part.

**Remaining wall types (separate from this catalog entry) on Effect family ctors:**
- Store-ordering wall (DOL emits stw at offsets 0x4C/0x44/0x48, GCC chooses 0x48/0x4C/0x44)
- May be tractable via `relabel_range` or `swap_stw` mutator (not in scope for this thrust)

**Catalog reference:** Apply the recipe directly in the source — no `// ASMPROC_*` directive needed. The recipe is documented here and in info `652c5a9a` (Track I session log).
