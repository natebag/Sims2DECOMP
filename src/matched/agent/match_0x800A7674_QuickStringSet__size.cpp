/* QuickStringSet::size(void) at 0x800A7674 (56B) */

struct QSSVtable {
    char pad[0x70];
    short m_vbaseOff;
    int (*m_sizeFunc)(void *, int);
};

struct QuickStringSet_S {
    QSSVtable *m_vtable;

    int size(void);
};

int QuickStringSet_S::size(void) {
    QSSVtable *vt = m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, int) = vt->m_sizeFunc;
    return fn((char *)this + off, 0);
}
