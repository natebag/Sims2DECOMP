// 0x800EB0FC cXObjectImpl::GetAttr(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(3); rlwinm 4,4,1,0,30; lhax 3,4,9"
extern "C" int f_800EB0FC() {}
