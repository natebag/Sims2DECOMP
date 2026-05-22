// 0x8015E768 TreeTableEntryQuickData::GetActionTreeID(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lha 3,0x2(9)"
extern "C" int f_8015E768() {}
