// COMPILER: mwcc
// 0x80267348 AIGetStreamVolLeft (16B) — Dolphin SDK ai/ai.c
//
// Reads the AI/DSP stream volume register (0xCC006C04) and returns the left
// channel (low byte). MWCC GC-1.2.5n.

extern "C" unsigned int AIGetStreamVolLeft(void) {
    return *(volatile unsigned int*)0xCC006C04 & 0xFF;
}
