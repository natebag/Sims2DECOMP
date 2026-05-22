// 0x8038B14C GXTexModeSync (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,97; lwz 3,-17720(13); lis 5,-13311; stb 0,-32768(5); lis 4,25344; li 0,0; stw 4,-32768(5); sth 0,0x2(3)"
extern "C" void f_8038B14C() {}
