// 0x802E37B8 EEngine::ClearCurrentLevel(ERLevel (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x30(3); cmpw 0,4; bnelr; li 0,0; stw 0,0x30(3)"
extern "C" void f_802E37B8() {}
