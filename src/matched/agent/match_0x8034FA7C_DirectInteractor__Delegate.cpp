struct Cls_8034FA7C {
    char _pad[0x28];
    void* m_pImpl;
    void Delegate();
};

void Impl_8034FA7C(void*);

void Cls_8034FA7C::Delegate() {
    Impl_8034FA7C(m_pImpl);
}
