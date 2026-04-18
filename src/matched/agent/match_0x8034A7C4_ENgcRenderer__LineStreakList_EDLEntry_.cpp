// 0x8034A7C4 (36B) ENgcRenderer::LineStreakList(EDLEntry *)

extern volatile int g_ENgcR_LineStreakList_dirty;

struct ENgcR_LSL {
    char pad[0x4DC];
    char* m_4DC;
    void LineStreakList(void* entry);
};

void ENgcR_LSL::LineStreakList(void* entry) {
    if (g_ENgcR_LineStreakList_dirty) {
        g_ENgcR_LineStreakList_dirty = 0;
    }
    m_4DC += 32;
}
