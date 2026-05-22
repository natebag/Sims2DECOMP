// 0x80317848 ERFont::GetTypeInfo(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-12624"
extern "C" int f_80317848() {}
