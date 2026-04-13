// 0x800750A8 SimsMemCardWrap::IsCardFormatted (64b)
// FLAGS: -fno-schedule-insns

struct MemCardVtable {
    char pad[0xB0];
    short m_vbaseOff;
    int (*m_isFormattedFunc)(void *, int, void *);
};

struct MemCardObj {
    MemCardVtable *m_vtable;
};

// SDA extern technique - use char array
extern char g_memCardObj[4];

int SimsMemCardWrap_IsCardFormatted(int slot, void *result) {
    MemCardObj* obj = *(MemCardObj**)g_memCardObj;
    MemCardVtable *vt = obj->m_vtable;
    // Force ordering: compute func ptr first
    int (*fn)(void *, int, void *) = vt->m_isFormattedFunc;
    short off = vt->m_vbaseOff;
    return fn((char *)obj + off, slot, result);
}
