// 0x8009E688 BString::replace(unsigned (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,6; mr 28,3; mr 30,7; mr 27,4; mr 29,5; mr 25,8; mr 3,31; bl _s8009E688_0; cmplw 30,3; ble 0f; bl _s8009E688_1; 0:; mr 3,28; bl _s8009E688_2; subf 3,27,3; cmplw 29,3; ble 1f; mr 3,28; bl _s8009E688_3; subf 26,27,3; b 2f; 1:; mr 26,29; 2:; mr 3,31; bl _s8009E688_4; subf 3,30,3; cmplw 25,3; ble 3f; mr 3,31; bl _s8009E688_5; subf 29,30,3; b 4f; 3:; mr 29,25; 4:; mr 3,31; bl _s8009E688_6; add 6,3,30; mr 4,26; mr 3,28; mr 5,27; mr 7,29; bl _s8009E688_7; mr 3,28; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8009E688_0();
extern "C" void _s8009E688_1();
extern "C" void _s8009E688_2();
extern "C" void _s8009E688_3();
extern "C" void _s8009E688_4();
extern "C" void _s8009E688_5();
extern "C" void _s8009E688_6();
extern "C" void _s8009E688_7();
extern "C" void f_8009E688() {}
