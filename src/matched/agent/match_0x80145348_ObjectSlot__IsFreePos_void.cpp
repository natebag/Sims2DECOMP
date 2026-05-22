// 0x80145348 ObjectSlot::IsFreePos(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x10(3); rlwinm 3,3,31,31,31"
extern "C" int f_80145348() {}
