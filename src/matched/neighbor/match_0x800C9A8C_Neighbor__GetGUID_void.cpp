// 0x800C9A8C Neighbor::GetGUID(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x8(3)"
extern "C" int f_800C9A8C() {}
