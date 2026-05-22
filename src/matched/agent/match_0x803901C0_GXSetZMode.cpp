// 0x803901C0 GXSetZMode (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 6,-17720(13); li 0,97; lwz 7,0x1d8(6); rlwimi 7,3,0,31,31; lis 3,-13311; stb 0,-32768(3); rlwimi 7,4,1,28,30; rlwimi 7,5,4,27,27; stw 7,-32768(3); li 0,0; stw 7,0x1d8(6); sth 0,0x2(6)"
extern "C" void f_803901C0() {}
