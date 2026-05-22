// 0x802D46D8 EString2::operator=(wchar_t) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); sth 4,0x8(1); addi 9,1,8; li 0,0; mr 30,3; sth 0,0x2(9); mr 4,9; lwz 29,0x0(30); bl _s802D46D8_0; mr 3,30; mr 4,29; bl _s802D46D8_1; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802D46D8_0();
extern "C" void _s802D46D8_1();
extern "C" void f_802D46D8() {}
