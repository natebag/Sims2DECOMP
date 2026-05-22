// 0x80149284 TreeSim::SetBreakOnCallTreeStringFailure(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 3,-31632(13)"
extern "C" void f_80149284() {}
