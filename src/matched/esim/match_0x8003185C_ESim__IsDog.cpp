/* ESim::IsDog(void) at 0x8003185C (56B) */

struct ESimInnerVtable {
    char pad[0x1D8];
    short m_vbaseOff;
    int (*m_isDogFunc)(void *);
};

struct ESimInner {
    char pad[0x04];
    ESimInnerVtable *m_vtable;
};

struct ESim_IsDog {
    char pad[0x3D0];
    ESimInner *m_inner;

    int IsDog(void);
};

int ESim_IsDog::IsDog(void) {
    ESimInner *inner = m_inner;
    ESimInnerVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_isDogFunc;
    return fn((char *)inner + off);
}
