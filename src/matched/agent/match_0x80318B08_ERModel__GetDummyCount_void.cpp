// 0x80318B08 ERModel::GetDummyCount(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x120(3)"
extern "C" int f_80318B08() {}
