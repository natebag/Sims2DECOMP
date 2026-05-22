// 0x8014ACA8 WantFear::Bookmark::IsHidden(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lbz 3,0x1d(9); rlwinm 3,3,0,31,31"
extern "C" int f_8014ACA8() {}
