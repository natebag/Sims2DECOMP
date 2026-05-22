// 0x80149260 TreeSim::SetTooLongInTickTime(bool, (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 3,-31648(13); stfs f1,-31640(13)"
extern "C" void f_80149260() {}
