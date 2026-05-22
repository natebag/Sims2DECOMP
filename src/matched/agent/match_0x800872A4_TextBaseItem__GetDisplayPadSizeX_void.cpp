// 0x800872A4 TextBaseItem::GetDisplayPadSizeX(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x34(3)"
extern "C" int f_800872A4() {}
