// 0x80077FF0 CUnlockDisplay::SetDisplayBoxBottom(float) (24B)

struct CUnlockDisplay {
    char _pad[0x468];
    float m_left;
    float m_top;
    float m_right;
    float m_bottom;
    void SetDisplayBoxBottom(float f);
};

void CUnlockDisplay::SetDisplayBoxBottom(float f) {
    if (f <= m_top)
        return;
    m_bottom = f;
}
