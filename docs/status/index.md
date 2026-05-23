# Status

The public progress dashboard lives at **[decomp.dev/natebag/Sims2DECOMP](https://decomp.dev/natebag/Sims2DECOMP)** and updates on every push to `main`.

[![Game Code](https://decomp.dev/natebag/Sims2DECOMP.svg?mode=shield&measure=code&label=Game%20code&category=game)](https://decomp.dev/natebag/Sims2DECOMP)
[![Overall](https://decomp.dev/natebag/Sims2DECOMP.svg?mode=shield&measure=code&label=Overall&category=all)](https://decomp.dev/natebag/Sims2DECOMP)

## `.text` byte-match

| | Total | Matched | % |
|---|---|---|---|
| Bytes | 4,145,724 | 4,145,724 | 100.00% |
| Functions | 18,458 | 18,458 | 100.00% |

Verified per commit via `tools/verify_match.sh`.

## Data section byte-match

| Section | Total | Matched | % |
|---------|-------|---------|---|
| `.ctors` | 644 B | 13 B | 2.02% |
| `.dtors` | 360 B | 0 B | 0.00% |
| `.rodata` | 362,672 B | 61,380 B | 16.92% |
| `.data` | 306,168 B | 753 B | 0.25% |
| `.sdata` | 7,576 B | 604 B | 7.97% |
| `.sdata2` | 3,980 B | 28 B | 0.70% |
| **Total** | **681,400 B** | **62,778 B** | **9.21%** |

Data section tracking was added in 2026-05-23. Current matched bytes come from string literals embedded in `ASMPROC inject_before` directives plus a small number of vtable matches that fall out of the build.

## Hand-written C++ ratio

A separate internal metric tracks the fraction of matched functions that have hand-written C++ source rather than `ASMPROC inject_before` byte directives.

- Matchable-function hand-written ratio: **~57%** (10,468 / 18,458)
- The remaining ~43% byte-match but read as wrapped raw bytes

This is the metric that determines port-readiness. See [Semantic recovery](semantic-recovery.md) for the ongoing work.
