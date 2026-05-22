// 0x800EAF38 cXObjectImpl::GetFolder(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8c(3); lwz 3,0x50(9)"
extern "C" int f_800EAF38() {}
