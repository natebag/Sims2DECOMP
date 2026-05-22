// 0x8012C9C0 cXPersonImpl::GetRecordCurTicks(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x43c(3)"
extern "C" int f_8012C9C0() {}
