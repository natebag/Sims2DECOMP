// 0x8015E5A8 TreeTableAdQuickData::GetMax(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lha 0,0x4(9); lha 3,0x2(9); add 3,3,0"
extern "C" int f_8015E5A8() {}
