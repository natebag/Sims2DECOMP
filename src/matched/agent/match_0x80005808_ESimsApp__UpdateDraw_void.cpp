// 0x80005808 ESimsApp::UpdateDraw(void) (708 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-456(1); mfspr 0,8; stmw 25,0x1ac(1); stw 0,0x1cc(1); lwz 11,-26392(13); mr 31,3; li 4,0; lwz 9,0x0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; stw 30,0x47c(31); bl _s80005808_0; mr 3,30; bl _s80005808_1; lis 3,-32697; mr 4,30; addi 3,3,23428; bl _s80005808_2; lwz 11,-26392(13); mr 4,30; lwz 9,0x0(11); lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x49c(31); li 0,0; stw 0,0x47c(31); cmpwi 9,0; beq 4f; lwz 11,-26392(13); li 26,0; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4a4(31); cmpw 26,0; bge 3f; 0:; lwz 4,0x4a0(31); li 28,0; addi 25,26,1; cmpw 28,4; bge 2f; addi 27,1,168; 1:; lwz 5,0x4a4(31); mr 7,26; mr 6,28; li 3,1; bl _s80005808_3; addi 29,28,1; lwz 3,-26392(13); mr 28,29; lwz 9,0x0(3); lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; lwz 11,-26392(13); li 4,0; lwz 9,0x0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; stw 30,0x47c(31); addi 3,1,8; bl _s80005808_4; addi 3,1,8; mr 4,30; bl _s80005808_5; mr 3,30; bl _s80005808_6; lwz 11,-26392(13); mr 4,30; lwz 9,0x0(11); lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; lis 4,-32707; mr 5,29; mr 6,25; addi 4,4,-19684; mr 3,27; crxor 6,6,6; bl _s80005808_7; lwz 11,-26392(13); mr 4,27; lwz 9,0x0(11); lha 3,0x168(9); lwz 0,0x16c(9); add 3,11,3; mtspr 8,0; blrl; li 4,2; addi 3,1,8; bl _s80005808_8; lwz 4,0x4a0(31); cmpw 28,4; blt 1b; 2:; lwz 0,0x4a4(31); mr 26,25; cmpw 26,0; blt 0b; 3:; li 5,1; li 6,0; li 7,0; li 4,1; li 3,1; bl _s80005808_9; lwz 11,-26392(13); lwz 9,0x0(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26392(13); li 4,0; lwz 9,0x0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; stw 30,0x47c(31); addi 3,1,8; bl _s80005808_10; addi 3,1,8; mr 4,30; bl _s80005808_11; mr 3,30; bl _s80005808_12; lwz 11,-26392(13); mr 4,30; lwz 9,0x0(11); lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; li 3,0; li 4,1; li 5,1; li 6,0; li 7,0; bl _s80005808_13; li 0,0; addi 3,1,8; stw 0,0x49c(31); li 4,2; bl _s80005808_14; 4:; lwz 0,0x1cc(1); mtspr 8,0; lmw 25,0x1ac(1); addi 1,1,456"
extern "C" void _s80005808_0();
extern "C" void _s80005808_1();
extern "C" void _s80005808_2();
extern "C" void _s80005808_3();
extern "C" void _s80005808_4();
extern "C" void _s80005808_5();
extern "C" void _s80005808_6();
extern "C" void _s80005808_7();
extern "C" void _s80005808_8();
extern "C" void _s80005808_9();
extern "C" void _s80005808_10();
extern "C" void _s80005808_11();
extern "C" void _s80005808_12();
extern "C" void _s80005808_13();
extern "C" void _s80005808_14();
extern "C" void f_80005808() {}
