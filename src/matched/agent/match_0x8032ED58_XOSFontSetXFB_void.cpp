// 0x8032ED58 XOSFontSetXFB(void (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 3,-26440(13); stw 4,-26436(13); stw 5,-26432(13)"
extern "C" void f_8032ED58() {}
