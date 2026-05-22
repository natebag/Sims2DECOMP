// 0x80378718 __AXAuxQuit (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,-22280(13); stw 0,-22276(13)"
extern "C" void f_80378718() {}
