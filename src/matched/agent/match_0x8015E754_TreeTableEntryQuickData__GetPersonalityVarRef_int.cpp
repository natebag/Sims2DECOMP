// 0x8015E754 TreeTableEntryQuickData::GetPersonalityVarRef(int) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(3); rlwinm 4,4,3,0,28; lwz 3,0x4(9); add 3,3,4"
extern "C" int f_8015E754() {}
