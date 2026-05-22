// 0x800EABC4 cXObjectImpl::GetFreeWill(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-31912(13)"
extern "C" int f_800EABC4() {}
