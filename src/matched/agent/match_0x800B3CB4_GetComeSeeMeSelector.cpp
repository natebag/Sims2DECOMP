/* GetComeSeeMeSelector(void) at 0x800B3CB4 (64B) */

struct ComeSeeVtable {
    char pad[0x78];
    short m_vbaseOff;
    int (*m_getFunc)(void *, unsigned int);
};

struct ComeSeeObj {
    ComeSeeVtable *m_vtable;
};

extern ComeSeeObj *g_comeSeeObj;

int GetComeSeeMeSelector(void) {
    ComeSeeVtable *vt = g_comeSeeObj->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, unsigned int) = vt->m_getFunc;
    return fn((char *)g_comeSeeObj + off, 0xF3AAA62Fu);
}
