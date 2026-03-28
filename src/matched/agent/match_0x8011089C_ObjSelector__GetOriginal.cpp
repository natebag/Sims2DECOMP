/* ObjSelector::GetOriginal(void) at 0x8011089C (64B) */

struct ObjSelVtable {
    char pad[0x78];
    short m_vbaseOff;
    int (*m_getOrigFunc)(void *, int);
};

struct ObjSelInner {
    ObjSelVtable *m_vtable;
};

struct ObjSelData {
    char pad[0x8C];
    int m_origId;
};

struct ObjSelector {
    char pad[0x38];
    ObjSelData *m_data;
    char pad2[0x14];
    ObjSelInner *m_inner;

    int GetOriginal(void);
};

int ObjSelector::GetOriginal(void) {
    ObjSelInner *inner = m_inner;
    ObjSelVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, int) = vt->m_getOrigFunc;
    return fn((char *)inner + off, m_data->m_origId);
}
