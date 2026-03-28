/* cXObjectImpl::GetSim(void) at 0x800EB450 (56B) */

struct GetSimVtable {
    char pad[0xD8];
    short m_vbaseOff;
    int (*m_getSimFunc)(void *);
};

struct GetSimInner {
    GetSimVtable *m_vtable;
};

struct cXObjectImplGS {
    char pad[0x58];
    GetSimInner *m_inner;

    int GetSim(void);
};

int cXObjectImplGS::GetSim(void) {
    GetSimInner *inner = m_inner;
    GetSimVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_getSimFunc;
    return fn((char *)inner + off);
}
