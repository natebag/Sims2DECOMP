struct Inner_AptGlobal_Lookup {
    void func();
};
struct AptGlobal_Lookup_S {
    char pad[0x0C];
    Inner_AptGlobal_Lookup m_inner;
    void func();
};
void AptGlobal_Lookup_S::func() {
    m_inner.func();
}
