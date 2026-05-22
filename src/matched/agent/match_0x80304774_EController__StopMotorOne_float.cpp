// 0x80304774 EController::StopMotorOne(float) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f1,0x1e4(3); li 3,1"
extern "C" void f_80304774() {}
