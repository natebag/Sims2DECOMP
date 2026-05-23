# Live Progress

The public-facing dashboard lives at **[decomp.dev/natebag/Sims2DECOMP](https://decomp.dev/natebag/Sims2DECOMP)**. It updates on every push to `main`.

## What the dashboard shows

[![Game Code](https://decomp.dev/natebag/Sims2DECOMP.svg?mode=shield&measure=code&label=Game%20code&category=game)](https://decomp.dev/natebag/Sims2DECOMP)
[![Overall](https://decomp.dev/natebag/Sims2DECOMP.svg?mode=shield&measure=code&label=Overall&category=all)](https://decomp.dev/natebag/Sims2DECOMP)

- **Code bar (`.text`)**: 100.00% byte-match across all 18,458 functions. This is the public floor — every commit's pre-commit hook verifies it can't drop.
- **Data bar (`.data` family)**: ~9.2% byte-match across `.ctors`, `.dtors`, `.rodata`, `.data`, `.sdata`, `.sdata2`. Tracking landed in 2026-05-23; see [Semantic Recovery](semantic-recovery.md) for the roadmap to climb this.

## Per-section data breakdown

| Section | Matched / Total | % |
|---------|----------------|---|
| `.ctors` | 13 / 644 | **2.02%** |
| `.dtors` | 0 / 360 | **0.00%** |
| `.rodata` | 61,380 / 362,672 | **16.92%** |
| `.data` | 753 / 306,168 | **0.25%** |
| `.sdata` | 604 / 7,576 | **7.97%** |
| `.sdata2` | 28 / 3,980 | **0.70%** |
| **TOTAL** | **62,778 / 681,400** | **9.21%** |

## What's NOT on the dashboard

Two important metrics that the public dashboard doesn't capture:

- **Semantic-recovery ratio** (~56.7%): the fraction of matched functions that have *readable C++* source rather than `ASMPROC inject_before` byte directives. This is the internal "code quality / port-readiness" axis.
- **Code-quality work**: refactors that move stubs into properly-named class directories, real-symbol replacements of fake SDA-coincidence externs, polish that makes the codebase materially more navigable. These add 0 to the dashboard but reduce the cost of every subsequent conversion.

See [Semantic Recovery](semantic-recovery.md) for full session-end totals.
