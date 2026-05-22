// 0x8009381C MUStateMachine::MUPollForResult(MUStateMachine::eMURequest) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-21364(13); li 9,0; cmpw 0,3; bne 0f; lwz 9,-21372(13); 0:; mr 3,9"
extern "C" int f_8009381C() {}
