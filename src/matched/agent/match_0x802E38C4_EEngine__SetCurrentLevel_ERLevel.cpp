// 0x802E38C4 EEngine::SetCurrentLevel(ERLevel (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x30(3)"
extern "C" void f_802E38C4() {}
