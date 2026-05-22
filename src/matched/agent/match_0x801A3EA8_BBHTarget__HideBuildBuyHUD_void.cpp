// 0x801A3EA8 BBHTarget::HideBuildBuyHUD(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x90(3)"
extern "C" void f_801A3EA8() {}
