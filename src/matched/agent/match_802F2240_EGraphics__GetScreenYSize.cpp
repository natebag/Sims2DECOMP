class EGraphics {
public:
    char m_pad[28];
    int m_screenYSize;
    int GetScreenYSize();
};
int EGraphics::GetScreenYSize() { return m_screenYSize; }
