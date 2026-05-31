// COMPILER: mwcc
// 0x8024BC48 OSGetDIConfig (20B) — Dolphin SDK os/OSExec.c / DI
//
// Returns the low byte of the DI configuration register (DICFG, index 9 of the
// DI hardware register block at 0xCC006000). Declaring __DIRegs as an extern
// array (a relocated symbol) makes MWCC materialise the base via lis/addi then
// index it (lwz 0x24) — rather than folding the constant address — matching the
// DOL's lis/addi/lwz/clrlwi. MWCC GC-1.2.5n.

extern volatile unsigned int __DIRegs[];

extern "C" unsigned int OSGetDIConfig(void) {
    return __DIRegs[9] & 0xFF;
}
