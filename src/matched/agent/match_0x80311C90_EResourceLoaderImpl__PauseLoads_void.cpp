// 0x80311C90 EResourceLoaderImpl::PauseLoads(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0x3e8(3)"
extern "C" void f_80311C90() {}
