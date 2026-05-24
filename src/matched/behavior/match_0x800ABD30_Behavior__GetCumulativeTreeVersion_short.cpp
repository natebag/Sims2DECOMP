// 0x800ABD30 Behavior::GetCumulativeTreeVersion(short) (1620 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; stmw 16,0x40(1); stw 0,0x84(1); lwz 11,-24532(13); mr 19,3; sth 4,0x10(1); lis 18,-32696; cmpwi 11,0; bne 0f; addi 9,18,23984; li 0,1; stw 11,0xc(9); lis 3,-32757; stw 0,-24532(13); addi 3,3,-17264; stw 11,0x5db0(18); stw 11,0x4(9); bl _s800ABD30_0; 0:; lwz 11,-24528(13); lis 16,-32696; cmpwi 11,0; bne 1f; addi 9,16,24000; li 0,1; stw 11,0xc(9); lis 3,-32757; stw 0,-24528(13); addi 3,3,-17184; stw 11,0x5dc0(16); stw 11,0x4(9); bl _s800ABD30_1; 1:; lis 9,-32696; lis 10,-32696; lwz 0,0x5db0(9); addi 27,10,23984; addi 9,9,23984; lis 11,-32696; stw 0,0x4(9); addi 10,11,24000; lwz 0,0xc(27); lwz 30,0x4(27); lwz 9,0x5dc0(11); cmpw 30,0; stw 9,0x4(10); beq 2f; lhz 0,0x10(1); addi 21,1,24; sth 0,0x0(30); lwz 9,0x4(27); addi 9,9,2; stw 9,0x4(27); b 13f; 2:; li 0,1; addi 10,1,40; stw 0,0x28(1); addi 11,1,36; lwz 0,0x5db0(18); subf 0,0,30; srawi 9,0,1; stw 9,0x24(1); cmplwi 9,1; bge 3f; mr 11,10; 3:; lwz 0,0x0(11); add. 0,9,0; beq 5f; add 0,0,0; mr 28,0; cmplwi 0,128; ble 4f; mr 3,28; bl _s800ABD30_2; mr 29,3; b 6f; 4:; mr 3,28; bl _s800ABD30_3; mr 29,3; b 6f; 5:; li 29,0; li 28,0; 6:; lwz 4,0x0(27); cmpw 30,4; beq 7f; subf 30,4,30; mr 3,29; mr 5,30; bl _s800ABD30_4; add 0,3,30; b 8f; 7:; mr 0,29; 8:; lwz 9,0x28(1); mr 30,0; addi 21,1,24; mtspr 9,9; cmpwi 9,0; beq 10f; 9:; lhz 0,0x10(1); sth 0,0x0(30); addi 30,30,2; bdnz 9b; 10:; lwz 3,0x0(27); lwz 0,0xc(27); cmpwi 3,0; subf 0,3,0; srawi 0,0,1; beq 12f; add 4,0,0; cmplwi 4,128; ble 11f; bl _s800ABD30_5; b 12f; 11:; bl _s800ABD30_6; 12:; add 0,28,29; stw 29,0x0(27); stw 0,0xc(27); stw 30,0x4(27); 13:; lis 9,-32696; li 10,0; addi 8,9,23984; lwz 11,0x5db0(9); lwz 0,0x4(8); stw 10,0x18(1); subf 0,11,0; rlwinm. 9,0,31,1,31; beq 42f; lis 9,-32696; mr 20,8; addi 24,9,24000; lis 17,-32696; li 22,1; 14:; lwz 9,0x4(20); addi 5,1,32; lwz 11,0x5db0(17); addi 10,9,-2; lwz 4,0x4(24); subf 9,11,9; rlwinm 9,9,0,0,30; addi 9,9,-2; lhax 0,11,9; stw 10,0x4(20); sth 0,0x20(1); lwz 3,0x5dc0(16); bl _s800ABD30_7; lwz 0,0x4(24); cmpw 3,0; bne 41f; lwz 0,0xc(24); cmpw 3,0; beq 15f; lhz 0,0x20(1); sth 0,0x0(3); lwz 9,0x4(24); addi 9,9,2; stw 9,0x4(24); b 26f; 15:; stw 22,0x30(1); mr 30,3; addi 11,1,48; addi 10,1,44; lwz 0,0x5dc0(16); subf 0,0,30; srawi 9,0,1; stw 9,0x2c(1); cmplw 9,22; bge 16f; mr 10,11; 16:; lwz 0,0x0(10); add. 0,9,0; beq 18f; add 0,0,0; mr 28,0; cmplwi 0,128; ble 17f; mr 3,28; bl _s800ABD30_8; mr 29,3; b 19f; 17:; mr 3,28; bl _s800ABD30_9; mr 29,3; b 19f; 18:; li 29,0; li 28,0; 19:; lwz 4,0x0(24); cmpw 30,4; beq 20f; subf 30,4,30; mr 3,29; mr 5,30; bl _s800ABD30_10; add 0,3,30; b 21f; 20:; mr 0,29; 21:; lwz 9,0x30(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 23f; 22:; lhz 0,0x20(1); sth 0,0x0(30); addi 30,30,2; bdnz 22b; 23:; lwz 3,0x0(24); lwz 0,0xc(24); cmpwi 3,0; subf 0,3,0; srawi 0,0,1; beq 25f; add 4,0,0; cmplwi 4,128; ble 24f; bl _s800ABD30_11; b 25f; 24:; bl _s800ABD30_12; 25:; add 0,28,29; stw 29,0x0(24); stw 30,0x4(24); stw 0,0xc(24); 26:; lwz 11,0x18(1); lha 30,0x20(1); cmpwi 11,0; beq 27f; lwz 9,0x0(11); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x18(1); 27:; mr 4,30; mr 3,19; mr 5,21; li 6,1; bl _s800ABD30_13; cmpwi 3,0; beq 41f; lwz 3,0x18(1); li 26,0; bl _s800ABD30_14; mr 23,3; cmpw 26,23; bge 41f; 28:; lwz 3,0x18(1); mr 4,26; addi 27,26,1; bl _s800ABD30_15; lhz 0,0x0(3); rlwinm 9,0,0,17,31; cmpwi 9,255; ble 40f; sth 9,0x34(1); addi 29,18,23984; addi 25,1,52; lwz 30,0x4(29); lwz 0,0xc(29); cmpw 30,0; beq 29f; sth 9,0x0(30); lwz 9,0x4(29); addi 9,9,2; stw 9,0x4(29); b 40f; 29:; stw 22,0x3c(1); addi 10,1,60; addi 11,1,56; lwz 0,0x5db0(18); subf 0,0,30; srawi 9,0,1; stw 9,0x38(1); cmplw 9,22; bge 30f; mr 11,10; 30:; lwz 0,0x0(11); add. 0,9,0; beq 32f; add 0,0,0; mr 28,0; cmplwi 0,128; ble 31f; mr 3,28; bl _s800ABD30_16; mr 31,3; b 33f; 31:; mr 3,28; bl _s800ABD30_17; mr 31,3; b 33f; 32:; li 31,0; li 28,0; 33:; lwz 4,0x0(29); cmpw 30,4; beq 34f; subf 30,4,30; mr 3,31; mr 5,30; bl _s800ABD30_18; add 0,3,30; b 35f; 34:; mr 0,31; 35:; lwz 9,0x3c(1); mr 30,0; addi 27,26,1; mtspr 9,9; cmpwi 9,0; beq 37f; 36:; lhz 0,0x0(25); sth 0,0x0(30); addi 30,30,2; bdnz 36b; 37:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,1; beq 39f; add 4,0,0; cmplwi 4,128; ble 38f; bl _s800ABD30_19; b 39f; 38:; bl _s800ABD30_20; 39:; add 0,28,31; stw 31,0x0(29); stw 0,0xc(29); stw 30,0x4(29); 40:; mr 26,27; cmpw 26,23; blt 28b; 41:; lwz 9,0x5db0(17); lwz 0,0x4(20); subf 0,9,0; rlwinm. 9,0,31,1,31; bne 14b; 42:; lwz 11,0x18(1); li 28,0; lha 30,0x10(1); cmpwi 11,0; beq 43f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; stw 28,0x18(1); 43:; mr 4,30; mr 3,19; mr 5,21; li 6,1; bl _s800ABD30_21; cmpwi 3,0; beq 44f; lwz 3,0x18(1); bl _s800ABD30_22; rlwinm 28,3,16,0,15; 44:; lis 9,-32696; addi 11,9,24000; lwz 30,0x5dc0(9); lwz 0,0x4(11); cmpw 30,0; beq 48f; mr 26,11; li 27,0; 45:; lwz 11,0x18(1); lha 29,0x0(30); cmpwi 11,0; beq 46f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; stw 27,0x18(1); 46:; mr 4,29; mr 3,19; mr 5,21; li 6,1; bl _s800ABD30_23; cmpwi 3,0; beq 47f; lwz 3,0x18(1); bl _s800ABD30_24; add 28,28,3; 47:; lwz 0,0x4(26); addi 30,30,2; cmpw 30,0; bne 45b; 48:; lwz 11,0x18(1); cmpwi 11,0; beq 49f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 49:; mr 3,28; lwz 0,0x84(1); mtspr 8,0; lmw 16,0x40(1); addi 1,1,128"

extern "C" void _s800ABD30_0();
extern "C" void _s800ABD30_1();
extern "C" void _s800ABD30_2();
extern "C" void _s800ABD30_3();
extern "C" void _s800ABD30_4();
extern "C" void _s800ABD30_5();
extern "C" void _s800ABD30_6();
extern "C" void _s800ABD30_7();
extern "C" void _s800ABD30_8();
extern "C" void _s800ABD30_9();
extern "C" void _s800ABD30_10();
extern "C" void _s800ABD30_11();
extern "C" void _s800ABD30_12();
extern "C" void _s800ABD30_13();
extern "C" void _s800ABD30_14();
extern "C" void _s800ABD30_15();
extern "C" void _s800ABD30_16();
extern "C" void _s800ABD30_17();
extern "C" void _s800ABD30_18();
extern "C" void _s800ABD30_19();
extern "C" void _s800ABD30_20();
extern "C" void _s800ABD30_21();
extern "C" void _s800ABD30_22();
extern "C" void _s800ABD30_23();
extern "C" void _s800ABD30_24();

struct Behavior {
    void GetCumulativeTreeVersion();
};

void Behavior::GetCumulativeTreeVersion() {
}
