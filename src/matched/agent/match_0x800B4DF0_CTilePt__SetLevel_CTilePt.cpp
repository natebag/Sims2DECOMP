// 0x800B4DF0 CTilePt::SetLevel(CTilePt (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x2(4); stb 0,0x2(3)"
extern "C" void f_800B4DF0() {}
