static void* s_freeList_AptFloat_DeleteThis;
struct AptFloat_DeleteThis_S {
    char pad[0x0C];
    void* m_next;
    void func();
};
void AptFloat_DeleteThis_S::func() {
    m_next = s_freeList_AptFloat_DeleteThis;
    s_freeList_AptFloat_DeleteThis = this;
}
