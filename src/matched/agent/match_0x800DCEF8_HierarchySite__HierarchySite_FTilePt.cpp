// 0x800DCEF8 HierarchySite::HierarchySite(FTilePt (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x0(4); lwz 12,0x4(4); mr 9,3; li 0,0; li 10,-1; li 8,1; stw 11,0x4(9); stw 12,0x8(9); stw 0,0xc(9); stw 10,0x10(9); stw 5,0x14(9); stw 8,0x0(9)"
extern "C" void f_800DCEF8() {}
