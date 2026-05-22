// 0x80090090 ELiveMode::SetInitialized(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x30(3)"
extern "C" void f_80090090() {}
