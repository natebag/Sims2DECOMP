struct Inner_AptObject_Set {
    void func();
};
struct AptObject_Set_S {
    char pad[0x0C];
    Inner_AptObject_Set m_inner;
    void func();
};
void AptObject_Set_S::func() {
    m_inner.func();
}
