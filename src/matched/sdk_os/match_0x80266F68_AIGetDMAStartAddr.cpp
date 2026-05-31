// COMPILER: mwcc
// 0x80266F68 AIGetDMAStartAddr (28B) — Dolphin SDK ai/ai.c
//
// Reads the two AI DMA start-address registers (0xCC005030 hi, 0xCC005032 lo)
// and reassembles the 26-bit aligned address. The register block base is
// materialised once (lis+addi) and reused for both halfword loads, so it is
// declared as an extern array rather than a constant pointer. MWCC GC-1.2.5n.

extern volatile unsigned short __AIRegs[];

extern "C" unsigned int AIGetDMAStartAddr(void) {
    return ((__AIRegs[24] & 0x03FF) << 16) | (__AIRegs[25] & 0xFFE0);
}
