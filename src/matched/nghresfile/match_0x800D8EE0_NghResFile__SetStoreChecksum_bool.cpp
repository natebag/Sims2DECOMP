// 0x800D8EE0 NghResFile::SetStoreChecksum(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x18c(3)"
extern "C" void f_800D8EE0() {}
