// 0x80172D68 CasSimState::GetAdjacentIndex(unsigned (1828 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 30,3; mr 31,4; li 26,1; mr. 28,5; bne 0f; li 26,-1; 0:; addi 3,1,8; li 27,0; bl _s80172D68_0; li 29,0; lwz 4,0x8c(30); addi 3,1,8; bl _s80172D68_1; cmpwi 31,21; beq 34f; bgt 7f; cmpwi 31,10; beq 23f; bgt 4f; cmpwi 31,4; beq 17f; bgt 2f; cmpwi 31,1; beq 14f; bgt 1f; cmpwi 31,0; beq 13f; b 58f; 1:; cmpwi 31,2; beq 15f; cmpwi 31,3; beq 16f; b 58f; 2:; cmpwi 31,7; beq 20f; bgt 3f; cmpwi 31,5; beq 18f; cmpwi 31,6; beq 19f; b 58f; 3:; cmpwi 31,8; beq 21f; cmpwi 31,9; beq 22f; b 58f; 4:; cmpwi 31,15; beq 28f; bgt 5f; cmpwi 31,12; beq 25f; blt 24f; cmpwi 31,13; beq 26f; cmpwi 31,14; beq 27f; b 58f; 5:; cmpwi 31,18; beq 31f; bgt 6f; cmpwi 31,16; beq 29f; cmpwi 31,17; beq 30f; b 58f; 6:; cmpwi 31,19; beq 32f; cmpwi 31,20; beq 33f; b 58f; 7:; cmpwi 31,32; beq 46f; bgt 10f; cmpwi 31,26; beq 40f; bgt 8f; cmpwi 31,23; beq 36f; blt 35f; cmpwi 31,24; beq 37f; cmpwi 31,25; beq 38f; b 58f; 8:; cmpwi 31,29; beq 43f; bgt 9f; cmpwi 31,27; beq 41f; cmpwi 31,28; beq 42f; b 58f; 9:; cmpwi 31,30; beq 44f; cmpwi 31,31; beq 45f; b 58f; 10:; cmpwi 31,37; beq 51f; bgt 11f; cmpwi 31,34; beq 48f; blt 47f; cmpwi 31,35; beq 49f; cmpwi 31,36; beq 50f; b 58f; 11:; cmpwi 31,40; beq 54f; bgt 12f; cmpwi 31,38; beq 52f; cmpwi 31,39; beq 53f; b 58f; 12:; cmpwi 31,41; beq 56f; cmpwi 31,45; beq 57f; b 58f; 13:; addi 3,1,8; li 4,7; bl _s80172D68_2; lbz 0,0xa0(30); b 55f; 14:; lbz 5,0xa0(30); mr 6,28; li 4,8; addi 7,1,8; extsb 5,5; mr 3,30; bl _s80172D68_3; mr 31,3; li 4,2; addi 3,1,8; b 62f; 15:; lbz 5,0xa0(30); addi 3,1,8; li 4,7; extsb 5,5; bl _s80172D68_4; lbz 0,0xa1(30); b 55f; 16:; addi 3,1,8; li 4,9; bl _s80172D68_5; lbz 0,0xac(30); b 55f; 17:; lbz 4,0xac(30); mr 5,28; addi 6,1,8; mr 3,30; extsb 4,4; bl _s80172D68_6; mr 31,3; li 4,2; addi 3,1,8; b 62f; 18:; lbz 4,0xac(30); addi 5,1,8; mr 3,30; extsb 4,4; bl _s80172D68_7; mr 31,3; li 4,2; addi 3,1,8; b 62f; 19:; lbz 5,0xac(30); mr 6,28; li 4,11; addi 7,1,8; extsb 5,5; mr 3,30; bl _s80172D68_8; mr 31,3; li 4,2; addi 3,1,8; b 62f; 20:; lbz 5,0xac(30); addi 3,1,8; li 4,9; extsb 5,5; bl _s80172D68_9; lbz 0,0xad(30); b 55f; 21:; addi 3,1,8; li 4,12; bl _s80172D68_10; lbz 0,0xbc(30); b 55f; 22:; lbz 4,0xbc(30); addi 5,1,8; mr 3,30; extsb 4,4; bl _s80172D68_11; mr 31,3; li 4,2; addi 3,1,8; b 62f; 23:; lbz 4,0xbc(30); mr 5,28; addi 6,1,8; mr 3,30; extsb 4,4; bl _s80172D68_12; mr 31,3; li 4,2; addi 3,1,8; b 62f; 24:; lbz 5,0xbc(30); mr 6,28; li 4,14; addi 7,1,8; extsb 5,5; mr 3,30; bl _s80172D68_13; mr 31,3; li 4,2; addi 3,1,8; b 62f; 25:; lbz 5,0xbc(30); addi 3,1,8; li 4,12; extsb 5,5; bl _s80172D68_14; lbz 0,0xbd(30); b 55f; 26:; addi 3,1,8; li 4,15; bl _s80172D68_15; lbz 0,0xcc(30); b 55f; 27:; lbz 4,0xcc(30); mr 5,28; addi 6,1,8; mr 3,30; extsb 4,4; bl _s80172D68_16; mr 31,3; li 4,2; addi 3,1,8; b 62f; 28:; lbz 5,0xcc(30); addi 3,1,8; li 4,15; extsb 5,5; bl _s80172D68_17; lbz 0,0xcd(30); b 55f; 29:; addi 3,1,8; li 4,16; bl _s80172D68_18; lbz 0,0xd4(30); b 55f; 30:; lbz 5,0xd4(30); addi 3,1,8; li 4,16; extsb 5,5; bl _s80172D68_19; lbz 0,0xd5(30); b 55f; 31:; addi 3,1,8; li 4,2; bl _s80172D68_20; lbz 0,0x95(30); b 55f; 32:; lbz 4,0x95(30); mr 5,28; addi 6,1,8; mr 3,30; extsb 4,4; bl _s80172D68_21; mr 31,3; li 4,2; addi 3,1,8; b 62f; 33:; lbz 5,0x95(30); addi 3,1,8; li 4,2; extsb 5,5; bl _s80172D68_22; lbz 0,0x96(30); b 55f; 34:; addi 3,1,8; li 4,1; bl _s80172D68_23; lbz 0,0x94(30); b 55f; 35:; addi 3,1,8; li 4,18; bl _s80172D68_24; lbz 0,0xdc(30); b 55f; 36:; addi 3,1,8; li 4,0; bl _s80172D68_25; lbz 0,0xfa(30); b 39f; 37:; addi 3,1,8; li 4,1; bl _s80172D68_26; lbz 0,0xfb(30); b 39f; 38:; addi 3,1,8; li 4,2; bl _s80172D68_27; lbz 0,0xfc(30); 39:; mr 27,3; extsb 29,0; b 58f; 40:; addi 3,1,8; li 4,19; bl _s80172D68_28; lbz 0,0xdd(30); b 55f; 41:; lbz 4,0xdd(30); mr 5,28; addi 6,1,8; mr 3,30; extsb 4,4; bl _s80172D68_29; mr 31,3; li 4,2; addi 3,1,8; b 62f; 42:; lbz 5,0xdd(30); addi 3,1,8; li 4,19; extsb 5,5; bl _s80172D68_30; lbz 0,0xde(30); b 55f; 43:; addi 3,1,8; li 4,0; bl _s80172D68_31; lbz 0,0x92(30); b 55f; 44:; lbz 5,0x92(30); addi 3,1,8; li 4,0; extsb 5,5; bl _s80172D68_32; lbz 0,0x93(30); b 55f; 45:; addi 3,1,8; li 4,21; bl _s80172D68_33; lbz 0,0xf2(30); b 55f; 46:; lbz 4,0xf2(30); mr 5,28; addi 6,1,8; mr 3,30; extsb 4,4; bl _s80172D68_34; mr 31,3; li 4,2; addi 3,1,8; b 62f; 47:; lbz 5,0xf2(30); addi 3,1,8; li 4,21; extsb 5,5; bl _s80172D68_35; lbz 0,0xf3(30); b 55f; 48:; addi 3,1,8; li 4,25; bl _s80172D68_36; lbz 0,0xf0(30); b 55f; 49:; lbz 5,0xf0(30); addi 3,1,8; li 4,25; extsb 5,5; bl _s80172D68_37; lbz 0,0xf1(30); b 55f; 50:; addi 3,1,8; li 4,20; bl _s80172D68_38; lbz 0,0xf8(30); b 55f; 51:; lbz 5,0xf8(30); addi 3,1,8; li 4,20; extsb 5,5; bl _s80172D68_39; lbz 0,0xf9(30); b 55f; 52:; addi 3,1,8; li 4,22; bl _s80172D68_40; lbz 0,0xe4(30); b 55f; 53:; lwz 0,0xe8(30); li 27,1; li 29,0; cmpwi 0,0; beq 58f; lwz 0,0xec(30); cmpwi 0,0; beq 58f; li 29,1; b 58f; 54:; lbz 5,0xe4(30); addi 3,1,8; li 4,22; extsb 5,5; bl _s80172D68_41; lbz 0,0xe5(30); 55:; addi 27,3,-1; extsb 29,0; b 58f; 56:; lbz 0,0x90(30); extsb 29,0; add 31,29,26; cmpwi 31,2; bgt 59f; cmpwi 31,0; bge 61f; li 31,2; b 61f; 57:; lbz 0,0x91(30); extsb 29,0; add 31,29,26; cmpwi 31,10; bgt 59f; cmpwi 31,0; bge 61f; li 31,10; b 61f; 58:; cmpwi 27,0; li 31,0; beq 61f; add 31,29,26; cmpw 31,27; ble 60f; 59:; li 31,0; b 61f; 60:; cmpwi 31,0; bge 61f; mr 31,27; 61:; addi 3,1,8; li 4,2; 62:; bl _s80172D68_42; mr 3,31; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"
extern "C" void _s80172D68_0();
extern "C" void _s80172D68_1();
extern "C" void _s80172D68_2();
extern "C" void _s80172D68_3();
extern "C" void _s80172D68_4();
extern "C" void _s80172D68_5();
extern "C" void _s80172D68_6();
extern "C" void _s80172D68_7();
extern "C" void _s80172D68_8();
extern "C" void _s80172D68_9();
extern "C" void _s80172D68_10();
extern "C" void _s80172D68_11();
extern "C" void _s80172D68_12();
extern "C" void _s80172D68_13();
extern "C" void _s80172D68_14();
extern "C" void _s80172D68_15();
extern "C" void _s80172D68_16();
extern "C" void _s80172D68_17();
extern "C" void _s80172D68_18();
extern "C" void _s80172D68_19();
extern "C" void _s80172D68_20();
extern "C" void _s80172D68_21();
extern "C" void _s80172D68_22();
extern "C" void _s80172D68_23();
extern "C" void _s80172D68_24();
extern "C" void _s80172D68_25();
extern "C" void _s80172D68_26();
extern "C" void _s80172D68_27();
extern "C" void _s80172D68_28();
extern "C" void _s80172D68_29();
extern "C" void _s80172D68_30();
extern "C" void _s80172D68_31();
extern "C" void _s80172D68_32();
extern "C" void _s80172D68_33();
extern "C" void _s80172D68_34();
extern "C" void _s80172D68_35();
extern "C" void _s80172D68_36();
extern "C" void _s80172D68_37();
extern "C" void _s80172D68_38();
extern "C" void _s80172D68_39();
extern "C" void _s80172D68_40();
extern "C" void _s80172D68_41();
extern "C" void _s80172D68_42();
extern "C" void f_80172D68() {}
