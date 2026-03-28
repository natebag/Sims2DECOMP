struct StateMachine {
    void CallState(int id);
};

struct StateMachineState {
    char pad[0x08];
    StateMachine *m_owner;

    void OwnerCallState(int id);
};

void StateMachineState::OwnerCallState(int id) {
    m_owner->CallState(id);
}
