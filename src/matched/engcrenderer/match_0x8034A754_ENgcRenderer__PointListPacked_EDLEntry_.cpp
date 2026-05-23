// 0x8034A754 (36B) ENgcRenderer::PointListPacked(EDLEntry *)

extern volatile int g_ENgcR_PointListPacked_dirty;

struct ENgcR_PLP {
    char pad[0x4DC];
    char* m_4DC;
    void PointListPacked(void* entry);
};

void ENgcR_PLP::PointListPacked(void* entry) {
    if (g_ENgcR_PointListPacked_dirty) {
        g_ENgcR_PointListPacked_dirty = 0;
    }
    m_4DC += 24;
}
