static void* s_freeList_AptInteger_Destroy;
struct AptInteger_Destroy_S {
    char pad[0x0C];
    void* m_next;
    void func();
};
void AptInteger_Destroy_S::func() {
    m_next = s_freeList_AptInteger_Destroy;
    s_freeList_AptInteger_Destroy = this;
}
