/* ESim::IsCat(void) at 0x80031894 (56B) */

struct ESimCatVtable {
    char pad[0x1E0];
    short m_vbaseOff;
    int (*m_isCatFunc)(void *);
};

struct ESimCatInner {
    char pad[0x04];
    ESimCatVtable *m_vtable;
};

struct ESim_IsCat {
    char pad[0x3D0];
    ESimCatInner *m_inner;

    int IsCat(void);
};

int ESim_IsCat::IsCat(void) {
    ESimCatInner *inner = m_inner;
    ESimCatVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_isCatFunc;
    return fn((char *)inner + off);
}
