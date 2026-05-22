// 0x8038F6BC GXSetTevColor (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 6,3,1,0,30; lwz 8,0x0(4); addi 4,6,224; lwz 3,-17720(13); rlwinm 7,4,24,0,7; li 5,97; lis 4,-13311; rlwimi 7,8,8,24,31; stb 5,-32768(4); rlwimi 7,8,12,12,19; stw 7,-32768(4); addi 6,6,225; rlwinm 6,6,24,0,7; rlwimi 6,8,24,24,31; stb 5,-32768(4); rlwimi 6,8,28,12,19; stw 6,-32768(4); li 0,0; stb 5,-32768(4); stw 6,-32768(4); stb 5,-32768(4); stw 6,-32768(4); sth 0,0x2(3)"
extern "C" void f_8038F6BC() {}
