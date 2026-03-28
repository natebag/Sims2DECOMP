/* ESim::IsMale(void) at 0x80031790 (56B) */

struct ESimMaleVtable {
    char pad[0x200];
    short m_vbaseOff;
    int (*m_isMaleFunc)(void *);
};

struct ESimMaleInner {
    char pad[0x04];
    ESimMaleVtable *m_vtable;
};

struct ESim_IsMale {
    char pad[0x3D0];
    ESimMaleInner *m_inner;

    int IsMale(void);
};

int ESim_IsMale::IsMale(void) {
    ESimMaleInner *inner = m_inner;
    ESimMaleVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_isMaleFunc;
    return fn((char *)inner + off);
}
