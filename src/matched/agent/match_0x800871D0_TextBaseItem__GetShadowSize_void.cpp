// 0x800871D0 TextBaseItem::GetShadowSize(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x4c(3)"
extern "C" int f_800871D0() {}
