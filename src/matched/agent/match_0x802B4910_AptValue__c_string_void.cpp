// 0x802B4910 AptValue::c_string(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); rlwinm 0,0,0,25,31; cmplwi 0,1; beqlr; lwz 3,0x24(3)"
extern "C" int f_802B4910() {}
