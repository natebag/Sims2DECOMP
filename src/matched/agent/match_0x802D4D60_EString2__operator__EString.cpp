// 0x802D4D60 EString2::operator+(EString (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); lwz 30,0x0(4); addi 29,1,8; mr 28,3; lwz 4,0x0(5); mr 3,29; bl _s802D4D60_0; lwz 5,0x8(1); mr 4,30; mr 3,28; bl _s802D4D60_1; lwz 4,0x8(1); mr 3,29; bl _s802D4D60_2; mr 3,28; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s802D4D60_0();
extern "C" void _s802D4D60_1();
extern "C" void _s802D4D60_2();
extern "C" void f_802D4D60() {}
