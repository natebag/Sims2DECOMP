// 0x8009E1B4 BString::insert(unsigned (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,5; mr 28,3; mr 30,6; mr 27,4; mr 29,7; mr 3,31; bl _s8009E1B4_0; cmplw 30,3; ble 0f; bl _s8009E1B4_1; 0:; mr 3,31; bl _s8009E1B4_2; subf 3,30,3; cmplw 29,3; ble 1f; mr 3,31; bl _s8009E1B4_3; subf 29,30,3; 1:; mr 3,31; bl _s8009E1B4_4; add 5,3,30; mr 4,27; mr 3,28; mr 6,29; bl _s8009E1B4_5; mr 3,28; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8009E1B4_0();
extern "C" void _s8009E1B4_1();
extern "C" void _s8009E1B4_2();
extern "C" void _s8009E1B4_3();
extern "C" void _s8009E1B4_4();
extern "C" void _s8009E1B4_5();
extern "C" void f_8009E1B4() {}
