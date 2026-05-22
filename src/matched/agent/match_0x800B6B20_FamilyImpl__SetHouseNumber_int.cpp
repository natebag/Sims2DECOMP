// 0x800B6B20 FamilyImpl::SetHouseNumber(int) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0xc(3)"
extern "C" void f_800B6B20() {}
