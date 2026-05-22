// 0x80134710 ReconBuilder::SwapFourByteNumber(unsigned (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 10,0x3(4); lbz 9,0x0(4); lbz 0,0x2(4); lbz 11,0x1(4); stb 0,0x1(4); stb 9,0x3(4); stb 10,0x0(4); stb 11,0x2(4)"
extern "C" void f_80134710() {}
