// 0x802D7240 FastAllocPool::GetBlockSize(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xc(3)"
extern "C" int f_802D7240() {}
