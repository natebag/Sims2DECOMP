/* EWindow::SetClip(TRect<float>&) at 0x80300600 (72 bytes) */

struct TRectFloat {
    float left;
    float top;
    float right;
    float bottom;
};

struct EWindow {
    char _pad[0x60];
    TRectFloat m_clip;

    void CalcClipInv();
    void SetClip(TRectFloat& rect);
};

void EWindow::SetClip(TRectFloat& rect)
{
    TRectFloat* pClip = &m_clip;
    pClip->left = rect.left;
    pClip->top = rect.top;
    pClip->right = rect.right;
    pClip->bottom = rect.bottom;
    CalcClipInv();
}
