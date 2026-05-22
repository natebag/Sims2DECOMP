// 0x800B6B60 FamilyImpl::GetHouseValue(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x18(3)"
extern "C" int f_800B6B60() {}
