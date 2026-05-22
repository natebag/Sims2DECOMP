// 0x80090060 ELiveMode::SetIntroCameraState(IntroCameraStartState) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0xc(3)"
extern "C" void f_80090060() {}
