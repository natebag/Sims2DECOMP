// 0x800A7E64 Swizzle2(void (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x0(3); lbz 9,0x1(3); stb 0,0x1(3); stb 9,0x0(3)"
extern "C" void f_800A7E64() {}
