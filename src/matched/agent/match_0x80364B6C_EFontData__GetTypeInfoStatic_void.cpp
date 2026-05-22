// 0x80364B6C EFontData::GetTypeInfoStatic(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-10444"
extern "C" int f_80364B6C() {}
