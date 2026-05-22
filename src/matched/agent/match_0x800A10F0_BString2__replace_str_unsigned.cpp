// 0x800A10F0 BString2::replace_str(unsigned (772 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 21,0xc(1); stw 0,0x3c(1); mr 31,3; mr 24,5; mr 27,4; mr 21,6; mr 26,7; bl _s800A10F0_0; cmplw 24,3; ble 0f; bl _s800A10F0_1; 0:; mr 3,31; bl _s800A10F0_2; subf 3,27,3; not 0,26; cmplw 3,0; blt 1f; bl _s800A10F0_3; 1:; mr 3,31; bl _s800A10F0_4; cmplwi 3,1; bgt 2f; mr 3,31; bl _s800A10F0_5; mr 30,3; mr 3,31; bl _s800A10F0_6; add 3,3,26; addi 0,27,-1; subf 3,0,3; cmplw 30,3; bge 7f; 2:; bl _s800A10F0_7; li 4,16; li 5,0; bl _s800A10F0_8; mr 29,3; mr 3,31; bl _s800A10F0_9; cmpwi 3,0; beq 3f; lwz 9,0x0(31); lwz 30,0x0(9); b 4f; 3:; li 30,0; 4:; mr 3,31; bl _s800A10F0_10; add 6,3,26; mr 4,30; subf 6,27,6; mr 5,24; mr 3,29; bl _s800A10F0_11; mr 25,3; mr 3,31; bl _s800A10F0_12; cmpwi 3,0; beq 5f; lwz 9,0x0(31); lwz 30,0x0(9); b 6f; 5:; li 30,0; 6:; mr 3,31; add 29,26,26; bl _s800A10F0_13; add 28,27,27; subf 5,24,3; lwz 0,0x0(25); add 3,24,24; subf 5,27,5; add 4,3,30; rlwinm 5,5,1,0,30; add 3,3,0; add 4,28,4; add 3,29,3; subf 22,27,26; bl _s800A10F0_14; mr 23,29; cmpwi 26,0; mr 3,31; mfcr 27; bl _s800A10F0_15; lwz 30,0x0(25); rlwinm 3,3,1,0,30; add 30,30,3; add 30,30,29; subf 30,28,30; bl _s800A10F0_16; sth 3,0x0(30); mr 3,31; bl _s800A10F0_17; stw 3,0x4(25); mr 3,31; bl _s800A10F0_18; stw 25,0x0(31); b 15f; 7:; cmplw 26,27; bge 10f; mr 3,31; bl _s800A10F0_19; mr 25,3; mr 3,31; bl _s800A10F0_20; cmpwi 3,0; beq 8f; lwz 9,0x0(31); lwz 28,0x0(9); b 9f; 8:; li 28,0; 9:; mr 3,31; add 30,27,27; bl _s800A10F0_21; add 29,26,26; subf 5,24,3; subf 22,27,26; add 3,24,24; subf 5,27,5; add 4,3,28; rlwinm 5,5,1,0,30; add 3,3,25; add 4,30,4; add 3,29,3; mr 23,29; bl _s800A10F0_22; mr 25,30; cmpwi 26,0; mfcr 27; b 14f; 10:; mr 3,31; subf 22,27,26; bl _s800A10F0_23; add 25,27,27; subf 3,24,3; cmpwi 7,26,0; subf. 30,27,3; add 23,26,26; mfcr 27; rlwinm 27,27,28,0,3; beq 14f; add 28,24,24; 11:; mr 3,31; bl _s800A10F0_24; mr 29,3; mr 3,31; bl _s800A10F0_25; cmpwi 3,0; beq 12f; lwz 9,0x0(31); lwz 9,0x0(9); b 13f; 12:; li 9,0; 13:; add 9,28,9; add 11,30,30; add 9,25,9; add 0,28,29; add 9,11,9; add 0,23,0; lhz 10,-2(9); add 11,11,0; addic. 30,30,-1; sth 10,-2(11); bne 11b; 14:; mr 3,31; bl _s800A10F0_26; mr 30,3; mr 3,31; bl _s800A10F0_27; rlwinm 3,3,1,0,30; add 30,30,3; add 30,30,23; subf 30,25,30; bl _s800A10F0_28; sth 3,0x0(30); 15:; mtcrf 128,27; beq 16f; mr 3,31; bl _s800A10F0_29; add 0,24,24; mr 4,21; add 3,0,3; mr 5,23; bl _s800A10F0_30; 16:; lwz 9,0x0(31); lwz 0,0x4(9); add 0,0,22; stw 0,0x4(9); lwz 0,0x3c(1); mtspr 8,0; lmw 21,0xc(1); addi 1,1,56"
extern "C" void _s800A10F0_0();
extern "C" void _s800A10F0_1();
extern "C" void _s800A10F0_2();
extern "C" void _s800A10F0_3();
extern "C" void _s800A10F0_4();
extern "C" void _s800A10F0_5();
extern "C" void _s800A10F0_6();
extern "C" void _s800A10F0_7();
extern "C" void _s800A10F0_8();
extern "C" void _s800A10F0_9();
extern "C" void _s800A10F0_10();
extern "C" void _s800A10F0_11();
extern "C" void _s800A10F0_12();
extern "C" void _s800A10F0_13();
extern "C" void _s800A10F0_14();
extern "C" void _s800A10F0_15();
extern "C" void _s800A10F0_16();
extern "C" void _s800A10F0_17();
extern "C" void _s800A10F0_18();
extern "C" void _s800A10F0_19();
extern "C" void _s800A10F0_20();
extern "C" void _s800A10F0_21();
extern "C" void _s800A10F0_22();
extern "C" void _s800A10F0_23();
extern "C" void _s800A10F0_24();
extern "C" void _s800A10F0_25();
extern "C" void _s800A10F0_26();
extern "C" void _s800A10F0_27();
extern "C" void _s800A10F0_28();
extern "C" void _s800A10F0_29();
extern "C" void _s800A10F0_30();
extern "C" void f_800A10F0() {}
