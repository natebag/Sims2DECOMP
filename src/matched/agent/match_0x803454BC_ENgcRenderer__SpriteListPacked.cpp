// ENgcRenderer::SpriteListPacked(EDLEntry *) at 0x803454BC (60B)
// Wraps SpriteListPacked(int, float*, float*, uchar*, schar*, uchar*).

struct EDLEntry_SLP {
    char pad0[4];
    int m_count;        // 4
    float* m_p8;        // 8
    float* m_p12;       // 12
    unsigned char* m_p16; // 16
    signed char* m_p20;   // 20
    unsigned char* m_p24; // 24
};

struct ENgcRenderer_SLP {
    void SpriteListPacked(EDLEntry_SLP* cmd);
    void SpriteListPacked(int n, float* a, float* b, unsigned char* c, signed char* d, unsigned char* e);
};

void ENgcRenderer_SLP::SpriteListPacked(EDLEntry_SLP* cmd) {
    SpriteListPacked(cmd->m_count, cmd->m_p8, cmd->m_p12, cmd->m_p16, cmd->m_p20, cmd->m_p24);
}
