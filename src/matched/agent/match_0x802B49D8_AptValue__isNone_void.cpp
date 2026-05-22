// 0x802B49D8 AptValue::isNone(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); rlwinm 3,3,0,25,31; xoris 3,3,3; subfic 0,3,0; adde 3,0,3"
extern "C" int f_802B49D8() {}
