// 0x802D2D40 EString::Empty(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 4,0x0(30); bl _s802D2D40_0; mr 3,30; bl _s802D2D40_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D2D40_0();
extern "C" void _s802D2D40_1();
extern "C" void f_802D2D40() {}
