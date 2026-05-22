// 0x8007F084 MUWrapper::Startup(void) (1848 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-152(1); mfspr 0,8; stfd f31,0x90(1); stmw 14,0x48(1); stw 0,0x9c(1); mr 31,3; li 30,0; mr 4,31; bl _s8007F084_0; li 27,12; lis 3,-32697; lis 17,-32698; addi 3,3,24012; lis 14,-32698; bl _s8007F084_1; mr 4,3; li 5,0; lis 3,-32692; li 6,0; addi 3,3,-30916; bl _s8007F084_2; stw 3,0xa4(31); li 9,5; li 0,1; stw 3,-21408(13); stw 0,-21396(13); addi 19,1,20; stw 9,-21404(13); addi 18,1,32; stw 9,-21400(13); addi 21,1,8; li 3,108; bl _s8007F084_3; lis 9,-32698; mr 26,3; addi 9,9,-12072; addi 29,26,8; stw 9,0x5c(26); addi 11,29,8; stw 30,0x0(26); li 3,48; stw 30,0x4(26); stw 30,0x8(26); stw 30,0x4(29); stw 30,0x4(11); bl _s8007F084_4; stw 3,0x8(26); addi 0,3,48; stw 0,0xc(29); addi 9,1,16; stw 3,0x4(29); stw 30,0x10(1); lwz 10,0x8(26); 0:; lwz 0,0x0(9); addic. 27,27,-1; stw 0,0x0(10); addi 10,10,4; bne 0b; lis 9,-32707; lis 11,-32707; lfs f31,0x6bbc(9); addi 6,31,212; lfs f0,0x6bc0(11); addi 8,31,220; fmr f13,f31; addi 9,31,236; stfs f13,0x40(1); addi 11,31,228; mr 3,26; addi 28,26,8; lwz 23,0x40(1); mr 22,28; stw 10,0x4(29); li 25,0; stfs f0,0x30(26); li 15,2; stw 27,0x18(26); li 24,1; stfs f31,0x1c(26); li 20,0; stw 6,0x2c(1); stfs f31,0x20(26); stw 8,0x30(1); stfs f0,0x24(26); stw 9,0x38(1); stfs f0,0x28(26); stw 11,0x34(1); stfs f0,0x2c(26); stw 27,0x34(26); stw 27,0x38(26); stw 27,0x3c(26); bl _s8007F084_5; lis 9,-32698; mr 3,26; addi 9,9,-12136; stw 27,0x64(26); stw 9,0x5c(26); stw 27,0x60(26); bl _s8007F084_6; lis 9,-32698; stfs f31,0x68(26); addi 9,9,-12200; mr 3,26; stw 9,0x5c(26); bl _s8007F084_7; 1:; li 3,112; bl _s8007F084_8; mr 30,3; addi 9,17,-11112; stw 9,0x1c(30); addi 11,30,32; stw 15,0x0(30); mr 3,11; stw 24,0x4(30); stw 20,0x8(30); stw 23,0xc(30); stw 23,0x10(30); stw 23,0x14(30); stw 23,0x18(30); stw 20,0x24(11); bl _s8007F084_9; mr 3,30; stw 20,0x6c(30); bl _s8007F084_10; mr 3,30; bl _s8007F084_11; addi 0,14,-11832; mr 3,30; stw 0,0x1c(30); bl _s8007F084_12; lwz 9,0x4(22); lwz 0,0xc(22); stw 24,0x4(30); cmpw 9,0; stw 30,0x14(1); beq 2f; stw 30,0x0(9); addi 25,25,1; lwz 9,0x4(28); addi 9,9,4; stw 9,0x4(28); b 13f; 2:; lwz 30,0x4(28); addi 11,1,28; lwz 0,0x8(26); addi 10,1,24; stw 24,0x1c(1); subf 0,0,30; srawi 9,0,2; stw 9,0x18(1); cmplw 9,24; bge 3f; mr 10,11; 3:; lwz 0,0x0(10); add. 0,9,0; beq 5f; rlwinm 0,0,2,0,29; mr 27,0; cmplwi 0,128; ble 4f; mr 3,27; bl _s8007F084_13; mr 29,3; b 6f; 4:; mr 3,27; bl _s8007F084_14; mr 29,3; b 6f; 5:; li 29,0; li 27,0; 6:; lwz 4,0x0(28); cmpw 30,4; beq 7f; subf 30,4,30; mr 3,29; mr 5,30; bl _s8007F084_15; add 0,3,30; b 8f; 7:; mr 0,29; 8:; lwz 6,0x1c(1); mr 30,0; addi 25,25,1; mtspr 9,6; cmpwi 6,0; beq 10f; 9:; lwz 0,0x0(19); stw 0,0x0(30); addi 30,30,4; bdnz 9b; 10:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 12f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 11f; bl _s8007F084_16; b 12f; 11:; bl _s8007F084_17; 12:; add 0,27,29; stw 29,0x0(28); stw 30,0x4(28); stw 0,0xc(28); 13:; cmpwi 25,7; blt 1b; lis 9,-32707; li 25,0; lfs f31,0x6bbc(9); li 24,1; li 22,0; mr 23,28; 14:; li 3,112; bl _s8007F084_18; mr 30,3; addi 9,17,-11112; stw 9,0x1c(30); addi 11,30,32; stw 24,0x0(30); mr 3,11; stw 24,0x4(30); stw 22,0x8(30); stfs f31,0xc(30); stfs f31,0x10(30); stfs f31,0x14(30); stfs f31,0x18(30); stw 22,0x24(11); bl _s8007F084_19; mr 3,30; stw 22,0x6c(30); bl _s8007F084_20; mr 3,30; bl _s8007F084_21; lis 6,-32698; mr 3,30; addi 0,6,-11592; stw 0,0x1c(30); bl _s8007F084_22; lwz 9,0x4(23); lwz 0,0xc(23); stw 24,0x4(30); cmpw 9,0; stw 30,0x20(1); beq 15f; stw 30,0x0(9); addi 25,25,1; lwz 9,0x4(28); addi 9,9,4; stw 9,0x4(28); b 26f; 15:; lwz 30,0x4(28); addi 11,1,40; lwz 0,0x8(26); addi 10,1,36; stw 24,0x28(1); subf 0,0,30; srawi 9,0,2; stw 9,0x24(1); cmplw 9,24; bge 16f; mr 10,11; 16:; lwz 0,0x0(10); add. 0,9,0; beq 18f; rlwinm 0,0,2,0,29; mr 27,0; cmplwi 0,128; ble 17f; mr 3,27; bl _s8007F084_23; mr 29,3; b 19f; 17:; mr 3,27; bl _s8007F084_24; mr 29,3; b 19f; 18:; li 29,0; li 27,0; 19:; lwz 4,0x0(28); cmpw 30,4; beq 20f; subf 30,4,30; mr 3,29; mr 5,30; bl _s8007F084_25; add 0,3,30; b 21f; 20:; mr 0,29; 21:; lwz 6,0x28(1); mr 30,0; addi 25,25,1; mtspr 9,6; cmpwi 6,0; beq 23f; 22:; lwz 0,0x0(18); stw 0,0x0(30); addi 30,30,4; bdnz 22b; 23:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 25f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 24f; bl _s8007F084_26; b 25f; 24:; bl _s8007F084_27; 25:; add 0,27,29; stw 29,0x0(28); stw 30,0x4(28); stw 0,0xc(28); 26:; cmpwi 25,2; blt 14b; stw 26,0xa8(31); mr 4,26; mr 3,31; li 23,1; bl _s8007F084_28; lis 29,-32707; stw 23,0xc8(31); mr 3,31; lis 27,-32707; lis 26,-32707; bl _s8007F084_29; lis 25,-32707; lis 4,-32707; mr 3,31; addi 4,4,27480; lis 24,-32707; bl _s8007F084_30; lis 28,-32707; lis 30,-32697; lis 4,-32707; addi 30,30,24012; lis 8,-32707; lwz 3,0xb4(30); addi 4,4,27500; addi 8,8,27520; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s8007F084_31; lwz 3,0xb4(30); addi 4,29,27524; li 5,0; li 6,0; li 7,1; addi 8,27,27540; crxor 6,6,6; bl _s8007F084_32; lwz 3,0xb4(30); addi 4,29,27524; li 5,0; li 6,0; li 7,1; addi 8,26,27548; crxor 6,6,6; bl _s8007F084_33; lwz 3,0xb4(30); addi 4,29,27524; li 5,0; li 6,0; li 7,1; addi 8,25,27556; crxor 6,6,6; bl _s8007F084_34; lwz 3,0xb4(30); addi 4,29,27524; li 5,0; li 6,0; li 7,1; addi 8,24,27564; crxor 6,6,6; bl _s8007F084_35; lwz 3,0xb4(30); addi 8,27,27540; addi 4,28,27568; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s8007F084_36; lwz 3,0xb4(30); addi 8,26,27548; addi 4,28,27568; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s8007F084_37; lwz 3,0xb4(30); addi 8,25,27556; addi 4,28,27568; li 5,0; li 6,0; li 7,1; crxor 6,6,6; bl _s8007F084_38; lwz 3,0xb4(30); addi 8,24,27564; li 6,0; li 7,1; addi 4,28,27568; li 5,0; crxor 6,6,6; bl _s8007F084_39; lis 9,-32707; lis 11,-32707; lfs f0,0x6bbc(9); lis 10,-32707; lfs f11,0x6bc4(11); lis 9,-32707; stfs f0,0x4(21); li 0,0; stfs f0,0x8(1); lfs f12,0x6bcc(9); lwz 11,0x8(1); lwz 7,0x4(21); stfs f0,0x4(21); stfs f0,0x8(1); lfs f13,0x6bc8(10); lwz 8,0x8(1); lwz 9,0x4(21); stfs f11,0x8(1); stfs f13,0x4(21); stw 0,0xcc(31); stw 0,0x114(31); stw 0,0x110(31); stw 0,0x10c(31); stw 0,0x108(31); stw 0,0xac(31); stw 23,0xd0(31); stw 11,0xd4(31); lwz 11,0x8(1); lwz 6,0x2c(1); lwz 10,0x4(21); stw 7,0x4(6); stfs f12,0x8(1); stw 8,0xdc(31); stfs f12,0x4(21); lwz 8,0x30(1); stw 9,0x4(8); stw 11,0xec(31); lwz 11,0x38(1); lwz 9,0x8(1); stw 10,0x4(11); lwz 0,0x4(21); stw 9,0xe4(31); lwz 6,0x34(1); stw 0,0x4(6); lwz 0,0x9c(1); mtspr 8,0; lmw 14,0x48(1); lfd f31,0x90(1); addi 1,1,152"
extern "C" void _s8007F084_0();
extern "C" void _s8007F084_1();
extern "C" void _s8007F084_2();
extern "C" void _s8007F084_3();
extern "C" void _s8007F084_4();
extern "C" void _s8007F084_5();
extern "C" void _s8007F084_6();
extern "C" void _s8007F084_7();
extern "C" void _s8007F084_8();
extern "C" void _s8007F084_9();
extern "C" void _s8007F084_10();
extern "C" void _s8007F084_11();
extern "C" void _s8007F084_12();
extern "C" void _s8007F084_13();
extern "C" void _s8007F084_14();
extern "C" void _s8007F084_15();
extern "C" void _s8007F084_16();
extern "C" void _s8007F084_17();
extern "C" void _s8007F084_18();
extern "C" void _s8007F084_19();
extern "C" void _s8007F084_20();
extern "C" void _s8007F084_21();
extern "C" void _s8007F084_22();
extern "C" void _s8007F084_23();
extern "C" void _s8007F084_24();
extern "C" void _s8007F084_25();
extern "C" void _s8007F084_26();
extern "C" void _s8007F084_27();
extern "C" void _s8007F084_28();
extern "C" void _s8007F084_29();
extern "C" void _s8007F084_30();
extern "C" void _s8007F084_31();
extern "C" void _s8007F084_32();
extern "C" void _s8007F084_33();
extern "C" void _s8007F084_34();
extern "C" void _s8007F084_35();
extern "C" void _s8007F084_36();
extern "C" void _s8007F084_37();
extern "C" void _s8007F084_38();
extern "C" void _s8007F084_39();
extern "C" void f_8007F084() {}
