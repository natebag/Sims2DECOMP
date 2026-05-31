// COMPILER: mwcc
// 0x80266F18 AIGetDMAEnableFlag (16B) — Dolphin SDK ai/ai.c
//
// Reads the AI DMA control register (0xCC005036) and returns its enable bit.
// The constant address folds to lis+lhz. MWCC GC-1.2.5n.

extern "C" unsigned int AIGetDMAEnableFlag(void) {
    return (*(volatile unsigned short*)0xCC005036 >> 15) & 1;
}
