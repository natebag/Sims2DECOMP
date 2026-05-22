// 0x8006A69C SAnimator2::GetMovementVelocityFromStyle(SAnimator2::eWalkRunStyle) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x9c(3); cmpwi 4,2; bne 0f; lfs f1,0xa8(3); blr; 0:; cmpwi 4,3; bne 1f; lfs f1,0xac(3); blr; 1:; cmpwi 4,1; bne 2f; lfs f1,0xa0(3); blr; 2:; cmpwi 4,7; bne 4f; 3:; lis 9,-32707; lfs f1,0x4d08(9); blr; 4:; cmpwi 4,8; bne 5f; lis 9,-32707; lfs f1,0x4d0c(9); blr; 5:; cmpwi 4,4; bne 6f; lis 9,-32707; lfs f1,0x4d10(9); blr; 6:; cmpwi 4,5; beq 3b; cmpwi 4,6; bnelr; lis 9,-32707; lfs f1,0x4d10(9)"
extern "C" float f_8006A69C() {}
