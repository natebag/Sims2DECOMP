// 0x801354C0 RelMatrixImpl::CountKeys(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); lwz 3,0x8(3); subf 3,0,3; srawi 3,3,2"
extern "C" int f_801354C0() {}
