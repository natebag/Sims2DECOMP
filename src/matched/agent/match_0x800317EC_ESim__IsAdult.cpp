/* ESim::IsAdult(void) at 0x800317EC (56B) */

struct ESimAdultVtable {
    char pad[0x210];
    short m_vbaseOff;
    int (*m_isAdultFunc)(void *);
};

struct ESimAdultInner {
    char pad[0x04];
    ESimAdultVtable *m_vtable;
};

struct ESim_IsAdult {
    char pad[0x3D0];
    ESimAdultInner *m_inner;

    int IsAdult(void);
};

int ESim_IsAdult::IsAdult(void) {
    ESimAdultInner *inner = m_inner;
    ESimAdultVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_isAdultFunc;
    return fn((char *)inner + off);
}
