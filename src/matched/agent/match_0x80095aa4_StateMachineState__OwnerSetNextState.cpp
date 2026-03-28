struct StateMachine {
    void SetNextState(int id, float delay);
};

struct StateMachineState {
    char pad[0x08];
    StateMachine *m_owner;

    void OwnerSetNextState(int id, float delay);
};

void StateMachineState::OwnerSetNextState(int id, float delay) {
    m_owner->SetNextState(id, delay);
}
