typedef unsigned char u8;

class ScrollingTextBox {
    u8 _pad0[0x14];
    float m_fScrollVelocityX;
    float m_fScrollVelocityY;
public:
    void SetScrollVelocity(float, float);
};

void ScrollingTextBox::SetScrollVelocity(float x, float y) {
    m_fScrollVelocityX = x;
    m_fScrollVelocityY = y;
}
