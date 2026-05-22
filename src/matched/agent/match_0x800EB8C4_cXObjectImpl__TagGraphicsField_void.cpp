// 0x800EB8C4 cXObjectImpl::TagGraphicsField(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0xe8(3)"
extern "C" void f_800EB8C4() {}
