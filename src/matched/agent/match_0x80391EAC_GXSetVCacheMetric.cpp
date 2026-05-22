// 0x80391EAC GXSetVCacheMetric (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 7,-17720(13); li 6,8; lis 5,-13311; lwz 0,0x5a4(7); rlwimi 0,3,0,28,31; li 4,32; stw 0,0x5a4(7); li 3,16; li 0,1; stb 6,-32768(5); stb 4,-32768(5); lwz 4,0x5a4(7); stw 4,-32768(5); stb 6,-32768(5); stb 3,-32768(5); stw 0,-32768(5)"
extern "C" void f_80391EAC() {}
