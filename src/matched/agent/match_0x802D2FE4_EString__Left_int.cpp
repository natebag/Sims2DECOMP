// 0x802D2FE4 EString::Left(int) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 28,3; addi 30,1,8; mr 29,5; mr 3,4; bl _s802D2FE4_0; mr 4,3; mr 3,30; bl _s802D2FE4_1; lwz 9,0x8(1); li 0,0; mr 3,30; stbx 0,9,29; bl _s802D2FE4_2; mr 4,3; mr 3,28; bl _s802D2FE4_3; lwz 4,0x8(1); mr 3,30; bl _s802D2FE4_4; mr 3,28; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s802D2FE4_0();
extern "C" void _s802D2FE4_1();
extern "C" void _s802D2FE4_2();
extern "C" void _s802D2FE4_3();
extern "C" void _s802D2FE4_4();
extern "C" void f_802D2FE4() {}
