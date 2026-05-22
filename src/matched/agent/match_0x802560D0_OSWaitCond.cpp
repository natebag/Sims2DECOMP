// 0x802560D0 OSWaitCond (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stmw 27,0x14(1); addi 27,3,0; addi 28,4,0; bl _s802560D0_0; mr 31,3; bl _s802560D0_1; lwz 0,0x8(28); addi 30,3,0; cmplw 0,30; bne 5f; lwz 29,0xc(28); li 0,0; stw 0,0xc(28); lwz 3,0x10(28); lwz 4,0x14(28); cmplwi 3,0; bne 0f; stw 4,0x2f8(30); b 1f; 0:; stw 4,0x14(3); 1:; cmplwi 4,0; bne 2f; stw 3,0x2f4(30); b 3f; 2:; stw 3,0x10(4); 3:; li 0,0; stw 0,0x8(28); lwz 3,0x2d0(30); lwz 0,0x2d4(30); cmpw 3,0; bge 4f; mr 3,30; bl _s802560D0_2; stw 3,0x2d0(30); 4:; bl _s802560D0_3; mr 3,28; bl _s802560D0_4; bl _s802560D0_5; mr 3,27; bl _s802560D0_6; mr 3,28; bl _s802560D0_7; stw 29,0xc(28); 5:; mr 3,31; bl _s802560D0_8; lmw 27,0x14(1); lwz 0,0x2c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s802560D0_0();
extern "C" void _s802560D0_1();
extern "C" void _s802560D0_2();
extern "C" void _s802560D0_3();
extern "C" void _s802560D0_4();
extern "C" void _s802560D0_5();
extern "C" void _s802560D0_6();
extern "C" void _s802560D0_7();
extern "C" void _s802560D0_8();
extern "C" void f_802560D0() {}
