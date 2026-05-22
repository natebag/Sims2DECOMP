// 0x800EABD4 cXObjectImpl::SetAutoCenter(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 3,-31904(13)"
extern "C" void f_800EABD4() {}
