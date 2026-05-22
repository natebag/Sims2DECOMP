// 0x8009EFC0 BString::find(BString (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,4; mr 28,3; mr 27,5; mr 3,30; bl _s8009EFC0_0; mr 29,3; mr 3,30; bl _s8009EFC0_1; mr 6,3; mr 4,29; mr 3,28; mr 5,27; bl _s8009EFC0_2; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8009EFC0_0();
extern "C" void _s8009EFC0_1();
extern "C" void _s8009EFC0_2();
extern "C" void f_8009EFC0() {}
