// 0x8012C780 cXPersonImpl::GetIdleState(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 3,0x8(3)"
extern "C" int f_8012C780() {}
