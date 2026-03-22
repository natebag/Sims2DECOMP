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

## Unfixed Patterns (Remaining ~333 functions)

### Pattern A: lis+ori vs lis+addi (Address Loading)
GCC loads 32-bit constants with `lis+ori`; SN uses `lis+addi` with HA/LO
relocations. ~107 functions affected. Fix requires either using extern symbol
references (with @ha/@l relocations) or inline asm for the address load.

### Pattern B: SDA Global Returns
~32 functions return a global variable via `lwz r3,offset(r13)` (SDA access)
but our source code returns literal 0. Need to identify the SDA globals and
return them instead.

### Pattern C: Wrong Struct Offsets
~53 functions have the right instruction but wrong memory offset, meaning the
auto-matcher assigned the wrong field offsets. Needs manual review against the
original binary.

### Pattern D: Bitfield Extraction
~35 functions have `rlwinm` with wrong shift/mask values, indicating the
bitfield position was guessed incorrectly. Needs verification against the
original.

### Pattern E: Instruction Reordering
~1 function has independent instructions in the wrong order, which cannot be
fixed with `-fno-schedule-insns` alone.

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
| Before fixes | 1114 | 47.0% |
| After r0 fixes + improved comparison | 1268 | 53.5% |
| Delta | +154 | +6.5% |
