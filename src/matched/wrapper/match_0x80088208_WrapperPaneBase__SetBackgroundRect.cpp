// 0x80088208 WrapperPaneBase::SetBackgroundRect (36B)
// FLAGS: -fno-schedule-insns

struct EVec2 {
    int x, y;
};

struct WrapperPaneBase {
    char pad[0x1c];
    EVec2 m_bgPos;
    EVec2 m_bgSize;

    void SetBackgroundRect(EVec2* pos, EVec2* size);
};

void WrapperPaneBase::SetBackgroundRect(EVec2* pos, EVec2* size) {
    unsigned int* p = (unsigned int*)pos;
    unsigned int* s = (unsigned int*)size;
    unsigned int py = p[1];
    unsigned int px = p[0];
    unsigned int sy = s[1];
    unsigned int sx = s[0];
    unsigned int* d1 = (unsigned int*)&m_bgPos;
    d1[1] = py;
    d1[0] = px;
    unsigned int* d2 = (unsigned int*)&m_bgSize;
    d2[1] = sy;
    d2[0] = sx;
}
