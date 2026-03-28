static void* s_freeList_AptInteger_DeleteThis;
struct AptInteger_DeleteThis_S {
    char pad[0x0C];
    void* m_next;
    void func();
};
void AptInteger_DeleteThis_S::func() {
    m_next = s_freeList_AptInteger_DeleteThis;
    s_freeList_AptInteger_DeleteThis = this;
}
