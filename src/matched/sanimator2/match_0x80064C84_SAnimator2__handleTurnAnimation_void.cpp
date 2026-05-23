// 0x80064C84 SAnimator2::handleTurnAnimation(void) (1040 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 30,0x10(1); stw 0,0x24(1); mr 31,3; lwz 0,0x61c(31); andi. 9,0,16; bne 37f; lbz 0,0x5f8(31); extsb 0,0; cmpwi 0,2; beq 37f; cmpwi 0,1; bne 0f; lwz 0,0x2c(31); cmpwi 0,3; beq 37f; 0:; lwz 9,0x18(31); addi 5,1,8; lwz 0,0x118(31); cmpwi 9,1; beq 1f; cmpwi 9,8; beq 1f; lwz 9,0x2c(31); addi 9,9,-9; cmplwi 9,5; bgt 11f; 1:; cmpwi 0,0; beq 25f; bgt 2f; cmpwi 0,-3; beq 8f; bgt 7f; cmpwi 0,-5; beq 10f; cmpwi 0,-4; beq 9f; b 25f; 2:; cmpwi 0,3; beq 4f; blt 3f; cmpwi 0,4; beq 5f; cmpwi 0,5; beq 6f; b 25f; 3:; lwz 3,0x4(31); li 4,29; bl _s80064C84_0; b 25f; 4:; lwz 3,0x4(31); li 4,31; bl _s80064C84_1; b 25f; 5:; lwz 3,0x4(31); li 4,33; bl _s80064C84_2; b 25f; 6:; lwz 3,0x4(31); li 4,35; bl _s80064C84_3; b 25f; 7:; lwz 3,0x4(31); li 4,30; bl _s80064C84_4; b 25f; 8:; lwz 3,0x4(31); li 4,32; bl _s80064C84_5; b 25f; 9:; lwz 3,0x4(31); li 4,34; bl _s80064C84_6; b 25f; 10:; lwz 3,0x4(31); li 4,36; bl _s80064C84_7; b 25f; 11:; cmpwi 0,0; beq 25f; bgt 13f; cmpwi 0,-3; beq 22f; bgt 12f; cmpwi 0,-5; beq 24f; cmpwi 0,-4; beq 23f; b 25f; 12:; cmpwi 0,-2; beq 21f; cmpwi 0,-1; beq 20f; b 25f; 13:; cmpwi 0,3; beq 17f; bgt 14f; cmpwi 0,1; beq 15f; cmpwi 0,2; beq 16f; b 25f; 14:; cmpwi 0,4; beq 18f; cmpwi 0,5; beq 19f; b 25f; 15:; lwz 3,0x4(31); li 4,14; bl _s80064C84_8; b 25f; 16:; lwz 3,0x4(31); li 4,8; bl _s80064C84_9; b 25f; 17:; lwz 3,0x4(31); li 4,6; bl _s80064C84_10; b 25f; 18:; lwz 3,0x4(31); li 4,17; bl _s80064C84_11; b 25f; 19:; lwz 3,0x4(31); li 4,4; bl _s80064C84_12; b 25f; 20:; lwz 3,0x4(31); li 4,13; bl _s80064C84_13; b 25f; 21:; lwz 3,0x4(31); li 4,9; bl _s80064C84_14; b 25f; 22:; lwz 3,0x4(31); li 4,7; bl _s80064C84_15; b 25f; 23:; lwz 3,0x4(31); li 4,16; bl _s80064C84_16; b 25f; 24:; lwz 3,0x4(31); li 4,5; bl _s80064C84_17; 25:; lwz 9,0x2c(31); li 30,0; cmpwi 9,2; beq 26f; cmpwi 9,17; bne 27f; 26:; li 30,4; b 31f; 27:; cmpwi 9,3; beq 30f; cmpwi 9,15; beq 30f; addi 0,9,-9; cmplwi 0,5; bgt 31f; lwz 9,0x8(31); addi 11,9,820; lwz 9,0x8(11); cmpwi 9,-1; beq 28f; mulli 9,9,176; lwz 0,0x44(11); add 9,9,0; lwz 9,0x30(9); b 29f; 28:; li 9,0; 29:; andi. 0,9,2; li 30,4; beq 31f; 30:; li 30,8; 31:; lwz 9,0x8(1); lis 3,-32707; addi 3,3,18872; mr 4,30; lwz 5,0x0(9); li 6,6842; crxor 6,6,6; bl _s80064C84_18; lwz 9,0x8(31); addi 11,9,820; lwz 9,0x8(11); cmpwi 9,-1; beq 32f; mulli 9,9,176; lwz 0,0x44(11); add 9,9,0; lwz 9,0x30(9); b 33f; 32:; li 9,0; 33:; and. 0,9,30; beq 34f; lfs f1,-32312(13); b 35f; 34:; lfs f1,-32308(13); 35:; li 9,0; lwz 0,0x61c(31); stw 9,0xc8(31); lis 11,-32707; lwz 9,0x8(1); oris 0,0,1; lfs f31,0x4a2c(11); mr 4,30; stw 0,0x61c(31); li 6,-1; stw 9,0xd4(31); li 7,0; stfs f31,0xd0(31); lwz 3,0x8(31); lwz 5,0x0(9); addi 3,3,820; bl _s80064C84_19; mr 30,3; fmr f1,f31; lwz 3,0x8(31); mr 4,30; li 5,1; addi 3,3,820; bl _s80064C84_20; li 9,1; stb 9,0xd(30); lwz 0,0x61c(31); lwz 9,0x2c(31); ori 0,0,16; stw 0,0x61c(31); cmpwi 9,12; bne 36f; lis 9,-32707; lfs f13,0x98(31); lfs f0,0x4a30(9); mr 4,30; lfs f12,0x104(31); fdivs f0,f0,f13; lfs f1,0xfc(31); lwz 3,0x8(31); addi 3,3,820; fmuls f1,f1,f12; fmuls f1,f1,f0; bl _s80064C84_21; b 37f; 36:; lfs f1,0x104(31); mr 4,30; lwz 3,0x8(31); lfs f0,0xfc(31); addi 3,3,820; fmuls f1,f0,f1; bl _s80064C84_22; 37:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x10(1); lfd f31,0x18(1); addi 1,1,32"

extern "C" void _s80064C84_0();
extern "C" void _s80064C84_1();
extern "C" void _s80064C84_2();
extern "C" void _s80064C84_3();
extern "C" void _s80064C84_4();
extern "C" void _s80064C84_5();
extern "C" void _s80064C84_6();
extern "C" void _s80064C84_7();
extern "C" void _s80064C84_8();
extern "C" void _s80064C84_9();
extern "C" void _s80064C84_10();
extern "C" void _s80064C84_11();
extern "C" void _s80064C84_12();
extern "C" void _s80064C84_13();
extern "C" void _s80064C84_14();
extern "C" void _s80064C84_15();
extern "C" void _s80064C84_16();
extern "C" void _s80064C84_17();
extern "C" void _s80064C84_18();
extern "C" void _s80064C84_19();
extern "C" void _s80064C84_20();
extern "C" void _s80064C84_21();
extern "C" void _s80064C84_22();

struct SAnimator2 {
    void handleTurnAnimation();
};

void SAnimator2::handleTurnAnimation() {
}
