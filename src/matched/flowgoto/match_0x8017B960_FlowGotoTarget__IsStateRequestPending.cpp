/* FlowGotoTarget::IsStateRequestPending(void) - 0x8017B960 (32 bytes) */

class FlowGotoTarget {
public:
    char pad0[132];
    int m_current;
    int m_requested;

    int IsStateRequestPending(void);
};

int FlowGotoTarget::IsStateRequestPending(void) {
    int r = 1;
    if (m_current == m_requested) {
        r = 0;
    }
    return r;
}
