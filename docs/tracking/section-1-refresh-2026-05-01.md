# Section 1 Audit Refresh (2026-05-01)

Methodology: address-based cross-check against ALL src/matched/**/*.cpp files
(extracted from filenames `match_0xADDR` AND header-comment addresses for non-standard names)

## Refreshed Section 1 Table

| Size Band | Unmatched Count | Session-2 Count | Delta | Delta % |
|-----------|-----------------|-----------------|-------|---------|
| 8-40B | 1242 | 562 | +-680 | +-121.0% |
| 40-64B | 739 | 676 | +-63 | +-9.3% |
| 64-128B | 2480 | 2427 | +-53 | +-2.2% |
| 128-256B | 2926 | 2856 | +-70 | +-2.5% |
| 256-512B | 2097 | 2056 | +-41 | +-2.0% |
| 512B+ | 1677 | 1665 | +-12 | +-0.7% |

**Total delta from session-2: -919**
**Matched index: 8374 addresses**
**Total .text/.init functions in symbols.txt: 18539**

**Note on scope difference:** Session-2 numbers are lower across all bands, suggesting
the session-2 audit used DVD map (~16,211 C++-named functions) or a filtered subset,
while this refresh uses the full symbols.txt (~18,539 functions including compiler-generated
helpers, static initializers, and template instantiations). These refreshed numbers are
the new planning baseline.

## Top 10 Classes (128-256B + 256-512B bands)

| Class | Unmatched Count |
|-------|----------------|
| global | 198 |
| InteractorModule | 130 |
| SAnimator2 | 79 |
| AptActionInterpreter | 76 |
| cXObjectImpl | 70 |
| ERC | 65 |
| EAnimController | 60 |
| INVTarget | 51 |
| SimModel | 42 |
| cXPersonImpl | 39 |

## Recommended Priority Bands

1. **128-256B**: 2926 unmatched
2. **64-128B**: 2480 unmatched
3. **256-512B**: 2097 unmatched
4. **512B+**: 1677 unmatched
5. **8-40B**: 1242 unmatched
6. **40-64B**: 739 unmatched
