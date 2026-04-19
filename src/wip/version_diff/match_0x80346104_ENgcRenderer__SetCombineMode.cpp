/* ENgcRenderer::SetCombineMode(EDLEntry *) at 0x80346104 (32B) */

struct EDLEntry_SCM {
    char pad[2];
    unsigned short m_idx;
    int m_value;
};

struct ENgcRenderer_SCM {
    char pad1[0x510];
    int m_dirty;
    char pad2[0x55];
    unsigned char m_combineData[1];
    void SetCombineMode(EDLEntry_SCM* entry);
};

void ENgcRenderer_SCM::SetCombineMode(EDLEntry_SCM* entry) {
    unsigned int idx = entry->m_idx;
    m_combineData[idx << 6] = (unsigned char)entry->m_value;
    m_dirty = 1;
}
