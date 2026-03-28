struct TheSimsStateMachine {
    void SetFlowStateCurrent(void);
};

struct InLevelBaseState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    void SetFlowStateCurrent(void);
};

void InLevelBaseState::SetFlowStateCurrent(void) {
    m_owner->SetFlowStateCurrent();
}
