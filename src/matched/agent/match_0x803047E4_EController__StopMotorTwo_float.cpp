// 0x803047E4 EController::StopMotorTwo(float) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f1,0x1e8(3); li 3,1"
extern "C" void f_803047E4() {}
