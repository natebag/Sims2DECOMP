# Technique Catalog Entry — `unsigned int` shift for `srwi` (logical right shift)

**Status:** VALIDATED on Park-Miller LCG (S13 Track I E-9 triage 2026-05-01).

**Use case:** When DOL emits `srwi rA, rS, n` (logical right shift) but GCC produces `srawi rA, rS, n` (arithmetic right shift), the source-level fix is to do the shift on an `unsigned int` value (not signed `int`).

**Why:** `srwi` is the extended mnemonic for `rlwinm rA, rS, 32-n, n, 31` (zero-fill), which GCC selects only for unsigned-typed shifts. `srawi` (sign-extend) is what `int >> n` compiles to. Park-Miller-style LCGs and bit-pattern decomposition functions need the unsigned form to match.

**Recipe:**

```cpp
// WRONG (compiles to srawi, signed shift):
int hi = s >> 16;

// RIGHT (compiles to srwi, logical/unsigned shift):
unsigned int s_u = (unsigned int)s;
unsigned int hi = s_u >> 16;
int hi_mul = (int)hi * 16807;  // cast back to signed if needed for downstream math
```

**Validated case:**
- **Effects::PMRand (0x8035214C, 68B)** — Park-Miller LCG with multiplier 16807, modulus 2^31-1. Original signed-int source produced `srawi r9, r0, 16` at offset 0x04 + `srawi r9, r9, 15` at offset 0x18. Switching to `unsigned int` shift pattern produced byte-exact match (commit `8e2f9ad3`).

**General applicability:** Any bit-manipulation function (RNG state advance, hash functions, CRC, packed-field extraction, IEEE-754 bit unpacking) where the DOL uses `srwi`/`rlwinm` for a logical right shift. Apply the unsigned-cast recipe before the shift.

**Triage outcome (E-9 task):** swap_operands mutator was DESCOPED for PMRand based on this triage. The wall was a shift-kind mismatch, NOT a true operand-commutativity wall.

**Remaining E-9 unlock pool wall (StackSwap operand-transposition):** Still needs evaluation — it may or may not be source-level rewritable. Documented separately if mutator authoring proceeds.

**Catalog reference:** Apply the recipe directly in source. No `// ASMPROC_*` directive needed.
