struct Cls_Wrapper_8039F448 {
    void* _vtable;
    void* m_pImpl;
    void Delegate();
};

void Impl_Wrapper_8039F448(void*);

void Cls_Wrapper_8039F448::Delegate() {
    Impl_Wrapper_8039F448(m_pImpl);
}
