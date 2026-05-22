// 0x80090FC4 LoadingScreenStateMachine::IsFadedOut(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-32160(13); lwz 3,0xb4(9); rlwinm 3,3,29,31,31"
extern "C" int f_80090FC4() {}
