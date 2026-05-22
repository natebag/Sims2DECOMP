// 0x8008739C TextBaseItem::GetFontSize(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x54(3)"
extern "C" int f_8008739C() {}
