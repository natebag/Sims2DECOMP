/* FlowGotoTarget::SetPendingStateCurrent - 0x8017B988 (12 bytes) */

class FlowGotoTarget {
public:
    char pad[0x84];
    int m_currentState;
    int m_pendingState;
    void SetPendingStateCurrent();
};

void FlowGotoTarget::SetPendingStateCurrent() {
    m_pendingState = m_currentState;
}
