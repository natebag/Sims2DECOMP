// 0x80068DD0 SAnimator2::shouldUseLowMotiveWalk(void) (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f30,0x10(1); stfd f31,0x18(1); stmw 30,0x8(1); stw 0,0x24(1); mr 31,3; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x178(9); lwz 9,0x17c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; li 3,0; b 3f; 0:; lwz 10,0x4(31); li 4,5; lis 11,-32707; li 30,5; lwz 9,0x4(10); lfs f30,0x4bec(11); lwz 0,0x5c(9); lha 3,0x58(9); mtspr 8,0; add 3,10,3; blrl; lwz 11,0x4(31); li 4,9; fmr f31,f1; lwz 9,0x4(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; fcmpu 0,f1,f31; cror 3,2,0; bns 1f; lwz 3,0x4(31); li 4,9; li 30,9; lwz 9,0x4(3); lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; fmr f31,f1; 1:; fcmpu 0,f31,f30; cror 3,2,1; bns 2f; li 30,0; 2:; mr 3,30; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x8(1); lfd f30,0x10(1); lfd f31,0x18(1); addi 1,1,32"

struct SAnimator2 {
    void shouldUseLowMotiveWalk();
};

void SAnimator2::shouldUseLowMotiveWalk() {
}
