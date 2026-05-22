// 0x800A9338 AmbientSoundPlayer::SetAmbientSound(ERAmbientSound (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x4(3)"
extern "C" void f_800A9338() {}
