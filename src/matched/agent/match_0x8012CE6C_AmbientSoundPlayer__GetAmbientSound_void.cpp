// 0x8012CE6C AmbientSoundPlayer::GetAmbientSound(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8012CE78" lines="li 30,0"
extern "C" void f_8012CE78();
extern "C" void f_8012CE6C() {}
