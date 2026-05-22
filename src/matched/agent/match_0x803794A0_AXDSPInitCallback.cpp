// 0x803794A0 __AXDSPInitCallback (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,-22172(13)"
extern "C" void f_803794A0() {}
