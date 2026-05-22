// 0x800EABE4 cXObjectImpl::SetAutoReset(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 3,-31900(13)"
extern "C" void f_800EABE4() {}
