// 0x801A08E8 CASGeneticsTarget::GetWarnOnGenerate(void) (12 B)

struct CASGeneticsTarget {
    char pad_0000[0x300];
    unsigned int m_flags;

    int GetWarnOnGenerate();
};

int CASGeneticsTarget::GetWarnOnGenerate() {
    return (m_flags >> 5) & 1;
}
