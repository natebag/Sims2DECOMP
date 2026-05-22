// 0x802A17F0 AptFile::GetMainCharacter(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x10(3)"
extern "C" int f_802A17F0() {}
