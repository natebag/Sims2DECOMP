// 0x802E38D4 EEngine::SetResetAllowed(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0xc(3)"
extern "C" void f_802E38D4() {}
