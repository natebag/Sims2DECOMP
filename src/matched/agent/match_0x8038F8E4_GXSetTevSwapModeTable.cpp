// 0x8038F8E4 GXSetTevSwapModeTable (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 9,3,1,0,30; lwz 8,-17720(13); rlwinm 3,3,3,0,28; addi 10,3,432; add 10,8,10; lwz 3,0x0(10); rlwimi 3,4,0,30,31; addi 0,9,1; stw 3,0x0(10); rlwinm 3,0,2,0,29; addi 9,3,432; lwz 0,0x0(10); rlwimi 0,5,2,28,29; li 5,97; stw 0,0x0(10); lis 4,-13311; add 9,8,9; stb 5,-32768(4); li 0,0; lwz 3,0x0(10); stw 3,-32768(4); lwz 3,0x0(9); rlwimi 3,6,0,30,31; stw 3,0x0(9); lwz 3,0x0(9); rlwimi 3,7,2,28,29; stw 3,0x0(9); stb 5,-32768(4); lwz 3,0x0(9); stw 3,-32768(4); sth 0,0x2(8)"
extern "C" void f_8038F8E4() {}
