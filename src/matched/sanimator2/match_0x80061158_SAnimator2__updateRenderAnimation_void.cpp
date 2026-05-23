// 0x80061158 SAnimator2::updateRenderAnimation(void) (1280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; lwz 9,0x18(31); lwz 30,0x2c(31); cmpwi 7,9,5; ble cr7,4f; cmpwi 9,7; beq 2f; bgt 0f; cmpwi 9,6; beq 1f; b 25f; 0:; cmpwi 9,8; beq 3f; b 25f; 1:; li 30,15; b 25f; 2:; li 30,16; b 25f; 3:; li 30,17; b 25f; 4:; lwz 0,0x10(31); cmpwi 0,1; bne 11f; cmpwi 9,3; bne 5f; li 30,1; b 25f; 5:; cmpwi 9,1; bne 6f; li 30,2; b 25f; 6:; cmpwi 9,2; bne 7f; li 30,4; b 25f; 7:; cmpwi 9,4; beq 10f; bne cr7,25f; lwz 11,0x4(31); li 4,1; lwz 10,0x0(11); lwz 9,0x4(10); lwz 0,0x264(9); lha 3,0x260(9); mtspr 8,0; add 3,10,3; blrl; xoris 3,3,32768; stw 3,0xc(1); lis 0,17200; lis 11,-32707; lis 10,-32707; stw 0,0x8(1); lis 8,-32707; lfd f13,0x4800(11); lis 7,-32707; lfd f0,0x8(1); lfs f11,0x4808(10); fsub f0,f0,f13; lfs f12,0x480c(8); frsp f0,f0; lfs f13,0x4810(7); fsubs f11,f0,f11; fmuls f11,f11,f12; fcmpu 0,f11,f13; bge 8f; lis 9,-32707; lfs f0,0x4814(9); fadds f11,f11,f0; 8:; lis 9,-32707; lfs f0,0x4818(9); fcmpu 0,f11,f0; ble 9f; lis 9,-32707; lfs f0,0x4814(9); fsubs f11,f11,f0; 9:; lfs f0,0x30(31); fcmpu 0,f0,f11; beq 25f; 10:; li 30,3; b 25f; 11:; cmpwi 30,10; bne 12f; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x168(9); lwz 0,0x16c(9); add 3,11,3; mtspr 8,0; blrl; addi 3,3,-1; cmplwi 3,1; bgt 25f; li 0,9; lwz 11,0x4(31); stw 0,0x2c(31); stw 0,0xb0(31); lwz 9,0x4(11); lha 3,0x3c0(9); lwz 0,0x3c4(9); add 3,11,3; mtspr 8,0; blrl; b 25f; 12:; mr 3,31; bl _s80061158_0; cmpwi 3,0; bne 14f; lwz 11,0x4(31); li 4,2; lwz 10,0x0(11); lwz 9,0x4(10); lha 3,0x260(9); lwz 0,0x264(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; bne 13f; cmpwi 30,8; bgt 25f; li 30,9; b 25f; 13:; li 30,8; b 25f; 14:; lwz 9,0x8(31); mr 10,9; addi 11,9,820; lwz 9,0x8(11); cmpwi 9,-1; beq 15f; mulli 9,9,176; lwz 0,0x44(11); add 9,9,0; lwz 9,0x30(9); b 16f; 15:; li 9,0; 16:; andis. 0,9,1; beq 19f; addi 11,10,820; lwz 9,0x8(11); cmpwi 9,-1; beq 17f; mulli 9,9,176; lwz 0,0x44(11); add 9,9,0; lwz 9,0x30(9); b 18f; 17:; li 9,0; 18:; andi. 0,9,1; beq 20f; 19:; lwz 3,0x4(31); li 30,0; b 23f; 20:; addi 11,10,820; lwz 9,0x8(11); cmpwi 9,-1; beq 21f; mulli 9,9,176; lwz 0,0x44(11); add 9,9,0; lwz 9,0x30(9); b 22f; 21:; li 9,0; 22:; andi. 0,9,32; beq 24f; lwz 3,0x4(31); li 30,7; 23:; lwz 9,0x4(3); lha 0,0x330(9); lwz 9,0x334(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 25f; li 30,6; b 25f; 24:; li 30,5; 25:; lwz 0,0x2c(31); cmpw 0,30; beq 26f; mr 3,31; mr 4,30; bl _s80061158_1; stw 30,0x2c(31); 26:; lwz 0,0x2c(31); cmpwi 0,8; beq 34f; bgt 28f; cmpwi 0,3; bgt 27f; cmpwi 0,2; bge 37f; cmpwi 0,0; beq 34f; cmpwi 0,1; beq 30f; b 40f; 27:; cmpwi 0,6; bgt 33f; cmpwi 0,5; bge 32f; b 31f; 28:; cmpwi 0,14; bgt 29f; cmpwi 0,13; bge 38f; cmpwi 0,10; beq 35f; blt 34f; cmpwi 0,11; beq 36f; cmpwi 0,12; beq 37f; b 40f; 29:; cmpwi 0,16; beq 39f; blt 37f; cmpwi 0,17; beq 37f; b 40f; 30:; mr 3,31; bl _s80061158_2; mr 3,31; bl _s80061158_3; b 40f; 31:; mr 3,31; bl _s80061158_4; mr 3,31; bl _s80061158_5; b 40f; 32:; mr 3,31; bl _s80061158_6; b 40f; 33:; mr 3,31; bl _s80061158_7; b 40f; 34:; mr 3,31; bl _s80061158_8; b 40f; 35:; mr 3,31; bl _s80061158_9; mr 3,31; bl _s80061158_10; b 40f; 36:; mr 3,31; bl _s80061158_11; mr 3,31; bl _s80061158_12; b 40f; 37:; mr 3,31; bl _s80061158_13; mr 3,31; bl _s80061158_14; b 40f; 38:; mr 3,31; bl _s80061158_15; mr 3,31; bl _s80061158_16; b 40f; 39:; mr 3,31; bl _s80061158_17; 40:; mr 3,31; bl _s80061158_18; lwz 9,0x28(31); cmpwi 9,0; bne 43f; lwz 0,0x24(31); cmpwi 0,0; beq 41f; stw 9,0x24(31); mr 3,31; bl _s80061158_19; mr 30,3; mr 3,31; bl _s80061158_20; xoris 30,30,32768; stw 30,0xc(1); lis 0,17200; mr 10,11; xoris 3,3,32768; stw 0,0x8(1); lis 9,-32707; lfd f12,0x4800(9); lfd f13,0x8(1); stw 3,0xc(1); fsub f13,f13,f12; stw 0,0x8(1); frsp f13,f13; stfs f13,0x1c(31); lfd f0,0x8(1); fsub f0,f0,f12; frsp f0,f0; stfs f0,0x20(31); 41:; lfs f13,0x1c(31); addi 3,31,1568; lfs f0,0x20(31); lwz 4,0x2c(31); stfs f13,0x34(31); stfs f0,0x38(31); bl _s80061158_21; lwz 9,0x8(31); lwz 0,0x638(9); cmpwi 0,0; beq 42f; mr 3,31; li 4,0; bl _s80061158_22; 42:; mr 3,31; bl _s80061158_23; 43:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s80061158_0();
extern "C" void _s80061158_1();
extern "C" void _s80061158_2();
extern "C" void _s80061158_3();
extern "C" void _s80061158_4();
extern "C" void _s80061158_5();
extern "C" void _s80061158_6();
extern "C" void _s80061158_7();
extern "C" void _s80061158_8();
extern "C" void _s80061158_9();
extern "C" void _s80061158_10();
extern "C" void _s80061158_11();
extern "C" void _s80061158_12();
extern "C" void _s80061158_13();
extern "C" void _s80061158_14();
extern "C" void _s80061158_15();
extern "C" void _s80061158_16();
extern "C" void _s80061158_17();
extern "C" void _s80061158_18();
extern "C" void _s80061158_19();
extern "C" void _s80061158_20();
extern "C" void _s80061158_21();
extern "C" void _s80061158_22();
extern "C" void _s80061158_23();

struct SAnimator2 {
    void updateRenderAnimation();
};

void SAnimator2::updateRenderAnimation() {
}
