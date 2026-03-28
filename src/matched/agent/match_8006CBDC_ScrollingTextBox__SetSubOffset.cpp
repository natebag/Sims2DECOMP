typedef unsigned char u8;

class ScrollingTextBox {
    u8 _pad0[0x34];
    float m_fSubOffsetX;
    float m_fSubOffsetY;
public:
    void SetSubOffset(float, float);
};

void ScrollingTextBox::SetSubOffset(float x, float y) {
    m_fSubOffsetX = x;
    m_fSubOffsetY = y;
}
