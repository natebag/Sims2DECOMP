// 0x801108DC ObjSelector::GetGUID(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x38(3); lwz 3,0x1c(9)"
extern "C" int f_801108DC() {}
