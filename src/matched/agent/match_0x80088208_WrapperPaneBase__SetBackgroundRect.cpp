// 0x80088208 WrapperPaneBase::SetBackgroundRect(EVec2*, EVec2*) (36B)

struct EVec2 {
    int x;
    int y;
};

struct WrapperPaneBase {
    char pad0[28];
    int m_aX;
    int m_aY;
    int m_bX;
    int m_bY;
    void SetBackgroundRect(EVec2* a, EVec2* b);
};

void WrapperPaneBase::SetBackgroundRect(EVec2* a, EVec2* b) {
    int ay = a->y;
    int ax = a->x;
    *(volatile int*)&m_aY = ay;
    *(volatile int*)&m_aX = ax;
    int by = b->y;
    int bx = b->x;
    *(volatile int*)&m_bY = by;
    *(volatile int*)&m_bX = bx;
}
