struct Inner_AptObject_Lookup {
    void func();
};
struct AptObject_Lookup_S {
    char pad[0x0C];
    Inner_AptObject_Lookup m_inner;
    void func();
};
void AptObject_Lookup_S::func() {
    m_inner.func();
}
