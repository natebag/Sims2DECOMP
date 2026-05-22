// 0x8015E5FC TreeTableEntryQuickData::GetAvailableToVisitors(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); li 3,0; lwz 0,0x10(9); andi. 9,0,1; beqlr; li 3,1"
extern "C" int f_8015E5FC() {}
