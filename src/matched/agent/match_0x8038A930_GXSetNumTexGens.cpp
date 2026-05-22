// 0x8038A930 GXSetNumTexGens (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 6,-17720(13); rlwinm 5,3,0,24,31; li 4,16; lwz 0,0x204(6); rlwimi 0,3,0,28,31; lis 3,-13311; stw 0,0x204(6); li 0,4159; stb 4,-32768(3); stw 0,-32768(3); stw 5,-32768(3); lwz 0,0x5ac(6); ori 0,0,4; stw 0,0x5ac(6)"
extern "C" void f_8038A930() {}
