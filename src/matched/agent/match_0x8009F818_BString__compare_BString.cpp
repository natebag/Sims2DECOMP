// 0x8009F818 BString::compare(BString (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 31,5; mr 30,6; mr 27,4; bl _s8009F818_0; subf 3,31,3; cmplw 30,3; ble 0f; mr 3,29; bl _s8009F818_1; subf 28,31,3; b 1f; 0:; mr 28,30; 1:; mr 3,27; bl _s8009F818_2; mr 30,3; mr 3,27; bl _s8009F818_3; mr 7,3; mr 4,31; mr 3,29; mr 5,30; mr 6,28; bl _s8009F818_4; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8009F818_0();
extern "C" void _s8009F818_1();
extern "C" void _s8009F818_2();
extern "C" void _s8009F818_3();
extern "C" void _s8009F818_4();
extern "C" void f_8009F818() {}
