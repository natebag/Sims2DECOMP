// 0x800540F8 ISimsMultiTileObjectModel::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-18396(9)"
extern "C" int f_800540F8() {}
