// 0x800E583C EdithVariableSet::ReconStream(ReconBuffer (1408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; mfcr 12; stmw 24,0x78(1); stw 0,0x9c(1); stw 12,0x74(1); mr 27,4; li 0,1; lwz 9,0xc(27); mr 31,3; mr 25,5; stw 0,-31860(13); cmpwi 9,1; beq 0f; cmpwi 9,2; bne 11f; 0:; lha 5,0x1e(31); li 28,0; stb 28,0x8(1); li 4,8; mr 3,31; cmpwi 4,25,86; bl _s800E583C_0; lha 5,0x20(31); li 4,25; mr 3,31; bl _s800E583C_1; lha 5,0x22(31); li 4,29; mr 3,31; bl _s800E583C_2; lha 5,0x24(31); li 4,34; mr 3,31; bl _s800E583C_3; lha 5,0x26(31); li 4,1; mr 3,31; bl _s800E583C_4; lha 5,0x28(31); li 4,0; mr 3,31; bl _s800E583C_5; lha 5,0x2a(31); li 4,66; mr 3,31; bl _s800E583C_6; lha 5,0x2c(31); mr 3,31; li 4,39; bl _s800E583C_7; bgt cr4,1f; addi 9,31,12; lwz 11,0xc(31); lwz 0,0x4(9); mr 3,27; addi 4,1,8; li 5,1; subf 0,11,0; mr 29,9; srawi 0,0,1; addi 28,1,16; stb 0,0x8(1); bl _s800E583C_8; b 2f; 1:; li 4,72; mr 3,31; bl _s800E583C_9; addi 29,31,12; addi 30,1,16; stw 3,0x18(1); stw 31,0x10(1); mr 3,31; stw 29,0x14(1); mr 4,27; stw 28,0xc(30); mr 5,30; bl _s800E583C_10; mr 28,30; stb 3,0x8(1); 2:; mr 3,31; li 4,72; bl _s800E583C_11; stw 3,0x18(1); li 0,0; stw 31,0x10(1); stw 29,0x14(1); stw 0,0xc(28); addi 30,1,32; b 8f; 3:; cmpwi 25,84; bgt 4f; lwz 9,0x14(1); mr 3,27; lwz 0,0x18(1); mr 4,30; lwz 11,0x0(9); li 5,4; lwz 9,0x1c(1); stb 0,0x20(1); add 9,9,9; lhzx 0,11,9; sth 0,0x22(1); bl _s800E583C_12; b 6f; 4:; bgt cr4,5f; lwz 0,0x18(1); addi 4,1,48; mr 3,27; li 5,1; stb 0,0x30(1); bl _s800E583C_13; lwz 9,0x14(1); mr 3,27; lwz 4,0x1c(1); li 5,1; lwz 0,0x0(9); add 4,4,4; add 4,0,4; bl _s800E583C_14; b 6f; 5:; lwz 9,0x14(1); mr 3,27; lwz 4,0x1c(1); li 5,1; lwz 0,0x0(9); add 4,4,4; add 4,0,4; bl _s800E583C_15; 6:; lwz 3,0x10(1); li 5,72; lwz 4,0x18(1); bl _s800E583C_16; cmpwi 3,72; stw 3,0x18(1); beq 7f; lwz 9,0x1c(1); addi 9,9,1; stw 9,0x1c(1); b 8f; 7:; lwz 9,0x14(1); lwz 11,0x0(9); lwz 0,0x4(9); subf 0,11,0; srawi 0,0,1; stw 0,0x1c(1); 8:; lwz 11,0x4(29); li 9,72; stw 31,0x20(1); li 8,0; stw 29,0x24(1); stw 9,0x8(30); lwz 0,0xc(31); lwz 10,0x10(1); subf 11,0,11; lwz 9,0x20(1); srawi 11,11,1; cmpw 10,9; stw 11,0x2c(1); bne 9f; lwz 9,0x18(1); lwz 0,0x28(1); cmpw 9,0; beq 10f; 9:; li 8,1; 10:; cmpwi 8,0; bne 3b; b 22f; 11:; addi 3,1,16; li 4,0; li 5,12; li 26,0; bl _s800E583C_17; cmpwi 4,25,86; addi 11,1,28; stw 26,0x1c(1); stw 26,0x4(11); addi 9,1,36; stw 26,0x4(9); mr 24,11; stb 26,0x40(1); bgt cr4,12f; mr 3,27; addi 4,1,64; li 5,1; addi 28,1,16; bl _s800E583C_18; addi 30,1,72; b 13f; 12:; addi 30,1,16; addi 29,1,72; li 4,72; mr 3,30; bl _s800E583C_19; mr 28,30; stw 30,0x48(1); mr 4,27; stw 24,0x4(29); mr 5,29; stw 3,0x50(1); mr 30,29; stw 26,0xc(29); mr 3,31; bl _s800E583C_20; stb 3,0x40(1); 13:; mr 3,28; li 4,72; bl _s800E583C_21; li 26,0; stw 28,0x48(1); li 9,0; stw 24,0x4(30); stw 3,0x50(1); stw 9,0xc(30); lbz 0,0x40(1); extsb 0,0; cmpw 26,0; bge 20f; li 29,0; addi 30,1,88; 14:; cmpwi 25,84; bgt 15f; li 0,0; li 9,0; stb 0,0x58(1); mr 3,27; sth 9,0x5a(1); addi 4,1,88; li 5,4; bl _s800E583C_22; lbz 9,0x58(1); mr 3,31; lhz 0,0x5a(1); addi 4,1,96; stw 9,0x60(1); sth 0,0x64(1); stw 9,0x68(1); bl _s800E583C_23; b 17f; 15:; bgt cr4,16f; mr 3,27; mr 4,30; li 5,1; stw 29,0x58(1); sth 29,0x5c(1); bl _s800E583C_24; mr 3,27; addi 4,1,92; li 5,1; bl _s800E583C_25; mr 3,31; mr 4,30; bl _s800E583C_26; b 17f; 16:; stw 29,0x58(1); mr 3,27; sth 29,0x4(30); addi 4,1,92; li 5,1; lwz 0,0x50(1); stw 0,0x58(1); bl _s800E583C_27; mr 3,31; mr 4,30; bl _s800E583C_28; 17:; lwz 3,0x48(1); li 5,72; lwz 4,0x50(1); addi 26,26,1; bl _s800E583C_29; cmpwi 3,72; stw 3,0x50(1); beq 18f; lwz 9,0x54(1); addi 9,9,1; stw 9,0x54(1); b 19f; 18:; lwz 9,0x4c(1); lwz 11,0x0(9); lwz 0,0x4(9); subf 0,11,0; srawi 0,0,1; stw 0,0x54(1); 19:; lbz 0,0x40(1); extsb 0,0; cmpw 26,0; blt 14b; 20:; mr 3,31; mr 4,31; bl _s800E583C_30; li 4,8; mr 3,31; bl _s800E583C_31; lhz 0,0x0(3); li 4,25; mr 3,31; sth 0,0x1e(31); bl _s800E583C_32; lhz 0,0x0(3); li 4,29; mr 3,31; sth 0,0x20(31); bl _s800E583C_33; lhz 0,0x0(3); li 4,1; mr 3,31; sth 0,0x22(31); bl _s800E583C_34; lhz 0,0x0(3); li 4,0; mr 3,31; sth 0,0x26(31); bl _s800E583C_35; lhz 0,0x0(3); li 4,34; mr 3,31; sth 0,0x28(31); bl _s800E583C_36; lhz 0,0x0(3); li 4,66; mr 3,31; sth 0,0x24(31); bl _s800E583C_37; lhz 0,0x0(3); li 4,39; mr 3,31; sth 0,0x2a(31); bl _s800E583C_38; lwz 9,0x1c(1); lhz 0,0x0(3); cmpwi 9,0; sth 0,0x2c(31); beq 22f; lwz 0,0xc(24); subf 0,9,0; rlwinm 4,0,0,0,30; cmplwi 4,128; ble 21f; mr 3,9; bl _s800E583C_39; b 22f; 21:; mr 3,9; bl _s800E583C_40; 22:; li 0,0; stw 0,-31860(13); lwz 0,0x9c(1); lwz 12,0x74(1); mtspr 8,0; lmw 24,0x78(1); mtcrf 8,12; addi 1,1,152"
extern "C" void _s800E583C_0();
extern "C" void _s800E583C_1();
extern "C" void _s800E583C_2();
extern "C" void _s800E583C_3();
extern "C" void _s800E583C_4();
extern "C" void _s800E583C_5();
extern "C" void _s800E583C_6();
extern "C" void _s800E583C_7();
extern "C" void _s800E583C_8();
extern "C" void _s800E583C_9();
extern "C" void _s800E583C_10();
extern "C" void _s800E583C_11();
extern "C" void _s800E583C_12();
extern "C" void _s800E583C_13();
extern "C" void _s800E583C_14();
extern "C" void _s800E583C_15();
extern "C" void _s800E583C_16();
extern "C" void _s800E583C_17();
extern "C" void _s800E583C_18();
extern "C" void _s800E583C_19();
extern "C" void _s800E583C_20();
extern "C" void _s800E583C_21();
extern "C" void _s800E583C_22();
extern "C" void _s800E583C_23();
extern "C" void _s800E583C_24();
extern "C" void _s800E583C_25();
extern "C" void _s800E583C_26();
extern "C" void _s800E583C_27();
extern "C" void _s800E583C_28();
extern "C" void _s800E583C_29();
extern "C" void _s800E583C_30();
extern "C" void _s800E583C_31();
extern "C" void _s800E583C_32();
extern "C" void _s800E583C_33();
extern "C" void _s800E583C_34();
extern "C" void _s800E583C_35();
extern "C" void _s800E583C_36();
extern "C" void _s800E583C_37();
extern "C" void _s800E583C_38();
extern "C" void _s800E583C_39();
extern "C" void _s800E583C_40();
extern "C" void f_800E583C() {}
