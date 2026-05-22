// 0x802AF1D4 AptTextFormat::objectMemberLookup(AptValue (1440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 29,0x1c(1); stw 0,0x34(1); mr 29,3; cmpwi 4,0; beq 0f; lwz 3,0x0(5); lhz 4,0x2(3); addi 3,3,8; bl _s802AF1D4_0; b 1f; 0:; li 3,0; 1:; cmpwi 3,0; beq 46f; lwz 3,0x4(3); cmpwi 3,7; beq 33f; bgt 3f; cmpwi 3,3; beq 15f; bgt 2f; cmpwi 3,1; beq 5f; b 46f; 2:; cmpwi 3,5; beq 20f; cmpwi 3,6; beq 26f; b 46f; 3:; cmpwi 3,11; beq 37f; bgt 4f; cmpwi 3,8; beq 34f; cmpwi 3,10; beq 36f; b 46f; 4:; cmpwi 3,14; beq 38f; cmpwi 3,15; beq 42f; b 46f; 5:; lwz 30,-26892(13); cmpwi 30,0; beq 9f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 6f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 7f; 6:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 7:; addi 31,30,12; mr 3,31; bl _s802AF1D4_1; cmpwi 3,0; bne 8f; mr 3,31; li 4,0; bl _s802AF1D4_2; 8:; mr 31,30; b 10f; 9:; lwz 3,-23020(13); li 4,20; bl _s802AF1D4_3; bl _s802AF1D4_4; mr 31,3; 10:; lwz 3,0x30(29); cmpwi 3,1; beq 13f; bgt 11f; cmpwi 3,0; beq 12f; b 21f; 11:; cmpwi 3,2; beq 14f; cmpwi 3,3; b 21f; 12:; lis 4,-32694; addi 3,31,12; addi 4,4,-11332; addi 4,4,344; bl _s802AF1D4_5; b 32f; 13:; lis 4,-32694; addi 3,31,12; addi 4,4,-11332; addi 4,4,504; bl _s802AF1D4_6; b 32f; 14:; lis 4,-32694; addi 3,31,12; addi 4,4,-11332; addi 4,4,164; bl _s802AF1D4_7; b 32f; 15:; lwz 3,0x34(29); andis. 0,3,1; beq 21f; li 31,0; andi. 0,3,1; beq 16f; li 31,1; 16:; lwz 3,-26916(13); cmpwi 3,0; beq 44f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26916(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 18f; 17:; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 19f; 18:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 19:; stw 31,0xc(3); b 47f; 20:; lwz 0,0x2c(29); cmpwi 0,-1; bne 22f; 21:; lwz 3,-22936(13); b 47f; 22:; lwz 3,-26908(13); rlwinm 31,0,0,8,31; cmpwi 3,0; beq 25f; 23:; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); 24:; stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; bge 17b; b 18b; 25:; lwz 3,-23020(13); li 4,16; bl _s802AF1D4_8; mr 30,3; li 4,7; bl _s802AF1D4_9; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; b 45f; 26:; lwz 0,0x24(29); lis 9,-32700; addi 9,9,-6476; cmpw 0,9; beq 21b; lwz 30,-26892(13); cmpwi 30,0; beq 30f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 27f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 28f; 27:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 28:; addi 31,30,12; mr 3,31; bl _s802AF1D4_10; cmpwi 3,0; bne 29f; mr 3,31; li 4,0; bl _s802AF1D4_11; 29:; mr 31,30; b 31f; 30:; lwz 3,-23020(13); li 4,20; bl _s802AF1D4_12; bl _s802AF1D4_13; mr 31,3; 31:; lwz 4,0x24(29); addi 3,1,8; addi 30,31,12; addi 4,4,8; bl _s802AF1D4_14; addi 4,1,8; mr 3,30; bl _s802AF1D4_15; addi 3,1,8; li 4,2; bl _s802AF1D4_16; 32:; mr 3,31; b 47f; 33:; lwz 31,0x38(29); cmpwi 31,-1; beq 21b; lwz 3,-26908(13); cmpwi 3,0; bne 23b; lwz 3,-23020(13); li 4,16; bl _s802AF1D4_17; mr 30,3; li 4,7; bl _s802AF1D4_18; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; b 45f; 34:; lwz 3,0x34(29); andis. 0,3,16; beq 21b; li 31,0; andi. 0,3,16; beq 35f; li 31,1; 35:; lwz 3,-26916(13); cmpwi 3,0; beq 44f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26916(13); b 24b; 36:; lwz 31,0x3c(29); cmpwi 31,-1; beq 21b; lwz 3,-26908(13); cmpwi 3,0; bne 23b; lwz 3,-23020(13); li 4,16; bl _s802AF1D4_19; mr 30,3; li 4,7; bl _s802AF1D4_20; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; b 45f; 37:; lwz 31,0x40(29); cmpwi 31,-1; beq 21b; lwz 3,-26908(13); cmpwi 3,0; bne 23b; lwz 3,-23020(13); li 4,16; bl _s802AF1D4_21; mr 30,3; li 4,7; bl _s802AF1D4_22; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; b 45f; 38:; lis 9,-32703; lfs f31,0x28(29); lfs f0,0x1318(9); fcmpu 0,f31,f0; beq 21b; lwz 3,-26912(13); cmpwi 3,0; beq 41f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26912(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 39f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 40f; 39:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 40:; stfs f31,0xc(3); b 47f; 41:; lwz 3,-23020(13); li 4,16; bl _s802AF1D4_23; mr 30,3; li 4,6; bl _s802AF1D4_24; lis 9,-32702; stfs f31,0xc(30); addi 9,9,-26784; b 45f; 42:; lwz 3,0x34(29); andis. 0,3,256; beq 21b; li 31,0; andi. 0,3,256; beq 43f; li 31,1; 43:; lwz 3,-26916(13); cmpwi 3,0; beq 44f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26916(13); b 24b; 44:; lwz 3,-23020(13); li 4,16; bl _s802AF1D4_25; mr 30,3; li 4,5; bl _s802AF1D4_26; lis 9,-32702; stw 31,0xc(30); addi 9,9,-29224; 45:; mr 3,30; stw 9,0x8(30); b 47f; 46:; li 3,0; 47:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x1c(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s802AF1D4_0();
extern "C" void _s802AF1D4_1();
extern "C" void _s802AF1D4_2();
extern "C" void _s802AF1D4_3();
extern "C" void _s802AF1D4_4();
extern "C" void _s802AF1D4_5();
extern "C" void _s802AF1D4_6();
extern "C" void _s802AF1D4_7();
extern "C" void _s802AF1D4_8();
extern "C" void _s802AF1D4_9();
extern "C" void _s802AF1D4_10();
extern "C" void _s802AF1D4_11();
extern "C" void _s802AF1D4_12();
extern "C" void _s802AF1D4_13();
extern "C" void _s802AF1D4_14();
extern "C" void _s802AF1D4_15();
extern "C" void _s802AF1D4_16();
extern "C" void _s802AF1D4_17();
extern "C" void _s802AF1D4_18();
extern "C" void _s802AF1D4_19();
extern "C" void _s802AF1D4_20();
extern "C" void _s802AF1D4_21();
extern "C" void _s802AF1D4_22();
extern "C" void _s802AF1D4_23();
extern "C" void _s802AF1D4_24();
extern "C" void _s802AF1D4_25();
extern "C" void _s802AF1D4_26();
extern "C" void f_802AF1D4() {}
