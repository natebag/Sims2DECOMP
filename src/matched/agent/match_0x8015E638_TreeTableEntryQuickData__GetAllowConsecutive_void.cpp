// 0x8015E638 TreeTableEntryQuickData::GetAllowConsecutive(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lwz 3,0x10(9); rlwinm 3,3,29,31,31"
extern "C" int f_8015E638() {}
