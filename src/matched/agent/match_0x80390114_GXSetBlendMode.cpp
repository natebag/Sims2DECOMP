// 0x80390114 GXSetBlendMode (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 8,-17720(13); subfic 0,3,3; cntlzw 7,0; subfic 0,3,2; lwz 9,0x1d0(8); rlwimi 9,7,6,20,20; addi 7,9,0; rlwimi 7,3,0,31,31; cntlzw 0,0; rlwimi 7,0,28,30,30; rlwimi 7,6,12,16,19; rlwimi 7,4,8,21,23; li 0,97; lis 3,-13311; stb 0,-32768(3); rlwimi 7,5,5,24,26; li 0,0; stw 7,-32768(3); stw 7,0x1d0(8); sth 0,0x2(8)"
extern "C" void f_80390114() {}
