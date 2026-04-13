// 0x800EB7F4 cXObjectImpl::GetNext (24B)
struct cXObjectImpl {
    char pad[0x5C];
    void* m_listNode;
};
void* cXObjectImpl_GetNext(cXObjectImpl* self) {
    void* node = self->m_listNode;
    void* result = 0;
    if (node != 0) {
        result = ((void**)node)[1];
    }
    return result;
}
