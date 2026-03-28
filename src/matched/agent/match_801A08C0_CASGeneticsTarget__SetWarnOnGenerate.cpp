class CASGeneticsTarget {
public:
    char _pad[0x300];
    int m_flags;

    void SetWarnOnGenerate(bool warn);
};

void CASGeneticsTarget::SetWarnOnGenerate(bool warn) {
    if (warn) {
        m_flags |= 0x20;
        return;
    }
    m_flags &= ~0x20;
}
