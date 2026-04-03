struct StateMachine {
    char pad[0x90];
    int m_returnVal;
};

struct StateMachineState {
    char pad[0x08];
    StateMachine *m_owner;

    int OwnerGetReturnVal(void);
};

int StateMachineState::OwnerGetReturnVal(void) {
    return m_owner->m_returnVal;
}
