// 0x8038F5A8 GXSetTevAlphaIn (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-17720(13); rlwinm 3,3,2,0,29; li 0,97; add 8,9,3; lwz 10,0x170(8); lis 3,-13311; rlwimi 10,4,13,16,18; stb 0,-32768(3); addi 4,10,0; rlwimi 4,5,10,19,21; rlwimi 4,6,7,22,24; rlwimi 4,7,4,25,27; stw 4,-32768(3); li 0,0; stw 4,0x170(8); sth 0,0x2(9)"
extern "C" void f_8038F5A8() {}
