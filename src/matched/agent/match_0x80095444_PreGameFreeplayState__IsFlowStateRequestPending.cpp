struct TheSimsStateMachine {
    int IsFlowStateRequestPending(void);
};

struct PreGameFreeplayState {
    char pad[0x08];
    TheSimsStateMachine *m_owner;

    int IsFlowStateRequestPending(void);
};

int PreGameFreeplayState::IsFlowStateRequestPending(void) {
    return m_owner->IsFlowStateRequestPending();
}
