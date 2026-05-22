// 0x800A2DC4 BString2::replace(unsigned (976 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 22,0x10(1); stw 0,0x3c(1); mr 31,3; mr 24,4; mr 30,5; sth 6,0x8(1); mr 25,7; bl _s800A2DC4_0; cmplw 24,3; ble 0f; bl _s800A2DC4_1; 0:; mr 3,31; bl _s800A2DC4_2; subf 3,24,3; cmplw 30,3; ble 1f; mr 3,31; bl _s800A2DC4_3; subf 28,24,3; b 2f; 1:; mr 28,30; 2:; mr 3,31; bl _s800A2DC4_4; subf 3,28,3; not 0,25; cmplw 3,0; blt 3f; bl _s800A2DC4_5; 3:; cmpwi 25,0; bne 4f; mr 3,31; mr 4,24; mr 5,30; bl _s800A2DC4_6; b 27f; 4:; mr 3,31; bl _s800A2DC4_7; cmplwi 3,1; bgt 5f; mr 3,31; bl _s800A2DC4_8; mr 30,3; mr 3,31; bl _s800A2DC4_9; subf 3,28,3; add 3,3,25; addi 3,3,1; cmplw 30,3; bge 16f; 5:; bl _s800A2DC4_10; li 4,16; li 5,0; bl _s800A2DC4_11; mr 29,3; mr 3,31; bl _s800A2DC4_12; cmpwi 3,0; beq 6f; lwz 9,0x0(31); lwz 30,0x0(9); b 7f; 6:; li 30,0; 7:; mr 3,31; bl _s800A2DC4_13; mr 6,3; cmplw 28,25; ble 8f; subf 0,25,28; add 6,6,0; 8:; mr 3,29; mr 4,30; mr 5,24; bl _s800A2DC4_14; mr 23,3; cmplw 25,28; bge 11f; mr 3,31; bl _s800A2DC4_15; cmpwi 3,0; beq 9f; lwz 9,0x0(31); lwz 27,0x0(9); b 10f; 9:; li 27,0; 10:; mr 3,31; add 30,25,25; bl _s800A2DC4_16; add 29,28,28; subf 5,24,3; lwz 0,0x0(23); add 3,24,24; subf 5,28,5; add 4,3,27; rlwinm 5,5,1,0,30; add 3,3,0; add 4,29,4; add 3,30,3; mr 26,30; bl _s800A2DC4_17; mr 27,29; subf 22,28,25; b 15f; 11:; mr 3,31; subf 22,28,25; bl _s800A2DC4_18; add 26,25,25; subf 3,28,3; add 27,28,28; subf. 30,24,3; beq 15f; add 28,24,24; 12:; mr 3,31; bl _s800A2DC4_19; cmpwi 3,0; beq 13f; lwz 9,0x0(31); lwz 9,0x0(9); b 14f; 13:; li 9,0; 14:; lwz 0,0x0(23); add 9,28,9; add 11,30,30; add 9,27,9; add 9,11,9; add 0,28,0; add 0,26,0; lhz 10,-2(9); add 11,11,0; addic. 30,30,-1; sth 10,-2(11); bne 12b; 15:; mr 3,31; bl _s800A2DC4_20; lwz 30,0x0(23); rlwinm 3,3,1,0,30; add 30,30,26; add 30,30,3; subf 30,27,30; bl _s800A2DC4_21; sth 3,0x0(30); mr 3,31; bl _s800A2DC4_22; stw 3,0x4(23); mr 3,31; bl _s800A2DC4_23; stw 23,0x0(31); b 24f; 16:; cmplw 25,28; bge 19f; mr 3,31; bl _s800A2DC4_24; mr 26,3; mr 3,31; bl _s800A2DC4_25; cmpwi 3,0; beq 17f; lwz 9,0x0(31); lwz 27,0x0(9); b 18f; 17:; li 27,0; 18:; mr 3,31; add 29,25,25; bl _s800A2DC4_26; add 30,28,28; subf 5,24,3; subf 22,28,25; add 3,24,24; subf 5,28,5; add 4,3,27; rlwinm 5,5,1,0,30; add 3,3,26; add 4,30,4; add 3,29,3; mr 26,29; bl _s800A2DC4_27; mr 27,30; b 23f; 19:; mr 3,31; subf 22,28,25; bl _s800A2DC4_28; add 26,25,25; subf 3,28,3; add 27,28,28; subf. 30,24,3; beq 23f; add 29,24,24; 20:; mr 3,31; bl _s800A2DC4_29; mr 28,3; mr 3,31; bl _s800A2DC4_30; cmpwi 3,0; beq 21f; lwz 9,0x0(31); lwz 9,0x0(9); b 22f; 21:; li 9,0; 22:; add 9,29,9; add 11,30,30; add 9,27,9; add 0,29,28; add 9,11,9; add 0,26,0; lhz 10,-2(9); add 11,11,0; addic. 30,30,-1; sth 10,-2(11); bne 20b; 23:; mr 3,31; bl _s800A2DC4_31; mr 30,3; mr 3,31; bl _s800A2DC4_32; rlwinm 3,3,1,0,30; add 30,30,26; add 30,30,3; subf 30,27,30; bl _s800A2DC4_33; sth 3,0x0(30); 24:; li 30,0; cmplw 30,25; bge 26f; add 29,24,24; 25:; mr 3,31; bl _s800A2DC4_34; add 9,30,30; lhz 0,0x8(1); add 3,29,3; addi 30,30,1; sthx 0,9,3; cmplw 30,25; blt 25b; 26:; lwz 9,0x0(31); mr 3,31; lwz 0,0x4(9); add 0,0,22; stw 0,0x4(9); 27:; lwz 0,0x3c(1); mtspr 8,0; lmw 22,0x10(1); addi 1,1,56"
extern "C" void _s800A2DC4_0();
extern "C" void _s800A2DC4_1();
extern "C" void _s800A2DC4_2();
extern "C" void _s800A2DC4_3();
extern "C" void _s800A2DC4_4();
extern "C" void _s800A2DC4_5();
extern "C" void _s800A2DC4_6();
extern "C" void _s800A2DC4_7();
extern "C" void _s800A2DC4_8();
extern "C" void _s800A2DC4_9();
extern "C" void _s800A2DC4_10();
extern "C" void _s800A2DC4_11();
extern "C" void _s800A2DC4_12();
extern "C" void _s800A2DC4_13();
extern "C" void _s800A2DC4_14();
extern "C" void _s800A2DC4_15();
extern "C" void _s800A2DC4_16();
extern "C" void _s800A2DC4_17();
extern "C" void _s800A2DC4_18();
extern "C" void _s800A2DC4_19();
extern "C" void _s800A2DC4_20();
extern "C" void _s800A2DC4_21();
extern "C" void _s800A2DC4_22();
extern "C" void _s800A2DC4_23();
extern "C" void _s800A2DC4_24();
extern "C" void _s800A2DC4_25();
extern "C" void _s800A2DC4_26();
extern "C" void _s800A2DC4_27();
extern "C" void _s800A2DC4_28();
extern "C" void _s800A2DC4_29();
extern "C" void _s800A2DC4_30();
extern "C" void _s800A2DC4_31();
extern "C" void _s800A2DC4_32();
extern "C" void _s800A2DC4_33();
extern "C" void _s800A2DC4_34();
extern "C" void f_800A2DC4() {}
