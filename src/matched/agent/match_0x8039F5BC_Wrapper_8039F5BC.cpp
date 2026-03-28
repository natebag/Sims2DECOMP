struct Cls_Wrapper_8039F5BC {
    void* _vtable;
    void* m_pImpl;
    void Delegate();
};

void Impl_Wrapper_8039F5BC(void*);

void Cls_Wrapper_8039F5BC::Delegate() {
    Impl_Wrapper_8039F5BC(m_pImpl);
}
