// 0x80087AC8 WrapperPaneBase::IsDrawEnabled(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x4(3); rlwinm 3,3,0,31,31"
extern "C" int f_80087AC8() {}
