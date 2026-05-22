// 0x80304D18 EController::SetControlFake(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x1ac(3)"
extern "C" void f_80304D18() {}
