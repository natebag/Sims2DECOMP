// 0x8015E774 TreeTableEntryQuickData::GetCheckTreeID(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lha 3,0x0(9)"
extern "C" int f_8015E774() {}
