/* SimsMemCardWrap::DeleteFile(int, int) at 0x80075678 (64B) */

struct MemCardVtable2 {
    char pad[0x58];
    short m_vbaseOff;
    int (*m_deleteFunc)(void *, int, int);
};

struct MemCardObj2 {
    MemCardVtable2 *m_vtable;
};

extern MemCardObj2 *g_memCardObj2;
extern int g_memCardSlot;

int SimsMemCardWrap_DeleteFile(int fileId) {
    MemCardVtable2 *vt = g_memCardObj2->m_vtable;
    int slot = g_memCardSlot;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, int, int) = vt->m_deleteFunc;
    return fn((char *)g_memCardObj2 + off, slot, fileId);
}
