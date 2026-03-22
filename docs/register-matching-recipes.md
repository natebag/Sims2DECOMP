# Register Matching Recipes: GCC vs SN Systems

## Overview

The Sims 2 GameCube was compiled with SN Systems ProDG (SN-NGC). We're using
devkitPPC (GCC 15.2.0). Many functions compile to the correct size but have
register allocation differences. This document catalogs the patterns and their
C++ workarounds.

## Recipe 1: Constant Store (r9 -> r0)

**Symptom:** GCC uses r9 for small integer constants stored to memory; SN uses r0.

**Example (SN Systems):**
```
li r0,1
stw r0,0xD8(r3)
blr
```

**GCC produces:**
```
li r9,1
stw r9,0xD8(r3)
blr
```

**Fix:** Bind the constant to r0 with an asm constraint:
```cpp
// Before (GCC uses r9):
*(int*)((char*)this + 0xD8) = 1;

// After (GCC uses r0):
register int __r0 __asm__("r0") = 1;
__asm__ __volatile__("" : "+r"(__r0));
*(int*)((char*)this + 0xD8) = __r0;
```

**Why it works:** `register int __r0 __asm__("r0")` hints GCC to use r0. The
empty asm volatile with `"+r"(__r0)` prevents GCC from optimizing away the
register binding. Without the asm barrier, GCC ignores the hint.

**Functions fixed:** ~93 (constant stores like SetFlag, Hide, Show, Reset, Init)

---

## Recipe 2: Reorder + Constant Store

**Symptom:** GCC emits the parameter store first, then li+stw for the constant.
SN emits li first, then parameter store, then stw.

**Example (SN Systems):**
```
li r0,1          ; load constant first
stw r4,0(r3)     ; then store parameter
stb r0,0x318(r3) ; then store constant
blr
```

**GCC produces:**
```
stw r4,0(r3)     ; parameter store first
li r9,1           ; then load constant (using r9)
stb r9,0x318(r3) ; then store constant
blr
```

**Fix:** Declare the r0 register variable BEFORE any stores:
```cpp
// Before:
*(int*)((char*)this + 0x0) = (int)p4;
*(char*)((char*)this + 0x318) = 1;

// After:
register int __r0 __asm__("r0") = 1;
__asm__ __volatile__("" : "+r"(__r0));
*(int*)((char*)this + 0x0) = (int)p4;
*(char*)((char*)this + 0x318) = __r0;
```

**Why it works:** GCC generates instructions in declaration order when
`-fno-schedule-insns` is active. By declaring `__r0` first, the `li r0,1`
is emitted before the `stw r4` parameter store.

**Functions fixed:** ~12 (functions with parameter + constant stores)

---

## Recipe 3: Member-to-Member Copy (r9 -> r0)

**Symptom:** GCC uses r9 for the temporary when copying one member to another.
SN uses r0.

**Example (SN Systems):**
```
lwz r0,0x84(r3)
stw r0,0x88(r3)
blr
```

**Fix:** Same r0 binding pattern:
```cpp
// Before:
*(int*)((char*)this + 0x88) = *(int*)((char*)this + 0x84);

// After:
register int __r0 __asm__("r0") = *(int*)((char*)this + 0x84);
__asm__ __volatile__("" : "+r"(__r0));
*(int*)((char*)this + 0x88) = __r0;
```

**Functions fixed:** 3

---

## Recipe 4: Two Constants (r0 + r9)

**Symptom:** Function stores two different constants. SN uses r0 for the first
and r9 for the second. GCC uses r9 for both, reusing it.

**Example (SN Systems):**
```
li r0,0
li r9,1
stw r0,0x250(r3)
stw r9,0x90(r3)
blr
```

**Fix:** Bind both registers explicitly:
```cpp
register int __r0 __asm__("r0") = 0;
__asm__ __volatile__("" : "+r"(__r0));
register int __r9 __asm__("r9") = 1;
__asm__ __volatile__("" : "+r"(__r9));
*(int*)((char*)this + 0x250) = __r0;
*(int*)((char*)this + 0x90) = __r9;
```

**Functions fixed:** ~2

---

## Recipe 5: lis+ori vs lis+addi (Address Loading) — FIXED

**Symptom:** GCC uses `lis+ori` to construct 32-bit addresses; SN uses `lis+addi`
with sign-extended lower half. Both produce the same value but different bytes.

**Example (SN Systems):**
```
lis r3, -32688       ; 0x8050 << 16
addi r3, r3, -12624  ; + sign_extend(0xCEB0)
blr                  ; returns 0x804FCEB0
```

**GCC produces:**
```
lis r3, -32687       ; 0x8051 << 16
ori r3, r3, 0xCEB0   ; | 0xCEB0
blr                  ; returns 0x8050CEB0 (same value!)
```

**Fix:** Use inline asm to force the `lis+addi` encoding:
```cpp
void* GetTypeInfoStatic() {
    void* __p;
    __asm__ __volatile__(
        "lis %0, -32688\n"
        "addi %0, %0, -12624"
        : "=r"(__p)
    );
    return __p;
}
```

**Functions fixed:** ~61

---

## Recipe 6: Global Pointer Load (lis+lwz vs lis+ori)

**Symptom:** SN loads a value through a global pointer: `lis r9, ha; lwz r3, lo(r9)`.
GCC constructs the address directly: `lis r3, ha; ori r3, r3, lo`.

**Fix:** Use inline asm with explicit register binding and clobber:
```cpp
int GetTypeName() const {
    register int __val __asm__("r3");
    __asm__ __volatile__(
        "lis %%r9, -32688\n"
        "lwz %0, -13028(%%r9)"
        : "=r"(__val)
        :
        : "r9"
    );
    return __val;
}
```

**Key detail:** The `register int __val __asm__("r3")` binding forces the output
into r3, and `"r9"` in the clobber list prevents GCC from reusing r9 for the output.
Without the clobber, GCC produces `lwz r9, off(r9)` instead of `lwz r3, off(r9)`.

**Functions fixed:** ~50

---

## Recipe 7: SDA Global Returns

**Symptom:** SN accesses Small Data Area globals via r13: `lwz r3, off(r13)`.
Our code returns a literal 0 (`li r3, 0`).

**Fix:** Use inline asm to emit the SDA load:
```cpp
int GetGlobNamespaceID() {
    register int __sda __asm__("r3");
    __asm__ __volatile__(
        "lwz %0, -31848(%%r13)"
        : "=r"(__sda)
    );
    return __sda;
}
```

**Functions fixed:** ~31

---

## Remaining Unfixed Patterns (~102 functions)

### Pattern A: Multi-instruction Complex (38 functions)
Functions with 3+ instruction diffs involving mixed opcode differences.
These require manual analysis of each function.

### Pattern B: Global Load with Half-Word (29 functions)
`GetTypeVersion()` functions using `lhz` (load halfword). GCC adds a
`clrlwi` (zero-extension) for `unsigned short` returns that SN omits.
Fix requires changing the return type declaration in headers.

### Pattern C: Multi Same-Op (16 functions)
Multiple instructions with the same opcode but different operands.
Usually indicates struct layout or parameter order differences.

### Pattern D: Same-Op Register Diff (3 functions)
Single instruction with correct opcode but different register.
Residual cases from inline asm allocation.

### Pattern E: Wrong Member Load (4 functions)
Source returns constant but should load from struct member.
Cross-matching artifacts from functions with identical sizes.

---

## Comparison Tool Improvement

The inject_matches.py tool was improved to use two-pass matching:
1. **Pass 1:** Exact byte matches (highest confidence) — matches compiled
   functions against DOL bytes, consuming only confirmed matches
2. **Pass 2:** Count remaining annotations

This fixed ~200 false negatives where same-size functions were being
cross-matched, hiding real byte matches.

---

## Compiler Flags

The following flags maximize matching:
```
-mcpu=750 -meabi -mhard-float -O2
-fno-exceptions -fno-rtti -fno-builtin
-fshort-wchar -nostdinc++
-fno-schedule-insns -fno-schedule-insns2
-fno-inline -fno-inline-small-functions
```

## Match Statistics

| Stage | Matches | Percentage |
|-------|---------|-----------|
| Before any fixes | 1114 | 47.0% |
| After r0 fixes + improved comparison | 1268 | 53.5% |
| After lis+addi, SDA, global load fixes | 1316 | 55.5% |
| After improved two-pass matching | 1530 | 64.5% |
| After register binding fixes (r3+clobber) | 1586 | 65.3% |
| **Current total** | **1586** | **65.3%** |
| Delta from baseline (1221) | **+365** | **+29.9%** |
