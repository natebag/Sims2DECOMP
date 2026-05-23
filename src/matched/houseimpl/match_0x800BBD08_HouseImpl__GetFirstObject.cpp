/* HouseImpl::GetFirstObject(void) at 0x800BBD08 (56B) */

struct HouseFirstVtable {
    char pad[0x98];
    short m_vbaseOff;
    int (*m_getFirstFunc)(void *);
};

struct HouseFirstObj {
    HouseFirstVtable *m_vtable;
};

extern HouseFirstObj *g_houseImpl;

int HouseImpl_GetFirstObject(void) {
    HouseFirstVtable *vt = g_houseImpl->m_vtable;
    short off = vt->m_vbaseOff;
    int (*fn)(void *) = vt->m_getFirstFunc;
    return fn((char *)g_houseImpl + off);
}
