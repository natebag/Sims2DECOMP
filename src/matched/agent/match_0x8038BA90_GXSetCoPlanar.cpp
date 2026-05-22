// 0x8038BA90 GXSetCoPlanar (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 6,-17720(13); li 4,97; lis 0,-504; lwz 5,0x204(6); rlwimi 5,3,19,12,12; lis 3,-13311; stw 5,0x204(6); stb 4,-32768(3); stw 0,-32768(3); stb 4,-32768(3); lwz 0,0x204(6); stw 0,-32768(3)"
extern "C" void f_8038BA90() {}
