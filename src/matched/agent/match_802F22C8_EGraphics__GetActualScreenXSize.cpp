class EGraphics {
public:
    char m_pad[24];
    int m_screenXSize;
    int GetActualScreenXSize();
};
int EGraphics::GetActualScreenXSize() { return m_screenXSize; }
