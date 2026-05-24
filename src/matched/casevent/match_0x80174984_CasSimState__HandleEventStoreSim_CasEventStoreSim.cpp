// 0x80174984 CasSimState::HandleEventStoreSim(CasEventStoreSim &) (88B)
// Self-copy of 292-byte buffer from this+8 to this+300. The event-ref arg
// is unused — the function just shuffles internal state.

struct CasEventStoreSim;

struct StorageBuf292 {
    unsigned int data[73];
};

struct CasSimState {
    char pad000[8];
    StorageBuf292 m_src;        // 0x008
    StorageBuf292 m_dst;        // 0x12C (adjacent to m_src)
    void HandleEventStoreSim(CasEventStoreSim& event);
};

void CasSimState::HandleEventStoreSim(CasEventStoreSim& /*event*/) {
    m_dst = m_src;
}
