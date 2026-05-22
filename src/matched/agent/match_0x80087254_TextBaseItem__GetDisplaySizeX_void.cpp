// 0x80087254 TextBaseItem::GetDisplaySizeX(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x2c(3)"
extern "C" int f_80087254() {}
