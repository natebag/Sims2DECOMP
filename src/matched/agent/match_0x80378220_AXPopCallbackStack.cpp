// 0x80378220 __AXPopCallbackStack (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-22288(13); cmpwi 0,0; mr 3,0; beqlr; lwz 0,0x8(3); stw 0,-22288(13)"
extern "C" void f_80378220() {}
