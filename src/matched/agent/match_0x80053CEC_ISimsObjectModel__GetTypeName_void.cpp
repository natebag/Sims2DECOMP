// 0x80053CEC ISimsObjectModel::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-18476(9)"
extern "C" int f_80053CEC() {}
