// 0x800A1CD0 BString2::BString2(unsigned (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; bl _s800A1CD0_0; li 5,0; li 4,16; bl _s800A1CD0_1; mr 4,30; bl _s800A1CD0_2; stw 3,0x0(29); mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800A1CD0_0();
extern "C" void _s800A1CD0_1();
extern "C" void _s800A1CD0_2();
extern "C" void f_800A1CD0() {}
