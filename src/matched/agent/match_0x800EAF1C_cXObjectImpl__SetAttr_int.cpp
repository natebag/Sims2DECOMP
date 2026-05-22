// 0x800EAF1C cXObjectImpl::SetAttr(int, (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(3); rlwinm 4,4,1,0,30; sthx 5,4,9"
extern "C" void f_800EAF1C() {}
