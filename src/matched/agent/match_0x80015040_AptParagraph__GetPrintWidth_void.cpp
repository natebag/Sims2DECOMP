// 0x80015040 AptParagraph::GetPrintWidth(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 1,1,8"
extern "C" int f_80015040() {}
