// 0x800F9968 ObjectModuleImpl::GetFirst (24B)
struct ObjectModuleImpl {
    char pad[0x2C];
    void* m_firstNode;
};
void* ObjectModuleImpl_GetFirst(ObjectModuleImpl* self) {
    void* node = self->m_firstNode;
    void* result = 0;
    if (node != 0) {
        result = ((void**)node)[1];
    }
    return result;
}
