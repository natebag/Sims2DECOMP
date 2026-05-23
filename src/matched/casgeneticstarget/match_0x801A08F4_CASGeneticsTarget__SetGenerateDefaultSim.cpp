// 0x801A08F4 CASGeneticsTarget::SetGenerateDefaultSim(int) (40B) — semantic consolidation
//
// Was using placeholder struct CASGT_SGDS. Twin with SetWarnOnGenerate
// (0x801A08C0) — same class layout, same bit-set/bit-clear idiom on m_flags
// (this one toggles bit 0x10 / GenerateDefaultSim, sister toggles 0x20).

class CASGeneticsTarget {
public:
    char pad[0x300];
    int m_flags;
    void SetGenerateDefaultSim(int val);
};

void CASGeneticsTarget::SetGenerateDefaultSim(int val) {
    if (val != 0) {
        m_flags = m_flags | 0x10;
    } else {
        int f = m_flags;
        m_flags = f & ~0x10;
    }
}
