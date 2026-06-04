// COMPILER: mwcc
// 0x8037E258 DSPReadMailFromDSP (24B) — Dolphin SDK dsp/dsp.c
//
// Reads 32-bit DSP→CPU mailbox as two halfwords.
// extern array at 0xCC005000 prevents constant-address fold → forces lis+addi;
// indices 2/3 give offsets +4/+6 from base.

extern volatile unsigned short __DSPMailboxFromDSP[];

extern "C" unsigned int DSPReadMailFromDSP(void) {
    return ((unsigned int)__DSPMailboxFromDSP[2] << 16) | __DSPMailboxFromDSP[3];
}
