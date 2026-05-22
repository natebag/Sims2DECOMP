// 0x803293F0 FreeResourceManager::GetUnreferencedResourceCount(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xca0(3)"
extern "C" int f_803293F0() {}
