// 0x8026B808 AptFlushInputQueue(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32694; lwz 0,-16052(9); cmplwi 0,0; bnelr; lwz 9,-23008(13); cmplwi 9,0; beqlr; stw 0,0x34(9)"
extern "C" void f_8026B808() {}
