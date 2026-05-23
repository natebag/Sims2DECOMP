# Semantic Recovery

## What "semantic recovery" means

A function is **byte-matched** if its compiled output equals the original DOL bytes. That's the public dashboard metric.

A function is **semantic** if, on top of being byte-matched, its C++ source is *readable* — declares its class, takes typed parameters, expresses program logic rather than baking in raw PowerPC bytes via `ASMPROC inject_before`. This is the metric that matters for port-readiness.

Byte-match is the floor. Semantic recovery is the ceiling we climb.

## Where we are

- **Matchable-function semantic ratio: 56.7%** (10,468 / 18,458) as of S17 close
- Baseline at S17 kickoff: 50.4%
- Net session gain: +6.3 percentage points (largely from classifier accuracy + hygiene cleanup; pure writer work added a smaller delta)

## Why the metric is subtle

Late in S17, a strategic insight surfaced: **the semantic-ratio classifier counts *unique addresses*, deduped across the whole `src/matched/` tree**.

That means:

- ❌ Promoting `agent/match_0xADDR_method.cpp` (semantic-shape but in agent/) → canonical class directory = **0 ratio gain**. The address was already counted.
- ✅ Converting `agent/inject_ADDR` (no semantic file *anywhere*) → ANY semantic file = **+1 ratio gain**. New address newly counted.

A lot of polish work moves the codebase materially closer to port-ready without moving the ratio. The corrected mental model is:

- **Polish work** = code-quality / port-readiness gain, dashboard movement = 0
- **Net-new-address conversion** = both code-quality AND dashboard gain

Both are valid. Reporting honestly means recognizing the distinction.

## Roadmap to climb

| Target | Approach |
|--------|----------|
| Stub-to-real-C++ on big classes | Convert `cXObjectImpl`, `cXPersonImpl`, `SAnimator2`, `targets_s2c` family stubs into readable C++ using TypeArch-recovered class layouts |
| Net-new inject-only addresses | 9,233 `inject_only` addresses remain — each one converted = +1 ratio |
| `.data` section pillar | Now that tracking is live, vtables + globals climb a separate metric |
| Cross-class technique transfer | Every cracked recipe ports to siblings — family-blast as documented in the [Technique Library](../story/techniques.md) |

## Cleanup work — also session-defining

In parallel to semantic conversions, S17 purged **~1,088 pre-existing duplicate stub files** from `src/matched/agent/` across five cleanup phases (A-E). Net byte impact: 0 (deletions of files with semantic twins didn't drop the floor). Net codebase impact: significant — duplicate noise distorted prior metrics and complicated reviewer attribution. The repo's cleanest state since pre-S15.

## Three-axis value framing

To honestly communicate session value:

1. **Public floor** (`.text` 100%) — held untouched throughout
2. **Semantic ceiling** (~57%) — slow steady climb via real conversion + classifier accuracy
3. **Code quality** — refactors, dupe purges, real-symbol upgrades, naming consistency — invisible to the dashboard but essential to long-term port viability

Collapsing all three to a single number understates the work. We report all three.
