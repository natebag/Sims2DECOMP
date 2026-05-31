// COMPILER: mwcc
// 0x80267014 AIGetStreamTrigger (16B) — Dolphin SDK ai/ai.c
//
// Returns the AI/DSP stream trigger register (__DSPRegs block at 0xCC006C00,
// word index 3). Base materialised via lis+addi. MWCC GC-1.2.5n.

extern volatile unsigned int __DSPRegs[];

extern "C" unsigned int AIGetStreamTrigger(void) {
    return __DSPRegs[3];
}
