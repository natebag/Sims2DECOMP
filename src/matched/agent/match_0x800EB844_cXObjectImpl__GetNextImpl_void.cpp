// 0x800EB844 cXObjectImpl::GetNextImpl(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x5c(3)"
extern "C" int f_800EB844() {}
