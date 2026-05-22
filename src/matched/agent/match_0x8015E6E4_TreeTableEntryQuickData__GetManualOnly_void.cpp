// 0x8015E6E4 TreeTableEntryQuickData::GetManualOnly(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lha 0,0x16(9); cmplwi 7,0,99; mfcr 3; rlwinm 3,3,30,31,31"
extern "C" int f_8015E6E4() {}
