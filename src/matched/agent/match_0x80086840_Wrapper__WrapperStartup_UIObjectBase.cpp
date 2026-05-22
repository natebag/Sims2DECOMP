// 0x80086840 Wrapper::WrapperStartup(UIObjectBase (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x88(3)"
extern "C" void f_80086840() {}
