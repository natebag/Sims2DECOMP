struct ENgcRenderer {
    char _pad[0x34c];
    int m_val;
    int GetNextExternalFrameBuffer();
};
int ENgcRenderer::GetNextExternalFrameBuffer() { return m_val; }
