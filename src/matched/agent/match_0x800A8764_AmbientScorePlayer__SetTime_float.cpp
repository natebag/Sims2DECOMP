// 0x800A8764 AmbientScorePlayer::SetTime(float) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f1,0x34(3)"
extern "C" void f_800A8764() {}
