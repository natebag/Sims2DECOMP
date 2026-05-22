// 0x800EAB40 cXObjectImpl::ClearSyncObject(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0xdc(3)"
extern "C" void f_800EAB40() {}
