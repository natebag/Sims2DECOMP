/* cXObjectImpl::SetIdleStatus(int) at 0x800EB040 (64B) */

struct XObjInnerVtable {
    char pad[0x228];
    short m_vbaseOff;
    int (*m_setIdleFunc)(void *, int, int);
};

struct XObjInner {
    XObjInnerVtable *m_vtable;
};

struct cXObjectImpl {
    char pad[0x58];
    XObjInner *m_inner;
    char pad2[8];
    short m_index;

    void SetIdleStatus(int status);
};

void cXObjectImpl::SetIdleStatus(int status) {
    XObjInner *inner = m_inner;
    XObjInnerVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, int, int) = vt->m_setIdleFunc;
    fn((char *)inner + off, m_index, status);
}
