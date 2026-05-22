// 0x800A81D8 AmbientScorePlayer::Update(void) (844 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 24,0x30(1); stw 0,0x54(1); mr 28,3; lwz 0,0x8(28); cmpwi 0,0; beq 24f; lwz 0,0xc(28); cmpwi 0,0; beq 24f; lwz 0,0x1c(28); li 30,0; cmpw 30,0; bge 2f; li 31,0; 0:; lwz 3,0xc(28); add 3,3,31; bl _s800A81D8_0; cmpwi 3,0; beq 1f; lwz 3,0xc(28); add 3,3,31; bl _s800A81D8_1; 1:; lwz 0,0x1c(28); addi 30,30,1; addi 31,31,48; cmpw 30,0; blt 0b; 2:; bl _s800A81D8_2; lwz 0,0x38(28); subf 3,0,3; addi 3,3,-1; cmplwi 3,998; ble 24f; bl _s800A81D8_3; stw 3,0x38(28); mr 3,28; bl _s800A81D8_4; lwz 0,0x0(28); cmpwi 0,1; bne 24f; li 25,0; addi 9,1,8; stw 25,0x8(1); mr 27,9; stw 25,0x4(9); addi 9,9,8; stw 25,0x4(9); lwz 11,0x8(28); lwz 9,0x30(11); lwz 0,0x2c(11); cmpw 0,9; stw 0,0x20(1); beq 16f; mr 24,27; 3:; lwz 4,0x20(1); mr 3,28; bl _s800A81D8_5; cmpwi 3,0; beq 15f; lwz 4,0x20(1); mr 3,28; bl _s800A81D8_6; cmpwi 3,0; bne 15f; lwz 4,0x20(1); mr 3,28; bl _s800A81D8_7; cmpwi 3,0; beq 15f; lwz 11,0x20(1); lwz 9,0x24(11); lwz 0,0x28(11); subf 0,9,0; rlwinm. 9,0,30,2,31; beq 15f; lbz 9,0x1b(11); addi 26,1,32; lwz 10,0x4(24); lwz 0,0xc(24); add 25,25,9; cmpw 10,0; beq 4f; stw 11,0x0(10); lwz 9,0x4(27); addi 9,9,4; stw 9,0x4(27); b 15f; 4:; lwz 30,0x4(27); li 9,1; lwz 0,0x8(1); addi 11,1,40; stw 9,0x28(1); addi 10,1,36; subf 0,0,30; srawi 9,0,2; stw 9,0x24(1); cmplwi 9,1; bge 5f; mr 10,11; 5:; lwz 0,0x0(10); add. 0,9,0; beq 7f; rlwinm 0,0,2,0,29; mr 29,0; cmplwi 0,128; ble 6f; mr 3,29; bl _s800A81D8_8; mr 31,3; b 8f; 6:; mr 3,29; bl _s800A81D8_9; mr 31,3; b 8f; 7:; li 31,0; li 29,0; 8:; lwz 4,0x0(27); cmpw 30,4; beq 9f; subf 30,4,30; mr 3,31; mr 5,30; bl _s800A81D8_10; add 0,3,30; b 10f; 9:; mr 0,31; 10:; lwz 9,0x28(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 12f; 11:; lwz 0,0x0(26); stw 0,0x0(30); addi 30,30,4; bdnz 11b; 12:; lwz 3,0x0(27); lwz 0,0xc(27); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 14f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 13f; bl _s800A81D8_11; b 14f; 13:; bl _s800A81D8_12; 14:; add 0,29,31; stw 31,0x0(27); stw 30,0x4(27); stw 0,0xc(27); 15:; lwz 9,0x20(1); lwz 11,0x8(28); addi 9,9,52; stw 9,0x20(1); lwz 0,0x30(11); cmpw 9,0; bne 3b; 16:; cmpwi 25,0; lwz 3,0x8(1); beq 17f; lwz 0,0x4(27); subf 0,3,0; rlwinm. 9,0,30,2,31; bne 18f; 17:; cmpwi 3,0; beq 24f; lwz 0,0xc(27); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; bgt 22f; bl _s800A81D8_13; b 24f; 18:; lwz 0,0x18(28); lwz 9,0x10(28); subf. 11,9,0; bge 19f; li 11,0; 19:; lwz 0,0x1c(28); cmpw 9,0; bge 21f; cmpwi 11,0; li 6,1; bgt 20f; li 6,0; 20:; mr 3,28; mr 5,25; mr 4,27; bl _s800A81D8_14; mr. 3,3; beq 21f; bl _s800A81D8_15; 21:; lwz 3,0x8(1); cmpwi 3,0; beq 24f; lwz 0,0xc(27); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 23f; 22:; bl _s800A81D8_16; b 24f; 23:; bl _s800A81D8_17; 24:; lwz 0,0x54(1); mtspr 8,0; lmw 24,0x30(1); addi 1,1,80"
extern "C" void _s800A81D8_0();
extern "C" void _s800A81D8_1();
extern "C" void _s800A81D8_2();
extern "C" void _s800A81D8_3();
extern "C" void _s800A81D8_4();
extern "C" void _s800A81D8_5();
extern "C" void _s800A81D8_6();
extern "C" void _s800A81D8_7();
extern "C" void _s800A81D8_8();
extern "C" void _s800A81D8_9();
extern "C" void _s800A81D8_10();
extern "C" void _s800A81D8_11();
extern "C" void _s800A81D8_12();
extern "C" void _s800A81D8_13();
extern "C" void _s800A81D8_14();
extern "C" void _s800A81D8_15();
extern "C" void _s800A81D8_16();
extern "C" void _s800A81D8_17();
extern "C" void f_800A81D8() {}
