// 0x80327ECC EResourceManager::IsInitialized(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x48(3)"
extern "C" int f_80327ECC() {}
