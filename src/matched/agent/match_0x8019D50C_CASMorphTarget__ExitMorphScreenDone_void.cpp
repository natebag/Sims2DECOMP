// 0x8019D50C CASMorphTarget::ExitMorphScreenDone(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x1c0(3)"
extern "C" void f_8019D50C() {}
