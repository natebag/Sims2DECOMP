// 0x80391F84 GXClearVCacheMetric (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,8; lis 3,-13311; stb 0,-32768(3); li 0,0; stb 0,-32768(3); stw 0,-32768(3)"
extern "C" void f_80391F84() {}
