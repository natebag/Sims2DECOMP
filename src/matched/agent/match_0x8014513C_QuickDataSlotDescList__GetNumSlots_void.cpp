// 0x8014513C QuickDataSlotDescList::GetNumSlots(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x54(3); li 3,0; cmplwi 9,0; beqlr; lwz 3,-4(9)"
extern "C" int f_8014513C() {}
