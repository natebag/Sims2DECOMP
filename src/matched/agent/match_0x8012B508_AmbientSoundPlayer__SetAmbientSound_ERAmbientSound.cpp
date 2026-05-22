// 0x8012B508 AmbientSoundPlayer::SetAmbientSound(ERAmbientSound (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8012B514" lines="adde 3,0,3"
extern "C" void f_8012B514();
extern "C" void f_8012B508() {}
