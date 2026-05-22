// 0x80090040 ELiveMode::IsIntroCameraTriggered(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xc(3); xoris 3,3,1; subfic 0,3,0; adde 3,0,3"
extern "C" int f_80090040() {}
