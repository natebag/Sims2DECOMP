// COMPILER: mwcc
// 0x80266FF0 AIResetStreamSampleCount (24B) — Dolphin SDK ai/ai.c
//
// Clears then sets bit 5 (0x20) of AI stream control register at 0xCC006C00.
// Uses direct constant address (no addi); DOL uses lwz r0, 0x6C00(r3) / stw form.

extern "C" void AIResetStreamSampleCount(void) {
    unsigned int reg = *(volatile unsigned int*)0xCC006C00;
    reg = (reg & ~0x20) | 0x20;
    *(volatile unsigned int*)0xCC006C00 = reg;
}
