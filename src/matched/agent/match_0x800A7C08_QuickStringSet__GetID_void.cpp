// 0x800A7C08 QuickStringSet::GetID(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(3); cmplwi 9,0; li 3,0; beqlr; lha 3,0x8(9)"
extern "C" int f_800A7C08() {}
