// 0x80054128 ISimsMultiTileObjectModel::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-18386(9)"
extern "C" int f_80054128() {}
