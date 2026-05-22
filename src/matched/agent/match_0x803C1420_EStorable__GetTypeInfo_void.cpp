// 0x803C1420 EStorable::GetTypeInfo(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-13320"
extern "C" int f_803C1420() {}
