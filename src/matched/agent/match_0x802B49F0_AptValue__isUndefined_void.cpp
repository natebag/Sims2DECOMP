// 0x802B49F0 AptValue::isUndefined(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); rlwinm 3,3,5,31,31; xori 3,3,1"
extern "C" int f_802B49F0() {}
