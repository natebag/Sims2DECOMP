/* cXObjectImpl::GetFirst(void) at 0x800EB80C (56B) */

struct GetFirstVtable {
    char pad[0x98];
    short m_vbaseOff;
    int (*m_getFirstFunc)(void *);
};

struct GetFirstInner {
    GetFirstVtable *m_vtable;
};

struct cXObjectImplGF {
    char pad[0x58];
    GetFirstInner *m_inner;

    int GetFirst(void);
};

int cXObjectImplGF::GetFirst(void) {
    GetFirstInner *inner = m_inner;
    GetFirstVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_getFirstFunc;
    return fn((char *)inner + off);
}
