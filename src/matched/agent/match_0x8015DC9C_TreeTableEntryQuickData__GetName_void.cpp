// 0x8015DC9C TreeTableEntryQuickData::GetName(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); li 3,0; lwz 9,0x1c(9); cmplwi 9,0; beqlr; lwz 3,0x0(9)"
extern "C" int f_8015DC9C() {}
