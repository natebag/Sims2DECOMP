// 0x80261D24 DVDLowBreak (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,-23360(13); li 3,1; stw 0,-23328(13)"
extern "C" void f_80261D24() {}
