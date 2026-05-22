// 0x802B8F98 CSMTarget::IsCSIMActive(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_802B9128" lines="bl _s802B8F98_0"
extern "C" void _s802B8F98_0();
extern "C" void f_802B9128();
extern "C" void f_802B8F98() {}
