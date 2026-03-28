class EGraphics {
public:
    char m_pad[36];
    int m_screenYOffset;
    void SetScreenYOffset(int);
};
void EGraphics::SetScreenYOffset(int offset) { m_screenYOffset = offset; }
