// 0x80090054 ELiveMode::ResetIntroCamera(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0xc(3)"
extern "C" void f_80090054() {}
