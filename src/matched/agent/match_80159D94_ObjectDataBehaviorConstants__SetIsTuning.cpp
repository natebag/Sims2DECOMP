// FLAGS: -fno-elide-constructors
struct ODB { char pad[4]; unsigned short m_flags; void SetIsTuning(int val); };
void ODB::SetIsTuning(int val) {
    int t = m_flags;
    m_flags = (unsigned short)(t & 0x7FFF);
    if (!val) return;
    m_flags = (unsigned short)(m_flags | 0x8000);
}
