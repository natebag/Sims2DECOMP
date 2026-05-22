// 0x8012C714 cXPersonImpl::GetPendingAction(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x534(3); li 3,0; cmplwi 0,0; beqlr; li 3,1"
extern "C" int f_8012C714() {}
