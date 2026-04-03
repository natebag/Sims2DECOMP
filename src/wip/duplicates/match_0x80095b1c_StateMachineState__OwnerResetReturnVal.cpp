struct StateMachine {
    char pad[0x90];
    int m_returnVal;
};

struct StateMachineState {
    char pad[0x08];
    StateMachine *m_owner;

    void OwnerResetReturnVal(void);
};

void StateMachineState::OwnerResetReturnVal(void) {
    m_owner->m_returnVal = 0;
}
