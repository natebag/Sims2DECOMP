// cSimulatorImpl::IsPausedAtAll(void) at 0x80141324 (40B)

struct cSim_IPAA {
    char pad_00[0x36];
    short m_b;          // at 0x36
    char pad_38[0x60];  // 0x98 - 0x38 = 0x60
    int m_a;            // at 0x98
    int IsPausedAtAll() const;
};

int cSim_IPAA::IsPausedAtAll() const {
    if (m_a != 0) return 1;
    return m_b != 0 ? 1 : 0;
}
