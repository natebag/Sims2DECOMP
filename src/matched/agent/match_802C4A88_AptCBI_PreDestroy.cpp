struct Inner_AptCBI_PreDestroy {
    void func();
};
struct AptCBI_PreDestroy_S {
    char pad[0x1C];
    Inner_AptCBI_PreDestroy m_inner;
    void func();
};
void AptCBI_PreDestroy_S::func() {
    m_inner.func();
}
