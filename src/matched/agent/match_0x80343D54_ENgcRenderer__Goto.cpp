// 0x80343D54 ENgcRenderer::Goto (12b)
typedef unsigned int uint;

struct EDLEntry {
    uint _pad0;
    uint m_next;
};

struct ENgcRenderer {
    char _pad[0x4DC];
    uint m_currentDL;
};

void ENgcRenderer__Goto(ENgcRenderer *self, EDLEntry *entry) {
    self->m_currentDL = entry->m_next;
}
