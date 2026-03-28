struct TheSimsStateMachine {
    int IsFlowStateRequestPending(void);
};

struct UrbzCreditsState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    int IsFlowStateRequestPending(void);
};

int UrbzCreditsState::IsFlowStateRequestPending(void) {
    return m_owner->IsFlowStateRequestPending();
}
