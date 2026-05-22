// 0x802C6C74 EFileSystem::FileCreator::GetCreatorCB(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3)"
extern "C" int f_802C6C74() {}
