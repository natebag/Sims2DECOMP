struct Cls_Wrapper_803A828C {
    void* _vtable;
    void* m_pImpl;
    void Delegate();
};

void Impl_Wrapper_803A828C(void*);

void Cls_Wrapper_803A828C::Delegate() {
    Impl_Wrapper_803A828C(m_pImpl);
}
