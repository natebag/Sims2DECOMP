// 0x80300974 (52B) EWindow::TransformInv(EVec2&, EVec2&)

struct EVec2 {
    float x;
    float y;
};

class EWindow {
public:
    float m_0_scaleX;
    char m_pad[16];
    float m_14_scaleY;
    char m_pad2[24];
    float m_30_offsetX;
    float m_34_offsetY;
    void TransformInv(EVec2& in, EVec2& out);
};

void EWindow::TransformInv(EVec2& in, EVec2& out) {
    out.x = (in.x - m_30_offsetX) / m_0_scaleX;
    out.y = (in.y - m_34_offsetY) / m_14_scaleY;
}
