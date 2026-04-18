// 0x80343D54 (12B) ENgcRenderer::Goto(EDLEntry *)

struct ENgcR_GT {
    char pad[0x4DC];
    unsigned int m_4DC;
    void Goto(void* entry);
};

void ENgcR_GT::Goto(void* entry) {
    m_4DC = ((unsigned int*)entry)[1];
}
