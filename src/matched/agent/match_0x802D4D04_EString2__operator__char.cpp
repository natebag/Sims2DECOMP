// 0x802D4D04 EString2::operator+(char (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); addi 28,1,8; mr 30,3; lwz 29,0x0(4); mr 3,28; mr 4,5; bl _s802D4D04_0; lwz 5,0x8(1); mr 4,29; mr 3,30; bl _s802D4D04_1; lwz 4,0x8(1); mr 3,28; bl _s802D4D04_2; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s802D4D04_0();
extern "C" void _s802D4D04_1();
extern "C" void _s802D4D04_2();
extern "C" void f_802D4D04() {}
