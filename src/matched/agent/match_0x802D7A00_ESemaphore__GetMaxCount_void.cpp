// 0x802D7A00 ESemaphore::GetMaxCount(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x8(3)"
extern "C" int f_802D7A00() {}
