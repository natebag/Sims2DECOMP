// 0x8029FCDC AptLinker::Notify(AptSharedPtr<AptFile>) (1840 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-312(1); mfspr 0,8; stmw 18,0x100(1); stw 0,0x13c(1); mr 29,3; mr 22,4; lwz 0,0xc(29); lwz 9,0x4(29); stw 0,0xa0(1); rlwinm 9,9,2,0,29; mr 11,0; add 9,9,0; stw 9,0x10(1); stw 11,0xc(1); stw 9,0xa4(1); stw 11,0x8(1); addi 7,1,168; b 1f; 0:; lwz 9,0x0(11); lwz 0,0x0(22); cmpw 9,0; beq 36f; addi 0,11,4; stw 0,0x8(1); 1:; addi 9,29,4; lwz 4,0x4(29); lwz 0,0x8(9); mr 26,9; rlwinm 10,4,2,0,29; li 8,1; stw 0,0xa8(1); add 0,10,0; stw 0,0x4(7); stw 0,0x18(1); lwz 11,0x8(1); lwz 9,0xa8(1); cmpw 11,0; stw 0,0x20(1); stw 9,0x1c(1); bne 2f; li 8,0; 2:; cmpwi 8,0; bne 0b; lwz 5,0x8(26); addi 0,22,4; stw 22,0xb8(1); addi 23,1,56; stw 5,0xb0(1); add 6,10,5; stw 0,0xbc(1); mr 9,22; mr 11,5; subf 0,9,0; mr 18,23; addi 20,1,184; addi 19,1,188; addi 27,1,40; stw 6,0xb4(1); srawi. 8,0,2; stw 11,0x2c(1); stw 6,0x28(1); stw 6,0x30(1); beq 36f; lwz 7,0x4(26); add 24,4,8; cmpw 24,7; bge 20f; stw 5,0xc0(1); stw 6,0xc4(1); mr 0,5; stw 6,0x38(1); stw 0,0x3c(1); stw 6,0x40(1); mr 0,6; cmpw 0,6; lwz 4,0x4(27); bne 8f; lwz 27,0xbc(1); mr 31,9; mr 28,0; addi 23,1,72; rlwinm 25,24,2,0,29; 3:; cmpw 31,27; beq 5f; mr 30,28; mr 29,31; addi 31,31,4; addi 28,30,4; cmpw 29,30; beq 3b; lwz 3,0x0(30); cmpwi 3,0; beq 4f; bl _s8029FCDC_0; cmpwi 3,0; bne 4f; lwz 3,0x0(30); bl _s8029FCDC_1; 4:; lwz 3,0x0(29); stw 3,0x0(30); cmpwi 3,0; beq 3b; bl _s8029FCDC_2; b 3b; 5:; lwz 30,0x8(26); li 0,0; stw 0,0x48(1); add 29,25,30; cmpw 23,29; beq 7f; lwzx 3,25,30; cmpwi 3,0; beq 6f; bl _s8029FCDC_3; cmpwi 3,0; bne 6f; lwzx 3,25,30; bl _s8029FCDC_4; 6:; lwz 3,0x48(1); stw 3,0x0(29); cmpwi 3,0; beq 7f; bl _s8029FCDC_5; 7:; lwz 3,0x48(1); cmpwi 3,0; beq 19f; bl _s8029FCDC_6; cmpwi 3,0; bne 19f; lwz 3,0x48(1); bl _s8029FCDC_7; b 19f; 8:; lwz 7,0x8(27); rlwinm 8,8,2,0,29; stw 0,0x50(1); addi 23,1,72; stw 5,0xd0(1); rlwinm 25,24,2,0,29; stw 6,0x60(1); lwz 0,0x28(1); mr 10,5; lwz 9,0x50(1); mr 11,6; subf 0,10,0; stw 5,0xc8(1); subf 9,9,11; rlwinm 0,0,0,0,29; srawi 29,9,2; add 0,0,5; add 30,8,0; rlwinm 9,29,2,0,29; mr 0,5; add 30,30,9; addi 11,11,-4; cmpwi 29,0; stw 4,0x54(1); addi 30,30,-4; stw 7,0x58(1); addi 29,29,-1; stw 0,0x64(1); stw 6,0x78(1); stw 11,0x60(1); stw 6,0xcc(1); stw 6,0x68(1); stw 6,0xd4(1); stw 10,0x70(1); stw 10,0x74(1); beq 12f; 9:; lwz 31,0x60(1); cmpw 31,30; beq 11f; lwz 3,0x0(30); cmpwi 3,0; beq 10f; bl _s8029FCDC_8; cmpwi 3,0; bne 10f; lwz 3,0x0(30); bl _s8029FCDC_9; 10:; lwz 3,0x0(31); stw 3,0x0(30); cmpwi 3,0; beq 11f; bl _s8029FCDC_10; 11:; lwz 9,0x60(1); cmpwi 29,0; addi 30,30,-4; addi 29,29,-1; addi 9,9,-4; stw 9,0x60(1); bne 9b; 12:; lwz 0,0x0(20); lwz 28,0x0(19); mr 31,0; lwz 11,0x8(27); lwz 9,0x0(27); cmpw 31,28; lwz 0,0x4(27); stw 9,0x58(1); stw 0,0x5c(1); stw 11,0x60(1); beq 16f; 13:; lwz 30,0x58(1); mr 29,31; lwz 11,0x5c(1); addi 31,31,4; lwz 9,0x60(1); addi 0,30,4; stw 0,0x58(1); cmpw 29,30; stw 11,0x84(1); stw 9,0x88(1); stw 30,0x90(1); stw 11,0x94(1); stw 9,0x98(1); stw 30,0x80(1); beq 15f; lwz 3,0x0(30); cmpwi 3,0; beq 14f; bl _s8029FCDC_11; cmpwi 3,0; bne 14f; lwz 3,0x0(30); bl _s8029FCDC_12; 14:; lwz 3,0x0(29); stw 3,0x0(30); cmpwi 3,0; beq 15f; bl _s8029FCDC_13; 15:; cmpw 31,28; bne 13b; 16:; lwz 30,0x8(26); li 0,0; lwz 9,0x5c(1); lwz 11,0x60(1); add 29,25,30; stw 9,0x4c(1); cmpw 23,29; stw 11,0x50(1); stw 0,0x48(1); beq 18f; lwzx 3,25,30; cmpwi 3,0; beq 17f; bl _s8029FCDC_14; cmpwi 3,0; bne 17f; lwzx 3,25,30; bl _s8029FCDC_15; 17:; lwz 3,0x48(1); stw 3,0x0(29); cmpwi 3,0; beq 18f; bl _s8029FCDC_16; 18:; lwz 3,0x48(1); cmpwi 3,0; beq 19f; bl _s8029FCDC_17; cmpwi 3,0; bne 19f; lwz 3,0x48(1); bl _s8029FCDC_18; 19:; stw 24,0x0(26); b 36f; 20:; xoris 0,7,32768; stw 0,0xfc(1); lis 11,17200; lis 10,-32703; mr 8,9; stw 11,0xf8(1); lfd f13,-27624(10); lfd f0,0xf8(1); fsub f0,f0,f13; frsp f0,f0; fadds f0,f0,f0; fmr f13,f0; fctiwz f12,f13; stfd f12,0xf8(1); lwz 28,0xfc(1); cmpw 28,24; bge 21f; mr 28,24; 21:; stw 5,0xd8(1); cmpw 28,7; lwz 0,0x28(1); addi 25,1,240; mr 9,5; stw 6,0x40(1); subf 0,9,0; stw 6,0xdc(1); srawi 21,0,2; stw 9,0x38(1); stw 9,0x3c(1); ble 35f; cmpwi 28,1; bgt 22f; stw 28,0x4(26); b 35f; 22:; addi 30,28,1; addi 24,29,16; rlwinm 3,30,2,0,29; addi 3,3,8; bl _s8029FCDC_19; addi 27,3,8; addi 10,1,224; addi 8,1,232; stw 30,-8(27); mr 11,27; mr 9,28; cmpwi 28,-1; beq 24f; li 0,0; 23:; stw 0,0x0(11); cmpwi 9,0; addi 11,11,4; addi 9,9,-1; bne 23b; 24:; lwz 0,0x0(26); mr 29,27; lwz 9,0x8(26); rlwinm 0,0,2,0,29; add 0,0,9; stw 9,0xe0(1); stw 0,0x4(10); stw 9,0xe8(1); lwz 11,0xe0(1); stw 0,0x40(1); stw 11,0x3c(1); stw 11,0x38(1); stw 0,0x4(8); stw 0,0x50(1); lwz 9,0xe8(1); stw 0,0x48(1); stw 9,0x4c(1); b 27f; 25:; lwz 9,0x40(1); mr 31,29; addi 0,30,4; stw 11,0x5c(1); stw 0,0x38(1); addi 29,29,4; stw 9,0x60(1); cmpw 30,31; stw 30,0x68(1); stw 11,0x6c(1); stw 9,0x70(1); stw 30,0x58(1); beq 27f; lwz 3,-4(29); cmpwi 3,0; beq 26f; bl _s8029FCDC_20; cmpwi 3,0; bne 26f; lwz 3,-4(29); bl _s8029FCDC_21; 26:; lwz 3,0x0(30); stw 3,0x0(31); cmpwi 3,0; beq 27f; bl _s8029FCDC_22; 27:; lwz 30,0x38(1); li 9,1; lwz 0,0x48(1); lwz 11,0x3c(1); cmpw 30,0; bne 28f; li 9,0; 28:; cmpwi 9,0; bne 25b; lwz 31,0x8(26); stw 28,0x4(26); cmpw 31,24; beq 32f; cmpwi 31,0; bne 29f; li 3,8; bl _s8029FCDC_23; stw 31,0x0(3); b 32f; 29:; lwz 0,-8(31); addi 29,31,-8; rlwinm 0,0,2,0,29; add 30,31,0; 30:; cmpw 31,30; beq 31f; lwzu 3,-4(30); cmpwi 3,0; beq 30b; bl _s8029FCDC_24; cmpwi 3,0; bne 30b; lwz 3,0x0(30); bl _s8029FCDC_25; b 30b; 31:; mr 3,29; bl _s8029FCDC_26; 32:; lwz 9,0x0(26); li 0,0; stw 0,0x38(1); rlwinm 30,9,2,0,29; stw 27,0x8(26); add 29,30,27; cmpw 23,29; beq 34f; lwzx 3,30,27; cmpwi 3,0; beq 33f; bl _s8029FCDC_27; cmpwi 3,0; bne 33f; lwzx 3,30,27; bl _s8029FCDC_28; 33:; lwz 3,0x0(18); stw 3,0x0(29); cmpwi 3,0; beq 34f; bl _s8029FCDC_29; 34:; lwz 3,0x38(1); cmpwi 3,0; beq 35f; bl _s8029FCDC_30; cmpwi 3,0; bne 35f; lwz 3,0x38(1); bl _s8029FCDC_31; 35:; lwz 0,0x0(26); rlwinm 11,21,2,0,29; lwz 9,0x8(26); mr 3,26; rlwinm 0,0,2,0,29; mr 4,20; add 0,0,9; stw 9,0xf0(1); stw 0,0x4(25); mr 5,19; stw 0,0x40(1); addi 6,1,56; lwz 9,0xf0(1); stw 0,0x50(1); add 11,11,9; stw 9,0x3c(1); stw 11,0x38(1); stw 9,0x48(1); stw 9,0x4c(1); bl _s8029FCDC_32; 36:; lwz 3,0x0(22); cmpwi 3,0; beq 37f; bl _s8029FCDC_33; cmpwi 3,0; bne 37f; lwz 3,0x0(22); bl _s8029FCDC_34; 37:; lwz 0,0x13c(1); mtspr 8,0; lmw 18,0x100(1); addi 1,1,312"
extern "C" void _s8029FCDC_0();
extern "C" void _s8029FCDC_1();
extern "C" void _s8029FCDC_2();
extern "C" void _s8029FCDC_3();
extern "C" void _s8029FCDC_4();
extern "C" void _s8029FCDC_5();
extern "C" void _s8029FCDC_6();
extern "C" void _s8029FCDC_7();
extern "C" void _s8029FCDC_8();
extern "C" void _s8029FCDC_9();
extern "C" void _s8029FCDC_10();
extern "C" void _s8029FCDC_11();
extern "C" void _s8029FCDC_12();
extern "C" void _s8029FCDC_13();
extern "C" void _s8029FCDC_14();
extern "C" void _s8029FCDC_15();
extern "C" void _s8029FCDC_16();
extern "C" void _s8029FCDC_17();
extern "C" void _s8029FCDC_18();
extern "C" void _s8029FCDC_19();
extern "C" void _s8029FCDC_20();
extern "C" void _s8029FCDC_21();
extern "C" void _s8029FCDC_22();
extern "C" void _s8029FCDC_23();
extern "C" void _s8029FCDC_24();
extern "C" void _s8029FCDC_25();
extern "C" void _s8029FCDC_26();
extern "C" void _s8029FCDC_27();
extern "C" void _s8029FCDC_28();
extern "C" void _s8029FCDC_29();
extern "C" void _s8029FCDC_30();
extern "C" void _s8029FCDC_31();
extern "C" void _s8029FCDC_32();
extern "C" void _s8029FCDC_33();
extern "C" void _s8029FCDC_34();
extern "C" void f_8029FCDC() {}
