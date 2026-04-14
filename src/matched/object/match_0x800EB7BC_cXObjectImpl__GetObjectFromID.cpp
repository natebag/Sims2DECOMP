/* cXObjectImpl::GetObjectFromID(short) at 0x800EB7BC (56B) */

struct ObjFromIDVtable {
    char pad[0x90];
    short m_vbaseOff;
    int (*m_getObjFunc)(void *, short);
};

struct ObjFromIDInner {
    ObjFromIDVtable *m_vtable;
};

struct cXObjectImplGO {
    char pad[0x58];
    ObjFromIDInner *m_inner;

    int GetObjectFromID(short id);
};

int cXObjectImplGO::GetObjectFromID(short id) {
    ObjFromIDInner *inner = m_inner;
    ObjFromIDVtable *vt = inner->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, short) = vt->m_getObjFunc;
    return fn((char *)inner + off, id);
}
