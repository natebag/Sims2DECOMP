/* SimsMemCardWrap::IsCardFormatted(int, bool &) at 0x800750A8 (64B) */

struct MemCardVtable {
    char pad[0xB0];
    short m_vbaseOff;
    int (*m_isFormattedFunc)(void *, int, void *);
};

struct MemCardObj {
    MemCardVtable *m_vtable;
};

extern MemCardObj *g_memCardObj;

int SimsMemCardWrap_IsCardFormatted(int slot, void *result) {
    MemCardVtable *vt = g_memCardObj->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, int, void *) = vt->m_isFormattedFunc;
    return fn((char *)g_memCardObj + off, slot, result);
}
