// 0x800A9330 AmbientSoundPlayer::SetScorePlayer(AmbientScorePlayer (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x0(3)"
extern "C" void f_800A9330() {}
