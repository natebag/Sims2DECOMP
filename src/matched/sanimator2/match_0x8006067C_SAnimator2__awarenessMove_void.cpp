// 0x8006067C SAnimator2::awarenessMove(void) (608 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stfd f30,0x38(1); stfd f31,0x40(1); stmw 29,0x2c(1); stw 0,0x4c(1); mr 31,3; lfs f0,-26800(13); lfs f12,0xfc(31); lis 9,-32707; lfs f13,0x104(31); li 30,0; fmuls f0,f0,f12; lfs f30,0x477c(9); addi 29,1,16; fmuls f31,f0,f13; 0:; lwz 0,0x18(31); cmpwi 0,7; beq 5f; bgt 1f; cmpwi 0,6; beq 2f; b 11f; 1:; cmpwi 0,8; beq 8f; b 11f; 2:; lfs f1,0xb4(31); mr 3,31; bl _s8006067C_0; fcmpu 0,f1,f30; stfs f1,0x8(1); bne 3f; lfs f0,0xb4(31); li 30,1; stfs f0,0x30(31); b 4f; 3:; mr 3,31; addi 4,31,180; addi 5,1,8; fmr f1,f31; bl _s8006067C_1; mr 30,3; 4:; cmpwi 30,1; bne 12f; mr 3,31; bl _s8006067C_2; b 11f; 5:; addi 3,31,1568; li 30,0; lwz 0,0x18(3); cmpwi 0,3; bne 7f; lwz 0,0x620(31); andi. 9,0,16; beq 6f; lwz 9,0x0(31); lha 3,0x138(9); lwz 0,0x13c(9); add 3,31,3; mtspr 8,0; blrl; b 11f; 6:; bl _s8006067C_3; cmpwi 3,0; beq 11f; 7:; mr 3,31; li 30,1; bl _s8006067C_4; b 11f; 8:; lfs f1,0xb4(31); mr 3,31; bl _s8006067C_5; fcmpu 0,f1,f30; stfs f1,0x8(1); bne 9f; lfs f0,0xb4(31); li 30,1; stfs f0,0x30(31); b 10f; 9:; mr 3,31; addi 4,31,180; addi 5,1,8; fmr f1,f31; bl _s8006067C_6; mr 30,3; 10:; cmpwi 30,1; bne 12f; mr 3,31; li 30,0; bl _s8006067C_7; 11:; cmpwi 30,1; beq 0b; 12:; lwz 9,0x4(31); lwz 10,0x0(9); lwz 11,0x4(10); lwz 0,0x354(11); lha 3,0x350(11); mtspr 8,0; add 3,10,3; blrl; lis 9,-32707; lfs f0,0x1c(31); lfs f10,0x4780(9); lfs f13,0x20(31); mr 9,11; fadds f0,f0,f10; lwz 10,0x4(31); mr 30,3; fctiwz f12,f0; mr 4,29; stfd f12,0x20(1); fadds f13,f13,f10; mr 5,30; lwz 11,0x24(1); fctiwz f11,f13; stfd f11,0x20(1); li 6,0; stw 11,0x4(29); li 7,0; lwz 9,0x24(1); stw 9,0x10(1); lwz 11,0x0(10); lwz 9,0x4(11); lha 3,0x130(9); lwz 0,0x134(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 13f; lwz 9,0x4(31); mr 4,29; mr 5,30; li 6,0; lwz 11,0x0(9); li 7,0; lwz 9,0x4(11); lha 3,0x138(9); lwz 0,0x13c(9); add 3,11,3; mtspr 8,0; blrl; 13:; mr 3,31; lfs f1,0x30(3); bl _s8006067C_8; lwz 0,0x4c(1); mtspr 8,0; lmw 29,0x2c(1); lfd f30,0x38(1); lfd f31,0x40(1); addi 1,1,72"

extern "C" void _s8006067C_0();
extern "C" void _s8006067C_1();
extern "C" void _s8006067C_2();
extern "C" void _s8006067C_3();
extern "C" void _s8006067C_4();
extern "C" void _s8006067C_5();
extern "C" void _s8006067C_6();
extern "C" void _s8006067C_7();
extern "C" void _s8006067C_8();

struct SAnimator2 {
    void awarenessMove();
};

void SAnimator2::awarenessMove() {
}
