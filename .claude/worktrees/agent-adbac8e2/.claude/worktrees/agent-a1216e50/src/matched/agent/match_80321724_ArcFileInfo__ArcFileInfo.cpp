/* 0x80321724 (32 bytes) - ArcFileInfo::ArcFileInfo(void) */
class ArcFileInfo {
public:
    int m_f0, m_f4, m_f8, m_fC, m_f10;
    ArcFileInfo();
};
ArcFileInfo::ArcFileInfo() { m_f10 = 0; m_f0 = 0; m_f4 = 0; m_f8 = 0; m_fC = 0; }
