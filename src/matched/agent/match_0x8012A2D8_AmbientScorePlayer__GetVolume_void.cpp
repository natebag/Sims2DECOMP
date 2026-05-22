// 0x8012A2D8 AmbientScorePlayer::GetVolume(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8012A30C" lines="addi 29,9,-1"
extern "C" void f_8012A30C();
extern "C" void f_8012A2D8() {}
