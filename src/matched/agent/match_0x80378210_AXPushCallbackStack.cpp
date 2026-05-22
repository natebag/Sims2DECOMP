// 0x80378210 __AXPushCallbackStack (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-22288(13); stw 0,0x8(3); stw 3,-22288(13)"
extern "C" void f_80378210() {}
