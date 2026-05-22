// 0x8038F89C GXSetTevSwapMode (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 3,3,2,0,29; lwz 7,-17720(13); addi 8,3,368; add 8,7,8; lwz 0,0x0(8); rlwimi 0,4,0,30,31; li 3,97; stw 0,0x0(8); lis 4,-13311; li 0,0; lwz 6,0x0(8); rlwimi 6,5,2,28,29; stw 6,0x0(8); stb 3,-32768(4); lwz 3,0x0(8); stw 3,-32768(4); sth 0,0x2(7)"
extern "C" void f_8038F89C() {}
