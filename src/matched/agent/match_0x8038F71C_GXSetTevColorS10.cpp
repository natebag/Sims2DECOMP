// 0x8038F71C GXSetTevColorS10 (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 8,0x0(4); rlwinm 6,3,1,0,30; lwz 9,0x4(4); li 5,97; addi 3,6,224; rlwinm 7,3,24,0,7; lwz 3,-17720(13); lis 4,-13311; rlwimi 7,8,16,21,31; stb 5,-32768(4); rlwimi 7,9,12,9,19; stw 7,-32768(4); addi 6,6,225; rlwinm 6,6,24,0,7; rlwimi 6,9,16,21,31; stb 5,-32768(4); rlwimi 6,8,12,9,19; stw 6,-32768(4); li 0,0; stb 5,-32768(4); stw 6,-32768(4); stb 5,-32768(4); stw 6,-32768(4); sth 0,0x2(3)"
extern "C" void f_8038F71C() {}
