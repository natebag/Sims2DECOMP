// 0x800B4DDC CTilePt::GetLevel(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 3,0x2(3); extsb 3,3"

struct CTilePt {
    void GetLevel();
};

void CTilePt::GetLevel() {
}
