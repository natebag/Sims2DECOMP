// 0x800689F4 SAnimator2::SetIdleInitialized(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x120(3)"
extern "C" void f_800689F4() {}
