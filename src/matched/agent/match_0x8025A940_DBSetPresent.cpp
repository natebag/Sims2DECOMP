// 0x8025A940 __DBSetPresent (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-23520(13); stw 3,0x0(4)"
extern "C" void f_8025A940() {}
