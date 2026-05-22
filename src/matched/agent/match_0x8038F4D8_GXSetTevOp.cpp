// 0x8038F4D8 GXSetTevOp (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,0; lis 5,-32698; addi 0,5,-23000; bne 0f; rlwinm 4,4,2,0,29; add 5,0,4; addi 9,5,40; b 1f; 0:; rlwinm 4,4,2,0,29; add 5,0,4; add 9,0,4; addi 5,5,20; addi 9,9,60; 1:; lwz 7,-17720(13); rlwinm 3,3,2,0,29; lwz 0,0x0(5); li 5,97; add 6,7,3; lwz 3,0x130(6); lis 4,-13311; stb 5,-32768(4); rlwinm 3,3,0,0,7; rlwimi 3,0,0,8,31; stw 3,-32768(4); li 0,0; stw 3,0x130(6); lwz 8,0x170(6); lwz 3,0x0(9); rlwinm 8,8,0,28,7; stb 5,-32768(4); rlwimi 8,3,0,8,27; stw 8,-32768(4); stw 8,0x170(6); sth 0,0x2(7)"
extern "C" void f_8038F4D8() {}
