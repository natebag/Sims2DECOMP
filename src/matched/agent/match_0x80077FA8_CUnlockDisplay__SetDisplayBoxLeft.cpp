// 0x80077FA8 CUnlockDisplay::SetDisplayBoxLeft(float) (24B)

struct CUnlockDisplay {
    char _pad[0x468];
    float m_left;
    float m_top;
    float m_right;
    float m_bottom;
    void SetDisplayBoxLeft(float f);
};

void CUnlockDisplay::SetDisplayBoxLeft(float f) {
    if (f >= m_right)
        return;
    m_left = f;
}
