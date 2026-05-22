// 0x800B4D10 CTilePt::SetY(int) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stb 4,0x1(3); extsb 3,4"
extern "C" void f_800B4D10() {}
