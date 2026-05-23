/* ENgcRenderer::SetCombineMode(EDLEntry *) at 0x80346104 (32B) */

struct EDLEntry_SCM {
    char pad[2];
    unsigned short m_idx;
    int m_val;
};

struct ENgcRenderer_SCM {
    char pad[1296];
    int m_active;
    char arr[1];
    void SetCombineMode(EDLEntry_SCM* e);
};

void ENgcRenderer_SCM::SetCombineMode(EDLEntry_SCM* e) {
    int idx = e->m_idx;
    int val = e->m_val;
    ((char*)this + (idx << 6))[1385] = (char)val;
    m_active = 1;
}
