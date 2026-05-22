// 0x800B4D04 CTilePt::SetX(int) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stb 4,0x0(3); extsb 3,4"
extern "C" void f_800B4D04() {}
