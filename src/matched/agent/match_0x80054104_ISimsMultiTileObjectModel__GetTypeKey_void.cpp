// 0x80054104 ISimsMultiTileObjectModel::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-18392(9)"
extern "C" int f_80054104() {}
