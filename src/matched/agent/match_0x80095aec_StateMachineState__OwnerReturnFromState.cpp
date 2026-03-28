struct StateMachine {
    void ReturnFromState(int code);
};

struct StateMachineState {
    char pad[0x08];
    StateMachine *m_owner;

    void OwnerReturnFromState(int code);
};

void StateMachineState::OwnerReturnFromState(int code) {
    m_owner->ReturnFromState(code);
}
