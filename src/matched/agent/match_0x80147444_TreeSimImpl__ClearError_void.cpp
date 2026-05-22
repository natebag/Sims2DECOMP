// 0x80147444 TreeSimImpl::ClearError(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; sth 0,0x34(3)"
extern "C" void f_80147444() {}
