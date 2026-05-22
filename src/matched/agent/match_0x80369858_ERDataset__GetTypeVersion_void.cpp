// 0x80369858 ERDataset::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10184(9)"
extern "C" int f_80369858() {}
