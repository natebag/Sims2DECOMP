// 0x8015E7B0 TreeTableEntryQuickData::GetCustomAttenuationValue(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lfs f1,0x8(9)"
extern "C" float f_8015E7B0() {}
