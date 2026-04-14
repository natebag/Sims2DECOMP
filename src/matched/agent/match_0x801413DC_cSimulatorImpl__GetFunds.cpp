// 0x801413DC cSimulatorImpl::GetFunds(cSimulator::tFundsPlayerNumber) (16B)
struct cSimulatorImpl {
    char pad[116];
    int m_fundsA;
    int m_fundsB;
};

int cSimulatorImpl__GetFunds(cSimulatorImpl* self, int player) {
    return self->m_fundsA + self->m_fundsB;
}
