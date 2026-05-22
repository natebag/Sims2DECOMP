// 0x8015E8E8 TreeTableQuickData::CountMotiveAds(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); cmplwi 9,0; li 3,0; beqlr; lha 3,0x4(9)"
extern "C" int f_8015E8E8() {}
