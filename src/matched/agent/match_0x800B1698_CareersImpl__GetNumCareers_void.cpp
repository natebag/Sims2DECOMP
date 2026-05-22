// 0x800B1698 CareersImpl::GetNumCareers(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(3); lwz 3,0xc(9)"
extern "C" int f_800B1698() {}
