// 0x80321710 ArcCopier::ResumeCopy(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,-26640(13)"
extern "C" void f_80321710() {}
