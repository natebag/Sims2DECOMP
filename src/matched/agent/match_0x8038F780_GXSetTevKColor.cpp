// 0x8038F780 GXSetTevKColor (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 5,3,1,0,30; lwz 9,0x0(4); addi 4,5,224; lwz 3,-17720(13); rlwinm 4,4,24,0,7; rlwimi 4,9,8,24,31; addi 8,4,0; li 0,97; lis 4,-13311; addi 6,5,225; stb 0,-32768(4); rlwinm 6,6,24,0,7; rlwimi 6,9,24,24,31; addi 5,6,0; li 7,8; rlwimi 8,9,12,12,19; rlwimi 8,7,20,8,11; stw 8,-32768(4); rlwimi 5,9,28,12,19; rlwimi 5,7,20,8,11; stb 0,-32768(4); li 0,0; stw 5,-32768(4); sth 0,0x2(3)"
extern "C" void f_8038F780() {}
