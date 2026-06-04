// COMPILER: mwcc
// 0x8037E454 DSPGetDMAStatus (16B) — Dolphin SDK dsp/dsp.c
//
// Returns bit 9 (0x200) of the DSP DMA control register at 0xCC00500A.

extern "C" unsigned int DSPGetDMAStatus(void) {
    return *(volatile unsigned short*)0xCC00500A & 0x200;
}
