// 0x800AA9F4 SAnimator2::clearImpatientIdleAnimation(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,0; bne 0f; li 31,1; 0:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16; blr; lwz 0,0x0(3); li 9,0; cmpwi 0,0; beq 1f; lwz 0,0x4(3); cmpwi 0,0; beq 1f; li 9,1; 1:; mr 3,9; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; mr. 4,3; beq 2f; lwz 3,-21432(13); bl _s800AA9F4_0; mr 0,3; 2:; mr. 3,0; bne 3f; lis 9,-32706; addi 3,9,-28064; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s800AA9F4_0();

struct SAnimator2 {
    void clearImpatientIdleAnimation();
};

void SAnimator2::clearImpatientIdleAnimation() {
}
