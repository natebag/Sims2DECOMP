// 0x80343E7C (36B) ENgcRenderer::ClipRect(EDLEntry *)

extern volatile int g_ENgcR_ClipRect_dirty;

struct ENgcR_CR {
    char pad[0x4DC];
    char* m_4DC;
    void ClipRect(void* entry);
};

void ENgcR_CR::ClipRect(void* entry) {
    m_4DC += 16;
    if (!g_ENgcR_ClipRect_dirty) return;
    g_ENgcR_ClipRect_dirty = 0;
}
