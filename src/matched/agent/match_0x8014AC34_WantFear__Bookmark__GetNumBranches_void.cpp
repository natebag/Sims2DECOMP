// 0x8014AC34 WantFear::Bookmark::GetNumBranches(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lha 3,0xc(9)"
extern "C" int f_8014AC34() {}
