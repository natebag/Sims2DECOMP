// 0x800A7674 QuickStringSet::size (56b)
// FLAGS: -fno-schedule-insns

struct QSSVtable {
    char pad[0x70];
    short m_vbaseOff;
    int (*m_sizeFunc)(void *, int);
};

struct QuickStringSet {
    QSSVtable *m_vtable;

    int size(void);
};

int QuickStringSet::size(void) {
    QSSVtable *vt = m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, int) = vt->m_sizeFunc;
    return fn((char *)this + off, 0);
}
