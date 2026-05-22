// 0x800A2768 BString2::insert(unsigned (640 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); mr 31,3; mr 25,4; sth 5,0x8(1); mr 26,6; bl _s800A2768_0; cmplw 25,3; ble 0f; bl _s800A2768_1; 0:; cmpwi 26,-1; beq 1f; mr 3,31; bl _s800A2768_2; not 0,26; cmplw 3,0; blt 2f; 1:; bl _s800A2768_3; 2:; cmpwi 26,0; beq 18f; mr 3,31; bl _s800A2768_4; cmplwi 3,1; bgt 3f; mr 3,31; bl _s800A2768_5; mr 30,3; mr 3,31; bl _s800A2768_6; add 3,3,26; addi 3,3,1; cmplw 30,3; bge 10f; 3:; bl _s800A2768_7; li 4,16; li 5,0; bl _s800A2768_8; mr 29,3; mr 3,31; bl _s800A2768_9; cmpwi 3,0; beq 4f; lwz 9,0x0(31); lwz 30,0x0(9); b 5f; 4:; li 30,0; 5:; mr 3,31; add 27,26,26; bl _s800A2768_10; add 6,3,26; mr 4,30; mr 5,25; mr 3,29; bl _s800A2768_11; mr 28,3; mr 3,31; bl _s800A2768_12; cmpwi 3,0; beq 9f; mr 3,31; bl _s800A2768_13; subf. 30,25,3; beq 9f; add 29,25,25; 6:; mr 3,31; bl _s800A2768_14; cmpwi 3,0; beq 7f; lwz 9,0x0(31); lwz 9,0x0(9); b 8f; 7:; li 9,0; 8:; lwz 0,0x0(28); add 11,29,9; add 9,30,30; add 11,9,11; add 0,29,0; add 0,27,0; lhz 10,-2(11); add 9,9,0; addic. 30,30,-1; sth 10,-2(9); bne 6b; 9:; mr 3,31; bl _s800A2768_15; mr 30,3; bl _s800A2768_16; lwz 0,0x0(28); add 30,30,30; add 30,30,0; sthx 3,27,30; mr 3,31; bl _s800A2768_17; stw 3,0x4(28); mr 3,31; bl _s800A2768_18; stw 28,0x0(31); b 15f; 10:; mr 3,31; add 27,26,26; bl _s800A2768_19; subf. 30,25,3; beq 14f; add 28,25,25; 11:; mr 3,31; bl _s800A2768_20; mr 29,3; mr 3,31; bl _s800A2768_21; cmpwi 3,0; beq 12f; lwz 9,0x0(31); lwz 9,0x0(9); b 13f; 12:; li 9,0; 13:; add 11,28,9; add 0,28,29; add 9,30,30; add 0,27,0; add 11,9,11; addic. 30,30,-1; lhz 10,-2(11); add 9,9,0; sth 10,-2(9); bne 11b; 14:; mr 3,31; bl _s800A2768_22; mr 29,3; mr 3,31; bl _s800A2768_23; mr 30,3; bl _s800A2768_24; add 29,27,29; add 30,30,30; sthx 3,30,29; 15:; li 30,0; cmplw 30,26; bge 17f; add 29,25,25; 16:; mr 3,31; bl _s800A2768_25; add 9,30,30; lhz 0,0x8(1); add 3,29,3; addi 30,30,1; sthx 0,9,3; cmplw 30,26; blt 16b; 17:; lwz 9,0x0(31); lwz 0,0x4(9); add 0,0,26; stw 0,0x4(9); 18:; mr 3,31; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s800A2768_0();
extern "C" void _s800A2768_1();
extern "C" void _s800A2768_2();
extern "C" void _s800A2768_3();
extern "C" void _s800A2768_4();
extern "C" void _s800A2768_5();
extern "C" void _s800A2768_6();
extern "C" void _s800A2768_7();
extern "C" void _s800A2768_8();
extern "C" void _s800A2768_9();
extern "C" void _s800A2768_10();
extern "C" void _s800A2768_11();
extern "C" void _s800A2768_12();
extern "C" void _s800A2768_13();
extern "C" void _s800A2768_14();
extern "C" void _s800A2768_15();
extern "C" void _s800A2768_16();
extern "C" void _s800A2768_17();
extern "C" void _s800A2768_18();
extern "C" void _s800A2768_19();
extern "C" void _s800A2768_20();
extern "C" void _s800A2768_21();
extern "C" void _s800A2768_22();
extern "C" void _s800A2768_23();
extern "C" void _s800A2768_24();
extern "C" void _s800A2768_25();
extern "C" void f_800A2768() {}
