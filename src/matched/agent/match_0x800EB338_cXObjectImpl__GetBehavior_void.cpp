// 0x800EB338 cXObjectImpl::GetBehavior(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8c(3); lwz 3,0xc(9)"
extern "C" int f_800EB338() {}
