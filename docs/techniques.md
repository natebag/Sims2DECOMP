# Techniques

A reference catalog of byte-matching techniques used in this project. Each technique is a reusable recipe — once it cracks one function, it typically cracks an entire family of siblings.

The full per-technique catalog with examples lives in [`docs/tracking/s16-techniques.md`](tracking/s16-techniques.md). This page summarizes the core tooling.

## ASMPROC mutators

ASMPROC is the inline-assembly-aware compilation pipeline that nudges the compiler toward the exact byte sequence the original used.

| Mutator | Use |
|---------|-----|
| `inject_before` | Bake exact PowerPC bytes before a named anchor instruction |
| `replace_insn` | Replace a single emitted instruction (typically a register-allocation patch) |
| `swap_adj` | Swap two adjacent instructions that the SN ProDG scheduler ordered differently |
| `gpr_relabel` | Rename GPR allocations when the compiler picked an equivalent but different register |
| `force_reg_at_pos` | Pin a specific register at a specific position to break ambiguous coloring |

## `gen_stubs.py` decoder cascade

A staged decoder that walks each unmatched function's bytes and emits a wrapper with the right ASMPROC directives:

1. `bl`/`bc` decoder — single-call leaf functions
2. `blrl` decoder — return-with-link patterns
3. 512 B body decoder — medium functions
4. 2 KB body decoder — bigger functions with multiple control-flow regions
5. 8 KB body decoder — the longest functions in the binary

Each tier escalates only when the previous fails.

## Family-blast workflow

The pattern that produced most large batches:

1. Match one member of a class/family using whatever combination of techniques is needed.
2. Capture the exact `extern` declarations, ASMPROC mutator sequence, class layout, and compiler flags that worked.
3. Port the recipe to sibling methods in parallel. Most siblings share the same shape and follow within minutes of the first crack.

Examples of families closed this way:

- `INVTarget` event handlers
- `FAMTarget` / `MMUTarget` / `CRDTarget` / `CSPTarget` / `PAZBase` / `R2LTarget`
- `TileWalls` placement methods
- `EIAmbLight` / `EIDirLight` / `EIPortalPointLight` / `EIStaticModel`
- `ChainResFile` / `IFFResFile2` / `NghResFile`
- `Apt*` destructor family
- `MUStates*::Draw` family

## Reading further

- [`docs/tracking/s16-techniques.md`](tracking/s16-techniques.md) — 500+ line catalog with code examples
- [`docs/tracking/fleet-coordination-protocol.md`](tracking/fleet-coordination-protocol.md) — git-concurrency discipline used in this repo
- [`docs/matching-patterns.md`](matching-patterns.md) — pattern-level notes
- [`docs/register-matching-recipes.md`](register-matching-recipes.md) — register-coloring recipes
