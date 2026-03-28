struct Cls_Wrapper_8039F5E8 {
    void* _vtable;
    void* m_pImpl;
    void Delegate();
};

void Impl_Wrapper_8039F5E8(void*);

void Cls_Wrapper_8039F5E8::Delegate() {
    Impl_Wrapper_8039F5E8(m_pImpl);
}
