// 0x802A1F08 void (1644 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-224(1); mfspr 0,8; stmw 20,0xb0(1); stw 0,0xe4(1); mr 21,4; mr 20,5; lwz 10,0x0(20); mr 26,3; lwz 9,0x0(21); mr 27,6; subf 0,9,10; srawi. 8,0,2; beq 34f; lwz 5,0x0(26); lwz 7,0x4(26); add 24,5,8; cmpw 24,7; bge 18f; lwz 6,0x8(26); rlwinm 0,5,2,0,29; lwz 5,0x0(27); stw 6,0x70(1); add 7,0,6; stw 7,0x74(1); cmpw 5,7; mr 0,6; stw 7,0x8(1); stw 0,0xc(1); stw 7,0x10(1); lwz 11,0x4(27); bne 6f; mr 31,9; mr 27,10; mr 28,5; cmpw 31,27; addi 23,1,24; rlwinm 25,24,2,0,29; beq 3f; 0:; mr 30,28; mr 29,31; addi 31,31,4; addi 28,30,4; cmpw 29,30; beq 2f; lwz 3,0x0(30); cmpwi 3,0; beq 1f; bl _s802A1F08_0; cmpwi 3,0; bne 1f; lwz 3,0x0(30); bl _s802A1F08_1; 1:; lwz 3,0x0(29); stw 3,0x0(30); cmpwi 3,0; beq 2f; bl _s802A1F08_2; 2:; cmpw 31,27; bne 0b; 3:; lwz 30,0x8(26); li 0,0; stw 0,0x18(1); add 29,25,30; cmpw 23,29; beq 5f; lwzx 3,25,30; cmpwi 3,0; beq 4f; bl _s802A1F08_3; cmpwi 3,0; bne 4f; lwzx 3,25,30; bl _s802A1F08_4; 4:; lwz 3,0x18(1); stw 3,0x0(29); cmpwi 3,0; beq 5f; bl _s802A1F08_5; 5:; lwz 3,0x18(1); cmpwi 3,0; beq 17f; bl _s802A1F08_6; cmpwi 3,0; bne 17f; lwz 3,0x18(1); bl _s802A1F08_7; b 17f; 6:; lwz 0,0x8(27); addi 9,1,32; stw 5,0x20(1); rlwinm 8,8,2,0,29; stw 0,0x8(9); addi 23,1,24; stw 11,0x4(9); rlwinm 25,24,2,0,29; stw 6,0x80(1); addi 22,1,40; stw 7,0x30(1); mr 10,6; lwz 9,0x20(1); mr 11,7; subf 0,10,5; subf 9,9,11; rlwinm 0,0,0,0,29; srawi 29,9,2; add 0,0,6; stw 6,0x78(1); add 30,8,0; rlwinm 9,29,2,0,29; addi 11,11,-4; mr 0,6; add 30,30,9; cmpwi 29,0; stw 0,0x34(1); stw 7,0x48(1); addi 30,30,-4; stw 11,0x30(1); addi 29,29,-1; stw 7,0x7c(1); stw 7,0x38(1); stw 7,0x84(1); stw 10,0x40(1); stw 10,0x44(1); beq 10f; 7:; lwz 31,0x30(1); cmpw 31,30; beq 9f; lwz 3,0x0(30); cmpwi 3,0; beq 8f; bl _s802A1F08_8; cmpwi 3,0; bne 8f; lwz 3,0x0(30); bl _s802A1F08_9; 8:; lwz 3,0x0(31); stw 3,0x0(30); cmpwi 3,0; beq 9f; bl _s802A1F08_10; 9:; lwz 9,0x30(1); cmpwi 29,0; addi 30,30,-4; addi 29,29,-1; addi 9,9,-4; stw 9,0x30(1); bne 7b; 10:; lwz 0,0x0(21); lwz 11,0x0(27); mr 29,0; lwz 28,0x0(20); lwz 9,0x8(27); lwz 0,0x4(27); cmpw 29,28; stw 11,0x28(1); stw 9,0x8(22); stw 0,0x4(22); beq 14f; 11:; lwz 30,0x28(1); mr 31,29; lwz 11,0x2c(1); addi 29,29,4; lwz 9,0x30(1); addi 0,30,4; stw 0,0x28(1); cmpw 31,30; stw 11,0x54(1); stw 9,0x58(1); stw 30,0x60(1); stw 11,0x64(1); stw 9,0x68(1); stw 30,0x50(1); beq 13f; lwz 3,0x0(30); cmpwi 3,0; beq 12f; bl _s802A1F08_11; cmpwi 3,0; bne 12f; lwz 3,0x0(30); bl _s802A1F08_12; 12:; lwz 3,0x0(31); stw 3,0x0(30); cmpwi 3,0; beq 13f; bl _s802A1F08_13; 13:; cmpw 29,28; bne 11b; 14:; lwz 30,0x8(26); li 0,0; lwz 9,0x2c(1); lwz 11,0x30(1); add 29,25,30; stw 9,0x1c(1); cmpw 23,29; stw 11,0x20(1); stw 0,0x18(1); beq 16f; lwzx 3,25,30; cmpwi 3,0; beq 15f; bl _s802A1F08_14; cmpwi 3,0; bne 15f; lwzx 3,25,30; bl _s802A1F08_15; 15:; lwz 3,0x18(1); stw 3,0x0(29); cmpwi 3,0; beq 16f; bl _s802A1F08_16; 16:; lwz 3,0x18(1); cmpwi 3,0; beq 17f; bl _s802A1F08_17; cmpwi 3,0; bne 17f; lwz 3,0x18(1); bl _s802A1F08_18; 17:; stw 24,0x0(26); b 34f; 18:; xoris 0,7,32768; stw 0,0xac(1); lis 11,17200; lis 10,-32703; mr 8,9; stw 11,0xa8(1); lfd f13,-27448(10); lfd f0,0xa8(1); fsub f0,f0,f13; frsp f0,f0; fadds f0,f0,f0; fmr f13,f0; fctiwz f12,f13; stfd f12,0xa8(1); lwz 28,0xac(1); cmpw 28,24; bge 19f; mr 28,24; 19:; lwz 0,0x8(26); rlwinm 9,5,2,0,29; lwz 11,0x0(27); cmpw 28,7; add 9,9,0; stw 0,0x88(1); subf 11,0,11; stw 9,0x10(1); addi 23,1,8; addi 25,1,160; stw 9,0x8c(1); srawi 22,11,2; stw 0,0x8(1); stw 0,0xc(1); ble 33f; cmpwi 28,1; bgt 20f; stw 28,0x4(26); b 33f; 20:; addi 30,28,1; addi 24,26,12; rlwinm 3,30,2,0,29; addi 3,3,8; bl _s802A1F08_19; addi 27,3,8; addi 10,1,144; addi 8,1,152; stw 30,-8(27); mr 11,27; mr 9,28; cmpwi 28,-1; beq 22f; li 0,0; 21:; stw 0,0x0(11); cmpwi 9,0; addi 11,11,4; addi 9,9,-1; bne 21b; 22:; lwz 0,0x0(26); mr 29,27; lwz 9,0x8(26); rlwinm 0,0,2,0,29; add 0,0,9; stw 9,0x90(1); stw 0,0x4(10); stw 9,0x98(1); lwz 11,0x90(1); stw 0,0x10(1); stw 11,0xc(1); stw 11,0x8(1); stw 0,0x4(8); stw 0,0x20(1); lwz 9,0x98(1); stw 0,0x18(1); stw 9,0x1c(1); b 25f; 23:; lwz 9,0x10(1); mr 31,29; addi 0,30,4; stw 11,0x2c(1); stw 0,0x8(1); addi 29,29,4; stw 9,0x30(1); cmpw 30,31; stw 30,0x38(1); stw 11,0x3c(1); stw 9,0x40(1); stw 30,0x28(1); beq 25f; lwz 3,-4(29); cmpwi 3,0; beq 24f; bl _s802A1F08_20; cmpwi 3,0; bne 24f; lwz 3,-4(29); bl _s802A1F08_21; 24:; lwz 3,0x0(30); stw 3,0x0(31); cmpwi 3,0; beq 25f; bl _s802A1F08_22; 25:; lwz 30,0x8(1); li 9,1; lwz 0,0x18(1); lwz 11,0xc(1); cmpw 30,0; bne 26f; li 9,0; 26:; cmpwi 9,0; bne 23b; lwz 31,0x8(26); stw 28,0x4(26); cmpw 31,24; beq 30f; cmpwi 31,0; bne 27f; li 3,8; bl _s802A1F08_23; stw 31,0x0(3); b 30f; 27:; lwz 0,-8(31); addi 29,31,-8; rlwinm 0,0,2,0,29; add 30,31,0; 28:; cmpw 31,30; beq 29f; lwzu 3,-4(30); cmpwi 3,0; beq 28b; bl _s802A1F08_24; cmpwi 3,0; bne 28b; lwz 3,0x0(30); bl _s802A1F08_25; b 28b; 29:; mr 3,29; bl _s802A1F08_26; 30:; lwz 9,0x0(26); li 0,0; stw 0,0x8(1); rlwinm 30,9,2,0,29; stw 27,0x8(26); add 29,30,27; cmpw 23,29; beq 32f; lwzx 3,30,27; cmpwi 3,0; beq 31f; bl _s802A1F08_27; cmpwi 3,0; bne 31f; lwzx 3,30,27; bl _s802A1F08_28; 31:; lwz 3,0x0(23); stw 3,0x0(29); cmpwi 3,0; beq 32f; bl _s802A1F08_29; 32:; lwz 3,0x8(1); cmpwi 3,0; beq 33f; bl _s802A1F08_30; cmpwi 3,0; bne 33f; lwz 3,0x8(1); bl _s802A1F08_31; 33:; lwz 0,0x0(26); rlwinm 11,22,2,0,29; lwz 9,0x8(26); mr 3,26; rlwinm 0,0,2,0,29; mr 4,21; add 0,0,9; stw 9,0xa0(1); stw 0,0x4(25); mr 5,20; stw 0,0x10(1); addi 6,1,8; lwz 9,0xa0(1); stw 0,0x20(1); add 11,11,9; stw 9,0xc(1); stw 11,0x8(1); stw 9,0x18(1); stw 9,0x1c(1); bl _s802A1F08_32; 34:; lwz 0,0xe4(1); mtspr 8,0; lmw 20,0xb0(1); addi 1,1,224"
extern "C" void _s802A1F08_0();
extern "C" void _s802A1F08_1();
extern "C" void _s802A1F08_2();
extern "C" void _s802A1F08_3();
extern "C" void _s802A1F08_4();
extern "C" void _s802A1F08_5();
extern "C" void _s802A1F08_6();
extern "C" void _s802A1F08_7();
extern "C" void _s802A1F08_8();
extern "C" void _s802A1F08_9();
extern "C" void _s802A1F08_10();
extern "C" void _s802A1F08_11();
extern "C" void _s802A1F08_12();
extern "C" void _s802A1F08_13();
extern "C" void _s802A1F08_14();
extern "C" void _s802A1F08_15();
extern "C" void _s802A1F08_16();
extern "C" void _s802A1F08_17();
extern "C" void _s802A1F08_18();
extern "C" void _s802A1F08_19();
extern "C" void _s802A1F08_20();
extern "C" void _s802A1F08_21();
extern "C" void _s802A1F08_22();
extern "C" void _s802A1F08_23();
extern "C" void _s802A1F08_24();
extern "C" void _s802A1F08_25();
extern "C" void _s802A1F08_26();
extern "C" void _s802A1F08_27();
extern "C" void _s802A1F08_28();
extern "C" void _s802A1F08_29();
extern "C" void _s802A1F08_30();
extern "C" void _s802A1F08_31();
extern "C" void _s802A1F08_32();
extern "C" void f_802A1F08() {}
