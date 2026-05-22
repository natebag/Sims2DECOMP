// 0x8012C990 cXPersonImpl::GetRecording(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x430(3)"
extern "C" int f_8012C990() {}
