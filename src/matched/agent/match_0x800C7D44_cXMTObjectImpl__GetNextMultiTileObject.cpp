// 0x800C7D44 cXMTObjectImpl::GetNextMultiTileObject (24B)
struct cXMTObjectImpl {
    char pad[0x08];
    void* m_listNode;
};
void* cXMTObjectImpl_GetNextMultiTileObject(cXMTObjectImpl* self) {
    void* node = self->m_listNode;
    void* r = 0;
    if (node != 0) {
        r = ((void**)node)[1];
    }
    return r;
}
