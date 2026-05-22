// 0x8015E658 TreeTableEntryQuickData::GetAvailableToAdults(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lwz 3,0x10(9); xori 3,3,64; rlwinm 3,3,26,31,31"
extern "C" int f_8015E658() {}
