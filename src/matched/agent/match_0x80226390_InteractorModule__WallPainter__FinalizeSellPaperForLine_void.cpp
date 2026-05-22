// 0x80226390 InteractorModule::WallPainter::FinalizeSellPaperForLine(void) (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; bl _s80226390_0; addi 28,30,96; lwz 4,0x0(30); addi 29,30,32; bl _s80226390_1; mr 4,28; mr 5,29; li 6,0; bl _s80226390_2; subfic 0,3,0; adde 7,0,3; mr 4,28; mr 3,30; mr 5,29; li 6,0; bl _s80226390_3; mr 30,3; cmpwi 30,1; bne 0f; lwz 3,-21472(13); bl _s80226390_4; lwz 11,-21488(13); li 4,0; lwz 9,0x0(11); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; lis 3,-32697; addi 3,3,24012; bl _s80226390_5; lwz 11,-21424(13); lwz 9,0x0(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; 0:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80226390_0();
extern "C" void _s80226390_1();
extern "C" void _s80226390_2();
extern "C" void _s80226390_3();
extern "C" void _s80226390_4();
extern "C" void _s80226390_5();
extern "C" void f_80226390() {}
