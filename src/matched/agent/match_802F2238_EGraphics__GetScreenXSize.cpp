class EGraphics {
public:
    char m_pad[24];
    int m_screenXSize;
    int GetScreenXSize();
};
int EGraphics::GetScreenXSize() { return m_screenXSize; }
