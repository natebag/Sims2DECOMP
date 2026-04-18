/* ENgcRenderer::DisplayList(EDLEntry *) at 0x80343D24 (48B) */

struct EDLEntry_DL {
    char pad[4];
    struct DL_t {
        char pad[72];
        void* m_next;
    };
    DL_t* m_dl;
};

struct ENgcRenderer_DL {
    char pad1[1244];
    void* m_current;
    char pad2[4];
    void* m_table[10];
    int m_head;
    char pad3[0x4640 - 0x50C - 4];
    void* m_display;
    void DisplayList(EDLEntry_DL* entry);
};

void ENgcRenderer_DL::DisplayList(EDLEntry_DL* entry) {
    int head = m_head;
    void* current = m_current;
    m_table[head] = current;
    m_head = head + 1;
    EDLEntry_DL::DL_t* dl = entry->m_dl;
    m_display = dl;
    m_current = dl->m_next;
}
