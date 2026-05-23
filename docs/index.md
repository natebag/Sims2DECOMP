---
hide:
  - navigation
  - toc
---

<div class="sims-hero">
  <h1>The Sims 2 GameCube</h1>
  <p>Matching decompilation of The Sims 2 for Nintendo GameCube (<code>G4ZE69</code>)</p>
  <span class="sims-metric">4,145,724 / 4,145,724 .text bytes matched</span>
  <span class="sims-metric">18,458 / 18,458 functions matched</span>
</div>

## Status

<div class="sims-stats">
  <div class="sims-stat">
    <span class="stat-label">Code (.text)</span>
    <span class="stat-value">100.00%</span>
    <span class="stat-sub">4,145,724 / 4,145,724 B</span>
  </div>
  <div class="sims-stat">
    <span class="stat-label">Functions</span>
    <span class="stat-value">18,458</span>
    <span class="stat-sub">all matched</span>
  </div>
  <div class="sims-stat">
    <span class="stat-label">Data sections</span>
    <span class="stat-value">9.21%</span>
    <span class="stat-sub">62,778 / 681,400 B</span>
  </div>
  <div class="sims-stat">
    <span class="stat-label">Hand-written C++</span>
    <span class="stat-value">~57%</span>
    <span class="stat-sub">of matched functions</span>
  </div>
</div>

`matched_code_percent` is verified on every commit via `tools/verify_match.sh` and regenerated into `build/G4ZE69/report.json` for [decomp.dev](https://decomp.dev/natebag/Sims2DECOMP).

## What this project is

The Sims 2 for Nintendo GameCube (`G4ZE69`) is a matching decompilation: every byte in the compiled `.text` section equals the retail DOL. The source builds to a bit-identical binary.

Two further axes of work remain:

- **Hand-written C++ source.** ~57% of matched functions express their logic as readable C++. The remaining functions byte-match but are wrapped raw bytes (`ASMPROC inject_before` directives). Stub-to-real-C++ conversion is the ongoing work.
- **Data sections.** `.rodata`, `.data`, `.sdata`, etc. are currently 9.21% byte-matched. Vtables, string tables, and initialized globals are the open work here.

[Live progress :material-chart-line:](https://decomp.dev/natebag/Sims2DECOMP){ .md-button .md-button--primary }
[Build instructions :material-hammer:](methodology/index.md){ .md-button }
[Contribute :material-hand-heart:](contributing/index.md){ .md-button }

## Documentation

- **[Status](status/index.md)** — current numbers and per-section breakdown
- **[Methodology](methodology/index.md)** — toolchain, build pipeline, verification
- **[Techniques](techniques.md)** — matching technique reference (ASMPROC mutators, decoder cascade, etc.)
- **[Contributing](contributing/index.md)** — workflow, hard rules, tooling guide
- **[Subsystem Map](contributing/subsystems.md)** — what's done, what's open
- **[Roadmap](roadmap/index.md)** — open work
