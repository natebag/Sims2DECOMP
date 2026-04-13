// 0x80089960 CreateASimBaseState::IsFlowStateRequestPending (36B)

int TheSimsStateMachine_IsFlowStateRequestPending(void* sm);

struct CreateASimBaseState {
    char pad[0x08];
    void* m_stateMachine;

    int IsFlowStateRequestPending();
};

int CreateASimBaseState::IsFlowStateRequestPending() {
    return TheSimsStateMachine_IsFlowStateRequestPending(m_stateMachine);
}
