// COMPILER: mwcc
// 0x8037E244 DSPReadCPUToDSPMbox (20B) — Dolphin SDK dsp/dsp.c
//
// Reads the 32-bit CPU→DSP mailbox. DOL uses lhzu to load hi16 and update base,
// then lhz for lo16. Extern array at HW base avoids constant-fold.

extern volatile unsigned short __DSPCPUMailbox[];

extern "C" unsigned int DSPReadCPUToDSPMbox(void) {
    volatile unsigned short *p = __DSPCPUMailbox;
    unsigned int hi = *p++;
    unsigned int lo = *p;
    return (hi << 16) | lo;
}
