// EWindow::Transform(EVec2 &, EVec2 &) - 0x80300924 (44B)
// Apply 2D affine transform: dst = src * scale + offset.

struct EVec2 { float x, y; };

class EWindow {
public:
    float m_scaleX;          // +0x00
    char _pad0[0x10];
    float m_scaleY;          // +0x14
    char _pad1[0x18];
    float m_offsetX;         // +0x30
    float m_offsetY;         // +0x34
    void Transform(EVec2& src, EVec2& dst);
};

void EWindow::Transform(EVec2& src, EVec2& dst)
{
    dst.x = src.x * m_scaleX + m_offsetX;
    dst.y = src.y * m_scaleY + m_offsetY;
}
