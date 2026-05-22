// 0x802D867C EThread::SetThreadName(char (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x32c(3)"
extern "C" void f_802D867C() {}
