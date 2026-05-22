// 0x800F29F0 ObjectFolderImpl::GetObjectsDatabase(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x690(3)"
extern "C" int f_800F29F0() {}
