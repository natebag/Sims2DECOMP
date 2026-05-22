// 0x8026B76C AptDebugEnableSavedInputs(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 3,-27608(13); stw 0,-23012(13)"
extern "C" void f_8026B76C() {}
