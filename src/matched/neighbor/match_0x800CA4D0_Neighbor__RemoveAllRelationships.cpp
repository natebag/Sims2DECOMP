/* Neighbor::RemoveAllRelationships(void) at 0x800CA4D0 (56B) */

struct NbrRelVtable {
    char pad[0x38];
    short m_vbaseOff;
    int (*m_removeFunc)(void *);
};

struct NbrRelInner {
    NbrRelVtable *m_vtable;
};

struct Neighbor_RAR {
    char pad[0x10];
    NbrRelInner *m_inner;

    void RemoveAllRelationships(void);
};

void Neighbor_RAR::RemoveAllRelationships(void) {
    NbrRelInner *inner = m_inner;
    NbrRelVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_removeFunc;
    fn((char *)inner + off);
}
