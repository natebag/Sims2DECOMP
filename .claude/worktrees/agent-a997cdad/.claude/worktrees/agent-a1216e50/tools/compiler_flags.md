# Compiler Flags Analysis: GCC vs SN Systems ProDG

## Summary

The original Sims 2 GameCube binary was compiled with **SN Systems ProDG for GameCube**
(SN-NGC). We use **devkitPPC GCC 15.2.0** for the matching decompilation. This document
records the systematic analysis of GCC flag combinations to maximize byte-matching between
our compiled output and the original binary.

### Best Flag Combination

```
-mcpu=750 -meabi -mhard-float -O2
-fno-schedule-insns -fno-schedule-insns2
-fno-inline -fno-inline-small-functions
-fno-exceptions -fno-rtti -fno-builtin
-fshort-wchar -nostdinc++
```

### Match Results

| Configuration | Matches | Rate | Same-size Diff |
|---------------|---------|------|----------------|
| O2 baseline (old) | 1099/2371 | 46.4% | 496 |
| **O2 + no-sched + no-inline (new)** | **1114/2371** | **47.0%** | **487** |
| O2 + no-sched | 1113/2371 | 46.9% | 485 |
| O1 baseline | 1113/2371 | 46.9% | 485 |
| Os baseline | 1111/2371 | 46.9% | 487 |

The best flags produce 1114 byte-identical functions (47.0% of tested). An additional 487
functions (20.5%) have the correct size but differ in specific instruction bytes.

## Methodology

### Test Procedure

1. Compiled all 479 matched source files in `src/matched/` with each flag combination
2. Extracted function bytes from compiled `.o` files using `objdump -d`
3. Compared each function's bytes against the original DOL at the annotated address
4. Counted exact byte matches, same-size-different-bytes, and size mismatches

### Tools Used

- `tools/flag_sweep.py` - Automated flag sweep across all matched sources
- `tools/categorize_diffs.py` - Categorized instruction-level differences
- `tools/compare_obj_vs_dol.py` - Per-function byte comparison (.o vs DOL)

## Detailed Findings

### Why `-fno-schedule-insns` Helps

SN Systems ProDG does not aggressively reorder instructions within basic blocks. It
generates stores roughly in source order. GCC's instruction scheduler reorders stores
and loads for pipeline efficiency. Disabling scheduling produces code closer to SN output.

Example - `ESimsApp::TakeBigScreenshot(int, int)`:

```
// Source: *(this+0x4A4) = p5; *(this+0x49C) = 1; *(this+0x4A0) = p4;

// Original (SN Systems): follows source order
li   r0,1          // constant loaded eagerly
stw  r5,0x4A4(r3)  // p5 store first (as written)
stw  r0,0x49C(r3)  // constant store
stw  r4,0x4A0(r3)  // p4 store last
blr

// GCC -O2 (scheduler ON): reorders for pipeline
li   r9,1
stw  r4,0x4A0(r3)  // p4 moved first
stw  r5,0x4A4(r3)  // p5 second
stw  r9,0x49C(r3)  // constant last
blr

// GCC -O2 -fno-schedule-insns: closer to source order
stw  r5,0x4A4(r3)  // p5 first (matches SN!)
li   r9,1
stw  r9,0x49C(r3)  // constant (matches SN position!)
stw  r4,0x4A0(r3)  // p4 last (matches SN!)
blr
```

### Why `-fno-inline` Helps

SN Systems has different inlining heuristics. Some functions that GCC inlines at `-O2` are
not inlined by SN. Disabling GCC inlining prevents cases where GCC creates a different
number of functions than the original, which would cause size mismatches.

### Irreversible GCC-vs-SN Differences

The following differences **cannot be fixed with compiler flags**:

#### 1. Register Allocation: r9 vs r0 (220+ affected instructions)

SN Systems freely uses r0 as a general-purpose scratch register. GCC's PPC backend reserves
r0 because it reads as literal 0 in certain instruction forms (base register of loads/stores).
GCC uses r9 as the first scratch register instead.

```
// Original (SN): uses r0 for constants
li   r0,0           // 0x38000000
stw  r0,0(r3)       // 0x90030000

// GCC: always uses r9+ for constants
li   r9,0           // 0x39200000
stw  r9,0(r3)       // 0x91230000
```

This is the single largest category of mismatch. No GCC flag changes this behavior;
it is hardcoded in the PPC backend's register allocator. Even `-ffixed-r9` just shifts
allocation to r10 -- r0 is never used as a general GPR.

**Mitigation**: For critical functions, use inline assembly to force r0 usage.

#### 2. Address Loading: `ori` vs `addi`

SN uses `lis + addi` to construct 32-bit addresses. GCC uses `lis + ori`. Both produce
correct results but different bytes.

```
// Original (SN): lis + addi
lis  r3, 0x803E      // adjusts high half for sign extension
addi r3, r3, -0x4D90 // signed add

// GCC: lis + ori
lis  r3, 0x803D      // direct high half
ori  r3, r3, 0xB270  // unsigned OR (no sign extension concern)
```

This affects all hardcoded address loads. In practice, most addresses should come through
linker relocations which both handle correctly. Functions returning string literal pointers
are the main exception.

#### 3. Prologue/Epilogue: stmw/lmw vs stw/lwz

SN uses `stmw` (store multiple word) and `lmw` (load multiple word) to save/restore
callee-saved registers. GCC always uses individual `stw`/`lwz` instructions. Even the
`-mmultiple` flag does not change this in modern GCC.

```
// Original (SN): compact register save
stmw r30, 8(r1)    // save r30-r31 in one instruction
...
lmw  r30, 8(r1)    // restore r30-r31 in one instruction

// GCC: individual saves
stw  r30, 8(r1)
stw  r31, 12(r1)
...
lwz  r30, 8(r1)
lwz  r31, 12(r1)
```

This affects any non-leaf function that saves 2+ callee-saved registers. The SN version
is shorter by (N-1)*4 bytes for N saved registers.

**Mitigation**: For critical functions, write the prologue/epilogue in inline assembly.

#### 4. SDA Register Access (r13/r2)

SN Systems uses r13-relative addressing (SDA - Small Data Area) for global variables.
GCC can generate SDA accesses but the linker/symbol handling differs. Functions like
`ESimsApp::GetStartLot()` that load globals via `lwz r3, -26908(r13)` cannot be
matched without correct SDA symbol resolution.

### Mismatch Categories (496 same-size functions)

| Category | Count | Description |
|----------|-------|-------------|
| REG_ALLOC: stw r9 vs r0 | 113 | Store using wrong scratch register |
| OPCODE_DIFF: ori vs addi | 61 | Address loading pattern |
| REG_ALLOC: li r9 vs r0 | 98 | Constant load using wrong register |
| OPCODE_DIFF: various | 107 | Wrong source code (offsets, etc.) |
| BIT_MANIP: rlwinm | 35 | Bitfield extract differences |
| REG_ALLOC: other | 20 | Other register differences |

## Flags That Were Tested But Did Not Help

The following flags were tested in combination with `-O2 -fno-schedule-insns
-fno-schedule-insns2 -fno-inline -fno-inline-small-functions` and produced
identical results (1114 matches):

- `-fno-peephole -fno-peephole2`
- `-fno-optimize-sibling-calls`
- `-fno-reorder-blocks -fno-reorder-functions`
- `-fno-crossjumping`
- `-fno-if-conversion -fno-if-conversion2`
- `-fno-dce -fno-dse`
- `-fno-gcse`
- `-fno-rerun-cse-after-loop`
- `-fomit-frame-pointer`
- `-fno-omit-frame-pointer` (hurts -- adds unnecessary frame setup)
- `-mno-eabi`
- `-msdata=none -G0`
- `-ffixed-r2 -ffixed-r13`
- `-fno-strict-aliasing`
- `-fno-caller-saves`
- `-freg-struct-return`
- `-fira-algorithm=priority` / `-fira-algorithm=CB`
- `-fno-tree-fre -fno-tree-pre`
- `-fno-combine-stack-adjustments`
- `-fno-rename-registers`
- `-fno-tree-coalesce-vars`
- `-mrelocatable`
- `-mmultiple`
- `-fno-section-anchors`
- `-fno-function-cse`
- `-fno-delayed-branch`
- `-fcall-used-r0` / `-fcall-used-r9` / `-ffixed-r9`

## Recommendations

### Short Term
1. Use the best flags: `-O2 -fno-schedule-insns -fno-schedule-insns2 -fno-inline
   -fno-inline-small-functions`
2. Focus on writing correct C++ source that produces same-size output. Many mismatches
   (776 out of 2371) are size differences, meaning the C++ source itself is wrong.

### Medium Term
1. For functions that only differ in r9-vs-r0, consider a post-processing tool that
   patches the register field in the compiled object files
2. For functions with SDA access, set up proper SDA symbols so the linker generates
   correct r13/r2-relative accesses
3. Fix the skeleton linking so compiled functions replace their stubs at the correct
   addresses

### Long Term
1. Consider a custom GCC patch to the PPC backend that uses r0 for leaf-function
   scratch registers (would fix ~220 instruction mismatches)
2. Or use a post-link binary patching tool for the systematic r9->r0 differences
3. The stmw/lmw difference requires either inline assembly or a custom GCC patch

## Appendix: SN Systems ProDG Codegen Patterns

Common patterns observed in the original binary:

1. **r0 for scratch**: `li r0, <const>; stw r0, off(rN)` -- always r0, not r9
2. **r9-r12 for temps**: Multi-value operations use r9, r10, r11, r12
3. **`mr rN, r3` early**: Saves `this` pointer to callee-saved reg immediately
4. **No scheduling**: Stores follow source order within basic blocks
5. **stmw/lmw**: Compact register save/restore in prologue/epilogue
6. **lis+addi**: Address construction uses sign-extending `addi`, not `ori`
7. **SDA via r13**: Small globals accessed via r13-relative addressing
8. **crclr before varargs**: `crclr 4*cr1+eq` before variadic function calls
