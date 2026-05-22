// 0x80238250 ERLevel::SetWallFadeState(EWallUpDownStateType) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; stw 4,-7468(3)"
extern "C" void f_80238250() {}
