// 0x800D40D0 NghResFile::FlushAllData(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,0; bl _s800D40D0_0; mr 3,30; li 4,1; bl _s800D40D0_1; mr 3,30; li 4,2; bl _s800D40D0_2; li 4,3; mr 3,30; bl _s800D40D0_3; lwz 3,0x190(30); bl _s800D40D0_4; mr 3,30; bl _s800D40D0_5; mr 3,30; li 4,1; bl _s800D40D0_6; mr 3,30; bl _s800D40D0_7; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800D40D0_0();
extern "C" void _s800D40D0_1();
extern "C" void _s800D40D0_2();
extern "C" void _s800D40D0_3();
extern "C" void _s800D40D0_4();
extern "C" void _s800D40D0_5();
extern "C" void _s800D40D0_6();
extern "C" void _s800D40D0_7();
extern "C" void f_800D40D0() {}
