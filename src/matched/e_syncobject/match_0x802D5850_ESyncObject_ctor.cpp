// 0x802D5850 ESyncObject::ESyncObject (20b)

extern int ESyncObject_vtable[];

struct ESyncObject {
    int* m_vt;
    ESyncObject();
};

ESyncObject::ESyncObject() {
    *(int**)this = ESyncObject_vtable;
}
