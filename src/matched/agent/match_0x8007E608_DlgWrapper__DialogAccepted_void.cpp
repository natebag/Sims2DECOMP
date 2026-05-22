// 0x8007E608 DlgWrapper::DialogAccepted(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0xac(3); lwz 3,0x34(9); xoris 3,3,1; subfic 0,3,0; adde 3,0,3"
extern "C" int f_8007E608() {}
