/* ENgcRenderer::GetPreviousFrameBuffer(int *, int *) at 0x80349F4C (32B) */

struct ENgcRenderer_PFB {
    char pad1[0x368];
    unsigned short m_prevFbW;
    unsigned short m_prevFbH;
    char pad2[0x4650 - 0x36C];
    void* m_prevFrameBuffer;
    void* GetPreviousFrameBuffer(int* outW, int* outH);
};

void* ENgcRenderer_PFB::GetPreviousFrameBuffer(int* outW, int* outH) {
    *outW = m_prevFbW >> 1;
    *outH = m_prevFbH >> 1;
    return m_prevFrameBuffer;
}
