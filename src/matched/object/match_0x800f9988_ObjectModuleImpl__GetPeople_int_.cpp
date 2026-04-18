// 0x800F9988 (32B) ObjectModuleImpl::GetPeople(int)

typedef unsigned int cObject;

struct ObjectModuleImpl_GP {
    char pad[0x2058];
    cObject* m_objects;

    cObject GetPeople(int index);
};

cObject ObjectModuleImpl_GP::GetPeople(int index) {
    cObject* base = m_objects;
    int offset = index << 2;
    cObject result = 0;
    cObject obj = *(cObject*)((char*)base + offset);
    if (obj != 0) {
        result = *(cObject*)((char*)obj + 4);
    }
    return result;
}
