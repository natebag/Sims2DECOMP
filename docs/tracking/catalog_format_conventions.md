# Technique Catalog — Format Conventions

This document owns the meta-history of the technique-catalog format used in `docs/tracking/technique_catalog_*.md`. New format conventions are amended here when introduced by a specific catalog entry; the originating entry retains a one-line cross-reference back to this doc.

Structurally analogous to `feedback_multidirective_composition.md` (methodology decoupled from specific mutator docstrings).

---

## Format conventions in current effect

### Cross-class verification at first promotion (introduced Tech #72)

**Convention:** A technique catalog entry promotes at first encounter only when validated across MULTIPLE class families with distinct call shapes. N=2 is the minimum bar; N=3+ across 2+ class families is the comfortable target. The intent is to surface false-positives (single-class coincidences that look like a generalizable technique) before they enter the catalog.

**Originating entry:** [`technique_catalog_polarity_flip.md`](technique_catalog_polarity_flip.md) (Tech #72) — promoted at N=6 across 5 class families.

**Catalog-author rule:** before drafting a new entry, verify the technique reaches N≥2 across at least one cross-class boundary. Single-class N=N validations promote internally to the class's documentation, not the technique catalog.

### HOLDS/FAILS coverage map with concrete discriminators (introduced Tech #73)

**Convention:** A technique catalog entry includes a "Coverage map" section listing the SHAPES where the recipe HOLDS (produces byte-match) and the SHAPES where it FAILS (insufficient — escalate to mutator or Track-I queue). Each FAILS class includes a CONCRETE PRE-ATTEMPT DISCRIMINATOR — a structural signal a worker can read off the .s diff or DOL bytes BEFORE burning the 30-min triage budget on a wall the recipe cannot reach.

The intent is to prevent recipe over-trial: vague "this technique sometimes fails" guidance trains workers to apply the recipe everywhere; concrete discriminators let them route walls correctly on first inspection.

**Originating entry:** [`technique_catalog_anti_tail_merge_source_coax.md`](technique_catalog_anti_tail_merge_source_coax.md) (Tech #73) — N=6 across 4 control-flow shapes, with three FAILS classes each carrying a discriminator (size+fp-prologue+conditional-return for fp-multibranch; cc1plus-emits-bnelr-while-DOL-emits-bne-forward for preset+bnelr; two-or-more structural-diff types for compounded walls).

**Catalog-author rule:** any FAILS bullet in a coverage map must include the structural signal a worker uses to identify the case before attempting the recipe. "It depends on the function" is not a discriminator. "Function size ≥ 88B AND fmr-prologue AND bnelr-at-end" is a discriminator.

### Mutator vs source-coax decision tree (introduced Tech #73)

**Convention:** When a technique catalog entry replaces the use case of an existing mutator (i.e., the recipe handles cases the mutator was authored for), the entry MUST include a triage-outcome section that:
1. Names the affected mutator(s) and demotes them to EXPERIMENTAL or annotates with a Density Watch (per ORG framework)
2. Sets the 30-min source-coax-FIRST decision tree as the default path
3. Lists the concrete fallback criteria where the mutator IS the right tool (typically compounded structural walls)
4. Starts a 60-90d zero-invocation mothball clock if the demotion is full EXPERIMENTAL

**Originating entry:** Tech #73's "Triage outcome — `anti_tail_merge` mutator status change" section. anti_tail_merge demoted to EXPERIMENTAL at Tech #73 ship; mothball clock starts at catalog merge date 2026-05-02.

**Catalog-author rule:** the demotion only applies to mutators with an EXPLICIT replacement technique. Mutators without a replacement (e.g., `region_gpr_relabel`, `force_reg_at_pos`) get a "Density Watch" docstring annotation instead — STANDARD status retained, low-density usage flagged, no mothball clock unless a replacement technique lands.

---

## How to add a new format convention

When a new catalog entry introduces a format convention worth carrying forward:

1. Add a new subsection to "Format conventions in current effect" above.
2. Name the convention, describe the rule, give the rationale.
3. Cross-reference the originating entry (commit + filename + technique number).
4. Add the catalog-author rule that future entries should follow.

The originating catalog entry itself includes only a one-line cross-reference back to this doc, e.g.:

> This catalog adopts the HOLDS/FAILS coverage map format — see [`catalog_format_conventions.md`](catalog_format_conventions.md) for the format spec.

This keeps individual technique entries focused on the technique itself while format-history stays in one place.
