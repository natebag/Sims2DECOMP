// 0x80321704 ArcCopier::TerminateCopy(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,-26640(13)"
extern "C" void f_80321704() {}
