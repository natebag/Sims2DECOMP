class EGraphics {
public:
    char m_pad[32];
    int m_screenXOffset;
    void SetScreenXOffset(int);
};
void EGraphics::SetScreenXOffset(int offset) { m_screenXOffset = offset; }
