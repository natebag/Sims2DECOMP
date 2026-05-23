// 0x800E2AC4 cXObjectImpl::GetLevel(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x80(3)"
extern "C" int f_800E2AC4() {}
