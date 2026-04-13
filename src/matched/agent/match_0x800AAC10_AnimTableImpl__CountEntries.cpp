// 0x800AAC10 AnimTableImpl::CountEntries (28B)
struct AnimTableImpl {
    int pad;
    void* m_data;
};
int AnimTableImpl_CountEntries(AnimTableImpl* self) {
    void* data = self->m_data;
    void** inner = *(void***)data;
    int r = 0;
    if (inner != 0) {
        r = ((int*)inner)[-1];
    }
    return r;
}
