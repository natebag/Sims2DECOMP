// 0x800900A0 ELiveMode::SetDontDraw(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x34(3)"
extern "C" void f_800900A0() {}
