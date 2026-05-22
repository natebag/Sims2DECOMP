// 0x8014B36C WantFear::Bookmark::GetTarget(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lbz 0,0x1d(9); andi. 11,0,2; bne 0f; lha 3,0x6(9); blr; 0:; lha 3,0x2(3)"
extern "C" int f_8014B36C() {}
