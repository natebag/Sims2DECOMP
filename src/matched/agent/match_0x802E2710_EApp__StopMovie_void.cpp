// 0x802E2710 EApp::StopMovie(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x454(3)"
extern "C" void f_802E2710() {}
