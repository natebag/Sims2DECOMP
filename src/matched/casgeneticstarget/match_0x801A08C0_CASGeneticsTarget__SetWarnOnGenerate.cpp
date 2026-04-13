// 0x801A08C0 CASGeneticsTarget::SetWarnOnGenerate (40B)
struct CASGT_SWG {
    char pad[0x300];
    int m_flags;
    void SetWarnOnGenerate(int warn);
};

void CASGT_SWG::SetWarnOnGenerate(int warn) {
    if (warn != 0) {
        m_flags = m_flags | 0x20;
    } else {
        int f = m_flags;
        m_flags = f & ~0x20;
    }
}
