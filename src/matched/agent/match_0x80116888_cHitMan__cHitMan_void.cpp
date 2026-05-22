// 0x80116888 cHitMan::cHitMan(void) (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 25,0x4c(1); stw 0,0x6c(1); li 30,0; mr 28,3; stw 30,0x0(28); addi 26,28,4; stw 30,0x4(26); li 3,12; addi 29,28,32; addi 25,28,52; bl _s80116888_0; addi 27,28,64; mr 9,3; stw 9,0x0(9); li 3,24; stw 9,0x4(9); stw 9,0x4(26); stw 30,0x18(28); stw 30,0x1c(28); stw 30,0x4(29); bl _s80116888_1; mr 9,3; stw 30,0x8(29); stw 9,0x4(29); li 3,12; stb 30,0xc(29); stw 30,0x0(9); lwz 11,0x4(29); stw 30,0x4(11); lwz 9,0x4(29); stw 9,0x8(9); lwz 11,0x4(29); stw 11,0xc(11); stw 30,0x30(28); stw 30,0x4(25); bl _s80116888_2; mr 9,3; stw 9,0x0(9); li 3,24; stw 9,0x4(9); stw 9,0x4(25); stw 30,0x3c(28); stw 30,0x4(27); bl _s80116888_3; mr 9,3; stw 30,0x8(27); stw 9,0x4(27); li 3,260; stb 30,0xc(27); stw 30,0x0(9); lwz 11,0x4(27); stw 30,0x4(11); lwz 9,0x4(27); stw 9,0x8(9); lwz 11,0x4(27); stw 11,0xc(11); bl _s80116888_4; bl _s80116888_5; stw 3,0x50(28); mr 3,28; lwz 0,0x6c(1); mtspr 8,0; lmw 25,0x4c(1); addi 1,1,104"
extern "C" void _s80116888_0();
extern "C" void _s80116888_1();
extern "C" void _s80116888_2();
extern "C" void _s80116888_3();
extern "C" void _s80116888_4();
extern "C" void _s80116888_5();
extern "C" void f_80116888() {}
