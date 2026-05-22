// 0x8014924C TreeSim::SetTooLongInPrimTime(bool, (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 3,-31648(13); stfs f1,-31644(13)"
extern "C" void f_8014924C() {}
