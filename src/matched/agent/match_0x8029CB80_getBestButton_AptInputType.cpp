// 0x8029CB80 _getBestButton(AptInputType, (588 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; mfcr 12; stfd f30,0x50(1); stfd f31,0x58(1); stmw 24,0x30(1); stw 0,0x64(1); stw 12,0x2c(1); mr 24,3; mr 27,4; mr 25,5; 0:; cmpwi 27,0; bne 2f; li 3,0; b 17f; 1:; mr 28,31; b 13f; 2:; li 26,0; lis 9,-32703; lfs f31,-30340(9); li 28,0; stw 26,0xc(1); cmpwi 4,25,0; stw 26,0x8(1); beq cr4,3f; addi 3,25,12; addi 4,1,8; addi 5,1,12; bl _s8029CB80_0; 3:; lwz 9,0x4c(27); lwz 3,0xc(9); bl _s8029CB80_1; mr. 26,3; beq 13f; lis 9,-32703; lfs f30,-30336(9); 4:; lwz 31,0x4(26); li 11,0; lwz 0,0x0(31); rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 5f; rlwinm 11,0,5,31,31; 5:; cmpwi 11,0; beq 12f; cmpw 25,31; beq 12f; mr 3,31; li 29,0; bl _s8029CB80_2; li 30,0; cmpwi 3,13; bne 6f; mr 3,31; bl _s8029CB80_3; subfic 0,3,0; adde 30,0,3; 6:; cmpwi 30,0; bne 8f; mr 3,31; li 30,0; bl _s8029CB80_4; cmpwi 3,18; bne 7f; mr 3,31; bl _s8029CB80_5; subfic 0,3,0; adde 30,0,3; 7:; cmpwi 30,0; beq 9f; 8:; li 29,1; 9:; cmpwi 29,0; bne 11f; mr 3,31; li 30,0; bl _s8029CB80_6; cmpwi 3,14; bne 10f; mr 3,31; bl _s8029CB80_7; subfic 0,3,0; adde 30,0,3; 10:; cmpwi 30,0; beq 12f; 11:; mr 3,26; addi 4,1,16; addi 5,1,20; bl _s8029CB80_8; cmpwi 3,0; beq 12f; lwz 3,-23008(13); mr 4,31; bl _s8029CB80_9; cmpwi 3,0; bne 12f; beq cr4,1b; lwz 4,0x8(1); mr 3,24; lwz 5,0xc(1); lwz 6,0x10(1); lwz 7,0x14(1); bl _s8029CB80_10; fcmpu 0,f1,f30; blt 12f; fcmpu 0,f1,f31; cror 3,2,1; bso 12f; mr 28,31; fmr f31,f1; 12:; lwz 9,0x4c(27); mr 4,26; lwz 3,0xc(9); bl _s8029CB80_11; mr. 26,3; bne 4b; 13:; cmpwi 28,0; beq 16f; mr 3,28; li 31,0; bl _s8029CB80_12; cmpwi 3,13; bne 14f; mr 3,28; bl _s8029CB80_13; subfic 0,3,0; adde 31,0,3; 14:; cmpwi 31,0; beq 15f; mr 27,28; li 25,0; b 0b; 15:; mr 3,28; b 17f; 16:; mr 0,27; mr 25,0; lwz 27,0x48(27); b 0b; 17:; lwz 0,0x64(1); lwz 12,0x2c(1); mtspr 8,0; lmw 24,0x30(1); lfd f30,0x50(1); lfd f31,0x58(1); mtcrf 8,12; addi 1,1,96"
extern "C" void _s8029CB80_0();
extern "C" void _s8029CB80_1();
extern "C" void _s8029CB80_2();
extern "C" void _s8029CB80_3();
extern "C" void _s8029CB80_4();
extern "C" void _s8029CB80_5();
extern "C" void _s8029CB80_6();
extern "C" void _s8029CB80_7();
extern "C" void _s8029CB80_8();
extern "C" void _s8029CB80_9();
extern "C" void _s8029CB80_10();
extern "C" void _s8029CB80_11();
extern "C" void _s8029CB80_12();
extern "C" void _s8029CB80_13();
extern "C" void f_8029CB80() {}
