// 0x8033CA98 (32B) ENgcRenderer::GetExternalFrameBuffer(void)

struct ENgcRenderer {
    char pad[0x344];
    void* m_frameBuffer;  // offset 0x344
    char pad2[4];
    void* m_otherBuffer;  // offset 0x34C
    void* m_externalBuffer;  // offset 0x348

    void* GetExternalFrameBuffer(void);
};

void* ENgcRenderer::GetExternalFrameBuffer(void) {
    void* fb = m_frameBuffer;
    void* other = m_otherBuffer;

    if (other == fb) {
        return m_externalBuffer;
    }
    return fb;
}
