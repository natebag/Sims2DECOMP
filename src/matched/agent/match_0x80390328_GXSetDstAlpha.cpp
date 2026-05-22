// 0x80390328 GXSetDstAlpha (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 6,-17720(13); rlwinm 5,4,0,24,31; li 0,97; lwz 7,0x1d4(6); lis 4,-13311; rlwimi 7,5,0,24,31; stb 0,-32768(4); rlwinm 0,3,0,24,31; addi 3,7,0; rlwimi 3,0,8,23,23; stw 3,-32768(4); li 0,0; stw 3,0x1d4(6); sth 0,0x2(6)"
extern "C" void f_80390328() {}
