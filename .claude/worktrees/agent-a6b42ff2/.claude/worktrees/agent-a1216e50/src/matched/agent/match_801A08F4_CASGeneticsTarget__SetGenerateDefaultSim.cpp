class CASGeneticsTarget {
public:
    char _pad[0x300];
    int m_flags;

    void SetGenerateDefaultSim(bool generate);
};

void CASGeneticsTarget::SetGenerateDefaultSim(bool generate) {
    if (generate) {
        m_flags |= 0x10;
        return;
    }
    m_flags &= ~0x10;
}
