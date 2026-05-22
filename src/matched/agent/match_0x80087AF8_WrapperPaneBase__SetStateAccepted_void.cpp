// 0x80087AF8 WrapperPaneBase::SetStateAccepted(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0x34(3)"
extern "C" void f_80087AF8() {}
