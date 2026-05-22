// 0x802E3A3C RegisterExitFunction (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 3,-26736(13)"
extern "C" void f_802E3A3C() {}
