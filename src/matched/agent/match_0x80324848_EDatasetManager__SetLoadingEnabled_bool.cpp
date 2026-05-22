// 0x80324848 EDatasetManager::SetLoadingEnabled(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 3,-26632(13)"
extern "C" void f_80324848() {}
