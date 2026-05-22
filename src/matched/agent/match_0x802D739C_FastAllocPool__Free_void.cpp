// 0x802D739C FastAllocPool::Free(void (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 4,4; beqlr; lis 0,17733; ori 0,0,21062; stw 0,0x0(4); lwz 9,0x4(3); stw 9,0x4(4); stw 4,0x4(3)"
extern "C" void f_802D739C() {}
