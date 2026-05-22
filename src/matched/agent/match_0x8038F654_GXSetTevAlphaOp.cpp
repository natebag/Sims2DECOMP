// 0x8038F654 GXSetTevAlphaOp (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-17720(13); rlwinm 9,3,2,0,29; cmpwi 4,1; add 3,0,9; lwz 3,0x170(3); rlwimi 3,4,18,13,13; addi 10,3,0; bgt 0f; rlwimi 10,6,20,10,11; rlwimi 10,5,16,14,15; b 1f; 0:; li 0,3; rlwimi 10,4,19,10,11; rlwimi 10,0,16,14,15; 1:; li 0,97; lwz 4,-17720(13); lis 5,-13311; stb 0,-32768(5); rlwimi 10,7,19,12,12; rlwimi 10,8,22,8,9; stw 10,-32768(5); add 3,4,9; li 0,0; stw 10,0x170(3); sth 0,0x2(4)"
extern "C" void f_8038F654() {}
