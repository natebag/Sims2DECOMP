// 0x801A08F4 CASGeneticsTarget::SetGenerateDefaultSim (40B)
struct CASGT_SGDS {
    char pad[0x300];
    int m_flags;
    void SetGenerateDefaultSim(int val);
};

void CASGT_SGDS::SetGenerateDefaultSim(int val) {
    if (val != 0) {
        m_flags = m_flags | 0x10;
    } else {
        int f = m_flags;
        m_flags = f & ~0x10;
    }
}
