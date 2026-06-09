# Day-0 Compiler Point-Version A/B Test — VERDICT: HYPOTHESIS DEAD

**Date:** 2026-06-09. **Operator:** Fable-5 solo session.
**Question:** Are the recurring wall classes (redundant-mr coloring, addi-vs-mr,
copy-prop, comparison-constant canon, redundant-li, peephole-fold) caused by a
SN ProDG **point-version difference** between our verifier (3.9.3) and whatever
built the September 2005 DOL? (S20 kickoff Lane B's premise.)

**Answer: No.** All four installed ProDG versions are codegen-identical on every
function tested. The wall classes are NOT version drift across 3.5–3.9.3.
Lane B's version-override premise should be retired; its tooling budget repoints
to source-level permutation (see "What replaces Lane B" below).

---

## Method

New tool: `tools/version_ab_test.py` — parallel batch orchestrator that copies
each source to a temp file with `// SN-VERSION: <v>` prepended (the override
`verify_match.sh` already supports) and runs strict verification under each of
3.9.3 / 3.8.1 / 3.7 / 3.5, recording MATCH/MISMATCH + differing-word count.
No post-compile mutation anywhere; this only selects which historical
cc1plus.exe/NgcAs.exe pair compiles the file.

Binaries confirmed genuinely distinct (4 different SHA-1s / sizes for cc1plus,
4 for NgcAs). Repo-wide inventory: these 4 are the ONLY unique cc1plus builds
present (alt_versions/* are hash-identical copies).

## Results

| Corpus | Functions | Runs | Outcome |
|---|---|---|---|
| Random clean sample (seed 42) | 200 | 800 | 100% four-way agreement, all MATCH |
| 150 largest clean matches (up to 2,396B) | 150 | 600 | 100% four-way agreement, all MATCH |
| Wall/near-miss corpus from src/wip (deduped, stale-filtered) | 259 | 1,036 | 100% four-way agreement — zero status or diff-count flips |

Direct assembly comparison on the flagship wall (ReportNext 0x802DA950, 480B,
112/120 under 3.9.3): normalized `.s` output is **instruction-identical** across
all four versions (only cosmetic difference: 3.9.3 emits an extra local label).

Conclusion: SN shipped effectively the same GCC 2.95 codegen core across
ProDG 3.5→3.9.3. Point-version selection cannot crack any wall class.

## Incidental find #1: 171 orphaned clean matches recovered (+0.11pp)

171 of the 259 wall-corpus files verify **MATCH under strict mode as-is** —
they were verified-clean C++ sitting in `src/wip/duplicates/` with NO
corresponding file in `src/matched/` (an earlier dedup/purge pass orphaned
them; their addresses were in neither clean.txt nor forced.txt).
All 171 landed via `git mv` in 5 hook-verified commits.

**Clean headline: 12.38% → 12.49%** (452,332 → 456,240 / 3,653,648 bytes).
report.json refreshed and committed.

## Incidental find #2: the genuine-wall permuter seed list

43 corpus files are genuine MISMATCHes under every compiler version —
version-invariant walls. Sorted by differing-word count, the head of the list
is extremely close:

| Addr | Size | Words off | Function |
|---|---|---|---|
| 0x8021F480 | 200B | 1 | SocialModeInteractor::SetupInteractionMenu |
| 0x802D7024 | 112B | 2 | FastAllocPool::Init |
| 0x80109264 | 224B | 3 | cXObjectImpl::TryChangeWantFearTree |
| 0x8012CBE8 | 28B | 4 | PiecewiseFn ctor |
| 0x80064434 | 260B | 5 | SAnimator2::handleImpatientIdleAnimation |

Full list: `docs/tracking/permuter-targets-day0.txt` (43 entries, ascending
diff count). These are the seed corpus for the source-permuter.

## What replaces Lane B

The S20/S21 "compiler-version unlock" lane is retired. The replacement, in
priority order:

1. **SN-ProDG source permuter** (decomp-permuter pattern, honest C++ output):
   automated source-level transforms (temp introduction, statement reorder,
   decl-order, ternary↔if) scored against DOL bytes. The wall taxonomy
   (store-order, coloring, temp-slot coupling) is exactly what it automates,
   and the 43-entry seed list starts with a 1-word-off 200B function.
2. **objdiff install** (config already present) for instruction-level wall
   diagnosis.
3. **m2c-first pipeline** for the 512B+ tier (half of remaining bytes).

Wall taxonomy note for walls.md readers: every wall previously labeled
"SN-ProDG-point-version" / "compiler-version difference" should be re-tagged
as version-invariant — the fix, if any, is a different source shape, not a
different compiler binary.
