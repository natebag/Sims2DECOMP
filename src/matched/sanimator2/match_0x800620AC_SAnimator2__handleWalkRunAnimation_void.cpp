// 0x800620AC SAnimator2::handleWalkRunAnimation(void) (1268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 30,0x18(1); stw 0,0x2c(1); mr 31,3; lwz 0,0x18(31); cmpwi 0,3; bne 27f; lwz 0,0x61c(31); andi. 9,0,2; bne 17f; xori 0,0,1; stw 9,0xc(1); andi. 9,0,1; beq 1f; lwz 0,0x600(31); cmpwi 0,0; beq 1f; lbz 30,0x5f9(31); cmpwi 30,0; bne 1f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x1a0(9); lwz 9,0x1a4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 0,0x108(31); cmpwi 0,1; beq 1f; li 0,1; stw 0,0x108(31); b 1f; 0:; lwz 0,0x108(31); cmpwi 0,0; beq 1f; stw 30,0x108(31); 1:; lwz 0,0x108(31); addi 30,1,8; cmpwi 0,2; bne 2f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x218(9); lwz 9,0x21c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 7f; lwz 3,0x4(31); mr 5,30; li 4,18; b 11f; 2:; cmpwi 0,3; bne 3f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x218(9); lwz 9,0x21c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 7f; b 10f; 3:; cmpwi 0,1; beq 4f; cmpwi 0,8; bne 6f; 4:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x218(9); lwz 9,0x21c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 5f; lwz 3,0x4(31); mr 5,30; li 4,73; bl _s800620AC_0; b 13f; 5:; lwz 3,0x4(31); mr 5,30; li 4,21; bl _s800620AC_1; b 13f; 6:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x218(9); lwz 9,0x21c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 8f; 7:; lwz 3,0x4(31); mr 5,30; li 4,74; bl _s800620AC_2; b 13f; 8:; lbz 0,0x5f9(31); cmpwi 0,5; beq 9f; cmpwi 0,9; beq 10f; b 12f; 9:; lwz 3,0x4(31); mr 5,30; li 4,18; b 11f; 10:; lwz 3,0x4(31); mr 5,30; li 4,59; 11:; bl _s800620AC_3; lwz 9,0x8(1); lis 3,-32693; addi 3,3,11064; lwz 4,0x0(9); bl _s800620AC_4; cmpwi 3,0; bne 13f; lwz 3,0x4(31); mr 5,30; li 4,20; bl _s800620AC_5; b 13f; 12:; lwz 3,0x4(31); mr 5,30; li 4,20; bl _s800620AC_6; 13:; lwz 9,0x8(1); lis 11,-32707; lwz 3,0x8(31); li 4,2; lwz 5,0x0(9); li 6,4; lfs f1,0x4970(11); addi 3,3,820; addi 7,1,12; bl _s800620AC_7; lwz 0,0x118(31); cmpwi 0,0; bge 14f; lwz 3,0x8(31); lis 9,-32707; lfs f1,0x4974(9); lis 4,1; addi 3,3,820; li 5,1; bl _s800620AC_8; 14:; li 30,0; lwz 0,0x61c(31); stw 30,0xc8(31); lis 9,-32707; oris 0,0,1; lwz 11,0xc(1); lwz 10,0x8(1); lfs f1,0x496c(9); cmpwi 11,0; stw 10,0xd4(31); stw 0,0x61c(31); stfs f1,0xd0(31); beq 16f; lwz 4,0x668(31); cmpwi 4,0; beq 15f; lwz 3,0x8(31); lis 9,-32707; lfs f3,0x4978(9); lfs f2,-32292(13); addi 3,3,820; bl _s800620AC_9; stw 30,0x668(31); 15:; lwz 0,0x61c(31); lwz 9,0xc(1); ori 0,0,4; stw 9,0x668(31); stw 0,0x61c(31); 16:; lwz 0,0x61c(31); ori 0,0,2; stw 0,0x61c(31); 17:; lwz 0,0x61c(31); andi. 9,0,4; beq 19f; lwz 4,0x668(31); cmpwi 4,0; beq 26f; lis 11,-32707; lfs f12,0x110(31); lfs f13,0x497c(11); lis 9,-32707; lfs f0,0x4980(9); fsubs f31,f13,f12; fcmpu 0,f31,f0; bge 18f; lis 9,-32707; lfs f31,0x496c(9); 18:; lwz 3,0x8(31); fmr f1,f31; li 5,0; addi 3,3,820; bl _s800620AC_10; lis 9,-32707; lfs f0,0x496c(9); fcmpu 0,f31,f0; bne 26f; lwz 0,0x61c(31); li 9,0; stw 9,0x668(31); rlwinm 0,0,0,30,28; b 25f; 19:; andi. 9,0,8; beq 26f; lwz 9,0x8(31); addi 11,9,820; lwz 9,0x8(11); cmpwi 9,-1; beq 20f; mulli 9,9,176; lwz 0,0x44(11); add 9,9,0; lwz 9,0x30(9); b 21f; 20:; li 9,0; 21:; andi. 30,9,1; bne 23f; lwz 3,0x4(31); addi 5,1,16; stw 30,0x14(1); li 4,3; bl _s800620AC_11; lwz 9,0x10(1); lis 11,-32707; lwz 3,0x8(31); li 4,1; lfs f1,0x4970(11); li 6,4; lwz 5,0x0(9); addi 3,3,820; addi 7,1,20; bl _s800620AC_12; stw 30,0xc8(31); lis 9,-32707; lwz 0,0x61c(31); lfs f1,0x496c(9); lwz 9,0x14(1); oris 0,0,1; lwz 11,0x10(1); stw 0,0x61c(31); cmpwi 9,0; stw 11,0xd4(31); stfs f1,0xd0(31); beq 23f; lwz 4,0x668(31); cmpwi 4,0; beq 22f; lwz 3,0x8(31); lis 9,-32707; lfs f3,0x4978(9); lfs f2,-32292(13); addi 3,3,820; bl _s800620AC_13; stw 30,0x668(31); 22:; lwz 0,0x14(1); stw 0,0x668(31); 23:; lwz 4,0x668(31); cmpwi 4,0; beq 26f; lis 9,-32707; lfs f31,0x110(31); lfs f0,0x4980(9); fcmpu 0,f31,f0; bge 24f; lis 9,-32707; lfs f31,0x496c(9); 24:; lwz 3,0x8(31); fmr f1,f31; li 5,0; addi 3,3,820; bl _s800620AC_14; lis 9,-32707; lfs f0,0x496c(9); fcmpu 0,f31,f0; bne 26f; lwz 0,0x61c(31); li 9,0; stw 9,0x668(31); rlwinm 0,0,0,29,27; 25:; stw 0,0x61c(31); 26:; lwz 3,0x8(31); lis 4,1; lfs f0,0xfc(31); lfs f1,0x104(31); addi 3,3,820; fmuls f1,f0,f1; bl _s800620AC_15; li 0,1; stw 0,0x1c4(31); b 28f; 27:; lis 9,-32707; li 0,0; lfs f0,0x496c(9); stw 0,0x1c4(31); stfs f0,0x1c0(31); 28:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x18(1); lfd f31,0x20(1); addi 1,1,40"

extern "C" void _s800620AC_0();
extern "C" void _s800620AC_1();
extern "C" void _s800620AC_2();
extern "C" void _s800620AC_3();
extern "C" void _s800620AC_4();
extern "C" void _s800620AC_5();
extern "C" void _s800620AC_6();
extern "C" void _s800620AC_7();
extern "C" void _s800620AC_8();
extern "C" void _s800620AC_9();
extern "C" void _s800620AC_10();
extern "C" void _s800620AC_11();
extern "C" void _s800620AC_12();
extern "C" void _s800620AC_13();
extern "C" void _s800620AC_14();
extern "C" void _s800620AC_15();

struct SAnimator2 {
    void handleWalkRunAnimation();
};

void SAnimator2::handleWalkRunAnimation() {
}
