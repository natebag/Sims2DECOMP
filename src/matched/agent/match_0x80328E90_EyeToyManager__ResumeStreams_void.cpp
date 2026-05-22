// 0x80328E90 EyeToyManager::ResumeStreams(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-26600(13); li 0,0; stw 0,-26600(13)"
extern "C" void f_80328E90() {}
