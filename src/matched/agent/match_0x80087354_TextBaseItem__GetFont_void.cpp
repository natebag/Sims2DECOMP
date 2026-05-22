// 0x80087354 TextBaseItem::GetFont(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x50(3)"
extern "C" int f_80087354() {}
