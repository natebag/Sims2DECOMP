/* ObjectModuleImpl::AddObject(cXObject *, short, short, short, short, int) at 0x800F9930 (56B) */

struct ObjModVtable {
    char pad[0x260];
    short m_vbaseOff;
    int (*m_addObjFunc)(void *, void *, short, int);
};

struct ObjectModuleImpl_AO {
    ObjModVtable *m_vtable;

    int AddObject(void *obj, short a);
};

int ObjectModuleImpl_AO::AddObject(void *obj, short a) {
    ObjModVtable *vt = m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *, void *, short, int) = vt->m_addObjFunc;
    return fn((char *)this + off, obj, a, 0);
}
