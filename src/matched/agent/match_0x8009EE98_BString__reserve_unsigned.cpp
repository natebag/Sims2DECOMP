// 0x8009EE98 BString::reserve(unsigned (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,4; mr 31,3; cmpwi 28,-1; bne 0f; bl _s8009EE98_0; 0:; mr 3,31; addi 30,28,1; bl _s8009EE98_1; cmplw 30,3; ble 1f; bl _s8009EE98_2; li 4,16; li 5,0; bl _s8009EE98_3; mr 29,3; mr 3,31; bl _s8009EE98_4; mr 30,3; mr 3,31; bl _s8009EE98_5; mr 5,3; mr 4,30; mr 6,28; mr 3,29; bl _s8009EE98_6; mr 30,3; mr 3,31; bl _s8009EE98_7; stw 30,0x0(31); 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8009EE98_0();
extern "C" void _s8009EE98_1();
extern "C" void _s8009EE98_2();
extern "C" void _s8009EE98_3();
extern "C" void _s8009EE98_4();
extern "C" void _s8009EE98_5();
extern "C" void _s8009EE98_6();
extern "C" void _s8009EE98_7();
extern "C" void f_8009EE98() {}
