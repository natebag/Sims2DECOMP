// 0x80261BEC DVDLowSetResetCoverCallback (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s80261BEC_0; lwz 31,-23348(13); stw 30,-23348(13); bl _s80261BEC_1; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80261BEC_0();
extern "C" void _s80261BEC_1();
extern "C" void f_80261BEC() {}
