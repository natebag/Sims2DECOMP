// 0x802331F8 ERLevel::IsInstanceListKindaFull(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; lwz 0,-15688(3); cmplwi 7,0,1663; mfcr 3; rlwinm 3,3,30,31,31"
extern "C" int f_802331F8() {}
