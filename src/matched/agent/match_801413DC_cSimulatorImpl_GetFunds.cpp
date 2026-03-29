// 0x801413DC (16 bytes) - cSimulatorImpl::GetFunds(cSimulator::tFundsPlayerNumber)
// lwz r0,120(r3); lwz r3,116(r3); add r3,r3,r0; blr
// Returns this->field_74 + this->field_78 (ignores the arg)

struct cSimulatorImpl_GF {
    char pad[0x74];
    int m_field74;
    int m_field78;

    int GetFunds(int playerNum);
};

int cSimulatorImpl_GF::GetFunds(int playerNum) {
    return m_field74 + m_field78;
}
