// COMPILER: mwcc
// 0x8024F918 OSGetInterruptMask (12B) — Dolphin SDK os/OSInterrupt.c
//
// Returns the current OS interrupt mask cached in low memory at 0x800000C8.
// Absolute lis/lwz, no relocation. MWCC GC-1.2.5n.

extern "C" unsigned int OSGetInterruptMask(void) {
    return *(unsigned int*)0x800000C8;
}
