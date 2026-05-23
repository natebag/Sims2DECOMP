// 0x800EB2E0 cXObjectImpl::GetID(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 3,0x64(3)"
extern "C" int f_800EB2E0() {}
