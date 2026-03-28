/* 0x8006CA5C (12 bytes) - ScrollingTextBox::SetScrollVelocity(float, float) */
class ScrollingTextBox {
public:
    char pad[0x14];
    float m_scrollVelX;
    float m_scrollVelY;
    void SetScrollVelocity(float x, float y);
};

void ScrollingTextBox::SetScrollVelocity(float x, float y) {
    m_scrollVelX = x;
    m_scrollVelY = y;
}
