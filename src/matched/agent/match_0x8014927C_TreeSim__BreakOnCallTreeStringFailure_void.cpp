// 0x8014927C TreeSim::BreakOnCallTreeStringFailure(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-31632(13)"
extern "C" int f_8014927C() {}
