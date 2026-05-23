// 0x80318B00 ERModel::GetLatticeCount(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x114(3)"
extern "C" int f_80318B00() {}
