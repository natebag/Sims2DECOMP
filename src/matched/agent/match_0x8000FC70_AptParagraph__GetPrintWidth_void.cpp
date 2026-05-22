// 0x8000FC70 AptParagraph::GetPrintWidth(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x24(3)"
extern "C" int f_8000FC70() {}
