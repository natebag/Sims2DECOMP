// 0x800EAA3C cXObjectImpl::GetNumAttr(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xc(3)"
extern "C" int f_800EAA3C() {}
