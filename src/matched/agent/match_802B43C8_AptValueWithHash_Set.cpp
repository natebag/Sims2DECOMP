struct Inner_AptValueWithHash_Set {
    void func();
};
struct AptValueWithHash_Set_S {
    char pad[0x0C];
    Inner_AptValueWithHash_Set m_inner;
    void func();
};
void AptValueWithHash_Set_S::func() {
    m_inner.func();
}
