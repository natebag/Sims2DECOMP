// 0x8005C8E8 SAnimator2::updateFreeMoveState(void) (836 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f29,0x10(1); stfd f30,0x18(1); stfd f31,0x20(1); stmw 30,0x8(1); stw 0,0x2c(1); mr 31,3; lfs f0,-26800(13); lis 9,-32707; lfs f13,0xfc(31); lfs f1,0xb4(31); lfs f30,0x456c(9); fmuls f0,f0,f13; lfs f12,0x104(31); fcmpu 0,f1,f30; fmuls f29,f0,f12; beq 6f; bl _s8005C8E8_0; lis 9,-32707; fmr f31,f1; lfs f0,0x4570(9); fcmpu 0,f31,f0; beq 4f; lfs f0,0x608(31); fcmpu 0,f0,f30; bne 0f; lfs f0,0x30(31); stfs f0,0x608(31); 0:; lwz 0,0x2c(31); cmpwi 0,9; beq 1f; cmpwi 0,11; bne 3f; b 2f; 1:; lwz 11,0x4(31); lwz 30,-21492(13); lwz 10,0x0(11); lwz 9,0x4(10); lha 3,0x328(9); lwz 0,0x32c(9); add 3,10,3; mtspr 8,0; blrl; mr 4,3; mr 3,30; bl _s8005C8E8_1; 2:; fmr f1,f31; mr 3,31; bl _s8005C8E8_2; mr 3,31; bl _s8005C8E8_3; mr 3,31; bl _s8005C8E8_4; mr 3,31; bl _s8005C8E8_5; li 0,12; stw 0,0x2c(31); 3:; lfs f2,0xb4(31); fmr f1,f29; fmr f3,f31; mr 3,31; bl _s8005C8E8_6; cmpwi 3,0; beq 5f; lis 9,-32707; mr 3,31; lfs f0,0x456c(9); stfs f0,0x608(31); stfs f0,0xb4(31); bl _s8005C8E8_7; b 5f; 4:; mr 3,31; bl _s8005C8E8_8; 5:; mr 3,31; lfs f1,0x30(3); bl _s8005C8E8_9; b 18f; 6:; lwz 0,0x2c(31); cmpwi 0,10; bne 8f; lwz 0,0xb0(31); cmpwi 0,10; bne 7f; lwz 0,0x61c(31); andis. 9,0,256; beq 18f; lwz 3,0x8(31); li 4,1; addi 3,3,820; bl _s8005C8E8_10; cmpwi 3,0; beq 18f; lwz 0,0x61c(31); li 9,9; stw 9,0x2c(31); mr 3,31; rlwinm 0,0,0,8,6; stw 9,0xb0(31); stw 0,0x61c(31); bl _s8005C8E8_11; mr 3,31; bl _s8005C8E8_12; mr 3,31; bl _s8005C8E8_13; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x3c0(9); lwz 0,0x3c4(9); add 3,11,3; mtspr 8,0; blrl; b 18f; 7:; lwz 0,0x61c(31); mr 3,31; rlwinm 0,0,0,8,6; stw 0,0x61c(31); bl _s8005C8E8_14; 8:; lwz 9,0x8(31); addi 10,9,820; mr 3,9; lwz 11,0x70(10); lbz 0,0x0(11); extsb 0,0; cmpwi 0,-1; beq 9f; mulli 9,0,176; lwz 0,0x44(10); add 9,0,9; b 10f; 9:; li 9,0; 10:; li 11,0; cmpwi 9,0; beq 11f; lwz 0,0x30(9); andi. 9,0,2; beq 11f; li 11,1; 11:; lwz 0,0xb0(31); mr 30,0; cmpwi 0,9; bne 14f; lwz 0,0x2c(31); mr 9,0; cmpwi 0,14; beq 12f; cmpwi 9,13; bne 13f; cmpwi 11,0; beq 13f; 12:; lwz 9,0x61c(31); li 0,11; stw 0,0x2c(31); mr 3,31; rlwinm 9,9,0,9,7; stw 9,0x61c(31); bl _s8005C8E8_15; b 18f; 13:; cmpwi 30,9; bne 14f; cmpwi 9,11; bne 14f; addi 3,3,820; li 4,1; bl _s8005C8E8_16; cmpwi 3,0; beq 18f; lwz 0,0x61c(31); mr 3,31; stw 30,0x2c(31); rlwinm 0,0,0,9,7; stw 0,0x61c(31); bl _s8005C8E8_17; b 18f; 14:; cmpwi 30,14; bne 16f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x178(9); lwz 9,0x17c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 15f; mr 3,31; bl _s8005C8E8_18; cmpwi 3,0; beq 16f; 15:; mr 3,31; bl _s8005C8E8_19; li 0,13; b 17f; 16:; lwz 4,0xb0(31); lwz 0,0x2c(31); cmpw 4,0; beq 18f; mr 3,31; bl _s8005C8E8_20; lwz 0,0xb0(31); 17:; stw 0,0x2c(31); 18:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x8(1); lfd f29,0x10(1); lfd f30,0x18(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s8005C8E8_0();
extern "C" void _s8005C8E8_1();
extern "C" void _s8005C8E8_2();
extern "C" void _s8005C8E8_3();
extern "C" void _s8005C8E8_4();
extern "C" void _s8005C8E8_5();
extern "C" void _s8005C8E8_6();
extern "C" void _s8005C8E8_7();
extern "C" void _s8005C8E8_8();
extern "C" void _s8005C8E8_9();
extern "C" void _s8005C8E8_10();
extern "C" void _s8005C8E8_11();
extern "C" void _s8005C8E8_12();
extern "C" void _s8005C8E8_13();
extern "C" void _s8005C8E8_14();
extern "C" void _s8005C8E8_15();
extern "C" void _s8005C8E8_16();
extern "C" void _s8005C8E8_17();
extern "C" void _s8005C8E8_18();
extern "C" void _s8005C8E8_19();
extern "C" void _s8005C8E8_20();
extern "C" void f_8005C8E8() {}
