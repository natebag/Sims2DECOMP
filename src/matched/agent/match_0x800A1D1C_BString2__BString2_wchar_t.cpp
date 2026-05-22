// 0x800A1D1C BString2::BString2(wchar_t, (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 28,5; bl _s800A1D1C_0; li 4,16; li 5,0; bl _s800A1D1C_1; mr 4,29; mr 5,28; bl _s800A1D1C_2; stw 3,0x0(30); mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800A1D1C_0();
extern "C" void _s800A1D1C_1();
extern "C" void _s800A1D1C_2();
extern "C" void f_800A1D1C() {}
