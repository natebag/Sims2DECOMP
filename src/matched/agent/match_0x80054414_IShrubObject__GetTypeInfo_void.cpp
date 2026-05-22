// 0x80054414 IShrubObject::GetTypeInfo(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-18328"
extern "C" int f_80054414() {}
