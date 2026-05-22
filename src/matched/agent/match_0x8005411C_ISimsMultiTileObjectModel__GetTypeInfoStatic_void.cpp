// 0x8005411C ISimsMultiTileObjectModel::GetTypeInfoStatic(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-18408"
extern "C" int f_8005411C() {}
