// 0x8012C978 cXPersonImpl::GetVisibility(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 3,0x9c(3)"
extern "C" int f_8012C978() {}
