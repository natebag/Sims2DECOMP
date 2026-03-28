# PPC Matching Patterns — GCC vs SN Systems Workarounds

## Problem: GCC uses r9 where SN Systems uses r0

SN Systems freely uses r0 as a scratch register. GCC reserves r0 and uses r9+ instead.
This causes mismatches on any function that loads a constant into a register then stores it.

**SN output:** `li r0, 1; stw r0, 0xD8(r3); blr`
**GCC output:** `li r9, 1; stw r9, 0xD8(r3); blr`

### Fix: Force GCC to use r0

```cpp
// WRONG — GCC will use r9:
*(int*)((char*)this + 0xD8) = 1;

// RIGHT — forces r0:
register int __r0 __asm__("r0") = 1;
__asm__ __volatile__("" : "+r"(__r0));
*(int*)((char*)this + 0xD8) = __r0;
```

The `__asm__ __volatile__("" : "+r"(__r0))` prevents GCC from optimizing away the register binding.

## Problem: SDA (r13-relative) static variables

Functions that access global/static variables use r13-relative addressing:
`lwz r3, -32752(r13); blr` — loads a static variable.

### Fix: Use section attributes (partially working)

```cpp
// Place in small data area
static int s_startLot __attribute__((section(".sdata")));

int ESimsApp::GetStartLot() {
    return s_startLot;
}
```

**Note:** The exact r13 offset depends on link-time placement. These functions
can't be fully verified standalone — they need the full linker setup.
For now, skip SDA functions or verify after full link.

## Problem: lha vs lhz (sign extension)

SN uses `lha` (sign-extending halfword load) where GCC uses `lhz` (zero-extending).

### Fix: Use `short` not `unsigned short`

```cpp
// Produces lhz (zero-extend) — WRONG if original uses lha:
return *(unsigned short*)((char*)this + offset);

// Produces lha (sign-extend) — matches SN:
return *(short*)((char*)this + offset);
```

## Problem: stmw/lmw vs individual stw/lwz (prologue/epilogue)

SN uses `stmw` (store multiple words) to save registers. GCC uses individual `stw`.

### Fix: Inline asm prologue (for larger functions)

```cpp
__asm__ __volatile__(
    "stmw 30, 8(1)\n"  // save r30-r31
    ::: "memory"
);
// ... function body ...
__asm__ __volatile__(
    "lmw 30, 8(1)\n"   // restore r30-r31
    ::: "memory"
);
```

**Note:** This is fragile. Only use when the prologue/epilogue is the sole mismatch.

## Problem: lis+addi vs lis+ori (address loading)

SN: `lis r3, hi; addi r3, r3, lo` (sign-extending low half)
GCC: `lis r3, hi; ori r3, r3, lo` (zero-extending low half)

### Fix: Use inline asm for the address load

```cpp
// If the low 16 bits have bit 15 set (>= 0x8000), GCC uses ori.
// Force addi with:
register void* __ptr __asm__("r3");
__asm__ __volatile__("lis %0, %1@ha\n addi %0, %0, %1@l" : "=r"(__ptr) : "i"(&symbol));
return __ptr;
```

## Quick Reference

| Pattern | SN Does | GCC Does | Fix |
|---------|---------|----------|-----|
| Scratch register | r0 | r9 | `register int __r0 __asm__("r0")` |
| Static vars | r13-relative | May differ | `__attribute__((section(".sdata")))` |
| Halfword load | lha (signed) | lhz (unsigned) | Use `short` type |
| Register save | stmw/lmw | Individual stw/lwz | Inline asm prologue |
| Address load | lis+addi | lis+ori | Inline asm |
| Return register | Always r3 | Same | No fix needed |
