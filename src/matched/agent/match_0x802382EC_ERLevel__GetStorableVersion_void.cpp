// 0x802382EC ERLevel::GetStorableVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; lwz 3,-24168(3)"
extern "C" int f_802382EC() {}
