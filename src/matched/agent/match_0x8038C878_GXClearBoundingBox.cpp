// 0x8038C878 GXClearBoundingBox (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 6,97; lwz 3,-17720(13); lis 5,-13311; lis 4,21760; stb 6,-32768(5); addi 0,4,1023; stw 0,-32768(5); lis 4,22016; addi 4,4,1023; stb 6,-32768(5); li 0,0; stw 4,-32768(5); sth 0,0x2(3)"
extern "C" void f_8038C878() {}
