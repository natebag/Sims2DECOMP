// 0x80369864 ERDataset::GetTypeInfoStatic(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-10204"
extern "C" int f_80369864() {}
