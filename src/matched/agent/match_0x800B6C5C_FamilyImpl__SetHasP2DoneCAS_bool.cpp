// 0x800B6C5C FamilyImpl::SetHasP2DoneCAS(bool) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x34(3); cmplwi 4,0; rlwinm 0,0,0,27,25; stw 0,0x34(3); beqlr; ori 0,0,32; stw 0,0x34(3)"
extern "C" void f_800B6C5C() {}
