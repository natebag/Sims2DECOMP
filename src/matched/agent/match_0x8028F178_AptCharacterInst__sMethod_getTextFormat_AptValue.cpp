// 0x8028F178 AptCharacterInst::sMethod_getTextFormat(AptValue (1476 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 25,0x1c(1); stw 0,0x44(1); mr 25,3; cmpwi 4,2; ble 0f; lwz 3,-22936(13); b 38f; 0:; lwz 3,-23016(13); li 4,68; li 31,1; bl _s8028F178_0; mr 28,3; lwz 3,-26916(13); cmpwi 3,0; beq 3f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26916(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 1f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 2f; 1:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 2:; stw 31,0xc(3); mr 27,3; b 4f; 3:; lwz 3,-23020(13); li 4,16; bl _s8028F178_1; mr 30,3; li 4,5; mr 27,30; bl _s8028F178_2; lis 9,-32702; stw 31,0xc(30); addi 9,9,-29224; stw 9,0x8(30); 4:; lis 9,-32704; lwz 26,-22936(13); lfs f31,0x4e94(9); li 4,36; mr 3,28; li 30,0; bl _s8028F178_3; addi 31,28,36; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,28,12; stw 9,0x8(28); li 29,-1; bl _s8028F178_4; stb 30,0x20(28); lis 9,-32703; addi 9,9,21120; mr 3,31; lwz 0,0x20(28); stw 9,0x8(28); rlwinm 0,0,0,10,7; stw 0,0x20(28); bl _s8028F178_5; lis 0,273; stfs f31,0x4(31); ori 0,0,2; stw 29,0x8(31); stw 30,0x1c(31); mr 3,26; stw 30,0x14(31); stw 30,0x18(31); stw 0,0x10(31); bl _s8028F178_6; cmpwi 3,0; bne 5f; mr 3,26; mr 4,31; bl _s8028F178_7; 5:; mr 3,27; bl _s8028F178_8; mr. 30,3; bne 11f; addi 3,1,8; bl _s8028F178_9; addi 4,1,8; mr 3,27; bl _s8028F178_10; lis 4,-32704; addi 3,1,8; addi 4,4,18408; bl _s8028F178_11; cmpwi 3,0; bne 6f; lis 4,-32704; addi 3,1,8; addi 4,4,18416; bl _s8028F178_12; cmpwi 3,0; beq 7f; 6:; stw 30,0xc(31); b 10f; 7:; lis 4,-32704; addi 3,1,8; addi 4,4,18424; bl _s8028F178_13; cmpwi 3,0; beq 8f; li 0,2; b 9f; 8:; lis 4,-32704; addi 3,1,8; addi 4,4,18432; bl _s8028F178_14; cmpwi 3,0; li 0,3; beq 9f; li 0,1; 9:; stw 0,0xc(31); 10:; addi 3,1,8; li 4,2; bl _s8028F178_15; b 12f; 11:; li 0,3; stw 0,0xc(31); 12:; lis 9,-32703; addi 9,9,4912; stw 9,0x8(28); lwz 27,0x4c(25); lwz 0,0x68(27); cmpwi 0,0; bne 21f; lwz 3,-23020(13); li 4,32; li 30,-1; li 26,2; bl _s8028F178_16; mr 29,3; lis 9,-32704; lfs f31,0x4e98(9); lwz 31,-22936(13); bl _s8028F178_17; stfs f31,0x4(29); mr 3,31; stw 30,0x1c(29); stw 30,0x8(29); stw 26,0x10(29); stw 30,0x14(29); stw 30,0x18(29); bl _s8028F178_18; cmpwi 3,0; bne 13f; mr 3,31; mr 4,29; bl _s8028F178_19; 13:; mr 3,31; bl _s8028F178_20; mr. 30,3; bne 19f; addi 3,1,8; bl _s8028F178_21; addi 4,1,8; mr 3,31; bl _s8028F178_22; lis 4,-32704; addi 3,1,8; addi 4,4,18408; bl _s8028F178_23; cmpwi 3,0; bne 14f; lis 4,-32704; addi 3,1,8; addi 4,4,18416; bl _s8028F178_24; cmpwi 3,0; beq 15f; 14:; stw 30,0xc(29); b 18f; 15:; lis 4,-32704; addi 3,1,8; addi 4,4,18424; bl _s8028F178_25; cmpwi 3,0; beq 16f; stw 26,0xc(29); b 18f; 16:; lis 4,-32704; addi 3,1,8; addi 4,4,18432; bl _s8028F178_26; cmpwi 3,0; li 0,3; beq 17f; li 0,1; 17:; stw 0,0xc(29); 18:; addi 3,1,8; li 4,2; bl _s8028F178_27; b 20f; 19:; li 0,3; stw 0,0xc(29); 20:; stw 29,0x68(27); 21:; lwz 9,0x4c(25); addi 29,28,36; lwz 30,0x68(9); lwz 0,0xc(30); cmpwi 0,3; beq 22f; stw 0,0xc(29); 22:; lwz 0,0x8(30); cmpwi 0,-1; beq 23f; stw 0,0x8(29); 23:; lis 4,-32704; mr 3,30; addi 4,4,18440; bl _s8028F178_28; cmpwi 3,0; beq 24f; mr 3,29; mr 4,30; bl _s8028F178_29; 24:; lis 9,-32704; lfs f13,0x4(30); lfs f0,0x4e98(9); fcmpu 0,f13,f0; beq 25f; stfs f13,0x4(29); 25:; lwz 0,0x10(30); cmpwi 0,2; beq 26f; stw 0,0x10(29); 26:; lwz 0,0x14(30); cmpwi 0,-1; beq 27f; stw 0,0x14(29); 27:; lwz 0,0x18(30); cmpwi 0,-1; beq 28f; stw 0,0x18(29); 28:; lwz 3,0x1c(30); cmpwi 3,-1; beq 29f; stw 3,0x1c(29); 29:; lwz 0,0x34(28); andis. 9,0,16; bne 30f; oris 0,0,16; stw 0,0x34(28); 30:; lwz 0,0x34(28); andis. 9,0,256; bne 31f; oris 0,0,256; stw 0,0x34(28); 31:; lwz 0,0x34(28); andis. 9,0,1; bne 32f; oris 0,0,1; stw 0,0x34(28); 32:; lwz 0,0x2c(28); cmpwi 0,-1; bne 33f; lwz 9,0x4c(25); lwz 0,0x24(9); rlwinm 0,0,0,8,31; stw 0,0x2c(28); 33:; lwz 9,0x4c(25); lwz 11,0x8(9); lwz 9,0x4(11); lwz 10,0x18(11); addi 9,9,8; lwz 0,0xc(9); cmpw 10,0; bge 35f; cmpwi 10,-1; beq 35f; lwz 9,0x10(9); rlwinm 11,10,2,0,29; lwzx 9,11,9; lwz 0,0x0(9); cmpwi 0,3; bne 35f; lwz 4,0x8(9); addi 3,1,8; bl _s8028F178_30; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x24(28); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 34f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028F178_31; 34:; lwz 0,0x8(1); stw 0,0x24(28); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 37f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028F178_32; b 37f; 35:; lis 4,-32704; addi 3,1,8; addi 4,4,18440; bl _s8028F178_33; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x24(28); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 36f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028F178_34; 36:; lwz 0,0x8(1); stw 0,0x24(28); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 37f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8028F178_35; 37:; lwz 9,0x4c(25); mr 3,28; lwz 0,0x3c(9); stw 0,0x30(28); lwz 9,0x4c(25); lfs f0,0x60(9); stfs f0,0x28(28); 38:; lwz 0,0x44(1); mtspr 8,0; lmw 25,0x1c(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s8028F178_0();
extern "C" void _s8028F178_1();
extern "C" void _s8028F178_2();
extern "C" void _s8028F178_3();
extern "C" void _s8028F178_4();
extern "C" void _s8028F178_5();
extern "C" void _s8028F178_6();
extern "C" void _s8028F178_7();
extern "C" void _s8028F178_8();
extern "C" void _s8028F178_9();
extern "C" void _s8028F178_10();
extern "C" void _s8028F178_11();
extern "C" void _s8028F178_12();
extern "C" void _s8028F178_13();
extern "C" void _s8028F178_14();
extern "C" void _s8028F178_15();
extern "C" void _s8028F178_16();
extern "C" void _s8028F178_17();
extern "C" void _s8028F178_18();
extern "C" void _s8028F178_19();
extern "C" void _s8028F178_20();
extern "C" void _s8028F178_21();
extern "C" void _s8028F178_22();
extern "C" void _s8028F178_23();
extern "C" void _s8028F178_24();
extern "C" void _s8028F178_25();
extern "C" void _s8028F178_26();
extern "C" void _s8028F178_27();
extern "C" void _s8028F178_28();
extern "C" void _s8028F178_29();
extern "C" void _s8028F178_30();
extern "C" void _s8028F178_31();
extern "C" void _s8028F178_32();
extern "C" void _s8028F178_33();
extern "C" void _s8028F178_34();
extern "C" void _s8028F178_35();
extern "C" void f_8028F178() {}
