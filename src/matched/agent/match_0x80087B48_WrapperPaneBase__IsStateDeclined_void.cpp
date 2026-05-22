// 0x80087B48 WrapperPaneBase::IsStateDeclined(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x34(3); xori 3,3,2; subfic 0,3,0; adde 3,0,3"
extern "C" int f_80087B48() {}
