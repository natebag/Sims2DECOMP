// COMPILER: mwcc
// 0x80266FE0 AIGetStreamSampleCount (16B) — Dolphin SDK ai/ai.c
//
// Returns the AI/DSP stream sample-count register (__DSPRegs block at
// 0xCC006C00, word index 2). Base materialised via lis+addi. MWCC GC-1.2.5n.

extern volatile unsigned int __DSPRegs[];

extern "C" unsigned int AIGetStreamSampleCount(void) {
    return __DSPRegs[2];
}
