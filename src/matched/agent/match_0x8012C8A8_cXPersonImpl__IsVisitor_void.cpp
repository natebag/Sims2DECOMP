// 0x8012C8A8 cXPersonImpl::IsVisitor(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 0,0x48(3); li 3,1; cmplwi 0,0; bnelr; li 3,0"
extern "C" int f_8012C8A8() {}
