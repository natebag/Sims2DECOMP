// 0x80149EB0 TTabScratchEntry::SetCustomAttenuation(float) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stfs f1,0x10c(3); stw 0,0x108(3)"
extern "C" void f_80149EB0() {}
