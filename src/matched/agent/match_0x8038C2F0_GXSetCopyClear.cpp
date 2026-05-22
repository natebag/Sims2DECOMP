// 0x8038C2F0 GXSetCopyClear (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 5,0x0(3); li 6,0; lbz 0,0x3(3); li 9,97; rlwimi 6,5,0,24,31; lis 8,-13311; lwz 5,-17720(13); rlwimi 6,0,8,16,23; stb 9,-32768(8); li 0,79; rlwimi 6,0,24,0,7; stw 6,-32768(8); li 10,0; li 6,80; lbz 7,0x2(3); li 11,0; lbz 3,0x1(3); li 0,81; rlwimi 11,7,0,24,31; rlwimi 11,3,8,16,23; stb 9,-32768(8); rlwimi 11,6,24,0,7; stw 11,-32768(8); rlwimi 10,4,0,8,31; rlwimi 10,0,24,0,7; stb 9,-32768(8); li 0,0; stw 10,-32768(8); sth 0,0x2(5)"
extern "C" void f_8038C2F0() {}
