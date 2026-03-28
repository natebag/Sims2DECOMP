class EGraphics {
public:
    char m_pad[32];
    int m_screenXOffset;
    int GetScreenXOffset();
};
int EGraphics::GetScreenXOffset() { return m_screenXOffset; }
