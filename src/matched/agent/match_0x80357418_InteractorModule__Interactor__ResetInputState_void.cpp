// 0x80357418 InteractorModule::Interactor::ResetInputState(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(9); stw 0,0x0(3); lwz 0,0x4(9); stw 0,0x4(3); lwz 0,0x8(9); stw 0,0x8(3); lwz 0,0xc(9); stw 0,0xc(3); lwz 0,0x10(9); stw 0,0x10(3); blr; lfs f0,0x0(3); fcmpu 7,f1,f0; cror 31,30,29; mfcr 3; rlwinm 3,3,0,31,31"
extern "C" void f_80357418() {}
