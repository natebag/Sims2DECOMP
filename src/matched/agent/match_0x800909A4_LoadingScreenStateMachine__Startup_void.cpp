// 0x800909A4 LoadingScreenStateMachine::Startup(void) (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,3; li 30,0; li 3,28; li 29,-1; bl _s800909A4_0; li 28,1; lis 11,-32698; mr 9,3; addi 11,11,-9736; mr 4,9; stw 11,0x18(9); mr 3,27; stw 30,0x0(9); stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 28,0x14(9); bl _s800909A4_1; li 3,28; bl _s800909A4_2; lis 11,-32698; mr 9,3; addi 11,11,-9808; mr 4,9; stw 11,0x18(9); mr 3,27; stw 28,0x0(9); stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 28,0x14(9); bl _s800909A4_3; li 3,28; bl _s800909A4_4; lis 11,-32698; mr 9,3; addi 11,11,-9880; li 0,2; mr 4,9; stw 0,0x0(9); stw 11,0x18(9); mr 3,27; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 28,0x14(9); bl _s800909A4_5; li 3,28; bl _s800909A4_6; lis 11,-32698; mr 9,3; addi 11,11,-9952; li 0,3; mr 4,9; stw 0,0x0(9); stw 29,0xc(9); mr 3,27; stw 30,0x10(9); stw 28,0x14(9); stw 11,0x18(9); stw 29,0x4(9); stw 30,0x8(9); bl _s800909A4_7; lis 9,-32706; mr 3,27; lfs f1,-32600(9); li 4,0; bl _s800909A4_8; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800909A4_0();
extern "C" void _s800909A4_1();
extern "C" void _s800909A4_2();
extern "C" void _s800909A4_3();
extern "C" void _s800909A4_4();
extern "C" void _s800909A4_5();
extern "C" void _s800909A4_6();
extern "C" void _s800909A4_7();
extern "C" void _s800909A4_8();
extern "C" void f_800909A4() {}
