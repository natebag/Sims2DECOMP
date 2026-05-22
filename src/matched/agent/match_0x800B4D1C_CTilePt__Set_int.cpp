// 0x800B4D1C CTilePt::Set(int, (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stb 5,0x1(3); stb 4,0x0(3)"
extern "C" void f_800B4D1C() {}
