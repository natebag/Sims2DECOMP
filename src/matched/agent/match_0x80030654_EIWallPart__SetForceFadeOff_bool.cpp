// 0x80030654 EIWallPart::SetForceFadeOff(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x3b0(3)"
extern "C" void f_80030654() {}
