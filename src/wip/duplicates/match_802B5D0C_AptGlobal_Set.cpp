struct Inner_AptGlobal_Set {
    void func();
};
struct AptGlobal_Set_S {
    char pad[0x0C];
    Inner_AptGlobal_Set m_inner;
    void func();
};
void AptGlobal_Set_S::func() {
    m_inner.func();
}
