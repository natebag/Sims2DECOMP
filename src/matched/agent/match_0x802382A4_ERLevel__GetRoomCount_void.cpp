// 0x802382A4 ERLevel::GetRoomCount(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; lwz 3,-23884(3)"
extern "C" int f_802382A4() {}
