// 0x8038FE10 GXSetFogColor (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,0x0(3); li 0,97; lis 4,-13311; lwz 3,-17720(13); stb 0,-32768(4); rlwinm 0,5,24,8,31; lis 5,-3584; rlwimi 5,0,0,8,31; stw 5,-32768(4); li 0,0; sth 0,0x2(3)"
extern "C" void f_8038FE10() {}
