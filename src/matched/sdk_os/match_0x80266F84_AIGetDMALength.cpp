// COMPILER: mwcc
// 0x80266F84 AIGetDMALength (16B) — Dolphin SDK ai/ai.c
//
// Reads the AI DMA length register (0xCC005036) and returns the byte length
// (15-bit field scaled by 32). MWCC GC-1.2.5n.

extern "C" unsigned int AIGetDMALength(void) {
    return (*(volatile unsigned short*)0xCC005036 & 0x7FFF) << 5;
}
