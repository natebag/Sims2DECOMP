// 0x8036AF08 REffectsSequencer::Deallocate(void) (52B)

struct VTable {
    char pad[104];
    short m_adj;
    short m_pad;
    void (*m_dealloc)(void*);
};

struct REffectsSequencer {
    VTable* m_vt;
    void Deallocate();
};

void REffectsSequencer::Deallocate() {
    VTable* vt = m_vt;
    vt->m_dealloc((char*)this + vt->m_adj);
}
