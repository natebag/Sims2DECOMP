/* cXObjectImpl::SimEnabled(void) at 0x800EAF80 (64B) */

struct XObjInnerVtable2 {
    char pad[0x248];
    short m_vbaseOff;
    int (*m_simEnabledFunc)(void *, int, int);
};

struct XObjInner2 {
    XObjInnerVtable2 *m_vtable;
};

struct cXObjectImpl2 {
    char pad[0x58];
    XObjInner2 *m_inner;
    char pad2[8];
    short m_index;

    int SimEnabled(void);
};

int cXObjectImpl2::SimEnabled(void) {
    XObjInner2 *inner = m_inner;
    XObjInnerVtable2 *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, int, int) = vt->m_simEnabledFunc;
    return fn((char *)inner + off, m_index, 1);
}
