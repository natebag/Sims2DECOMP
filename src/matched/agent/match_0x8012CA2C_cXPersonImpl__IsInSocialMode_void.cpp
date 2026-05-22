// 0x8012CA2C cXPersonImpl::IsInSocialMode(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 0,0x58(3); li 3,1; cmplwi 0,0; bnelr; li 3,0"
extern "C" int f_8012CA2C() {}
