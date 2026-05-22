// 0x8029985C AptDisplayListState::insert(int, (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; mr 28,4; mr 29,5; li 5,0; addi 6,1,8; addi 7,1,12; bl _s8029985C_0; lwz 4,0x8(1); mr 3,30; mr 5,29; bl _s8029985C_1; mr 9,3; lwz 0,0x58(9); rlwimi 0,28,15,0,16; stw 0,0x58(9); lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8029985C_0();
extern "C" void _s8029985C_1();
extern "C" void f_8029985C() {}
