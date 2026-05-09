// EWindow::TransformToPixel(EVec2 &, EVec2 &) - 0x80300330 (44B)
// Apply 2D affine pixel transform: dst = src * pixelScale + pixelOffset.
// Same body as EWindow::Transform but on the pixel-space matrix slots.

struct EVec2 { float x, y; };

class EWindow {
public:
    float m_pxScaleX;        // +0x00
    char _pad0[0x10];
    float m_pxScaleY;        // +0x14
    char _pad1[0x18];
    float m_pxOffsetX;       // +0x30
    float m_pxOffsetY;       // +0x34
    void TransformToPixel(EVec2& src, EVec2& dst);
};

void EWindow::TransformToPixel(EVec2& src, EVec2& dst)
{
    dst.x = src.x * m_pxScaleX + m_pxOffsetX;
    dst.y = src.y * m_pxScaleY + m_pxOffsetY;
}
