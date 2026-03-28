struct Cls_Wrapper_803A8260 {
    void* _vtable;
    void* m_pImpl;
    void Delegate();
};

void Impl_Wrapper_803A8260(void*);

void Cls_Wrapper_803A8260::Delegate() {
    Impl_Wrapper_803A8260(m_pImpl);
}
