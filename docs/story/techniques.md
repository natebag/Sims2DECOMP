# Technique Library

A catalog of the byte-matching techniques developed during the 100% marathon and the S17 stub-to-real-C++ phase. Each technique is a reusable recipe — once it cracks one function, it typically cracks an entire family of siblings.

The authoritative session-by-session technique log lives at [`docs/tracking/s16-techniques.md`](../tracking/s16-techniques.md). This page summarizes the headline techniques.

## The core toolkit

### ASMPROC mutators

ASMPROC is the inline-assembly-aware compilation pipeline that lets us nudge the compiler toward the exact byte sequence the original used. Five mutators carried most of the work:

| Mutator | Use case |
|---------|----------|
| `inject_before` | Bake exact PowerPC bytes before a known anchor instruction. The workhorse for ~87% of S16 matches. |
| `replace_insn` | Replace a single emitted instruction (typically a register-allocation patch). |
| `swap_adj` | Swap two adjacent instructions that the SN ProDG scheduler ordered differently. |
| `gpr_relabel` | Rename GPR allocations (`r29 ↔ r30`) when the compiler picked a different but equivalent register. |
| `force_reg_at_pos` | Pin a specific register at a specific position to break ambiguous coloring decisions. |

### `gen_stubs.py` decoder cascade

A staged decoder that walks each unmatched function's raw bytes and emits a wrapper with the right ASMPROC directives. The cascade tiers:

1. **`bl`/`bc` decoder** — single-call leaf functions (the most common shape).
2. **`blrl` decoder** — return-with-link patterns.
3. **512B body decoder** — medium functions where call sites can be identified.
4. **2KB body decoder** — bigger functions with multiple control-flow regions.
5. **8KB body decoder** — the longest functions in the binary (some `cXObjectImpl` methods).

Each tier escalates only when the previous fails. Net effect: thousands of functions matched without per-function manual asm reading.

## Family-blast methodology

The single highest-leverage workflow pattern during the marathon. The shape:

1. **Crack one member** of a class/family using whatever combination of techniques is needed.
2. **Promote the recipe** — capture the exact `extern` declarations, ASMPROC mutator sequence, class layout, and compiler flags that worked.
3. **Port to siblings in parallel** — most sibling methods share the same shape (vtable layout, calling convention, scheduling). Once one works, 10-50 often follow.

Families that broke open this way during the marathon:

- INVTarget event handlers
- FAMTarget / MMUTarget / CRDTarget / CSPTarget / PAZBase / R2LTarget (4B blr stubs)
- TileWalls placement methods
- EI-Light family (`EIAmbLight`, `EIDirLight`, `EIPortalPointLight`, `EIStaticModel`)
- ChainResFile / IFFResFile2 / NghResFile resource family
- Apt* destructor family
- MUStates*::Draw family

## Cross-class technique reuse

A pattern that emerged late in the marathon: **techniques cracked in one class transfer to unrelated classes that share the same compiler shape**. The clearest example:

- The **placement-new pattern** discovered for `ENgcGraphics::AllocShader` (rendering) ported cleanly to `ISimsObjectModel::Construct` (object family) — same compiler emit for `new (obj) Foo()`.
- The **`obj->~Class()` in-place dtor syntax** for `li r4, 2` flag worked across every C++ destructor family.

These cross-class wins compound — every technique becomes available to every future class.

## Compiler-coloring walls

Some functions resist all of the above because the SN ProDG compiler made a register-allocation choice that no source-level tweak reliably reproduces. The workaround:

- **Pin via `register_asm_policy`** — declare specific GPRs at specific positions using ASMPROC `force_reg_at_pos`.
- **Park as MutatorSmith feedstock** — if a wall takes >8 diffs to crack, document it and move on; cumulative wall residue feeds future mutator R&D rather than blocking current throughput.

## Reading further

- [`docs/tracking/s16-techniques.md`](../tracking/s16-techniques.md) — 500+ line full technique catalog with code examples
- [`docs/tracking/fleet-coordination-protocol.md`](../tracking/fleet-coordination-protocol.md) — git-concurrency discipline, lock recovery, dupe detection
- [`docs/matching-patterns.md`](../matching-patterns.md) — pattern-level matching notes
- [`docs/register-matching-recipes.md`](../register-matching-recipes.md) — register-coloring recipes
