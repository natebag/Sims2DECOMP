// 0x802262B8 InteractorModule::WallPainter::FinalizePaperForLine(void) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; lis 31,-32697; bl _s802262B8_0; addi 27,30,96; lwz 4,0x0(30); addi 28,30,32; bl _s802262B8_1; mr 5,28; li 6,0; mr 4,27; bl _s802262B8_2; lwz 4,0x90(30); mr 29,3; addi 3,31,24012; bl _s802262B8_3; mr 6,3; mr 4,27; mr 3,30; mr 5,28; subfic 0,29,0; adde 7,0,29; bl _s802262B8_4; mr 30,3; cmpwi 30,1; bne 0f; lwz 3,-21472(13); bl _s802262B8_5; lwz 11,-21488(13); li 4,0; lwz 9,0x0(11); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; addi 3,31,24012; bl _s802262B8_6; lwz 11,-21424(13); lwz 9,0x0(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; 0:; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s802262B8_0();
extern "C" void _s802262B8_1();
extern "C" void _s802262B8_2();
extern "C" void _s802262B8_3();
extern "C" void _s802262B8_4();
extern "C" void _s802262B8_5();
extern "C" void _s802262B8_6();
extern "C" void f_802262B8() {}
