// 0x80087B34 WrapperPaneBase::IsStateAccepted(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x34(3); xoris 3,3,1; subfic 0,3,0; adde 3,0,3"
extern "C" int f_80087B34() {}
