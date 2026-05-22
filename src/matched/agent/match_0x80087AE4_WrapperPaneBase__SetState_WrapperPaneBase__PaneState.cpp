// 0x80087AE4 WrapperPaneBase::SetState(WrapperPaneBase::PaneState) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x34(3)"
extern "C" void f_80087AE4() {}
