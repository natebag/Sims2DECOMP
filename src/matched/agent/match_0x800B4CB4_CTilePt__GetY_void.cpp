// 0x800B4CB4 CTilePt::GetY(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 3,0x1(3); extsb 3,3"
extern "C" int f_800B4CB4() {}
