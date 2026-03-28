class EGraphics {
public:
    char m_pad[28];
    int m_screenYSize;
    int GetActualScreenYSize();
};
int EGraphics::GetActualScreenYSize() { return m_screenYSize; }
