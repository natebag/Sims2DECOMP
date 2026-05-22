// 0x800B4D28 CTilePt::Set(int, (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stb 6,0x2(3); stb 4,0x0(3); stb 5,0x1(3)"
extern "C" void f_800B4D28() {}
