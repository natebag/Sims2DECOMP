// 0x8032471C EDatasetManager::GetLoadProgress(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0xd20(3)"
extern "C" int f_8032471C() {}
