// 0x800C0A7C IFFBehResFile::RefreshBufferWithBehavior(void) (1464 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-832(1); mfspr 0,8; stmw 18,0x308(1); stw 0,0x344(1); lis 9,-32706; mr 28,3; lwz 0,-24844(9); addi 11,1,8; addi 9,9,-24844; mr 22,11; stw 0,0x8(1); addi 24,1,48; lwz 7,0xc(9); addi 19,1,772; lwz 10,0x4(9); addi 20,1,192; lwz 8,0x8(9); addi 21,1,464; lwz 3,0x138(28); addi 18,1,736; stw 10,0x4(11); li 30,1; stw 8,0x8(11); stw 7,0xc(11); bl _s800C0A7C_0; li 0,0; mr 25,3; stw 0,0x18(1); addi 9,1,32; stw 0,0x1c(1); cmpw 30,25; stw 0,0x4(9); bgt 16f; 0:; lwz 3,0x138(28); mr 4,30; addi 26,30,1; bl _s800C0A7C_1; lwz 9,0x0(22); mr 0,3; mr 8,0; stw 3,0x2f8(1); cmpw 0,9; li 10,0; li 11,0; b 2f; 1:; addi 11,11,1; cmpwi 11,4; bge 3f; rlwinm 0,11,2,0,29; lwzx 9,22,0; cmpw 8,9; 2:; bne 1b; li 10,1; 3:; cmpwi 10,0; bne 15f; lwz 9,0x1c(1); addi 27,1,760; lwz 0,0x24(1); mr 30,9; cmpw 9,0; beq 4f; lwz 0,0x2f8(1); stw 0,0x0(30); lwz 9,0x1c(1); addi 9,9,4; stw 9,0x1c(1); b 15f; 4:; lwz 9,0x18(1); li 0,1; stw 0,0x300(1); addi 11,1,764; subf 9,9,30; addi 0,1,768; srawi 9,9,2; stw 9,0x2fc(1); cmplwi 9,1; bge 5f; mr 11,0; 5:; lwz 0,0x0(11); add. 0,9,0; beq 7f; rlwinm 0,0,2,0,29; mr 29,0; cmplwi 0,128; ble 6f; mr 3,29; bl _s800C0A7C_2; mr 31,3; b 8f; 6:; mr 3,29; bl _s800C0A7C_3; mr 31,3; b 8f; 7:; li 31,0; li 29,0; 8:; lwz 4,0x18(1); cmpw 30,4; beq 9f; subf 30,4,30; mr 3,31; mr 5,30; bl _s800C0A7C_4; add 3,3,30; b 10f; 9:; mr 3,31; 10:; lwz 0,0x300(1); mr 30,3; mtspr 9,0; cmpwi 0,0; beq 12f; 11:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 11b; 12:; lwz 3,0x18(1); lwz 0,0x24(1); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 14f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 13f; bl _s800C0A7C_5; b 14f; 13:; bl _s800C0A7C_6; 14:; add 0,29,31; stw 31,0x18(1); stw 30,0x1c(1); stw 0,0x24(1); 15:; mr 30,26; cmpw 30,25; ble 0b; 16:; lwz 30,0x18(1); addi 23,28,16; b 18f; 17:; lwz 4,0x0(30); lwz 3,0x138(28); addi 30,30,4; bl _s800C0A7C_7; 18:; lwz 0,0x1c(1); cmpw 30,0; bne 17b; lwz 0,0x18(1); li 29,0; mr 31,22; addi 27,22,16; stw 0,0x1c(1); 19:; lwz 30,0x0(31); lwz 3,0x138(28); addi 31,31,4; mr 4,30; bl _s800C0A7C_8; rlwinm 4,3,0,16,31; mr 5,30; mr 3,28; bl _s800C0A7C_9; add 29,29,3; cmpw 31,27; blt 19b; li 4,64; mr 3,23; bl _s800C0A7C_10; bl _s800C0A7C_11; addi 4,29,64; li 5,64; li 6,0; li 7,0; bl _s800C0A7C_12; li 0,64; lis 9,-32702; mtspr 9,0; mr 27,3; mr 10,24; li 11,0; addi 9,9,16524; 20:; lbzx 0,9,11; stbx 0,10,11; addi 11,11,1; bdnz 20b; li 0,0; li 11,53; li 9,50; stb 11,0x3b(1); stb 9,0x39(1); mr 10,24; stb 0,0x6f(1); mr 11,27; stb 0,0x6c(1); li 8,48; stb 0,0x6d(1); stb 0,0x6e(1); 21:; lwz 9,0x0(10); addic. 8,8,-24; stw 9,0x0(11); lwz 9,0x4(10); stw 9,0x4(11); lwz 9,0x8(10); stw 9,0x8(11); lwz 9,0xc(10); stw 9,0xc(11); lwz 9,0x10(10); stw 9,0x10(11); lwz 9,0x14(10); addi 10,10,24; stw 9,0x14(11); addi 11,11,24; bne 21b; lwz 9,0x0(10); li 0,64; li 31,0; stw 9,0x0(11); lwz 9,0x4(10); stw 9,0x4(11); lwz 9,0x8(10); stw 9,0x8(11); lwz 9,0xc(10); stw 9,0xc(11); stw 0,0x304(1); 22:; rlwinm 0,31,2,0,29; lwz 3,0x138(28); lwzx 29,22,0; li 30,1; addi 24,31,1; mr 4,29; bl _s800C0A7C_13; mr 25,3; cmpw 30,25; bgt 26f; 23:; lwz 3,0x138(28); mr 4,29; mr 5,30; li 6,0; bl _s800C0A7C_14; addi 26,30,1; mr. 31,3; beq 25f; mr 3,28; mr 4,31; li 5,0; mr 6,29; bl _s800C0A7C_15; cmpwi 3,0; bne 25f; lwz 0,0xc(31); cmpwi 0,0; beq 25f; addi 30,1,112; lwz 5,0x0(31); mr 3,28; mr 4,30; bl _s800C0A7C_16; cmpwi 3,0; bne 25f; lwz 0,0x304(1); mr 4,30; li 11,72; add 9,27,0; 24:; lwz 0,0x0(4); addic. 11,11,-24; stw 0,0x0(9); lwz 0,0x4(4); stw 0,0x4(9); lwz 0,0x8(4); stw 0,0x8(9); lwz 0,0xc(4); stw 0,0xc(9); lwz 0,0x10(4); stw 0,0x10(9); lwz 0,0x14(4); addi 4,4,24; stw 0,0x14(9); addi 9,9,24; bne 24b; lwz 0,0x0(4); stw 0,0x0(9); lwz 9,0x304(1); lwz 11,0xc(31); stw 9,0x0(31); addi 9,9,76; stw 9,0x304(1); add 3,27,9; lwz 5,0x0(11); lwz 4,0x4(11); bl _s800C0A7C_17; lwz 11,0xc(31); lwz 0,0x304(1); lwz 9,0x0(11); add 0,0,9; stw 0,0x304(1); 25:; rlwinm 30,26,0,16,31; cmpw 30,25; ble 23b; 26:; mr 31,24; cmpwi 31,4; blt 22b; li 4,0; mr 3,23; bl _s800C0A7C_18; mr 5,19; mr 4,27; mr 3,23; bl _s800C0A7C_19; bl _s800C0A7C_20; mr 4,27; bl _s800C0A7C_21; addi 4,1,200; addi 3,1,192; li 5,260; bl _s800C0A7C_22; addi 4,1,472; addi 3,1,464; li 5,260; bl _s800C0A7C_23; addi 4,1,744; addi 3,1,736; li 5,12; bl _s800C0A7C_24; lwz 9,0xc(28); mr 4,20; lwz 0,0x5c(9); lha 3,0x58(9); mtspr 8,0; add 3,28,3; blrl; mr 4,21; mr 3,20; mr 5,18; bl _s800C0A7C_25; lis 4,-32706; li 5,-1; addi 4,4,-24828; mr 3,21; bl _s800C0A7C_26; mr 4,21; mr 3,23; bl _s800C0A7C_27; mr 3,23; bl _s800C0A7C_28; lwz 3,0x138(28); bl _s800C0A7C_29; mr 3,23; bl _s800C0A7C_30; lwz 9,0xc(28); mr 4,21; lha 3,0x28(9); lwz 0,0x2c(9); add 3,28,3; mtspr 8,0; blrl; lwz 3,0x18(1); cmpwi 3,0; beq 28f; lwz 0,0x24(1); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 27f; bl _s800C0A7C_31; b 28f; 27:; bl _s800C0A7C_32; 28:; lwz 0,0x344(1); mtspr 8,0; lmw 18,0x308(1); addi 1,1,832"
extern "C" void _s800C0A7C_0();
extern "C" void _s800C0A7C_1();
extern "C" void _s800C0A7C_2();
extern "C" void _s800C0A7C_3();
extern "C" void _s800C0A7C_4();
extern "C" void _s800C0A7C_5();
extern "C" void _s800C0A7C_6();
extern "C" void _s800C0A7C_7();
extern "C" void _s800C0A7C_8();
extern "C" void _s800C0A7C_9();
extern "C" void _s800C0A7C_10();
extern "C" void _s800C0A7C_11();
extern "C" void _s800C0A7C_12();
extern "C" void _s800C0A7C_13();
extern "C" void _s800C0A7C_14();
extern "C" void _s800C0A7C_15();
extern "C" void _s800C0A7C_16();
extern "C" void _s800C0A7C_17();
extern "C" void _s800C0A7C_18();
extern "C" void _s800C0A7C_19();
extern "C" void _s800C0A7C_20();
extern "C" void _s800C0A7C_21();
extern "C" void _s800C0A7C_22();
extern "C" void _s800C0A7C_23();
extern "C" void _s800C0A7C_24();
extern "C" void _s800C0A7C_25();
extern "C" void _s800C0A7C_26();
extern "C" void _s800C0A7C_27();
extern "C" void _s800C0A7C_28();
extern "C" void _s800C0A7C_29();
extern "C" void _s800C0A7C_30();
extern "C" void _s800C0A7C_31();
extern "C" void _s800C0A7C_32();
extern "C" void f_800C0A7C() {}
