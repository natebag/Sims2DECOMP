// FLAGS: -fno-elide-constructors
// E3DWindow::GetViewport(void) const - 0x802E7650 (44B)
// Returns 16-byte TRect<float> at offset 0x220.

struct TRectFloat {
    float left;
    float top;
    float right;
    float bottom;
};

struct E3DWindow {
    char _pad[0x220];
    TRectFloat m_viewport;
    TRectFloat GetViewport() const;
};

TRectFloat E3DWindow::GetViewport() const return r
{
    r.left = m_viewport.left;
    const TRectFloat* p = &m_viewport;
    r.top = p->top;
    r.right = p->right;
    r.bottom = p->bottom;
}
