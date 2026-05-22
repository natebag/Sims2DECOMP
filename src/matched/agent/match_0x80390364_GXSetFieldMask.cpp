// 0x80390364 GXSetFieldMask (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,4,0,24,31; lwz 4,-17720(13); li 5,0; rlwimi 5,0,0,31,31; rlwimi 5,3,1,30,30; li 0,97; lis 3,-13311; stb 0,-32768(3); li 0,68; rlwimi 5,0,24,0,7; stw 5,-32768(3); li 0,0; sth 0,0x2(4)"
extern "C" void f_80390364() {}
