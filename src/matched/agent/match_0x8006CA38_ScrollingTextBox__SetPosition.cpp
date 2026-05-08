// 0x8006CA38 ScrollingTextBox::SetPosition(EVec2&, EVec2&) (36B)

struct EVec2 { int x; int y; };

struct ScrollingTextBox {
    char pad0[4];
    int m_posX;
    int m_posY;
    int m_sizeX;
    int m_sizeY;
    void SetPosition(EVec2& a, EVec2& b);
};

void ScrollingTextBox::SetPosition(EVec2& a, EVec2& b) {
    int ay = a.y;
    int ax = a.x;
    *(volatile int*)&m_posY = ay;
    *(volatile int*)&m_posX = ax;
    int by = b.y;
    int bx = b.x;
    *(volatile int*)&m_sizeY = by;
    *(volatile int*)&m_sizeX = bx;
}
