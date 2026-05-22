// 0x80324780 EDatasetManager::SetLoadProgress(float) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f1,0xd20(3)"
extern "C" void f_80324780() {}
