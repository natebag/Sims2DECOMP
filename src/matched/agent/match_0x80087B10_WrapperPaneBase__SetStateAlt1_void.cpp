// 0x80087B10 WrapperPaneBase::SetStateAlt1(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,3; stw 0,0x34(3)"
extern "C" void f_80087B10() {}
