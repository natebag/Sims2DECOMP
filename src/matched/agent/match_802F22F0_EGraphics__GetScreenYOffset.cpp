class EGraphics {
public:
    char m_pad[36];
    int m_screenYOffset;
    int GetScreenYOffset();
};
int EGraphics::GetScreenYOffset() { return m_screenYOffset; }
