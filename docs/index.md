---
hide:
  - navigation
  - toc
---

<div class="sims-hero">
  <h1>The Sims 2 GameCube</h1>
  <p>A byte-matching decompilation — <strong>100.00% complete</strong></p>
  <span class="sims-metric">4,145,724 / 4,145,724 bytes</span>
  <span class="sims-metric">18,458 / 18,458 functions</span>
  <span class="sims-metric">Public floor never broken</span>
</div>

## The headline

<div class="sims-stats">
  <div class="sims-stat">
    <span class="stat-label">Code (.text) byte-match</span>
    <span class="stat-value">100.00%</span>
    <span class="stat-sub">decomp.dev public floor</span>
  </div>
  <div class="sims-stat">
    <span class="stat-label">Functions matched</span>
    <span class="stat-value">18,458</span>
    <span class="stat-sub">every single one</span>
  </div>
  <div class="sims-stat">
    <span class="stat-label">Semantic recovery (S17)</span>
    <span class="stat-value">56.7%</span>
    <span class="stat-sub">readable C++ ceiling</span>
  </div>
  <div class="sims-stat">
    <span class="stat-label">Data section (.data + .rodata)</span>
    <span class="stat-value">9.21%</span>
    <span class="stat-sub">new tracking pillar</span>
  </div>
</div>

## What this is

The Sims 2 for Nintendo GameCube (`G4ZE69`) is a byte-perfect matching decompilation. Every `.text` byte in our compiled DOL matches the retail binary, and the source builds back to a bit-identical disc image.

The repo went from **11.50% byte-match to 100%** in a single multi-agent marathon session (~30 hours of wall time). It is, to our knowledge, the **fastest GameCube decomp** to ever reach the 100% byte-match milestone.

[See the marathon writeup :material-arrow-right:](story/marathon.md){ .md-button .md-button--primary }
[Live progress on decomp.dev :material-chart-line:](https://decomp.dev/natebag/Sims2DECOMP){ .md-button }

## Where the project stands today

- **Byte-match floor**: 100.00% (the public dashboard metric — held since the closing commit)
- **Semantic recovery**: ~57% of matchable functions have readable C++ source. The rest are byte-equivalent stubs (ASMPROC inject pipelines) that pass `verify_match.sh` but read as raw bytes rather than expressing program meaning.
- **Data section**: ~9% byte-matched. Tracking just landed; this is the next pillar of work.
- **Port-readiness**: partial. The ~13% of subsystems with handwritten C++ are portable today; the remaining stubs need stub-to-real-C++ conversion before a PC port is feasible.

## Three-axis value framing

Decomp progress is one number on the public dashboard, but the work has three independent axes:

<div class="sims-stats">
  <div class="sims-stat">
    <span class="stat-label">Public floor</span>
    <span class="stat-value">.text 100%</span>
    <span class="stat-sub">DOL rebuilds bit-perfect from source</span>
  </div>
  <div class="sims-stat">
    <span class="stat-label">Semantic ceiling</span>
    <span class="stat-value">~57% C++</span>
    <span class="stat-sub">readable, retargetable code</span>
  </div>
  <div class="sims-stat">
    <span class="stat-label">Data pillar</span>
    <span class="stat-value">~9% data</span>
    <span class="stat-sub">vtables, strings, globals</span>
  </div>
</div>

## Get involved

- **Run the build**: clone the repo, follow [Methodology](methodology/index.md) to set up the toolchain.
- **Pick a subsystem**: see the [Subsystem Map](contributing/subsystems.md) to claim a class for stub-to-real-C++ conversion.
- **Crack a wall**: the [Technique Library](story/techniques.md) documents 18+ matching techniques from the marathon.

## Links

- **Repo**: [github.com/natebag/Sims2DECOMP](https://github.com/natebag/Sims2DECOMP)
- **Live dashboard**: [decomp.dev/natebag/Sims2DECOMP](https://decomp.dev/natebag/Sims2DECOMP)
- **Toolchain notes**: see [Methodology > Byte Matching](byte_matching_plan.md)
