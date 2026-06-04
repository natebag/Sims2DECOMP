// COMPILER: mwcc
// 0x8037E234 DSPCheckMailFromDSP (16B) — Dolphin SDK dsp/dsp.c
//
// Checks if DSP has mail for CPU (returns bit 15 of DSP mailbox reg at 0xCC005004).

extern "C" unsigned int DSPCheckMailFromDSP(void) {
    return (*(volatile unsigned short*)0xCC005004 >> 15) & 1;
}
