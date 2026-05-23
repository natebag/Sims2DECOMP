// 0x800EAB4C cXObjectImpl::WaitingForSync(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xe4(3)"
extern "C" int f_800EAB4C() {}
