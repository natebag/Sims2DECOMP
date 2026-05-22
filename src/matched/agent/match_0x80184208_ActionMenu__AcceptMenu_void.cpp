// 0x80184208 ActionMenu::AcceptMenu(void) (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; li 9,4; lbz 0,0xa0(31); addi 29,31,112; stb 9,0xa(31); stb 9,0x9(31); rlwinm 0,0,2,0,29; lwzx 3,29,0; bl _s80184208_0; lbz 4,0x7(31); bl _s80184208_1; mr 30,3; lwz 28,0x58(30); cmpwi 28,0; bne 4f; lwz 0,0x5c(30); cmpwi 0,0; bne 2f; bl _s80184208_2; lwz 4,0xa8(31); li 5,2; bl _s80184208_3; li 0,9; mr. 29,3; stb 0,0x9(31); beq 1f; lwz 0,-31536(13); cmpwi 0,0; bne 0f; li 3,120; bl _s80184208_4; bl _s80184208_5; stw 3,-31536(13); 0:; lwz 3,-31536(13); lis 4,14155; ori 4,4,56554; bl _s80184208_6; lwz 11,0x0(30); lwz 9,0x4(11); lha 3,0x328(9); lwz 0,0x32c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 3,29; bl _s80184208_7; b 4f; 1:; lwz 11,0xa8(31); lis 9,-32697; addi 9,9,23428; rlwinm 11,11,4,0,27; add 11,11,9; lwz 3,0xfc(11); cmpwi 3,0; beq 4f; lwz 4,0x0(30); addi 5,30,4; li 6,1; bl _s80184208_8; cmpwi 3,0; bne 4f; mr 3,31; bl _s80184208_9; b 4f; 2:; lwz 0,-31536(13); cmpwi 0,0; bne 3f; li 3,120; bl _s80184208_10; bl _s80184208_11; stw 3,-31536(13); 3:; lwz 3,-31536(13); lis 4,14155; ori 4,4,56554; bl _s80184208_12; lbz 9,0xa0(31); addi 10,31,144; addi 9,9,1; stb 9,0xa0(31); rlwinm 0,9,2,22,29; stwx 30,29,0; lbz 9,0xa0(31); lhz 11,0x6(31); add 9,9,9; sthx 11,10,9; lbz 0,0xa0(31); rlwinm 0,0,2,0,29; lwzx 3,29,0; bl _s80184208_13; bl _s80184208_14; stb 3,0xa2(31); sth 28,0x6(31); mr 3,31; bl _s80184208_15; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80184208_0();
extern "C" void _s80184208_1();
extern "C" void _s80184208_2();
extern "C" void _s80184208_3();
extern "C" void _s80184208_4();
extern "C" void _s80184208_5();
extern "C" void _s80184208_6();
extern "C" void _s80184208_7();
extern "C" void _s80184208_8();
extern "C" void _s80184208_9();
extern "C" void _s80184208_10();
extern "C" void _s80184208_11();
extern "C" void _s80184208_12();
extern "C" void _s80184208_13();
extern "C" void _s80184208_14();
extern "C" void _s80184208_15();
extern "C" void f_80184208() {}
