// 0x80111054 ObjSelector::GetThumbnailGraphicIndex(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x38(3); lha 3,0x96(9)"
extern "C" int f_80111054() {}
