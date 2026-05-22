// 0x801EFA1C INVTarget::Cheat_InstallSelectedCategoryObjectShaders(int) (1588 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; mfcr 12; stmw 23,0xc(1); stw 0,0x34(1); stw 12,0x8(1); mr 31,3; mr 28,4; lbz 0,0x3251(31); cmpwi 0,10; beq 21f; bgt 0f; cmpwi 0,0; blt 39f; cmpwi 0,8; ble 1f; b 11f; 0:; cmpwi 0,11; beq 30f; cmpwi 0,13; bgt 39f; 1:; lbz 9,0x3251(31); addi 11,31,320; rlwinm 9,9,2,0,29; lwzx 29,11,9; lwz 0,0x4(29); lwz 9,0x0(29); subf 0,9,0; srawi. 30,0,2; bne 2f; lwz 0,0x84(31); addi 9,13,-28700; stb 30,0x18a(31); rlwinm 0,0,2,0,29; stb 30,0x189(31); stw 30,0xd4(31); stwx 30,9,0; b 39f; 2:; mr 3,31; mr 4,30; bl _s801EFA1C_0; lbz 11,0x189(31); rlwinm 9,3,0,24,31; addi 9,9,1; stb 3,0x18a(31); add 11,11,28; divw 0,11,9; mullw 0,0,9; subf. 11,0,11; bge 3f; stb 3,0x189(31); b 4f; 3:; stb 11,0x189(31); 4:; lbz 0,0x189(31); mulli 27,0,12; subf 0,27,30; cmpwi 0,12; ble 5f; li 0,12; 5:; li 28,0; cmpwi 4,30,0; cmpw 28,0; stw 0,0xd4(31); bge 9f; lis 9,-32704; lis 24,-32704; addi 25,9,-16548; li 26,0; rlwinm 30,27,2,0,29; 6:; lwz 0,0x4(29); add 9,28,27; lwz 11,0x0(29); subf 0,11,0; srawi 0,0,2; cmplw 9,0; blt 7f; addi 3,24,-26048; bl _s801EFA1C_1; bl _s801EFA1C_2; 7:; lwzx 3,11,30; bl _s801EFA1C_3; lwz 0,0x84(31); mr 5,3; lwz 9,0x0(31); mulli 0,0,48; cmpwi 9,0; add 0,26,0; lwzx 4,25,0; beq 8f; lwz 3,0x1c(31); cmpwi 3,0; beq 8f; lwz 6,0x7c(31); li 7,0; bl _s801EFA1C_4; 8:; lwz 0,0xd4(31); addi 28,28,1; addi 26,26,4; addi 30,30,4; cmpw 28,0; blt 6b; 9:; ble cr4,39f; lwz 11,0x0(29); lwz 0,0x4(29); subf 0,11,0; srawi 0,0,2; cmplw 27,0; blt 10f; lis 3,-32704; addi 3,3,-26048; bl _s801EFA1C_5; bl _s801EFA1C_6; 10:; rlwinm 9,27,2,0,29; mr 3,31; lwzx 4,11,9; bl _s801EFA1C_7; b 39f; 11:; lbz 0,0x3251(31); addi 11,31,320; mr 3,31; rlwinm 0,0,2,0,29; lwzx 26,11,0; lwz 0,0x0(26); lwz 9,0x4(26); subf 9,0,9; srawi 9,9,3; addi 30,9,1; mr 4,30; bl _s801EFA1C_8; lbz 11,0x189(31); rlwinm 9,3,0,24,31; addi 9,9,1; stb 3,0x18a(31); add 11,11,28; divw 0,11,9; mullw 0,0,9; subf. 11,0,11; bge 12f; stb 3,0x189(31); b 13f; 12:; stb 11,0x189(31); 13:; lbz 0,0x189(31); mulli 25,0,12; subf 28,25,30; cmpwi 28,12; ble 14f; li 28,12; 14:; cmpwi 11,0; stw 28,0xd4(31); li 29,0; bne 15f; lwz 0,0x84(31); lis 9,-32704; lwz 11,0x0(31); addi 9,9,-16548; mulli 0,0,48; li 29,1; cmpwi 11,0; addi 28,28,-1; lwzx 4,9,0; beq 15f; lwz 3,0x1c(31); cmpwi 3,0; beq 15f; lis 5,-8422; lwz 6,0x7c(31); ori 5,5,36483; li 7,0; bl _s801EFA1C_9; 15:; li 27,0; cmpwi 4,30,1; cmpw 27,28; bge 19f; lis 9,-32704; rlwinm 29,29,2,0,29; addi 23,9,-16548; lis 24,-32704; rlwinm 30,25,3,0,28; 16:; lwz 0,0x4(26); add 9,27,25; lwz 3,0x0(26); subf 0,3,0; srawi 0,0,3; cmplw 9,0; blt 17f; addi 3,24,-26048; bl _s801EFA1C_10; bl _s801EFA1C_11; 17:; add 3,3,30; bl _s801EFA1C_12; lwz 0,0x84(31); mr 5,3; lwz 9,0x0(31); mulli 0,0,48; cmpwi 9,0; add 0,29,0; lwzx 4,23,0; beq 18f; lwz 3,0x1c(31); cmpwi 3,0; beq 18f; lwz 6,0x7c(31); li 7,0; bl _s801EFA1C_13; 18:; addi 27,27,1; addi 29,29,4; addi 30,30,8; cmpw 27,28; blt 16b; 19:; ble cr4,39f; lwz 9,0x0(26); lwz 0,0x4(26); subf 0,9,0; srawi 0,0,3; cmplw 25,0; blt 20f; lis 3,-32704; addi 3,3,-26048; bl _s801EFA1C_14; bl _s801EFA1C_15; 20:; rlwinm 4,25,3,0,28; mr 3,31; add 4,9,4; bl _s801EFA1C_16; b 39f; 21:; lwz 29,0x168(31); mr 3,31; lwz 9,0x0(29); lwz 0,0x4(29); subf 0,9,0; srawi 30,0,3; mr 4,30; bl _s801EFA1C_17; lbz 11,0x189(31); rlwinm 9,3,0,24,31; addi 9,9,1; stb 3,0x18a(31); add 11,11,28; divw 0,11,9; mullw 0,0,9; subf. 11,0,11; bge 22f; stb 3,0x189(31); b 23f; 22:; stb 11,0x189(31); 23:; lbz 0,0x189(31); mulli 26,0,12; subf 27,26,30; cmpwi 27,12; ble 24f; li 27,12; 24:; li 28,0; cmpwi 4,30,0; stw 27,0xd4(31); cmpw 28,27; bge 28f; lis 9,-32704; lis 23,-32704; addi 24,9,-16548; li 25,0; rlwinm 30,26,3,0,28; 25:; lwz 0,0x4(29); add 9,28,26; lwz 3,0x0(29); subf 0,3,0; srawi 0,0,3; cmplw 9,0; blt 26f; addi 3,23,-26048; bl _s801EFA1C_18; bl _s801EFA1C_19; 26:; add 3,3,30; bl _s801EFA1C_20; lwz 0,0x84(31); mr 5,3; lwz 9,0x0(31); mulli 0,0,48; cmpwi 9,0; add 0,25,0; lwzx 4,24,0; beq 27f; lwz 3,0x1c(31); cmpwi 3,0; beq 27f; lwz 6,0x7c(31); li 7,0; bl _s801EFA1C_21; 27:; addi 28,28,1; addi 25,25,4; addi 30,30,8; cmpw 28,27; blt 25b; 28:; ble cr4,39f; lwz 9,0x0(29); lwz 0,0x4(29); subf 0,9,0; srawi 0,0,3; cmplw 26,0; blt 29f; lis 3,-32704; addi 3,3,-26048; bl _s801EFA1C_22; bl _s801EFA1C_23; 29:; rlwinm 4,26,3,0,28; mr 3,31; add 4,9,4; bl _s801EFA1C_24; b 39f; 30:; lwz 29,0x16c(31); mr 3,31; lwz 9,0x0(29); lwz 0,0x4(29); subf 0,9,0; srawi 30,0,3; mr 4,30; bl _s801EFA1C_25; lbz 11,0x189(31); rlwinm 9,3,0,24,31; addi 9,9,1; stb 3,0x18a(31); add 11,11,28; divw 0,11,9; mullw 0,0,9; subf. 11,0,11; bge 31f; stb 3,0x189(31); b 32f; 31:; stb 11,0x189(31); 32:; lbz 0,0x189(31); mulli 26,0,12; subf 27,26,30; cmpwi 27,12; ble 33f; li 27,12; 33:; li 28,0; cmpwi 4,30,0; stw 27,0xd4(31); cmpw 28,27; bge 37f; lis 9,-32704; lis 23,-32704; addi 24,9,-16548; li 25,0; rlwinm 30,26,3,0,28; 34:; lwz 0,0x4(29); add 9,28,26; lwz 3,0x0(29); subf 0,3,0; srawi 0,0,3; cmplw 9,0; blt 35f; addi 3,23,-26048; bl _s801EFA1C_26; bl _s801EFA1C_27; 35:; add 3,3,30; bl _s801EFA1C_28; lwz 0,0x84(31); mr 5,3; lwz 9,0x0(31); mulli 0,0,48; cmpwi 9,0; add 0,25,0; lwzx 4,24,0; beq 36f; lwz 3,0x1c(31); cmpwi 3,0; beq 36f; lwz 6,0x7c(31); li 7,0; bl _s801EFA1C_29; 36:; addi 28,28,1; addi 25,25,4; addi 30,30,8; cmpw 28,27; blt 34b; 37:; ble cr4,39f; lwz 9,0x0(29); lwz 0,0x4(29); subf 0,9,0; srawi 0,0,3; cmplw 26,0; blt 38f; lis 3,-32704; addi 3,3,-26048; bl _s801EFA1C_30; bl _s801EFA1C_31; 38:; rlwinm 4,26,3,0,28; mr 3,31; add 4,9,4; bl _s801EFA1C_32; 39:; lwz 0,0x34(1); lwz 12,0x8(1); mtspr 8,0; lmw 23,0xc(1); mtcrf 8,12; addi 1,1,48"
extern "C" void _s801EFA1C_0();
extern "C" void _s801EFA1C_1();
extern "C" void _s801EFA1C_2();
extern "C" void _s801EFA1C_3();
extern "C" void _s801EFA1C_4();
extern "C" void _s801EFA1C_5();
extern "C" void _s801EFA1C_6();
extern "C" void _s801EFA1C_7();
extern "C" void _s801EFA1C_8();
extern "C" void _s801EFA1C_9();
extern "C" void _s801EFA1C_10();
extern "C" void _s801EFA1C_11();
extern "C" void _s801EFA1C_12();
extern "C" void _s801EFA1C_13();
extern "C" void _s801EFA1C_14();
extern "C" void _s801EFA1C_15();
extern "C" void _s801EFA1C_16();
extern "C" void _s801EFA1C_17();
extern "C" void _s801EFA1C_18();
extern "C" void _s801EFA1C_19();
extern "C" void _s801EFA1C_20();
extern "C" void _s801EFA1C_21();
extern "C" void _s801EFA1C_22();
extern "C" void _s801EFA1C_23();
extern "C" void _s801EFA1C_24();
extern "C" void _s801EFA1C_25();
extern "C" void _s801EFA1C_26();
extern "C" void _s801EFA1C_27();
extern "C" void _s801EFA1C_28();
extern "C" void _s801EFA1C_29();
extern "C" void _s801EFA1C_30();
extern "C" void _s801EFA1C_31();
extern "C" void _s801EFA1C_32();
extern "C" void f_801EFA1C() {}
