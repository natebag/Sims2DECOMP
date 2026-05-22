// 0x8038F968 GXSetAlphaCompare (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,4,0,24,31; lwz 4,-17720(13); lis 8,-3328; rlwimi 8,0,0,24,31; rlwinm 0,7,0,24,31; addi 7,8,0; rlwimi 7,0,8,16,23; rlwimi 7,3,16,13,15; rlwimi 7,6,19,10,12; li 0,97; lis 3,-13311; stb 0,-32768(3); rlwimi 7,5,22,8,9; li 0,0; stw 7,-32768(3); sth 0,0x2(4)"
extern "C" void f_8038F968() {}
