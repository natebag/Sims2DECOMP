struct Inner_AptValueWithHash_Lookup {
    void func();
};
struct AptValueWithHash_Lookup_S {
    char pad[0x0C];
    Inner_AptValueWithHash_Lookup m_inner;
    void func();
};
void AptValueWithHash_Lookup_S::func() {
    m_inner.func();
}
