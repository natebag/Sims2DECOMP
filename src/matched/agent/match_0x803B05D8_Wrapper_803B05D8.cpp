struct Cls_Wrapper_803B05D8 {
    void* _vtable;
    void* m_pImpl;
    void Delegate();
};

void Impl_Wrapper_803B05D8(void*);

void Cls_Wrapper_803B05D8::Delegate() {
    Impl_Wrapper_803B05D8(m_pImpl);
}
