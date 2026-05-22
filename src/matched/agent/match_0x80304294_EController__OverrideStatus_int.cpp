// 0x80304294 EController::OverrideStatus(int) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x4(3)"
extern "C" void f_80304294() {}
