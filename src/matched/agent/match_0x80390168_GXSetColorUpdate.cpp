// 0x80390168 GXSetColorUpdate (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,-17720(13); li 0,97; lis 4,-13311; lwz 6,0x1d0(5); rlwimi 6,3,3,28,28; stb 0,-32768(4); li 0,0; stw 6,-32768(4); stw 6,0x1d0(5); sth 0,0x2(5)"
extern "C" void f_80390168() {}
