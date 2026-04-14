// 0x80077FC0 CUnlockDisplay::SetDisplayBoxTop(float) (24B)

struct CUnlockDisplay {
    char _pad[0x468];
    float m_left;
    float m_top;
    float m_right;
    float m_bottom;
    void SetDisplayBoxTop(float f);
};

void CUnlockDisplay::SetDisplayBoxTop(float f) {
    if (f >= m_bottom)
        return;
    m_top = f;
}
