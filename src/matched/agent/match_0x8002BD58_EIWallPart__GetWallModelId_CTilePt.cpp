// 0x8002BD58 EIWallPart::GetWallModelId(CTilePt (1172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 20,0x38(1); stw 0,0x6c(1); li 0,0; mr 25,3; mr 23,6; mr 31,7; stw 0,0x354(25); mr 27,4; mr 24,5; mr 28,8; mr 3,23; bl _s8002BD58_0; addi 0,31,-3; mr 30,3; cmplwi 0,1; bgt 0f; addi 30,30,2; 0:; lis 9,-32702; rlwinm 0,30,2,0,29; addi 9,9,14856; mr 6,31; lwzx 0,9,0; mr 4,24; mr 5,23; mr 3,27; mtspr 8,0; blrl; xoris 0,30,32768; stw 0,0x34(1); lis 8,17200; lis 9,-32707; lis 10,-32707; stw 8,0x30(1); mr 29,3; lfd f12,0xdc0(9); mr 3,24; lfd f0,0x30(1); lis 9,-32707; lfs f11,0xdc8(10); mr 4,23; fsub f0,f0,f12; lfs f13,0xdcc(9); frsp f0,f0; fmuls f0,f0,f11; fmuls f0,f0,f13; stfs f0,0x0(28); bl _s8002BD58_1; cmpwi 3,3; beq 1f; cmpwi 3,5; beq 1f; cmpwi 3,6; beq 1f; cmpwi 3,15; beq 1f; cmpwi 3,23; bne 2f; 1:; li 0,1; b 3f; 2:; li 0,0; 3:; cmpwi 0,0; beq 9f; addi 30,1,8; mr 3,24; bl _s8002BD58_2; li 31,0; mr 4,27; mr 3,30; li 5,0; bl _s8002BD58_3; mr 20,30; rlwinm 26,29,2,0,29; b 5f; 4:; addi 3,1,8; bl _s8002BD58_4; 5:; lwz 0,0x4(20); cmpwi 0,0; beq 6f; mr 31,0; li 4,6; lwz 3,0x0(31); bl _s8002BD58_5; cmpwi 3,0; beq 4b; 6:; cmpwi 31,0; beq 7f; lwz 3,0x0(31); li 4,6; bl _s8002BD58_6; cmpwi 3,0; beq 25f; lwz 9,0x4(31); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,31,3; blrl; lha 11,0xa2(3); lis 9,-32702; addi 9,9,15020; mulli 11,11,40; addi 8,9,40; addi 9,9,76; add 10,26,11; lwzx 30,9,11; lwzx 0,8,10; stw 0,0x354(25); lwz 11,0x0(31); b 27f; 7:; lis 9,-32702; addi 9,9,15020; lwzx 0,9,26; b 32f; 8:; mr 3,21; li 4,2; bl _s8002BD58_7; b 21f; 9:; cmpwi 3,22; bne 29f; addi 30,1,8; mr 3,24; bl _s8002BD58_8; rlwinm 26,29,2,0,29; mr 3,30; mr 4,27; li 5,0; mr 20,30; bl _s8002BD58_9; li 29,0; lwz 0,0x4(30); cmpwi 0,0; beq 21f; addi 31,1,24; 10:; lwz 29,0x4(20); cmpwi 29,0; beq 12f; lwz 3,0x0(29); li 4,6; bl _s8002BD58_10; b 13f; 11:; li 22,1; b 19f; 12:; li 3,0; 13:; cmpwi 3,0; beq 20f; lwz 9,0x4(29); li 22,0; mr 21,31; lwz 0,0x36c(9); lha 3,0x368(9); mtspr 8,0; add 3,29,3; blrl; bl _s8002BD58_11; mr 28,3; mr 3,31; bl _s8002BD58_12; lbz 0,0x2(27); mr 3,23; lbz 11,0x0(27); mr 4,31; lbz 9,0x1(27); stb 0,0x1a(1); stb 11,0x18(1); stb 9,0x19(1); bl _s8002BD58_13; addi 3,1,32; mr 4,31; li 5,0; bl _s8002BD58_14; b 18f; 14:; lwz 30,0x24(1); cmpwi 30,0; beq 15f; lwz 3,0x0(30); li 4,6; bl _s8002BD58_15; b 16f; 15:; li 3,0; 16:; cmpwi 3,0; beq 17f; lwz 9,0x4(30); lha 3,0x368(9); lwz 0,0x36c(9); add 3,30,3; mtspr 8,0; blrl; bl _s8002BD58_16; cmpw 3,28; beq 11b; 17:; addi 3,1,32; bl _s8002BD58_17; 18:; lwz 0,0x24(1); cmpwi 0,0; bne 14b; 19:; cmpwi 22,0; bne 8b; mr 3,21; li 4,2; bl _s8002BD58_18; 20:; addi 3,1,8; bl _s8002BD58_19; lwz 0,0x4(20); cmpwi 0,0; bne 10b; 21:; lis 9,-32697; cmpwi 29,0; lwz 0,0x5c74(9); mfcr 31; cmpwi 0,0; bne 24f; mtcrf 128,31; beq 22f; lwz 3,0x0(29); li 4,6; bl _s8002BD58_20; b 23f; 22:; li 3,0; 23:; cmpwi 3,0; bne 24f; lis 9,-32702; addi 9,9,15020; lwzx 0,9,26; b 32f; 24:; mtcrf 128,31; beq 28f; lwz 3,0x0(29); li 4,6; bl _s8002BD58_21; cmpwi 3,0; bne 26f; 25:; lis 9,-32702; mr 3,24; addi 9,9,15020; mr 5,23; lwzx 0,9,26; li 4,1; stw 0,0x354(25); bl _s8002BD58_22; b 33f; 26:; lwz 9,0x4(29); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,29,3; blrl; lha 11,0xa2(3); lis 9,-32702; addi 9,9,15020; mulli 11,11,40; addi 8,9,200; addi 9,9,236; add 10,26,11; lwzx 30,9,11; lwzx 0,8,10; stw 0,0x354(25); lwz 11,0x0(29); 27:; lwz 9,0x18(11); lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; stw 30,0x14(3); b 33f; 28:; lis 9,-32702; addi 9,9,15020; lwzx 0,9,26; b 32f; 29:; mr 3,24; bl _s8002BD58_23; cmpwi 3,0; bne 30f; lis 9,-32702; rlwinm 11,29,2,0,29; addi 9,9,15020; b 31f; 30:; lis 9,-32702; rlwinm 11,29,2,0,29; addi 9,9,15620; 31:; lwzx 0,9,11; 32:; stw 0,0x354(25); 33:; lis 3,-32692; lwz 4,0x354(25); addi 3,3,-27556; bl _s8002BD58_24; lwz 0,0x6c(1); mtspr 8,0; lmw 20,0x38(1); addi 1,1,104"
extern "C" void _s8002BD58_0();
extern "C" void _s8002BD58_1();
extern "C" void _s8002BD58_2();
extern "C" void _s8002BD58_3();
extern "C" void _s8002BD58_4();
extern "C" void _s8002BD58_5();
extern "C" void _s8002BD58_6();
extern "C" void _s8002BD58_7();
extern "C" void _s8002BD58_8();
extern "C" void _s8002BD58_9();
extern "C" void _s8002BD58_10();
extern "C" void _s8002BD58_11();
extern "C" void _s8002BD58_12();
extern "C" void _s8002BD58_13();
extern "C" void _s8002BD58_14();
extern "C" void _s8002BD58_15();
extern "C" void _s8002BD58_16();
extern "C" void _s8002BD58_17();
extern "C" void _s8002BD58_18();
extern "C" void _s8002BD58_19();
extern "C" void _s8002BD58_20();
extern "C" void _s8002BD58_21();
extern "C" void _s8002BD58_22();
extern "C" void _s8002BD58_23();
extern "C" void _s8002BD58_24();
extern "C" void f_8002BD58() {}
