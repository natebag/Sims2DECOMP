/* ESim::IsMonkey(void) at 0x800318CC (56B) */

struct ESimMonkeyVtable {
    char pad[0x1E8];
    short m_vbaseOff;
    int (*m_isMonkeyFunc)(void *);
};

struct ESimMonkeyInner {
    char pad[0x04];
    ESimMonkeyVtable *m_vtable;
};

struct ESim_IsMonkey {
    char pad[0x3D0];
    ESimMonkeyInner *m_inner;

    int IsMonkey(void);
};

int ESim_IsMonkey::IsMonkey(void) {
    ESimMonkeyInner *inner = m_inner;
    ESimMonkeyVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_isMonkeyFunc;
    return fn((char *)inner + off);
}
