// 0x80087ADC WrapperPaneBase::GetAlpha(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,0x30(3)"
extern "C" int f_80087ADC() {}
