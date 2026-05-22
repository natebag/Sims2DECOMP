// 0x802B63D8 AptObject::getInMainInst(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x20(3); rlwinm 3,3,10,31,31"
extern "C" int f_802B63D8() {}
