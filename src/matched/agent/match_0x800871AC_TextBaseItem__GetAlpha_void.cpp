// 0x800871AC TextBaseItem::GetAlpha(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x44(3); lfs f1,0xc(9)"
extern "C" float f_800871AC() {}
