// 0x80077FD8 CUnlockDisplay::SetDisplayBoxRight(float) (24B)

struct CUnlockDisplay {
    char _pad[0x468];
    float m_left;
    float m_top;
    float m_right;
    float m_bottom;
    void SetDisplayBoxRight(float f);
};

void CUnlockDisplay::SetDisplayBoxRight(float f) {
    if (f <= m_left)
        return;
    m_right = f;
}
