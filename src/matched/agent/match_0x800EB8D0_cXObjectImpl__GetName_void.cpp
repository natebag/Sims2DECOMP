// 0x800EB8D0 cXObjectImpl::GetName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8c(3); lwz 3,0x14(9)"
extern "C" int f_800EB8D0() {}
