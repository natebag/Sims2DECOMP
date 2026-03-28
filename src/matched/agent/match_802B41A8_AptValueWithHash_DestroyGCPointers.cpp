struct Inner_AptValueWithHash_DestroyGCPointers {
    void func();
};
struct AptValueWithHash_DestroyGCPointers_S {
    char pad[0x0C];
    Inner_AptValueWithHash_DestroyGCPointers m_inner;
    void func();
};
void AptValueWithHash_DestroyGCPointers_S::func() {
    m_inner.func();
}
