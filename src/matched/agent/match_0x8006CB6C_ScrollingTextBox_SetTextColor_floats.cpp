// 0x8006CB6C ScrollingTextBox::SetTextColor (44b)
// FLAGS: -fno-schedule-insns

struct EVec4 { float x, y, z, w; };

struct ScrollingTextBox {
    char pad[36];
    EVec4* m_textColor;
    void SetTextColor(float r, float g, float b, float a);
};

void ScrollingTextBox::SetTextColor(float r, float g, float b, float a) {
    if (m_textColor == 0) {
        return;
    }
    m_textColor->x = r;
    m_textColor->y = g;
    m_textColor->z = b;
    m_textColor->w = a;
}
