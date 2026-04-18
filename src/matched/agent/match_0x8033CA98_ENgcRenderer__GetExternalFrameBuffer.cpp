/* ENgcRenderer::GetExternalFrameBuffer(void) at 0x8033CA98 (32B) */

struct ENgcRenderer_EFB {
    char pad[0x344];
    void* m_head;
    void* m_default;
    void* m_tail;
    void* GetExternalFrameBuffer();
};

void* ENgcRenderer_EFB::GetExternalFrameBuffer() {
    void* head = m_head;
    void* tail = m_tail;
    if (tail == head) return m_default;
    return head;
}
