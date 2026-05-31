// COMPILER: mwcc
// 0x80267374 AIGetStreamVolRight (16B) — Dolphin SDK ai/ai.c
//
// Reads the AI/DSP stream volume register (0xCC006C04) and returns the right
// channel (second byte). MWCC GC-1.2.5n.

extern "C" unsigned int AIGetStreamVolRight(void) {
    return (*(volatile unsigned int*)0xCC006C04 >> 8) & 0xFF;
}
