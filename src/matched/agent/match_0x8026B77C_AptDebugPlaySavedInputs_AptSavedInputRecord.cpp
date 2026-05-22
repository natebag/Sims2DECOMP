// 0x8026B77C AptDebugPlaySavedInputs(AptSavedInputRecord (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 11,-32694; li 0,0; addi 9,11,-16052; stw 0,0x10(9); stw 3,-16052(11); stw 3,0x4(9); stw 4,0x8(9)"
extern "C" void f_8026B77C() {}
