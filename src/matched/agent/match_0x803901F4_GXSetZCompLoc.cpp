// 0x803901F4 GXSetZCompLoc (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 6,-17720(13); rlwinm 0,3,0,24,31; li 3,97; lwz 5,0x1dc(6); rlwimi 5,0,6,25,25; lis 4,-13311; stw 5,0x1dc(6); li 0,0; stb 3,-32768(4); lwz 3,0x1dc(6); stw 3,-32768(4); sth 0,0x2(6)"
extern "C" void f_803901F4() {}
