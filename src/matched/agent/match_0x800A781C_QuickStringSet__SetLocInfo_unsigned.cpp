// 0x800A781C QuickStringSet::SetLocInfo(unsigned (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lwz 11,-21508(13); mr 26,3; mr 30,5; mr 29,6; lwz 9,0x0(11); mr 28,7; mr 27,8; lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 5,30; mr 3,26; mr 6,29; mr 7,28; mr 8,27; bl _s800A781C_0; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800A781C_0();
extern "C" void f_800A781C() {}
