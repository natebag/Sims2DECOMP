// 0x8017348C CasSimState::GetMoreThanOneOption(unsigned (1736 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 29,0x3c(1); stw 0,0x4c(1); mr 31,3; mr 30,4; addi 3,1,8; bl _s8017348C_0; lwz 4,0x8c(31); addi 3,1,8; bl _s8017348C_1; cmpwi 30,21; beq 42f; bgt 6f; cmpwi 30,10; beq 27f; bgt 3f; cmpwi 30,4; beq 17f; bgt 1f; cmpwi 30,1; beq 13f; bgt 0f; cmpwi 30,0; beq 12f; b 69f; 0:; cmpwi 30,2; beq 15f; cmpwi 30,3; beq 16f; b 69f; 1:; cmpwi 30,7; beq 23f; bgt 2f; cmpwi 30,5; beq 19f; cmpwi 30,6; beq 21f; b 69f; 2:; cmpwi 30,8; beq 24f; cmpwi 30,9; beq 25f; b 69f; 3:; cmpwi 30,15; beq 35f; bgt 4f; cmpwi 30,12; beq 31f; blt 29f; cmpwi 30,13; beq 32f; cmpwi 30,14; beq 33f; b 69f; 4:; cmpwi 30,18; beq 38f; bgt 5f; cmpwi 30,16; beq 36f; cmpwi 30,17; beq 37f; b 69f; 5:; cmpwi 30,19; beq 39f; cmpwi 30,20; beq 41f; b 69f; 6:; cmpwi 30,32; beq 54f; bgt 9f; cmpwi 30,26; beq 47f; bgt 7f; cmpwi 30,23; beq 44f; blt 43f; cmpwi 30,24; beq 45f; cmpwi 30,25; beq 46f; b 69f; 7:; cmpwi 30,29; beq 51f; bgt 8f; cmpwi 30,27; beq 48f; cmpwi 30,28; beq 50f; b 69f; 8:; cmpwi 30,30; beq 52f; cmpwi 30,31; beq 53f; b 69f; 9:; cmpwi 30,37; beq 60f; bgt 10f; cmpwi 30,34; beq 57f; blt 56f; cmpwi 30,35; beq 58f; cmpwi 30,36; beq 59f; b 69f; 10:; cmpwi 30,40; beq 64f; bgt 11f; cmpwi 30,38; beq 61f; cmpwi 30,39; beq 62f; b 69f; 11:; cmpwi 30,41; beq 68f; cmpwi 30,45; beq 68f; b 69f; 12:; li 4,7; addi 3,1,8; bl _s8017348C_2; b 66f; 13:; lbz 5,0xa0(31); mr 3,31; li 4,8; li 6,1; extsb 5,5; addi 7,1,8; bl _s8017348C_3; li 30,1; lwz 0,0xa8(31); cmpw 3,0; bne 14f; li 30,0; 14:; addi 3,1,8; li 4,2; b 67f; 15:; lbz 5,0xa0(31); li 4,7; b 65f; 16:; li 4,9; addi 3,1,8; bl _s8017348C_4; b 66f; 17:; lbz 4,0xac(31); mr 3,31; li 5,1; addi 6,1,8; extsb 4,4; li 30,1; bl _s8017348C_5; lwz 0,0xb0(31); cmpw 3,0; bne 18f; li 30,0; 18:; addi 3,1,8; li 4,2; b 67f; 19:; lbz 4,0xac(31); mr 3,31; addi 5,1,8; li 30,1; extsb 4,4; bl _s8017348C_6; lwz 0,0xb4(31); cmpw 3,0; bne 20f; li 30,0; 20:; addi 3,1,8; li 4,2; b 67f; 21:; lbz 5,0xac(31); mr 3,31; li 4,11; li 6,1; extsb 5,5; addi 7,1,8; bl _s8017348C_7; li 30,1; lwz 0,0xb8(31); cmpw 3,0; bne 22f; li 30,0; 22:; addi 3,1,8; li 4,2; b 67f; 23:; lbz 5,0xac(31); li 4,9; b 65f; 24:; li 4,12; addi 3,1,8; bl _s8017348C_8; b 66f; 25:; lbz 4,0xbc(31); mr 3,31; addi 5,1,8; li 30,1; extsb 4,4; bl _s8017348C_9; lwz 0,0xc0(31); cmpw 3,0; bne 26f; li 30,0; 26:; addi 3,1,8; li 4,2; b 67f; 27:; lbz 4,0xbc(31); mr 3,31; li 5,1; addi 6,1,8; extsb 4,4; li 30,1; bl _s8017348C_10; lwz 0,0xc4(31); cmpw 3,0; bne 28f; li 30,0; 28:; addi 3,1,8; li 4,2; b 67f; 29:; lbz 5,0xbc(31); mr 3,31; li 4,14; li 6,1; extsb 5,5; addi 7,1,8; bl _s8017348C_11; li 30,1; lwz 0,0xc8(31); cmpw 3,0; bne 30f; li 30,0; 30:; addi 3,1,8; li 4,2; b 67f; 31:; lbz 5,0xbc(31); li 4,12; b 65f; 32:; li 4,15; addi 3,1,8; bl _s8017348C_12; b 66f; 33:; lbz 4,0xcc(31); mr 3,31; li 5,1; addi 6,1,8; extsb 4,4; li 30,1; bl _s8017348C_13; lwz 0,0xd0(31); cmpw 3,0; bne 34f; li 30,0; 34:; addi 3,1,8; li 4,2; b 67f; 35:; lbz 5,0xcc(31); li 4,15; b 65f; 36:; li 4,16; addi 3,1,8; bl _s8017348C_14; b 66f; 37:; lbz 5,0xd4(31); li 4,16; b 65f; 38:; li 4,2; addi 3,1,8; bl _s8017348C_15; b 66f; 39:; lbz 4,0x95(31); mr 3,31; li 5,1; addi 6,1,8; extsb 4,4; li 30,1; bl _s8017348C_16; lwz 0,0x98(31); cmpw 3,0; bne 40f; li 30,0; 40:; addi 3,1,8; li 4,2; b 67f; 41:; lbz 5,0x95(31); li 4,2; b 65f; 42:; li 4,1; addi 3,1,8; bl _s8017348C_17; b 66f; 43:; li 4,18; addi 3,1,8; bl _s8017348C_18; b 66f; 44:; li 4,0; addi 3,1,8; bl _s8017348C_19; b 66f; 45:; li 4,1; addi 3,1,8; bl _s8017348C_20; b 66f; 46:; li 4,2; addi 3,1,8; bl _s8017348C_21; b 66f; 47:; li 4,19; addi 3,1,8; bl _s8017348C_22; b 66f; 48:; lbz 4,0xdd(31); mr 3,31; li 5,1; addi 6,1,8; extsb 4,4; li 30,1; bl _s8017348C_23; lwz 0,0xe0(31); cmpw 3,0; bne 49f; li 30,0; 49:; addi 3,1,8; li 4,2; b 67f; 50:; lbz 5,0xdd(31); li 4,19; b 65f; 51:; li 4,0; addi 3,1,8; bl _s8017348C_24; b 66f; 52:; lbz 5,0x92(31); li 4,0; b 65f; 53:; li 4,21; addi 3,1,8; bl _s8017348C_25; b 66f; 54:; lbz 4,0xf2(31); mr 3,31; li 5,1; addi 6,1,8; extsb 4,4; li 30,1; bl _s8017348C_26; lwz 0,0xf4(31); cmpw 3,0; bne 55f; li 30,0; 55:; addi 3,1,8; li 4,2; b 67f; 56:; lbz 5,0xf2(31); li 4,21; b 65f; 57:; li 4,25; addi 3,1,8; bl _s8017348C_27; b 66f; 58:; lbz 5,0xf0(31); li 4,25; b 65f; 59:; li 4,20; addi 3,1,8; bl _s8017348C_28; b 66f; 60:; lbz 5,0xf8(31); li 4,20; b 65f; 61:; li 4,22; addi 3,1,8; bl _s8017348C_29; b 66f; 62:; addi 30,1,24; li 5,23; addi 4,31,8; mr 3,30; bl _s8017348C_30; li 29,1; li 0,1; lwz 8,0x18(1); stw 0,0x20(1); addi 9,1,40; stw 0,0x1c(1); mr 6,9; addi 3,1,8; li 4,23; lbz 5,0xe4(31); lwz 10,0xc(30); lwz 11,0x4(30); extsb 5,5; lwz 0,0x8(30); stw 8,0x28(1); stw 11,0x4(9); stw 0,0x8(9); stw 10,0xc(9); bl _s8017348C_31; cmpwi 3,0; bne 63f; li 29,0; 63:; addi 3,1,8; li 4,2; bl _s8017348C_32; mr 3,29; b 70f; 64:; lbz 5,0xe4(31); li 4,22; 65:; addi 3,1,8; extsb 5,5; bl _s8017348C_33; 66:; subfic 30,3,1; subfe 30,30,30; neg 30,30; li 4,2; addi 3,1,8; 67:; bl _s8017348C_34; mr 3,30; b 70f; 68:; addi 3,1,8; li 4,2; bl _s8017348C_35; li 3,1; b 70f; 69:; addi 3,1,8; li 4,2; bl _s8017348C_36; li 3,0; 70:; lwz 0,0x4c(1); mtspr 8,0; lmw 29,0x3c(1); addi 1,1,72"
extern "C" void _s8017348C_0();
extern "C" void _s8017348C_1();
extern "C" void _s8017348C_2();
extern "C" void _s8017348C_3();
extern "C" void _s8017348C_4();
extern "C" void _s8017348C_5();
extern "C" void _s8017348C_6();
extern "C" void _s8017348C_7();
extern "C" void _s8017348C_8();
extern "C" void _s8017348C_9();
extern "C" void _s8017348C_10();
extern "C" void _s8017348C_11();
extern "C" void _s8017348C_12();
extern "C" void _s8017348C_13();
extern "C" void _s8017348C_14();
extern "C" void _s8017348C_15();
extern "C" void _s8017348C_16();
extern "C" void _s8017348C_17();
extern "C" void _s8017348C_18();
extern "C" void _s8017348C_19();
extern "C" void _s8017348C_20();
extern "C" void _s8017348C_21();
extern "C" void _s8017348C_22();
extern "C" void _s8017348C_23();
extern "C" void _s8017348C_24();
extern "C" void _s8017348C_25();
extern "C" void _s8017348C_26();
extern "C" void _s8017348C_27();
extern "C" void _s8017348C_28();
extern "C" void _s8017348C_29();
extern "C" void _s8017348C_30();
extern "C" void _s8017348C_31();
extern "C" void _s8017348C_32();
extern "C" void _s8017348C_33();
extern "C" void _s8017348C_34();
extern "C" void _s8017348C_35();
extern "C" void _s8017348C_36();
extern "C" void f_8017348C() {}
