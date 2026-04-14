// 0x800F9820 ObjectModuleImpl::GetNumObjects (64B)

struct ObjectModuleImpl {
    char pad[0x2090];
    void** m_objectArrayBegin;
    void** m_objectArrayEnd;
    char pad2[8];
    void* m_fixedObjects[16];
};

int ObjectModuleImpl_GetNumObjects(ObjectModuleImpl* self) {
    int count = 0;
    for (int i = 0; i < 16; i++) {
        if (self->m_fixedObjects[i] != 0) count++;
    }
    return (((int)self->m_objectArrayEnd - (int)self->m_objectArrayBegin) >> 2) + count;
}
