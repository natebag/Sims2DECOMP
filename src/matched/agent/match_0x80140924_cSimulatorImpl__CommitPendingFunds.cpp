// 0x80140924 cSimulatorImpl::CommitPendingFunds(void) (56B)
struct cSimulatorImpl {
    char pad[116];
    int m_funds;    // 116
    int m_pending;  // 120
};

void cSimulatorImpl__CommitPendingFunds(cSimulatorImpl* self) {
    int pending = self->m_pending;
    if (pending == 0) return;
    int total = self->m_funds + pending;
    self->m_funds = total;
    if (total > 999999) self->m_funds = 999999;
    self->m_pending = 0;
}
