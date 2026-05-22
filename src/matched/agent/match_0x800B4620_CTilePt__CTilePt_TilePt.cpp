// 0x800B4620 CTilePt::CTilePt(TilePt (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x3(4); mr 9,3; stb 0,0x0(9); lbz 11,0x7(4); stb 5,0x2(9); stb 11,0x1(9)"
extern "C" void f_800B4620() {}
