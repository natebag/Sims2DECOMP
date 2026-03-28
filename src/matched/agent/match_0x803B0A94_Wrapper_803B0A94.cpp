struct Cls_Wrapper_803B0A94 {
    void* _vtable;
    void* m_pImpl;
    void Delegate();
};

void Impl_Wrapper_803B0A94(void*);

void Cls_Wrapper_803B0A94::Delegate() {
    Impl_Wrapper_803B0A94(m_pImpl);
}
