// COMPILER: mwcc
// 0x80252544 OSSyncSram (16B) — Dolphin SDK os/OSSram.c
//
// Returns the offset/status word of the SRAM control block. The control block
// is an extern (relocated) symbol at 0x80499F80; the returned word lives at
// +0x4C (index 19). Declaring it as an extern array makes MWCC materialise the
// base (lis/addi) then load the field (lwz 0x4C) rather than folding to a
// single absolute load. MWCC GC-1.2.5n.

extern unsigned int __SramControl[];

extern "C" unsigned int OSSyncSram(void) {
    return __SramControl[19];
}
