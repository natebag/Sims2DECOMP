// 0x80078DAC CUnlockDisplay::RemoveAllDirectLights(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x440(3)"
extern "C" void f_80078DAC() {}
