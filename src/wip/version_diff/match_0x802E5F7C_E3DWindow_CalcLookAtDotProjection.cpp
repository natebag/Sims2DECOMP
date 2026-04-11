/* E3DWindow::CalcLookAtDotProjection(void) - 0x802E5F7C (64 bytes) */

struct EMat4 {
    char data[64];
    void Mult4x4(EMat4 &, EMat4 &);
};

struct E3DWindow {
    char pad_0[0xA0];
    EMat4 m_viewMtx;
    char pad_E0[0x120 - 0xE0];
    EMat4 m_lookAt;
    char pad_160[0x160 - 0x160];
    EMat4 m_projMtx;

    void CalcLookAtDotProjection();
    void CalcViewportStructures();
};

void E3DWindow::CalcLookAtDotProjection()
{
    m_lookAt.Mult4x4(m_viewMtx, m_projMtx);
    CalcViewportStructures();
}
