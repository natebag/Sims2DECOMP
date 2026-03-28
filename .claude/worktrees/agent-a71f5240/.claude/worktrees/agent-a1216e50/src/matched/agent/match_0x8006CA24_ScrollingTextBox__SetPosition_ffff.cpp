/* 0x8006CA24 (20 bytes) - ScrollingTextBox::SetPosition(float, float, float, float) */
class ScrollingTextBox {
public:
    char pad[0x04];
    float m_f1;
    float m_f2;
    float m_f3;
    float m_f4;
    void SetPosition(float a, float b, float c, float d);
};

void ScrollingTextBox::SetPosition(float a, float b, float c, float d) {
    *(volatile float*)((char*)this + 0x10) = d;
    *(volatile float*)((char*)this + 0x04) = a;
    *(volatile float*)((char*)this + 0x08) = c;
    *(volatile float*)((char*)this + 0x0C) = b;
}
