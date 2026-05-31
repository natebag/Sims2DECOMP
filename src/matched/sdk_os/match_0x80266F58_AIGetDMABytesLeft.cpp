// COMPILER: mwcc
// 0x80266F58 AIGetDMABytesLeft (16B) — Dolphin SDK ai/ai.c
//
// Reads the AI DMA remaining-count register (0xCC00503A) and returns the byte
// count (15-bit field scaled by 32). MWCC GC-1.2.5n.

extern "C" unsigned int AIGetDMABytesLeft(void) {
    return (*(volatile unsigned short*)0xCC00503A & 0x7FFF) << 5;
}
