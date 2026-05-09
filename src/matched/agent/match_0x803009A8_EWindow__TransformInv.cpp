// EWindow::TransformInv(float, float, float &, float &) - 0x803009A8 (44B)
// Inverse 2D affine: out = (in - offset) / scale.

class EWindow {
public:
    float m_pxScaleX;        // +0x00
    char _pad0[0x10];
    float m_pxScaleY;        // +0x14
    char _pad1[0x18];
    float m_pxOffsetX;       // +0x30
    float m_pxOffsetY;       // +0x34
    void TransformInv(float x, float y, float& outX, float& outY);
};

void EWindow::TransformInv(float x, float y, float& outX, float& outY)
{
    outX = (x - m_pxOffsetX) / m_pxScaleX;
    outY = (y - m_pxOffsetY) / m_pxScaleY;
}
