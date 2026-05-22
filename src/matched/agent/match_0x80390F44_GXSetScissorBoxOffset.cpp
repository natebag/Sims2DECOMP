// 0x80390F44 GXSetScissorBoxOffset (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 5,3,342; lwz 3,-17720(13); addi 0,4,342; li 4,0; rlwimi 4,5,31,22,31; addi 5,4,0; rlwimi 5,0,9,12,21; li 0,97; lis 4,-13311; stb 0,-32768(4); li 0,89; rlwimi 5,0,24,0,7; stw 5,-32768(4); li 0,0; sth 0,0x2(3)"
extern "C" void f_80390F44() {}
