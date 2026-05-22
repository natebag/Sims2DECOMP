// 0x800D8A70 NghResFile::SwapTwoByteNumber(unsigned (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x1(4); lbz 9,0x0(4); stb 0,0x0(4); stb 9,0x1(4)"
extern "C" void f_800D8A70() {}
