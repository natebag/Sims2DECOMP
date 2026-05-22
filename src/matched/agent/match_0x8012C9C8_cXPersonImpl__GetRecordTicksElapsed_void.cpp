// 0x8012C9C8 cXPersonImpl::GetRecordTicksElapsed(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x444(3)"
extern "C" int f_8012C9C8() {}
