// 0x8031E2BC ERShader::DoLoad(EFile (1404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 25,0x24(1); stw 0,0x44(1); mr 27,3; mr 30,4; mr 31,5; addi 3,1,8; bl _s8031E2BC_0; lis 5,21320; addi 3,1,8; mr 4,30; ori 5,5,17490; li 6,22; li 7,22; bl _s8031E2BC_1; cmpwi 3,0; bne 2f; mr 3,27; mr 4,30; mr 5,31; bl _s8031E2BC_2; lbz 0,0x84(31); add 9,0,0; cmpwi 9,255; ble 0f; li 9,255; 0:; lbz 0,0xc4(31); stb 9,0x84(31); add 0,0,0; cmpwi 0,255; ble 1f; li 0,255; 1:; stb 0,0xc4(31); b 4f; 2:; lwz 0,0x10(27); addi 3,1,8; lwz 9,0x18(1); li 29,0; rlwimi 0,9,8,0,23; stw 0,0x10(27); bl _s8031E2BC_3; lwz 0,0x14(1); cmpwi 0,0; beq 3f; xori 29,0,1; subfic 6,29,0; adde 29,6,29; 3:; bl _s8031E2BC_4; lwz 4,0x18(1); li 5,0; bl _s8031E2BC_5; lwz 9,0x28(30); mr 25,3; mr 4,25; lwz 5,0x18(1); lha 3,0x18(9); mr 26,25; lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 29,0; beq 5f; mr 5,31; mr 4,26; mr 3,27; bl _s8031E2BC_6; bl _s8031E2BC_7; mr 4,26; bl _s8031E2BC_8; 4:; addi 3,1,8; li 4,2; bl _s8031E2BC_9; b 38f; 5:; lwz 0,0x58(27); mr 5,26; mr 3,27; mr 4,31; rlwinm 0,0,0,31,29; stw 0,0x58(27); bl _s8031E2BC_10; lbz 0,0x0(31); li 11,0; addi 8,31,48; mr 26,3; cmpw 11,0; bge 9f; li 10,2; li 7,127; mr 9,31; 6:; lwz 0,0x70(9); andi. 0,0,64; bne 7f; stb 0,0x83(9); stb 10,0x80(9); stb 10,0x81(9); stb 10,0x82(9); b 8f; 7:; lbz 0,0x80(9); cmpwi 0,0; bne 8f; lbz 0,0x81(9); cmpwi 0,2; bne 8f; lbz 0,0x82(9); cmpwi 0,2; bne 8f; lbz 0,0x83(9); cmpwi 0,1; bne 8f; lbz 0,0x84(9); andi. 6,0,128; beq 8f; stb 7,0x84(9); 8:; lbz 0,0x0(31); addi 11,11,1; addi 9,9,64; cmpw 11,0; blt 6b; 9:; li 0,3; lis 9,-32702; mtspr 9,0; lfs f13,0xa80(9); mr 11,8; li 9,0; 10:; lfsx f0,9,11; fcmpu 0,f0,f13; ble 11f; stfsx f13,9,8; 11:; addi 9,9,4; bdnz 10b; lwz 0,0xc(1); cmplwi 0,19; ble 17f; lwz 0,0x4(31); andis. 6,0,1024; beq 17f; lbz 28,0x88(31); cmpwi 28,0; ble 12f; rlwinm 30,28,2,0,29; lis 29,-32692; mr 4,30; li 5,8; addi 3,29,-17444; bl _s8031E2BC_11; mr 0,3; mr 4,26; stw 0,0x68(31); mr 5,30; add 26,26,30; bl _s8031E2BC_12; mr 4,30; li 5,8; addi 3,29,-17444; bl _s8031E2BC_13; mr 0,3; li 4,0; stw 0,0x34(27); mr 5,30; bl _s8031E2BC_14; mr 4,30; li 5,8; addi 3,29,-17444; bl _s8031E2BC_15; mr 0,3; mr 5,30; stw 0,0x38(27); li 4,0; bl _s8031E2BC_16; stw 28,0x30(27); 12:; addi 8,31,100; cmpwi 28,0; beq 16f; mtspr 9,28; li 7,1; li 10,0; 13:; lwz 9,0x4(8); lwzx 0,10,9; cmpwi 0,0; beq 14f; lwz 9,0x38(27); stwx 0,10,9; lwz 11,0x4(8); stwx 7,10,11; b 15f; 14:; stwx 0,10,9; 15:; addi 10,10,4; bdnz 13b; 16:; lhz 4,0x8a(31); cmpwi 4,0; beq 21f; lis 3,-32692; li 5,8; addi 3,3,-17444; bl _s8031E2BC_17; mr 0,3; lhz 5,0x8a(31); mr 4,26; stw 0,0x6c(31); bl _s8031E2BC_18; b 21f; 17:; lbz 0,0x0(31); li 10,0; cmpw 10,0; bge 21f; li 8,1; addi 11,27,40; li 9,100; 18:; lwzx 0,9,31; cmpwi 0,0; beq 19f; stw 0,0x0(11); stwx 8,9,31; b 20f; 19:; stwx 0,9,31; 20:; lbz 0,0x0(31); addi 10,10,1; addi 11,11,4; addi 9,9,64; cmpw 10,0; blt 18b; 21:; bl _s8031E2BC_19; mr 4,25; bl _s8031E2BC_20; lbz 0,0x0(31); li 8,0; li 10,0; cmpw 8,0; bge 27f; lis 9,-32702; li 6,5; lfs f13,0xa84(9); li 7,6; addi 11,31,100; 22:; lfs f0,0x28(11); fcmpu 0,f0,f13; bne 23f; lfs f0,0x2c(11); fcmpu 0,f0,f13; beq 25f; 23:; lwz 0,0x4(31); oris 0,0,32768; stw 0,0x4(31); lwz 0,0x10(11); lbz 9,0x22(11); ori 0,0,64; cmpwi 9,0; stw 0,0x10(11); bne 24f; stb 6,0x22(11); b 25f; 24:; cmpwi 9,1; bne 25f; stb 7,0x22(11); 25:; lbz 9,0x22(11); addi 9,9,-4; cmplwi 9,2; bgt 26f; li 8,1; 26:; lbz 0,0x0(31); addi 10,10,1; addi 11,11,64; cmpw 10,0; blt 22b; 27:; cmpwi 8,0; beq 28f; lwz 0,0x4(31); oris 0,0,2048; stw 0,0x4(31); 28:; lwz 0,0x4(31); andis. 6,0,1024; beq 31f; lwz 0,0x30(27); li 29,0; cmplw 29,0; bge 35f; lis 28,-32692; 29:; lwz 9,0x68(31); rlwinm 30,29,2,0,29; lwzx 0,30,9; cmpwi 0,0; beq 30f; lwz 9,0x38(27); addi 3,28,-7364; li 5,0; li 6,0; lwzx 4,30,9; bl _s8031E2BC_21; lwz 9,0x34(27); stwx 3,30,9; lwz 11,0x34(27); lwz 10,0x68(31); lwzx 9,30,11; lwz 0,0x14(9); stwx 0,30,10; 30:; addi 0,29,1; lwz 9,0x30(27); rlwinm 29,0,0,24,31; cmplw 29,9; blt 29b; b 35f; 31:; lbz 0,0x0(31); li 28,0; cmpw 28,0; bge 35f; addi 29,27,32; addi 30,31,100; lis 27,-32692; 32:; lwz 0,0x0(30); cmpwi 0,0; beq 34f; lwz 4,0x8(29); addi 3,27,-7364; li 5,0; li 6,0; bl _s8031E2BC_22; stw 3,0x0(29); cmpwi 3,0; beq 33f; lwz 0,0x14(3); stw 0,0x0(30); b 34f; 33:; stw 3,0x0(30); 34:; lbz 0,0x0(31); addi 28,28,1; addi 30,30,64; addi 29,29,4; cmpw 28,0; blt 32b; 35:; lbz 0,0x84(31); add 9,0,0; cmpwi 9,255; ble 36f; li 9,255; 36:; lbz 0,0xc4(31); stb 9,0x84(31); add 0,0,0; cmpwi 0,255; ble 37f; li 0,255; 37:; stb 0,0xc4(31); addi 3,1,8; li 4,2; bl _s8031E2BC_23; 38:; lwz 0,0x44(1); mtspr 8,0; lmw 25,0x24(1); addi 1,1,64"
extern "C" void _s8031E2BC_0();
extern "C" void _s8031E2BC_1();
extern "C" void _s8031E2BC_2();
extern "C" void _s8031E2BC_3();
extern "C" void _s8031E2BC_4();
extern "C" void _s8031E2BC_5();
extern "C" void _s8031E2BC_6();
extern "C" void _s8031E2BC_7();
extern "C" void _s8031E2BC_8();
extern "C" void _s8031E2BC_9();
extern "C" void _s8031E2BC_10();
extern "C" void _s8031E2BC_11();
extern "C" void _s8031E2BC_12();
extern "C" void _s8031E2BC_13();
extern "C" void _s8031E2BC_14();
extern "C" void _s8031E2BC_15();
extern "C" void _s8031E2BC_16();
extern "C" void _s8031E2BC_17();
extern "C" void _s8031E2BC_18();
extern "C" void _s8031E2BC_19();
extern "C" void _s8031E2BC_20();
extern "C" void _s8031E2BC_21();
extern "C" void _s8031E2BC_22();
extern "C" void _s8031E2BC_23();
extern "C" void f_8031E2BC() {}
