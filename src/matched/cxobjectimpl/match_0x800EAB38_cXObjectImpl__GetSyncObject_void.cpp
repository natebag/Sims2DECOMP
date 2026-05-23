// 0x800EAB38 cXObjectImpl::GetSyncObject(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xdc(3)"
extern "C" int f_800EAB38() {}
