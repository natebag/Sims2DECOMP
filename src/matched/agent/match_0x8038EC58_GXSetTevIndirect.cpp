// 0x8038EC58 GXSetTevIndirect (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); li 0,0; rlwimi 0,4,0,30,31; stw 31,0x2c(1); mr 11,0; rlwimi 11,5,2,28,29; lwz 12,0x3c(1); lbz 31,0x3b(1); rlwimi 11,6,4,25,27; lwz 4,-17720(13); rlwimi 11,12,7,23,24; rlwimi 11,7,9,19,22; rlwimi 11,8,13,16,18; rlwimi 11,9,16,13,15; rlwimi 11,31,19,12,12; li 0,97; lis 5,-13311; stb 0,-32768(5); addi 0,3,16; rlwimi 11,10,20,11,11; rlwimi 11,0,24,0,7; stw 11,-32768(5); li 0,0; sth 0,0x2(4); lwz 31,0x2c(1); addi 1,1,48"
extern "C" void f_8038EC58() {}
