struct TheSimsStateMachine {
    void SetFlowStateCurrent(void);
};

struct PreGameState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    void SetFlowStateCurrent(void);
};

void PreGameState::SetFlowStateCurrent(void) {
    m_owner->SetFlowStateCurrent();
}
