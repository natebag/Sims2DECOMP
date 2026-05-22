// 0x800B6414 FamilyImpl::CountMembers(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x24(3); lwz 3,0x28(3); subf 3,0,3; srawi 3,3,2"
extern "C" int f_800B6414() {}
