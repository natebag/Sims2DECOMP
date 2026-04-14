/* ESim::IsChild(void) at 0x80031824 (56B) */

struct ESimChildVtable {
    char pad[0x1F8];
    short m_vbaseOff;
    int (*m_isChildFunc)(void *);
};

struct ESimChildInner {
    char pad[0x04];
    ESimChildVtable *m_vtable;
};

struct ESim_IsChild {
    char pad[0x3D0];
    ESimChildInner *m_inner;

    int IsChild(void);
};

int ESim_IsChild::IsChild(void) {
    ESimChildInner *inner = m_inner;
    ESimChildVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_isChildFunc;
    return fn((char *)inner + off);
}
