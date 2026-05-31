// COMPILER: mwcc
// 0x802670FC AIGetStreamPlayState (16B) — Dolphin SDK ai/ai.c
//
// Reads the AI/DSP stream control register (0xCC006C00) and returns the play
// bit. MWCC GC-1.2.5n.

extern "C" unsigned int AIGetStreamPlayState(void) {
    return *(volatile unsigned int*)0xCC006C00 & 1;
}
