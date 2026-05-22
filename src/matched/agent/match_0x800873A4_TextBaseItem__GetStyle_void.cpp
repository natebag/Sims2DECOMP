// 0x800873A4 TextBaseItem::GetStyle(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x6c(3)"
extern "C" int f_800873A4() {}
