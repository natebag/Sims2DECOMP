struct TRectFloat {
    float left;
    float top;
    float right;
    float bottom;
};

struct EGraphics {
    char _pad[0x18];
    int m_screenXSize;
    int m_screenYSize;

    void GetOutputRect(TRectFloat& rect, int);
};

void EGraphics::GetOutputRect(TRectFloat& rect, int)
{
    rect.left = 0.0f;
    rect.top = 0.0f;
    rect.right = (float)m_screenXSize;
    rect.bottom = (float)m_screenYSize;
}
