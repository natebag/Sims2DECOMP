// 0x80125AD0 cXPersonImpl::IsIdle(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x534(3); xoris 3,3,1"
extern "C" int f_80125AD0() {}
