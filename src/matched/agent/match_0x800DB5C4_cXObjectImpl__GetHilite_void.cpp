// 0x800DB5C4 cXObjectImpl::GetHilite(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x84(3); rlwinm 3,3,0,27,31"
extern "C" int f_800DB5C4() {}
