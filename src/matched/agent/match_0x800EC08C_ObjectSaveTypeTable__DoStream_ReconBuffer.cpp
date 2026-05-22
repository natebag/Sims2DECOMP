// 0x800EC08C ObjectSaveTypeTable::DoStream(ReconBuffer (1528 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; mfcr 12; stmw 24,0x70(1); stw 0,0x94(1); stw 12,0x6c(1); mr 27,4; li 7,0; lwz 0,0xc(27); mr 26,3; mr 24,5; stw 7,0x54(1); cmpwi 0,0; stw 7,0x58(1); beq 12f; lwz 8,0x0(26); addi 9,1,8; stw 7,0x4(9); addi 11,1,40; stw 7,0x8(9); addi 8,8,64; stw 7,0x4(11); mr 29,9; stw 7,0x8(11); li 9,256; stw 8,0x28(1); mr 28,11; stw 9,0x4(11); addi 10,1,56; addi 25,1,80; lwz 9,0x2c(1); lwz 0,0x28(1); lwz 11,0x30(1); stw 9,0x1c(1); stw 0,0x18(1); stw 11,0x20(1); stw 7,0x4(10); stw 7,0x8(10); stw 8,0x38(1); stw 7,0x4(10); lwz 9,0x3c(1); cmpwi 9,255; bgt 1f; lwz 11,0x38(1); rlwinm 9,9,2,0,29; lwzx 9,11,9; cmpwi 9,0; beq 0f; stw 9,0x40(1); b 1f; 0:; lwz 9,0x3c(1); addi 0,9,1; stw 0,0x3c(1); cmpwi 0,255; bgt 1f; lwz 9,0x38(1); rlwinm 0,0,2,0,29; lwzx 0,9,0; cmpwi 0,0; beq 0b; stw 0,0x40(1); 1:; lwz 9,0x3c(1); mr 26,28; lwz 0,0x40(1); addi 24,1,76; stw 9,0x2c(1); stw 0,0x30(1); lwz 11,0x38(1); lwz 0,0x4(28); lwz 9,0x8(28); stw 11,0x8(1); stw 0,0x4(29); stw 9,0x8(29); stw 11,0x28(1); b 10f; 2:; lwz 31,0x8(29); lha 0,0x6c(31); cmpwi 0,0; beq 6f; sth 0,0x48(1); mr 3,31; bl _s800EC08C_0; addi 30,31,28; stw 3,0x50(1); mr 3,31; bl _s800EC08C_1; stw 3,0x54(1); mr 3,31; bl _s800EC08C_2; lwz 9,0x1c(30); stw 3,0x58(1); mr 3,28; lha 0,0x12(9); sth 0,0x4a(1); bl _s800EC08C_3; lwz 9,0x1c(30); lha 0,0x14(9); cmpwi 0,0; beq 3f; lha 0,0x16(9); cmpwi 0,-1; bne 5f; 3:; mr 3,31; bl _s800EC08C_4; mr 4,3; lwz 9,0x0(4); mr 3,24; lha 0,0x18(9); lwz 9,0x1c(9); add 4,4,0; mtspr 8,9; crxor 6,6,6; blrl; lwz 9,0x4c(1); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; mr 3,28; bl _s800EC08C_5; 5:; mr 3,27; mr 4,25; li 5,1; bl _s800EC08C_6; addi 4,1,84; mr 3,27; li 5,1; bl _s800EC08C_7; addi 4,1,88; mr 3,27; li 5,1; bl _s800EC08C_8; addi 4,1,72; mr 3,27; li 5,1; bl _s800EC08C_9; addi 4,1,74; mr 3,27; li 5,1; bl _s800EC08C_10; mr 3,27; mr 4,26; bl _s800EC08C_11; mr 3,26; li 4,2; bl _s800EC08C_12; 6:; lwz 9,0x8(29); cmpwi 9,0; beq 8f; lwz 0,0xa4(9); cmpwi 0,0; stw 0,0x8(29); bne 7f; lwz 9,0x4(29); addi 9,9,1; stw 9,0x4(29); 7:; lwz 0,0x8(29); cmpwi 0,0; bne 10f; 8:; lwz 9,0x4(29); cmpwi 9,255; bgt 10f; lwz 11,0x0(29); rlwinm 9,9,2,0,29; lwzx 9,11,9; cmpwi 9,0; beq 9f; stw 9,0x8(29); b 10f; 9:; lwz 9,0x4(29); addi 0,9,1; stw 0,0x4(29); cmpwi 0,255; bgt 10f; lwz 9,0x0(29); rlwinm 0,0,2,0,29; lwzx 0,9,0; cmpwi 0,0; beq 9b; stw 0,0x8(29); 10:; lwz 9,0x4(29); li 11,0; lwz 0,0x1c(1); cmpw 9,0; bne 11f; lwz 9,0x8(29); lwz 0,0x20(1); cmpw 9,0; bne 11f; lwz 9,0x8(1); lwz 0,0x18(1); xor 11,9,0; subfic 10,11,0; adde 11,10,11; 11:; xori 9,11,1; cmpwi 9,0; bne 2b; stw 9,0x50(1); mr 3,27; mr 4,25; li 5,1; bl _s800EC08C_13; b 35f; 12:; addi 30,1,80; mr 3,27; mr 4,30; li 5,1; bl _s800EC08C_14; mr 25,30; lwz 0,0x50(1); cmpwi 0,0; beq 35f; cmpwi 4,24,0; 13:; ble cr4,14f; mr 3,27; addi 4,1,84; li 5,1; bl _s800EC08C_15; mr 3,27; addi 4,1,88; li 5,1; bl _s800EC08C_16; 14:; mr 3,27; addi 4,1,72; li 5,1; bl _s800EC08C_17; cmpwi 24,1; ble 15f; mr 3,27; addi 4,1,74; li 5,1; bl _s800EC08C_18; b 16f; 15:; li 0,-1; sth 0,0x4a(1); 16:; addi 3,1,8; bl _s800EC08C_19; mr 3,27; addi 4,1,8; bl _s800EC08C_20; lwz 3,0x0(26); lwz 4,0x50(1); lwz 9,0x0(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; mr. 30,3; bne 28f; lha 0,0x4a(1); cmpwi 0,2; bne 34f; lwz 9,0x0(26); addi 31,9,1664; lwz 30,0x4(31); lwz 0,0xc(31); cmpw 30,0; beq 17f; lwz 0,0x50(1); stw 0,0x0(30); lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 34f; 17:; lwz 0,0x680(9); addi 10,1,96; li 9,1; addi 11,1,92; subf 0,0,30; stw 9,0x60(1); srawi 9,0,2; stw 9,0x5c(1); cmplwi 9,1; bge 18f; mr 11,10; 18:; lwz 0,0x0(11); add. 0,9,0; beq 20f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 19f; mr 3,28; bl _s800EC08C_21; mr 29,3; b 21f; 19:; mr 3,28; bl _s800EC08C_22; mr 29,3; b 21f; 20:; li 29,0; li 28,0; 21:; lwz 4,0x0(31); cmpw 30,4; beq 22f; subf 30,4,30; mr 3,29; mr 5,30; bl _s800EC08C_23; add 0,3,30; b 23f; 22:; mr 0,29; 23:; lwz 9,0x60(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 25f; 24:; lwz 0,0x0(25); stw 0,0x0(30); addi 30,30,4; bdnz 24b; 25:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 27f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 26f; bl _s800EC08C_24; b 27f; 26:; bl _s800EC08C_25; 27:; add 0,28,29; stw 29,0x0(31); stw 0,0xc(31); stw 30,0x4(31); b 34f; 28:; lhz 0,0x48(1); sth 0,0x6c(30); ble cr4,31f; mr 3,30; li 29,0; bl _s800EC08C_26; lwz 0,0x54(1); cmpw 3,0; bne 29f; mr 3,30; bl _s800EC08C_27; lwz 0,0x58(1); cmpw 3,0; beq 30f; 29:; li 29,1; 30:; lwz 0,0x7c(30); cmpwi 29,0; b 32f; 31:; mr 3,30; bl _s800EC08C_28; lwz 0,0x7c(30); cmpwi 3,0; 32:; rlwinm 0,0,0,31,29; stw 0,0x7c(30); beq 33f; ori 0,0,2; stw 0,0x7c(30); 33:; lwz 3,0x0(26); mr 4,30; li 5,1; lwz 9,0x0(3); lha 0,0x200(9); lwz 9,0x204(9); add 3,3,0; mtspr 8,9; blrl; 34:; mr 3,27; mr 4,25; li 5,1; bl _s800EC08C_29; addi 3,1,8; li 4,2; bl _s800EC08C_30; lwz 0,0x50(1); cmpwi 0,0; bne 13b; 35:; lwz 0,0x94(1); lwz 12,0x6c(1); mtspr 8,0; lmw 24,0x70(1); mtcrf 8,12; addi 1,1,144"
extern "C" void _s800EC08C_0();
extern "C" void _s800EC08C_1();
extern "C" void _s800EC08C_2();
extern "C" void _s800EC08C_3();
extern "C" void _s800EC08C_4();
extern "C" void _s800EC08C_5();
extern "C" void _s800EC08C_6();
extern "C" void _s800EC08C_7();
extern "C" void _s800EC08C_8();
extern "C" void _s800EC08C_9();
extern "C" void _s800EC08C_10();
extern "C" void _s800EC08C_11();
extern "C" void _s800EC08C_12();
extern "C" void _s800EC08C_13();
extern "C" void _s800EC08C_14();
extern "C" void _s800EC08C_15();
extern "C" void _s800EC08C_16();
extern "C" void _s800EC08C_17();
extern "C" void _s800EC08C_18();
extern "C" void _s800EC08C_19();
extern "C" void _s800EC08C_20();
extern "C" void _s800EC08C_21();
extern "C" void _s800EC08C_22();
extern "C" void _s800EC08C_23();
extern "C" void _s800EC08C_24();
extern "C" void _s800EC08C_25();
extern "C" void _s800EC08C_26();
extern "C" void _s800EC08C_27();
extern "C" void _s800EC08C_28();
extern "C" void _s800EC08C_29();
extern "C" void _s800EC08C_30();
extern "C" void f_800EC08C() {}
