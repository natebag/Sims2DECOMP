// 0x800C9A94 Neighbor::SetGUID(int) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x8(3)"
extern "C" void f_800C9A94() {}
