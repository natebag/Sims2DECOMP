/* 0x8006CBDC (12 bytes) - ScrollingTextBox::SetSubOffset(float, float) */
class ScrollingTextBox {
public:
    char pad[0x34];
    float m_subOffsetX;
    float m_subOffsetY;
    void SetSubOffset(float x, float y);
};

void ScrollingTextBox::SetSubOffset(float x, float y) {
    m_subOffsetX = x;
    m_subOffsetY = y;
}
