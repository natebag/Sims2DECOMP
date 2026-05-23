// 0x8005FF80 SAnimator2::endMoveAnimation(void) (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 31,3; addi 0,1,8; lwz 11,0x4(31); mr 30,0; lwz 10,0x0(11); lwz 9,0x4(10); lwz 0,0x354(9); lha 3,0x350(9); mtspr 8,0; add 3,10,3; blrl; mr 29,3; lwz 5,0x14(31); lwz 3,0xc(31); lwz 10,0x0(3); lwz 0,0x4(3); subf 0,10,0; srawi 11,0,3; addi 9,11,-1; cmpw 5,9; blt 0f; addi 11,11,-2; rlwinm 11,11,3,0,28; add 9,10,11; lwz 0,0x4(9); stw 0,0x4(30); lwz 9,0x0(3); lwzx 0,9,11; stw 0,0x8(1); b 1f; 0:; lis 9,-32707; lfs f0,0x1c(31); lfs f10,0x4750(9); lfs f13,0x20(31); mr 9,11; fadds f0,f0,f10; mr 4,30; fctiwz f12,f0; stfd f12,0x18(1); fadds f13,f13,f10; lwz 11,0x1c(1); fctiwz f11,f13; stfd f11,0x18(1); stw 11,0x4(30); lwz 9,0x1c(1); stw 9,0x8(1); bl _s8005FF80_0; 1:; lwz 9,0x4(31); mr 4,30; mr 5,29; li 6,0; lwz 11,0x0(9); li 7,0; lwz 9,0x4(11); lha 3,0x130(9); lwz 0,0x134(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; li 0,3; stw 0,0x10(31); b 3f; 2:; lwz 9,0x4(31); mr 4,30; mr 5,29; li 6,0; lwz 11,0x0(9); li 7,0; lwz 9,0x4(11); lha 3,0x138(9); lwz 0,0x13c(9); add 3,11,3; mtspr 8,0; blrl; 3:; mr 3,31; lfs f1,0x30(3); bl _s8005FF80_1; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"

extern "C" void _s8005FF80_0();
extern "C" void _s8005FF80_1();

struct SAnimator2 {
    void endMoveAnimation();
};

void SAnimator2::endMoveAnimation() {
}
