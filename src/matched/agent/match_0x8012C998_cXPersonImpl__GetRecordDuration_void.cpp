// 0x8012C998 cXPersonImpl::GetRecordDuration(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x434(3)"
extern "C" int f_8012C998() {}
