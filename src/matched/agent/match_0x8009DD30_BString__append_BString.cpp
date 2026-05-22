// 0x8009DD30 BString::append(BString (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,4; mr 27,3; mr 30,5; mr 29,6; mr 3,31; bl _s8009DD30_0; cmplw 30,3; ble 0f; bl _s8009DD30_1; 0:; mr 3,31; bl _s8009DD30_2; add 28,3,30; mr 3,31; bl _s8009DD30_3; subf 3,30,3; cmplw 29,3; ble 1f; mr 3,31; bl _s8009DD30_4; subf 5,30,3; b 2f; 1:; mr 5,29; 2:; mr 3,27; mr 4,28; bl _s8009DD30_5; mr 3,27; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8009DD30_0();
extern "C" void _s8009DD30_1();
extern "C" void _s8009DD30_2();
extern "C" void _s8009DD30_3();
extern "C" void _s8009DD30_4();
extern "C" void _s8009DD30_5();
extern "C" void f_8009DD30() {}
