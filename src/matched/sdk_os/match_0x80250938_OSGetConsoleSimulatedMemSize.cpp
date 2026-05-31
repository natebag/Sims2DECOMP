// COMPILER: mwcc
// 0x80250938 OSGetConsoleSimulatedMemSize (12B) — Dolphin SDK os/OSMemory.c
//
// Returns the console simulated memory size cached in low memory at 0x800000F0.
// Absolute lis/lwz, no relocation. MWCC GC-1.2.5n.

extern "C" unsigned int OSGetConsoleSimulatedMemSize(void) {
    return *(unsigned int*)0x800000F0;
}
