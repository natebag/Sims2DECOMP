// 0x80391E7C GXClearPixMetric (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 7,97; lwz 3,-17720(13); lis 6,-13311; lis 5,22272; stb 7,-32768(6); addi 4,5,2730; stw 5,-32768(6); li 0,0; stb 7,-32768(6); stw 4,-32768(6); sth 0,0x2(3)"
extern "C" void f_80391E7C() {}
