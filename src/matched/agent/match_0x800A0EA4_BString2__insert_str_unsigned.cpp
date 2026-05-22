// 0x800A0EA4 BString2::insert_str(unsigned (588 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; mfcr 12; stmw 24,0x10(1); stw 0,0x34(1); stw 12,0xc(1); mr 31,3; mr 27,4; mr 24,5; mr 26,6; bl _s800A0EA4_0; cmplw 27,3; ble 0f; bl _s800A0EA4_1; 0:; mr 3,31; bl _s800A0EA4_2; not 0,26; cmplw 3,0; blt 1f; bl _s800A0EA4_3; 1:; mr 3,31; bl _s800A0EA4_4; cmplwi 3,1; bgt 2f; mr 3,31; addi 29,26,1; bl _s800A0EA4_5; mr 30,3; mr 3,31; bl _s800A0EA4_6; subf 30,3,30; cmplw 29,30; ble 7f; 2:; bl _s800A0EA4_7; li 4,16; li 5,0; bl _s800A0EA4_8; mr 29,3; mr 3,31; bl _s800A0EA4_9; cmpwi 3,0; beq 3f; lwz 9,0x0(31); lwz 30,0x0(9); b 4f; 3:; li 30,0; 4:; mr 3,31; bl _s800A0EA4_10; add 6,3,26; mr 4,30; mr 5,27; mr 3,29; bl _s800A0EA4_11; mr 28,3; mr 3,31; bl _s800A0EA4_12; cmpwi 3,0; beq 5f; lwz 9,0x0(31); lwz 30,0x0(9); b 6f; 5:; li 30,0; 6:; mr 3,31; add 29,26,26; bl _s800A0EA4_13; mr 25,29; lwz 9,0x0(28); add 0,27,27; add 4,0,30; subf 5,27,3; add 0,0,9; rlwinm 5,5,1,0,30; add 3,29,0; cmpwi 4,26,0; bl _s800A0EA4_14; mr 3,31; bl _s800A0EA4_15; mr 30,3; bl _s800A0EA4_16; lwz 0,0x0(28); add 30,30,30; add 30,30,0; sthx 3,29,30; mr 3,31; bl _s800A0EA4_17; stw 3,0x4(28); mr 3,31; bl _s800A0EA4_18; stw 28,0x0(31); b 12f; 7:; mr 3,31; add 25,26,26; bl _s800A0EA4_19; cmpwi 4,26,0; subf. 30,27,3; beq 11f; add 28,27,27; 8:; mr 3,31; bl _s800A0EA4_20; mr 29,3; mr 3,31; bl _s800A0EA4_21; cmpwi 3,0; beq 9f; lwz 9,0x0(31); lwz 9,0x0(9); b 10f; 9:; li 9,0; 10:; add 11,28,9; add 0,28,29; add 9,30,30; add 0,25,0; add 11,9,11; addic. 30,30,-1; lhz 10,-2(11); add 9,9,0; sth 10,-2(9); bne 8b; 11:; mr 3,31; bl _s800A0EA4_22; mr 29,3; mr 3,31; bl _s800A0EA4_23; mr 30,3; bl _s800A0EA4_24; add 30,30,30; add 30,30,29; sthx 3,25,30; 12:; beq cr4,13f; mr 3,31; bl _s800A0EA4_25; add 0,27,27; mr 4,24; add 3,0,3; mr 5,25; bl _s800A0EA4_26; 13:; lwz 9,0x0(31); lwz 0,0x4(9); add 0,0,26; stw 0,0x4(9); lwz 0,0x34(1); lwz 12,0xc(1); mtspr 8,0; lmw 24,0x10(1); mtcrf 8,12; addi 1,1,48"
extern "C" void _s800A0EA4_0();
extern "C" void _s800A0EA4_1();
extern "C" void _s800A0EA4_2();
extern "C" void _s800A0EA4_3();
extern "C" void _s800A0EA4_4();
extern "C" void _s800A0EA4_5();
extern "C" void _s800A0EA4_6();
extern "C" void _s800A0EA4_7();
extern "C" void _s800A0EA4_8();
extern "C" void _s800A0EA4_9();
extern "C" void _s800A0EA4_10();
extern "C" void _s800A0EA4_11();
extern "C" void _s800A0EA4_12();
extern "C" void _s800A0EA4_13();
extern "C" void _s800A0EA4_14();
extern "C" void _s800A0EA4_15();
extern "C" void _s800A0EA4_16();
extern "C" void _s800A0EA4_17();
extern "C" void _s800A0EA4_18();
extern "C" void _s800A0EA4_19();
extern "C" void _s800A0EA4_20();
extern "C" void _s800A0EA4_21();
extern "C" void _s800A0EA4_22();
extern "C" void _s800A0EA4_23();
extern "C" void _s800A0EA4_24();
extern "C" void _s800A0EA4_25();
extern "C" void _s800A0EA4_26();
extern "C" void f_800A0EA4() {}
