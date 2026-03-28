struct Cls_Wrapper_8039E30C {
    void* _vtable;
    void* m_pImpl;
    void Delegate();
};

void Impl_Wrapper_8039E30C(void*);

void Cls_Wrapper_8039E30C::Delegate() {
    Impl_Wrapper_8039E30C(m_pImpl);
}
