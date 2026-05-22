// 0x800E2ACC cXObjectImpl::SetLevel(int) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x80(3)"
extern "C" void f_800E2ACC() {}
