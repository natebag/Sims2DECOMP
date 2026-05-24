// 0x80095EB4 StateMachine::GetCallingStateId(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x48(3); lwz 3,0x0(9)"

struct StateMachine {
    void GetCallingStateId();
};

void StateMachine::GetCallingStateId() {
}
