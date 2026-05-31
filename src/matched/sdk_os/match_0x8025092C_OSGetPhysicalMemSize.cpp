// COMPILER: mwcc
// 0x8025092C OSGetPhysicalMemSize (12B) — Dolphin SDK os/OSMemory.c
//
// Returns the physical memory size cached in low memory at 0x80000028.
// Absolute lis/lwz, no relocation. MWCC GC-1.2.5n.

extern "C" unsigned int OSGetPhysicalMemSize(void) {
    return *(unsigned int*)0x80000028;
}
