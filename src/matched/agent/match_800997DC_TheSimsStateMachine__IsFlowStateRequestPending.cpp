// FLAGS: -fno-elide-constructors
struct Inner { char pad[132]; int m_requested; int m_current; };
struct TSM { char pad[152]; Inner* m_state; int IsFlowStateRequestPending(); };
int TSM::IsFlowStateRequestPending() {
    if (m_state) {
        if (m_state->m_requested != m_state->m_current) return 1;
    }
    return 0;
}
