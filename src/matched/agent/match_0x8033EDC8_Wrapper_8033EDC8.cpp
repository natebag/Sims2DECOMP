struct Cls_Wrapper_8033EDC8 {
    char _pad[0x4D8];
    void* m_pImpl;
    void Delegate();
};

void Impl_Wrapper_8033EDC8(void*);

void Cls_Wrapper_8033EDC8::Delegate() {
    Impl_Wrapper_8033EDC8(m_pImpl);
}
