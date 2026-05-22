// 0x8015E780 TreeTableEntryQuickData::GetAttenuation(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lhz 3,0xe(9)"
extern "C" int f_8015E780() {}
