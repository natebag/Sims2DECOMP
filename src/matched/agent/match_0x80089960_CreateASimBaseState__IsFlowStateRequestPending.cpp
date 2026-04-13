struct TheSimsStateMachine {
    int IsFlowStateRequestPending(void);
};

struct CreateASimBaseState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    int IsFlowStateRequestPending(void);
};

int CreateASimBaseState::IsFlowStateRequestPending(void) {
    return m_owner->IsFlowStateRequestPending();
}
