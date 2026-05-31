// COMPILER: mwcc
// 0x802671EC AIGetDSPSampleRate (20B) — Dolphin SDK ai/ai.c
//
// Reads the AI DSP control register (0xCC006C00) and returns the sample-rate
// selector bit, inverted. MWCC GC-1.2.5n.

extern "C" unsigned int AIGetDSPSampleRate(void) {
    return ((*(volatile unsigned int*)0xCC006C00 >> 6) & 1) ^ 1;
}
