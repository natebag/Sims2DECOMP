// 0x80095E28 StateMachine::GetCurStateStage(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x3c(3); lwz 3,0xc(9)"

struct StateMachine {
    void GetCurStateStage();
};

void StateMachine::GetCurStateStage() {
}
