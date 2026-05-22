// 0x802534A0 OSIsThreadSuspended (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x2cc(3); cmpwi 0,0; ble 0f; li 3,1; blr; 0:; li 3,0"
extern "C" int f_802534A0() {}
