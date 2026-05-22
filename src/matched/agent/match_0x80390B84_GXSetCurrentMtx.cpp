// 0x80390B84 GXSetCurrentMtx (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); lwz 4,-17720(13); lwz 0,0x80(4); rlwimi 0,3,0,26,31; li 3,0; stw 0,0x80(4); bl _s80390B84_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80390B84_0();
extern "C" void f_80390B84() {}
