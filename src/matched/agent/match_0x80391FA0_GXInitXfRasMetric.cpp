// 0x80391FA0 GXInitXfRasMetric (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,97; lwz 3,-17720(13); lis 5,-13311; lis 4,9219; stb 0,-32768(5); addi 0,4,-16350; stw 0,-32768(5); li 0,16; lis 4,3; stb 0,-32768(5); li 0,4102; addi 4,4,4096; stw 0,-32768(5); li 0,1; stw 4,-32768(5); sth 0,0x2(3)"
extern "C" void f_80391FA0() {}
