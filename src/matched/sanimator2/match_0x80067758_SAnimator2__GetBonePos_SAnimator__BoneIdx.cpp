// 0x80067758 SAnimator2::GetBonePos(SAnimator::BoneIdx, (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="cmpwi 4,1; beq 2f; bgt 0f; cmpwi 4,0; beq 3f; blr; 0:; cmpwi 4,2; bnelr; addi 9,3,344; lwz 10,0x158(3); 1:; lwz 0,0x8(9); lwz 11,0x4(9); stw 0,0x8(5); stw 10,0x0(5); stw 11,0x4(5); blr; 2:; addi 9,3,332; lwz 10,0x14c(3); b 1b; 3:; addi 9,3,308; lwz 10,0x134(3); b 1b"

struct SAnimator2 {
    void GetBonePos_SAnimator__BoneIdx();
};

void SAnimator2::GetBonePos_SAnimator__BoneIdx() {
}
