// 0x800997DC TheSimsStateMachine::IsFlowStateRequestPending(void) (40 B)
struct FlowStateRequest {
    char _pad[0x84];
    int m_state_0x84;
    int m_state_0x88;
};
struct TheSimsStateMachine {
    char _pad[0x98];
    FlowStateRequest* m_request_0x98;
    int IsFlowStateRequestPending();
};
int TheSimsStateMachine::IsFlowStateRequestPending() {
    FlowStateRequest* req = m_request_0x98;
    if (req) {
        return req->m_state_0x84 != req->m_state_0x88;
    }
    return 0;
}
