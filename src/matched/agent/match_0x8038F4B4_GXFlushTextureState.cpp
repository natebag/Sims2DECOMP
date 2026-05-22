// 0x8038F4B4 __GXFlushTextureState (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,97; lwz 4,-17720(13); lis 5,-13311; stb 0,-32768(5); li 0,0; lwz 3,0x124(4); stw 3,-32768(5); sth 0,0x2(4)"
extern "C" void f_8038F4B4() {}
