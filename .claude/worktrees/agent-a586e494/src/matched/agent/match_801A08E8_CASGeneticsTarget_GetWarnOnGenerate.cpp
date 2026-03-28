// 0x801A08E8 (12 bytes)
// CASGeneticsTarget::GetWarnOnGenerate(void)
// lwz r3, 768(r3); rlwinm r3, r3, 27, 31, 31; blr
class CASGeneticsTarget {
public:
    char m_pad[768];
    int m_flags;
    int GetWarnOnGenerate();
};

int CASGeneticsTarget::GetWarnOnGenerate() {
    return (m_flags >> 5) & 1;
}
