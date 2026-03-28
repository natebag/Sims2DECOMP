struct TheSimsStateMachine {
    int IsFlowStateRequestPending(void);
};

struct InLevelBaseState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    int IsFlowStateRequestPending(void);
};

int InLevelBaseState::IsFlowStateRequestPending(void) {
    return m_owner->IsFlowStateRequestPending();
}
