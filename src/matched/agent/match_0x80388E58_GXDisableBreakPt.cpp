// 0x80388E58 GXDisableBreakPt (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s80388E58_0; lwz 4,-17720(13); li 5,0; lwz 0,0x8(4); rlwimi 0,5,1,30,30; stw 0,0x8(4); lwz 0,0x8(4); rlwimi 0,5,5,26,26; stw 0,0x8(4); lwz 0,0x8(4); lwz 4,-21996(13); sth 0,0x2(4); stw 5,-21932(13); bl _s80388E58_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80388E58_0();
extern "C" void _s80388E58_1();
extern "C" void f_80388E58() {}
