// 0x8000FC68 AptParagraph::GetParagraphHeight(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x30(3)"
extern "C" int f_8000FC68() {}
