// 0x800EB3EC cXObjectImpl::GetRelMatrix(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x60(3)"
extern "C" int f_800EB3EC() {}
