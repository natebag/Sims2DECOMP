/* ENgcRenderer::End(EDLEntry *) at 0x80343D60 (52B) */

struct ENgcRenderer_End {
    char pad1[1244];
    void* m_current;
    int m_underflow;
    void* m_table[10];
    int m_head;
    void End(void* entry);
};

void ENgcRenderer_End::End(void* entry) {
    int head = m_head;
    if (!head) goto underflow;
    m_head = head - 1;
    m_current = m_table[head - 1];
    return;
underflow:
    m_underflow = 1;
}
