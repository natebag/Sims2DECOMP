// 0x801A08C0 CASGeneticsTarget::SetWarnOnGenerate(int) (40B) — semantic consolidation
//
// Was using placeholder struct CASGT_SWG. Twin with SetGenerateDefaultSim
// (0x801A08F4) — same class layout, same bit-set/bit-clear idiom on m_flags
// (this one toggles bit 0x20 / WarnOnGenerate, sister toggles 0x10).

class CASGeneticsTarget {
public:
    char pad[0x300];
    int m_flags;
    void SetWarnOnGenerate(int warn);
};

void CASGeneticsTarget::SetWarnOnGenerate(int warn) {
    if (warn != 0) {
        m_flags = m_flags | 0x20;
    } else {
        int f = m_flags;
        m_flags = f & ~0x20;
    }
}
