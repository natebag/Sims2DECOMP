// 0x80378ABC AXRegisterAuxACallback (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 3,-22280(13); stw 4,-22272(13)"
extern "C" void f_80378ABC() {}
