// 0x800EB10C cXObjectImpl::GetModule(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x58(3)"
extern "C" int f_800EB10C() {}
