// 0x80240688 SimpleReconObject<CasCostumes>::GetType(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8024071C" lines="bl _s80240688_0"
extern "C" void _s80240688_0();
extern "C" void f_8024071C();
extern "C" void f_80240688() {}
