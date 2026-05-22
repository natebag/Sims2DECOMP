// 0x802D79F8 ESemaphore::GetCurrentCount(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xc(3)"
extern "C" int f_802D79F8() {}
