// 0x80390E84 GXSetScissor (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 7,-17720(13); addi 4,4,342; addi 6,6,-1; lwz 0,0xf8(7); rlwimi 0,4,0,21,31; addi 3,3,342; stw 0,0xf8(7); addi 8,5,-1; add 6,4,6; lwz 0,0xf8(7); rlwimi 0,3,12,9,19; add 8,3,8; stw 0,0xf8(7); li 5,97; lis 4,-13311; lwz 3,0xfc(7); rlwimi 3,6,0,21,31; li 0,0; stw 3,0xfc(7); lwz 3,0xfc(7); rlwimi 3,8,12,9,19; stw 3,0xfc(7); stb 5,-32768(4); lwz 3,0xf8(7); stw 3,-32768(4); stb 5,-32768(4); lwz 3,0xfc(7); stw 3,-32768(4); sth 0,0x2(7)"
extern "C" void f_80390E84() {}
