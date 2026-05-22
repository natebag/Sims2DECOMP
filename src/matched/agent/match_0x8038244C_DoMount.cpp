// 0x8038244C DoMount (1108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stw 31,0x2c(1); stw 30,0x28(1); stw 29,0x24(1); addi 29,3,0; mulli 4,29,272; stw 28,0x20(1); lis 3,-32688; addi 0,3,-24000; add 3,0,4; lwz 0,0x24(3); addi 31,3,0; cmpwi 0,0; bne 13f; addi 3,29,0; addi 5,1,24; li 4,0; bl _s8038244C_0; cmpwi 3,0; bne 0f; li 30,-3; b 2f; 0:; lwz 3,0x18(1); bl _s8038244C_1; cmpwi 3,0; beq 1f; li 30,0; b 2f; 1:; li 30,-2; 2:; cmpwi 30,0; blt 18f; lwz 0,0x18(1); lis 4,-32698; addi 5,4,-27464; stw 0,0x108(31); lis 3,-32698; addi 0,3,-27432; lwz 6,0x18(1); addi 3,29,0; addi 4,31,18; rlwinm 6,6,0,24,29; sth 6,0x8(31); lwz 6,0x18(1); rlwinm 6,6,23,27,29; add 5,5,6; lwz 5,0x0(5); stw 5,0xc(31); lhz 6,0x8(31); lwz 5,0xc(31); rlwinm 6,6,20,0,11; srawi 6,6,3; addze 6,6; divw 5,6,5; sth 5,0x10(31); lwz 5,0x18(1); rlwinm 5,5,26,27,29; add 5,0,5; lwz 0,0x0(5); stw 0,0x14(31); bl _s8038244C_2; mr. 30,3; blt 18f; bl _s8038244C_3; cmpwi 3,0; beq 3f; lhz 0,0x12(31); srawi 0,0,8; cmpwi 0,236; bne 3f; li 0,512; sth 0,0xa(31); b 4f; 3:; li 0,128; sth 0,0xa(31); 4:; mr 3,29; bl _s8038244C_4; mr. 30,3; blt 18f; addi 3,29,0; addi 4,1,20; bl _s8038244C_5; mr. 30,3; blt 18f; mr 3,29; bl _s8038244C_6; cmpwi 3,0; bne 5f; li 30,-3; b 18f; 5:; lbz 0,0x14(1); rlwinm. 0,0,0,25,25; bne 9f; addi 3,29,0; addi 4,31,24; bl _s8038244C_7; mr. 30,3; blt 18f; bl _s8038244C_8; mulli 0,29,12; add 4,3,0; lbz 0,0x18(31); addi 5,31,24; stb 0,0x0(4); addi 8,5,2; addi 9,5,3; lbz 7,0x18(31); addi 10,5,4; lbz 0,0x19(31); addi 11,5,5; addi 12,5,6; stb 0,0x1(4); addi 28,5,7; li 5,8; lbz 0,0x19(31); lbz 6,0x0(8); add 0,7,0; stb 6,0x2(4); lbz 7,0x0(8); lbz 6,0x0(9); add 0,0,7; stb 6,0x3(4); lbz 7,0x0(9); lbz 6,0x0(10); add 0,0,7; stb 6,0x4(4); lbz 7,0x0(10); lbz 6,0x0(11); add 0,0,7; stb 6,0x5(4); lbz 7,0x0(11); lbz 6,0x0(12); add 0,0,7; stb 6,0x6(4); lbz 7,0x0(12); lbz 6,0x0(28); add 0,0,7; stb 6,0x7(4); lbz 6,0x0(28); add 0,0,6; b 19f; 6:; subfic 4,5,12; cmpwi 5,12; mtspr 9,4; bge 8f; 7:; addi 7,5,24; add 7,31,7; lbz 4,0x0(7); addi 5,5,1; stb 4,0x0(6); addi 6,6,1; lbz 4,0x0(7); add 0,0,4; bdnz 7b; 8:; add 3,3,29; not 0,0; stb 0,0x26(3); li 3,1; bl _s8038244C_9; mr 3,30; b 21f; 9:; li 0,1; stw 0,0x24(31); bl _s8038244C_10; mulli 0,29,12; addi 30,3,0; add 5,30,0; lbz 4,0x0(5); li 6,8; lbz 0,0x1(5); lbz 3,0x2(5); add 28,4,0; lbz 0,0x3(5); add 28,28,3; lbz 3,0x4(5); add 28,28,0; lbz 0,0x5(5); add 28,28,3; lbz 3,0x6(5); add 28,28,0; lbz 0,0x7(5); add 28,28,3; add 28,28,0; b 20f; 10:; subfic 0,6,12; cmpwi 6,12; mtspr 9,0; bge 12f; 11:; lbz 0,0x0(3); addi 3,3,1; add 28,28,0; bdnz 11b; 12:; li 3,0; bl _s8038244C_11; add 3,30,29; not 0,28; lbz 3,0x26(3); rlwinm 0,0,0,24,31; cmplw 3,0; beq 13f; li 30,-5; b 18f; 13:; lwz 0,0x24(31); cmpwi 0,1; bne 16f; lwz 3,0x108(31); addis 0,3,-32768; cmplwi 0,4; bne 15f; bl _s8038244C_12; mulli 0,29,12; lhzx 28,3,0; li 3,0; bl _s8038244C_13; lhz 0,-25336(13); cmplwi 0,65535; beq 14f; cmplw 28,0; beq 15f; 14:; li 30,-2; b 18f; 15:; li 0,2; stw 0,0x24(31); addi 3,29,0; li 4,1; bl _s8038244C_14; mr. 30,3; blt 18f; lis 3,-32712; addi 4,3,-4032; addi 3,29,0; bl _s8038244C_15; mr 3,29; bl _s8038244C_16; lis 4,1; lwz 3,0x80(31); addi 4,4,-24576; bl _s8038244C_17; 16:; lwz 4,0x24(31); lis 3,-32712; lwz 0,0xc(31); addi 7,3,10400; addi 3,4,-2; mullw 4,0,3; lwz 5,0x80(31); rlwinm 0,3,13,0,18; add 6,5,0; addi 3,29,0; li 5,8192; bl _s8038244C_18; mr. 28,3; bge 17f; addi 3,31,0; addi 4,28,0; bl _s8038244C_19; 17:; mr 3,28; b 21f; 18:; mr 3,29; bl _s8038244C_20; addi 3,29,0; addi 4,30,0; bl _s8038244C_21; mr 3,30; b 21f; 19:; addi 6,4,8; b 6b; 20:; addi 3,5,8; b 10b; 21:; lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); lwz 29,0x24(1); lwz 28,0x20(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s8038244C_0();
extern "C" void _s8038244C_1();
extern "C" void _s8038244C_2();
extern "C" void _s8038244C_3();
extern "C" void _s8038244C_4();
extern "C" void _s8038244C_5();
extern "C" void _s8038244C_6();
extern "C" void _s8038244C_7();
extern "C" void _s8038244C_8();
extern "C" void _s8038244C_9();
extern "C" void _s8038244C_10();
extern "C" void _s8038244C_11();
extern "C" void _s8038244C_12();
extern "C" void _s8038244C_13();
extern "C" void _s8038244C_14();
extern "C" void _s8038244C_15();
extern "C" void _s8038244C_16();
extern "C" void _s8038244C_17();
extern "C" void _s8038244C_18();
extern "C" void _s8038244C_19();
extern "C" void _s8038244C_20();
extern "C" void _s8038244C_21();
extern "C" void f_8038244C() {}
