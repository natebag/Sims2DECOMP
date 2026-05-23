// 0x800B3C50 SAnimator2::SetNormalSimDescription(CasSimDescriptionS2C (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_800B3C78" lines="li 3,1"

struct SAnimator2 {
    void SetNormalSimDescription();
};

void SAnimator2::SetNormalSimDescription() {
}
