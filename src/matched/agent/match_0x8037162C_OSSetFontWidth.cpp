// 0x8037162C OSSetFontWidth (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-22376(13); stw 3,-22376(13); mr 3,0"
extern "C" void f_8037162C() {}
