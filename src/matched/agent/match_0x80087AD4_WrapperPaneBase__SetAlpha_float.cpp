// 0x80087AD4 WrapperPaneBase::SetAlpha(float) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f1,0x30(3)"
extern "C" void f_80087AD4() {}
