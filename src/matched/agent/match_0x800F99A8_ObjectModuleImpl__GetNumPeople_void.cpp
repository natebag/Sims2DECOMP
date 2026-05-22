// 0x800F99A8 ObjectModuleImpl::GetNumPeople(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x2058(3); lwz 3,0x205c(3); subf 3,0,3; srawi 3,3,2"
extern "C" int f_800F99A8() {}
