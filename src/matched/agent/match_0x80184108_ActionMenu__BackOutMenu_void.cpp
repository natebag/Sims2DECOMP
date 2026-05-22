// 0x80184108 ActionMenu::BackOutMenu(void) (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lbz 0,0xa0(31); addi 30,31,112; rlwinm 0,0,2,0,29; lwzx 3,30,0; bl _s80184108_0; cmpwi 3,0; beq 3f; lwz 0,-31536(13); cmpwi 0,0; bne 0f; li 3,120; bl _s80184108_1; bl _s80184108_2; stw 3,-31536(13); 0:; lwz 3,-31536(13); lis 4,1162; ori 4,4,59727; bl _s80184108_3; li 9,0; lbz 0,0xa0(31); sth 9,0x6(31); rlwinm 0,0,2,0,29; lwzx 3,30,0; bl _s80184108_4; bl _s80184108_5; lbz 11,0xa0(31); stb 3,0xa2(31); rlwinm 10,11,0,24,31; cmpwi 10,0; bne 2f; lwz 11,0xa8(31); lis 9,-32697; addi 9,9,23428; rlwinm 11,11,4,0,27; add 11,11,9; lwz 3,0xfc(11); cmpwi 3,0; beq 1f; bl _s80184108_6; 1:; lbz 9,0x9(31); li 0,9; stb 0,0x9(31); stb 9,0xa(31); b 3f; 2:; li 0,4; add 10,10,10; stb 0,0x9(31); addi 9,31,144; addi 11,11,-1; mr 3,31; lhzx 0,9,10; stb 11,0xa0(31); sth 0,0x6(31); bl _s80184108_7; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80184108_0();
extern "C" void _s80184108_1();
extern "C" void _s80184108_2();
extern "C" void _s80184108_3();
extern "C" void _s80184108_4();
extern "C" void _s80184108_5();
extern "C" void _s80184108_6();
extern "C" void _s80184108_7();
extern "C" void f_80184108() {}
