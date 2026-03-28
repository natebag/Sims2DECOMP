
void HouseImpl_StreamField0(void *);
void HouseImpl_StreamSelf(void *);

struct HouseImpl {
    void* m_field_000;
    void DoStream(int flags);
};

void HouseImpl::DoStream(int flags) {
    if (m_field_000 != 0) {
        HouseImpl_StreamField0(m_field_000);
    }
    if (flags & 1) {
        HouseImpl_StreamSelf(this);
    }
}
