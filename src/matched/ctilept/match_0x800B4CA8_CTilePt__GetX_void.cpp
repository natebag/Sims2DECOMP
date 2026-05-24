// 0x800B4CA8 CTilePt::GetX(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 3,0x0(3); extsb 3,3"

struct CTilePt {
    void GetX();
};

void CTilePt::GetX() {
}
