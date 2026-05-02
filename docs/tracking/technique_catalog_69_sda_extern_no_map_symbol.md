# Technique #69 — SDA-extern integer via -25836(r13) anchor (no-map-symbol resolution)

**Status:** VALIDATED on ERAnim (S13 2026-05-02 Lane H, commit `5c3a9298`).

**Sibling to:** `extern char globalName[]` SDA-extern singleton pattern (Technique #18).

## Use case

DOL emits `lwz r11, -25836(r13)` / `stw r11, -25836(r13)` referencing an SDA-resident integer counter (e.g. `s_instanceCount` for ref-counted resource classes). The symbol has **NO entry in the release map file** (release map omits .sbss-resident counters when the original TU never explicitly defined the symbol on a public-visibility line). The compiler still must emit a `R_PPC_EMB_SDA21` relocation against `r13` for the load/store.

## Recipe

```cpp
extern int s_instanceCount;   // no definition, no map symbol — SDA21 reloc only
```

Reference it directly in the body:

```cpp
ERAnim::~ERAnim() {
    --s_instanceCount;     // emits lwz / addi -1 / stw with SDA21 reloc
    // ...rest of body
}
```

## Why it works

`verify_match.sh` (line ~282 of the relocation-masking logic) treats `R_PPC_EMB_SDA21` as a 4-byte mask — the entire instruction word is wildcarded during the byte comparison, so the actual r13 displacement does not need to match. This means:

1. The compiler emits `lwz r11, sda21@(s_instanceCount)(r13)` with a relocation slot.
2. The relocation is masked during byte-level diffing.
3. **No linker resolution is required** for verify-match to pass.
4. Future link-stage resolution can be deferred — `decomp-toolkit` byte-injection from the DOL side satisfies the resolver if needed.

## Validated targets

- **ERAnim::~ERAnim @ 0x803674EC** (196B Variant I' pioneer, commit `5c3a9298`).
  Companion `ERAnim::ERAnim @ 0x803673AC` ctor uses the matching `++s_instanceCount` pattern with the SAME -25836(r13) offset — confirms the symbol is shared between ctor and dtor of the same class (sibling load/store anchor).

## Pitfalls

- **Do NOT add a definition** like `int s_instanceCount = 0;` in the same TU. The SN compiler will then place the symbol in `.sdata` at a specific (compiler-chosen) offset, which may not match the DOL's chosen offset. The relocation gets MASKED either way, but having a stray definition can introduce link-time conflicts when the TU is built into a larger object.
- **Distinct from `extern char globalName[]`** — that pattern targets `R_PPC_ADDR16_HA/LO` 16-bit immediate splits (lis/addi pair). Technique #69 targets `R_PPC_EMB_SDA21` (single instruction with packed 21-bit field). Both are masked by verify_match but the disasm shape is different.
- **Use the canonical name from disasm context** — for ERAnim the natural name is `s_instanceCount`. Naming consistency helps cross-class deduction (e.g. if ERAmbientScore later turns out to share the same -25836(r13) offset, the same `extern int s_instanceCount` declaration applies to both TUs).

## When to reach

Reach for Technique #69 when:
- DOL has `lwz/stw rN, <signed>(r13)` reference in the function body.
- The map file has no symbol at the corresponding SDA address.
- The reference is to a primitive type (int, short, char) — for pointer-sized references use the `extern char globalName[]` pattern instead (Technique #18).

## When NOT to reach

- Don't reach if the SDA reference IS in the map file — declare against the actual symbol name.
- Don't reach for non-SDA globals (lis/addi splits) — those need Technique #18.

## See also

- `technique_catalog_extern_char_vt.md` — vtable-at-non-zero-offset (related lis/addi-pair pattern)
- `feedback_mi_vcall_technique.md` — non-SDA singleton via `extern char g[16]`
- `verify_match.sh` line ~282 — `R_PPC_EMB_SDA21` masking logic
