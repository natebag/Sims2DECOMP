class EGraphics {
public:
    char m_pad[16];
    int m_frameBufferClearRequestFlag;
    int FrameBufferClearRequestFlag();
};
int EGraphics::FrameBufferClearRequestFlag() { return m_frameBufferClearRequestFlag; }
