// 0x80253428 OSInitThreadQueue (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x4(3); stw 0,0x0(3)"
extern "C" void f_80253428() {}
