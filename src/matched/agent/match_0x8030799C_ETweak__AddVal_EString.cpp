// 0x8030799C ETweak::AddVal(EString (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 28,3; mr 26,5; mr 25,6; mr 27,4; li 3,12; bl _s8030799C_0; mr 30,3; addi 29,30,4; mr 3,29; bl _s8030799C_1; mr 4,26; stw 27,0x0(30); stw 25,0x8(30); mr 3,29; bl _s8030799C_2; mr 4,30; addi 3,28,12; bl _s8030799C_3; lwz 9,0x8(28); addi 9,9,1; stw 9,0x8(28); lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8030799C_0();
extern "C" void _s8030799C_1();
extern "C" void _s8030799C_2();
extern "C" void _s8030799C_3();
extern "C" void f_8030799C() {}
