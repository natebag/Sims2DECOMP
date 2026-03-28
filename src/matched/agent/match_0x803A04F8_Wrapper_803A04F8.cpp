struct Cls_Wrapper_803A04F8 {
    void* _vtable;
    void* m_pImpl;
    void Delegate();
};

void Impl_Wrapper_803A04F8(void*);

void Cls_Wrapper_803A04F8::Delegate() {
    Impl_Wrapper_803A04F8(m_pImpl);
}
