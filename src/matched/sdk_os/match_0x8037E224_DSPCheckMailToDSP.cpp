// COMPILER: mwcc
// 0x8037E224 DSPCheckMailToDSP (16B) — Dolphin SDK dsp/dsp.c
//
// Checks if the CPU-to-DSP mailbox is ready (returns bit 15 of DSP CSR at 0xCC005000).

extern "C" unsigned int DSPCheckMailToDSP(void) {
    return (*(volatile unsigned short*)0xCC005000 >> 15) & 1;
}
