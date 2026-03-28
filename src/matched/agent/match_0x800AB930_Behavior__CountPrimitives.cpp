/* Behavior::CountPrimitives(void) at 0x800AB930 (56B) */

struct BehCountVtable {
    char pad[0x28];
    short m_vbaseOff;
    int (*m_countFunc)(void *);
};

struct BehCountInner {
    BehCountVtable *m_vtable;
};

struct Behavior_CP {
    char pad[0x08];
    BehCountInner *m_inner;

    int CountPrimitives(void);
};

int Behavior_CP::CountPrimitives(void) {
    BehCountInner *inner = m_inner;
    BehCountVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_countFunc;
    return fn((char *)inner + off);
}
