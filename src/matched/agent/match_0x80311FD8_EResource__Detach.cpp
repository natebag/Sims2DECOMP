struct EResource {
    char _pad[0x4];
    void* m_pManager;
    void Detach();
};

void Impl_80311FD8(void*, void*);

void EResource::Detach() {
    Impl_80311FD8(m_pManager, this);
}
