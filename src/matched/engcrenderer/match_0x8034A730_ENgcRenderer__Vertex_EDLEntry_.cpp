// 0x8034A730 (36B) ENgcRenderer::Vertex(EDLEntry *)

extern volatile int g_ENgcR_Vertex_dirty;

struct ENgcR_V1 {
    char pad[0x4DC];
    char* m_4DC;
    void Vertex(void* entry);
};

void ENgcR_V1::Vertex(void* entry) {
    if (g_ENgcR_Vertex_dirty) {
        g_ENgcR_Vertex_dirty = 0;
    }
    m_4DC += 24;
}
