// cSimulatorImpl::IsStopped(void) at 0x80141A8C (40B)

struct cSim_IS {
    char pad_00[0x178];
    int m_b;       // at 0x178
    int m_a;       // at 0x17C
    int IsStopped() const;
};

int cSim_IS::IsStopped() const {
    if (m_a != 0) return 0;
    return m_b != 0 ? 1 : 0;
}
