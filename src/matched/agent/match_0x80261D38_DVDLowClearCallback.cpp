// 0x80261D38 DVDLowClearCallback (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; li 0,0; stw 0,0x6004(3); lwz 3,-23352(13); stw 0,-23332(13); stw 0,-23352(13)"
extern "C" void f_80261D38() {}
