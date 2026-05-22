// 0x802D7230 FastAllocPool::GetPoolSize(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x8(3); lwz 3,0xc(3); mullw 3,3,0"
extern "C" int f_802D7230() {}
