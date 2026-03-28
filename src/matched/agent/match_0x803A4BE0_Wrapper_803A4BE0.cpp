struct Cls_Wrapper_803A4BE0 {
    void* _vtable;
    void* m_pImpl;
    void Delegate();
};

void Impl_Wrapper_803A4BE0(void*);

void Cls_Wrapper_803A4BE0::Delegate() {
    Impl_Wrapper_803A4BE0(m_pImpl);
}
