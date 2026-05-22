// 0x8025A8D0 __DBExceptionDestination (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8025A888" lines="mfmsr 3; ori 3,3,48; mtmsr 3"
extern "C" void f_8025A888();
extern "C" void f_8025A8D0() {}
