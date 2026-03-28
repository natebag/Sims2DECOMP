struct TheSimsStateMachine {
    int IsFlowStateRequestPending(void);
};

struct TheSimsMainMenuState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    int IsFlowStateRequestPending(void);
};

int TheSimsMainMenuState::IsFlowStateRequestPending(void) {
    return m_owner->IsFlowStateRequestPending();
}
