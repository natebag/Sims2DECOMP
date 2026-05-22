// 0x802D78C8 ESemaphore::Destroy(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x4(3)"
extern "C" void f_802D78C8() {}
