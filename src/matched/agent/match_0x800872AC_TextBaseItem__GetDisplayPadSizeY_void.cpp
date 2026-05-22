// 0x800872AC TextBaseItem::GetDisplayPadSizeY(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x38(3)"
extern "C" int f_800872AC() {}
