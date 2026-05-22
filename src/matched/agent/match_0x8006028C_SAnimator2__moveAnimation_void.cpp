// 0x8006028C SAnimator2::moveAnimation(void) (1008 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stfd f28,0x48(1); stfd f29,0x50(1); stfd f30,0x58(1); stfd f31,0x60(1); stmw 23,0x24(1); stw 0,0x6c(1); mr 31,3; lfs f0,-26800(13); lfs f13,0xfc(31); lfs f12,0x104(31); lis 24,-32707; fmuls f0,f0,f13; li 30,0; fmuls f31,f0,f12; li 25,0; bl _s8006028C_0; li 28,-95; fmr f0,f1; mr 3,31; stfs f0,0x8(1); bl _s8006028C_1; lis 26,-32707; lis 9,-32707; lis 11,-32707; lfs f30,0x4754(24); li 27,0; lfs f29,0x4774(9); li 23,4; lfd f28,0x4760(11); stfs f1,0xc(1); 0:; lwz 0,0x18(31); cmpwi 0,3; beq 7f; bgt 1f; cmpwi 0,1; beq 2f; cmpwi 0,2; beq 6f; b 22f; 1:; cmpwi 0,4; beq 13f; cmpwi 0,5; beq 17f; b 22f; 2:; mr 3,31; bl _s8006028C_2; lbz 0,0x5f8(31); cmpwi 0,2; bne 3f; li 30,1; b 5f; 3:; lfs f0,0xc(1); fcmpu 0,f0,f30; bne 4f; lfs f0,0x8(1); li 30,1; stfs f0,0x30(31); b 5f; 4:; mr 3,31; addi 4,1,8; addi 5,1,12; fmr f1,f31; bl _s8006028C_3; li 25,1; mr 30,3; 5:; cmpwi 30,1; bne 23f; mr 3,31; bl _s8006028C_4; fmr f0,f1; mr 3,31; stfs f0,0x8(1); bl _s8006028C_5; lwz 0,0x61c(31); li 9,3; stfs f1,0xc(1); mr 3,31; and 0,0,28; stw 9,0x18(31); stw 0,0x61c(31); bl _s8006028C_6; b 22f; 6:; mr 3,31; addi 4,1,8; addi 5,1,12; fmr f1,f31; bl _s8006028C_7; mr 30,3; cmpwi 30,1; bne 23f; mr 3,31; bl _s8006028C_8; fmr f0,f1; mr 3,31; stfs f0,0x8(1); bl _s8006028C_9; lwz 0,0x61c(31); lwz 4,0x668(31); stw 23,0x18(31); and 0,0,28; stfs f1,0xc(1); cmpwi 4,0; stw 0,0x61c(31); lfs f1,0x4754(24); b 16f; 7:; lbz 0,0x5f8(31); li 9,0; stw 9,0x5fc(31); cmpwi 0,2; bne 8f; stb 9,0x5f8(31); 8:; mr 3,31; addi 4,1,8; addi 5,1,12; fmr f1,f31; bl _s8006028C_10; mr 30,3; cmpwi 25,0; bne 11f; lfs f3,0xc(1); fcmpu 0,f3,f30; beq 9f; lfs f2,0x8(1); mr 3,31; fmr f1,f31; bl _s8006028C_11; b 10f; 9:; lfs f0,0x8(1); stfs f0,0x30(31); 10:; mr 3,31; bl _s8006028C_12; fmr f0,f1; mr 3,31; stfs f0,0x8(1); bl _s8006028C_13; stfs f1,0xc(1); 11:; cmpwi 25,1; bne 12f; li 30,0; 12:; cmpwi 30,1; bne 23f; lwz 0,0x61c(31); stw 23,0x18(31); and 0,0,28; lwz 4,0x668(31); stw 0,0x61c(31); cmpwi 4,0; lfs f1,0x4754(24); b 16f; 13:; lfs f0,0xc(1); lis 29,-32707; fcmpu 0,f0,f30; bne 14f; lfs f0,0x8(1); li 30,1; stfs f0,0x30(31); b 15f; 14:; mr 3,31; addi 4,1,8; addi 5,1,12; fmr f1,f31; bl _s8006028C_14; mr 30,3; 15:; cmpwi 30,1; bne 23f; li 9,5; lwz 0,0x61c(31); stw 9,0x18(31); and 0,0,28; lwz 4,0x668(31); lfs f1,0x4754(29); ori 0,0,32; stw 0,0x61c(31); cmpwi 4,0; 16:; stfs f1,0x114(31); beq 22f; lwz 3,0x8(31); lfs f2,-32292(13); lfs f3,0x4758(26); addi 3,3,820; bl _s8006028C_15; stw 27,0x668(31); b 22f; 17:; lwz 11,0x4(31); li 4,1; lwz 10,0x0(11); lwz 9,0x4(10); lwz 0,0x264(9); lha 3,0x260(9); mtspr 8,0; add 3,10,3; blrl; xoris 3,3,32768; stw 3,0x1c(1); lis 0,17200; lis 11,-32707; lis 10,-32707; stw 0,0x18(1); lis 8,-32707; lfs f11,0x4768(11); lfd f0,0x18(1); lfs f12,0x476c(10); fsub f0,f0,f28; lfs f13,0x4770(8); frsp f0,f0; fsubs f11,f0,f11; fmuls f11,f11,f12; fcmpu 0,f11,f13; bge 18f; fadds f11,f11,f29; 18:; lis 9,-32707; lfs f0,0x4778(9); fcmpu 0,f11,f0; ble 19f; fsubs f11,f11,f29; 19:; fmr f1,f11; stfs f11,0x8(1); mr 3,31; bl _s8006028C_16; fcmpu 0,f1,f30; stfs f1,0xc(1); bne 20f; lfs f0,0x8(1); li 30,1; stfs f0,0x30(31); b 21f; 20:; mr 3,31; addi 4,1,8; addi 5,1,12; fmr f1,f31; bl _s8006028C_17; mr 30,3; 21:; cmpwi 30,1; bne 23f; mr 3,31; bl _s8006028C_18; mr 30,3; 22:; cmpwi 30,1; beq 0b; 23:; mr 3,31; bl _s8006028C_19; lwz 0,0x6c(1); mtspr 8,0; lmw 23,0x24(1); lfd f28,0x48(1); lfd f29,0x50(1); lfd f30,0x58(1); lfd f31,0x60(1); addi 1,1,104"
extern "C" void _s8006028C_0();
extern "C" void _s8006028C_1();
extern "C" void _s8006028C_2();
extern "C" void _s8006028C_3();
extern "C" void _s8006028C_4();
extern "C" void _s8006028C_5();
extern "C" void _s8006028C_6();
extern "C" void _s8006028C_7();
extern "C" void _s8006028C_8();
extern "C" void _s8006028C_9();
extern "C" void _s8006028C_10();
extern "C" void _s8006028C_11();
extern "C" void _s8006028C_12();
extern "C" void _s8006028C_13();
extern "C" void _s8006028C_14();
extern "C" void _s8006028C_15();
extern "C" void _s8006028C_16();
extern "C" void _s8006028C_17();
extern "C" void _s8006028C_18();
extern "C" void _s8006028C_19();
extern "C" void f_8006028C() {}
