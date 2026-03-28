struct TheSimsStateMachine {
    void SetFlowStateCurrent(void);
};

struct PreGameFreeplayState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    void SetFlowStateCurrent(void);
};

void PreGameFreeplayState::SetFlowStateCurrent(void) {
    m_owner->SetFlowStateCurrent();
}
