// 0x8038F484 __GXSetIndirectMask (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 7,-17720(13); li 5,97; lis 4,-13311; lwz 6,0x124(7); rlwimi 6,3,0,24,31; li 0,0; stw 6,0x124(7); stb 5,-32768(4); lwz 3,0x124(7); stw 3,-32768(4); sth 0,0x2(7)"
extern "C" void f_8038F484() {}
