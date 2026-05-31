// COMPILER: mwcc
// 0x8026731C AIGetStreamSampleRate (16B) — Dolphin SDK ai/ai.c
//
// Reads the AI/DSP stream control register (0xCC006C00) and returns the
// sample-rate selector bit. MWCC GC-1.2.5n.

extern "C" unsigned int AIGetStreamSampleRate(void) {
    return (*(volatile unsigned int*)0xCC006C00 >> 1) & 1;
}
