// 0x800AAC04 AnimTableImpl::GetID(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); lha 3,0x4(9)"
extern "C" int f_800AAC04() {}
