// 0x802E26F0 EApp::PlayMovie(unsigned (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 4,4; beqlr; li 0,1; stw 6,0x464(3); stw 4,0x45c(3); stw 0,0x454(3); stw 5,0x460(3)"
extern "C" void f_802E26F0() {}
