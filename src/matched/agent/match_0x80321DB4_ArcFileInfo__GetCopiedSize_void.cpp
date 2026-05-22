// 0x80321DB4 ArcFileInfo::GetCopiedSize(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xc(3)"
extern "C" int f_80321DB4() {}
