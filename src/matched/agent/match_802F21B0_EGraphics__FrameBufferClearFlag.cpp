class EGraphics {
public:
    char m_pad[12];
    int m_frameBufferClearFlag;
    int FrameBufferClearFlag();
};
int EGraphics::FrameBufferClearFlag() { return m_frameBufferClearFlag; }
