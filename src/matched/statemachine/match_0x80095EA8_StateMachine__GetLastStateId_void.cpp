// 0x80095EA8 StateMachine::GetLastStateId(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x44(3); lwz 3,0x0(9)"

struct StateMachine {
    void GetLastStateId();
};

void StateMachine::GetLastStateId() {
}
