// 0x80388DCC GXEnableBreakPt (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s80388DCC_0; mr 31,3; bl _s80388DCC_1; lwz 3,-21996(13); rlwinm 0,30,16,18,31; sth 30,0x3c(3); li 3,1; lwz 4,-21996(13); sth 0,0x3e(4); lwz 4,-17720(13); lwz 0,0x8(4); rlwimi 0,3,1,30,30; stw 0,0x8(4); lwz 0,0x8(4); rlwimi 0,3,5,26,26; stw 0,0x8(4); lwz 0,0x8(4); lwz 3,-21996(13); sth 0,0x2(3); stw 30,-21932(13); bl _s80388DCC_2; mr 3,31; bl _s80388DCC_3; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80388DCC_0();
extern "C" void _s80388DCC_1();
extern "C" void _s80388DCC_2();
extern "C" void _s80388DCC_3();
extern "C" void f_80388DCC() {}
