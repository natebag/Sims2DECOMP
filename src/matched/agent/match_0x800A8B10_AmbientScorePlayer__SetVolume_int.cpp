// 0x800A8B10 AmbientScorePlayer::SetVolume(int) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x14(3); li 3,1"
extern "C" void f_800A8B10() {}
