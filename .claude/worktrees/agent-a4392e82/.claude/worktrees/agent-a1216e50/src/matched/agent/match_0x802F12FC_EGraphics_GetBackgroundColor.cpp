struct EVec3 { float x, y, z; };

struct EGraphics {
    char pad[0x80];
    EVec3 m_bgColor;
    int m_bgFlag;

    void GetBackgroundColor(EVec3& color, int& flag);
};

void EGraphics::GetBackgroundColor(EVec3& color, int& flag) {
    color = m_bgColor;
    flag = m_bgFlag;
}
