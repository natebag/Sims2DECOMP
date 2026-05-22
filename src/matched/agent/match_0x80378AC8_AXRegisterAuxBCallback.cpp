// 0x80378AC8 AXRegisterAuxBCallback (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 3,-22276(13); stw 4,-22268(13)"
extern "C" void f_80378AC8() {}
