// 0x80035440 ESimScratchPadMan::InitHeap(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32765; lis 11,-32765; addi 9,9,21460; addi 11,11,21516; stw 9,-31948(13); stw 11,-31944(13)"
extern "C" void f_80035440() {}
